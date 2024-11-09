#include "optimizers/layer_order_optimizer.h"
#include "utilities/mathutils.h"

namespace ORNL
{
    //优化图层的顺序，以便在 3D 打印过程中有效地处理不同的部分（Part）和步骤（Step）。
    QSharedPointer<GlobalLayer> LayerOrderOptimizer::populateStep(QVector<QSharedPointer<Part>> build_parts)
    {
        //! \note called by real-time slicers only

        QSharedPointer<GlobalLayer> new_g_layer = QSharedPointer<GlobalLayer>::create(0); // only one layer is kept at a time, so we can always number it 0

        // add all the dirty step groups to the global layer
        for (auto& part : build_parts)
        {
            QList<Part::StepPair> dirty_step_groups = part->getDirtyStepPairs();
            for(auto& step_group : dirty_step_groups)
                new_g_layer->addStepPair(part->getId(), step_group);
        }

        return new_g_layer;
    }

    //根据全局设置中的图层排序方法（LayerOrdering）来填充全局图层的列表
    QList<QSharedPointer<GlobalLayer>> LayerOrderOptimizer::populateSteps(QSharedPointer<SettingsBase> global_sb, QVector<QSharedPointer<Part>> build_parts)
    {
        // list to return at end of function
        QList<QSharedPointer<GlobalLayer>> global_layers = QList<QSharedPointer<GlobalLayer>>();

        // get the layer ordering method, and then populate the global layers accordingly
        // after global layers have been assigned, assign nozzles/tools (if necessary)
        LayerOrdering order_method = global_sb->setting<LayerOrdering>(Constants::ExperimentalSettings::PrinterConfig::kLayerOrdering);


        //! 假设所有部分的切片平面角度相同，计算每个部分的当前步骤，并找到“最低”的图层，然后将具有相同平面的图层组合到同一个全局图层中
        //! 获取切片平面的法向量和切片角度，然后计算每个部分的当前层与该层的距离。
        //! 使用一个映射来跟踪每个部分的当前图层。
        //! 通过循环检查每个部分的图层，找到距离最近的图层，并将其加入到全局图层中，直到所有部分的图层都被处理完。

        if (order_method == LayerOrdering::kByHeight)
        {
            //! \note Layer ordering by height assumes that all parts were sliced with same plane angle, and that the plane does not rotate
            //! 假设所有部分的切片平面角度相同，计算每个部分的当前步骤，并找到“最低”的图层，然后将具有相同平面的图层组合到同一个全局图层中。
            // fetch the slicing plane normal from global settings
            QVector3D slicing_plane =  QVector3D(0, 0, 1);
            //! 俯仰、偏航和滚动
            Angle slicing_plane_pitch = global_sb->setting<Angle>(Constants::ExperimentalSettings::SlicingAngle::kStackingDirectionPitch);
            Angle slicing_plane_yaw   = global_sb->setting<Angle>(Constants::ExperimentalSettings::SlicingAngle::kStackingDirectionYaw);
            Angle slicing_plane_roll  = global_sb->setting<Angle>(Constants::ExperimentalSettings::SlicingAngle::kStackingDirectionRoll);
            //! 使用一个四元数（QQuaternion）将初始法向量旋转到指定角度，以便获得最终的切片法向量（slicing_plane）
            QQuaternion quaternion = MathUtils::CreateQuaternion(slicing_plane_pitch, slicing_plane_yaw, slicing_plane_roll);
            slicing_plane = quaternion.rotatedVector(slicing_plane);

            bool steps_left = true;
            int num_global_steps = 0;

            // Make a map to track the step/layer number each part is currently on
            // Start each part at zero
            QMap<QUuid, int> current_layer;
            for (auto& part : build_parts)
                current_layer.insert(part->getId(), 0);

            while (steps_left)
            {

                // Check the current step of all the parts, find the minimum plane
                QUuid part_with_min_plane = QUuid(); // null quuid initially
                Plane min_plane;
                Distance min_dist;

                // Check all the parts for the next "lowest" layer to print
                //! 内层循环遍历所有的部分，为每个部分找到一个“当前最低”图层
                for (auto& part : build_parts)
                {
                    QUuid part_id = part->getId();

                    // Skip the part if all its layers have been assigned to a global layer
                    if (current_layer[part_id] >= part->countStepPairs())
                        continue;

                    // Get the current layer for this part
                    QSharedPointer<Step> current_step = part->getStepPair(current_layer[part_id]).printing_layer;

                    // calculate the distance from
                    Plane layer_plane = current_step->getSlicingPlane();
                    Distance layer_height = current_step->getSb()->setting<Distance>(Constants::ProfileSettings::Layer::kLayerHeight);
                    layer_plane.shiftAlongNormal(layer_height() / 2.0);

                    //! 表示切片平面与原点的距离
                    Distance layer_dist = MathUtils::linePlaneIntersection(Point(0,0,0), slicing_plane, layer_plane).distance();

                    // If this is the first plane in this loop, or its lower than the current min, set this layer as the min
                    if (part_with_min_plane.isNull() || layer_dist < min_dist)
                    {
                        part_with_min_plane = part_id;
                        min_plane = layer_plane;
                        min_dist = layer_dist;
                    }
                }

                // check all the parts (again) for layers with the same plane as the lowest layer. Layers with same plane can
                // be printed at the same time, and go on the same global layer
                QSharedPointer<GlobalLayer> new_global_layer = QSharedPointer<GlobalLayer>::create(num_global_steps);
                for (auto& part : build_parts)
                {
                    QUuid part_id = part->getId();

                    //skip the part if all its layers have been assigned to a global layer
                    if (current_layer[part_id] >= part->countStepPairs())
                        continue;

                    // get the current layer for this part
                    QSharedPointer<Step> current_step =  part->getStepPair(current_layer[part_id]).printing_layer;

                    Distance layer_height = current_step->getSb()->setting<Distance>(Constants::ProfileSettings::Layer::kLayerHeight);
                    //! 用于允许在一定范围内的图层合并，避免因微小差异而创建额外的全局图层。
                    Distance layer_grouping_tolerance = global_sb->setting<Distance>(Constants::ExperimentalSettings::PrinterConfig::kLayerGroupingTolerance);
                    Plane layer_plane = current_step->getSlicingPlane();
                    layer_plane.shiftAlongNormal(layer_height() / 2.0);

                    // if this part's current layer is equal to the min plane, add it to the global layer
                    if (layer_plane.isEqual(min_plane, layer_grouping_tolerance()))
                    {
                        new_global_layer->addStepPair(part_id, part->getStepPair(current_layer[part_id]));
                        ++current_layer[part_id];
                    }
                }

                // add the new global layer to the list
                //!global_layers 重点关注
                global_layers.push_back(new_global_layer);
                ++num_global_steps;

                // update steps_left
                steps_left = false;
                //! 如果所有部分的当前图层索引都已经达到了总图层数（countStepPairs）(下面的 或 判断逻辑)
                for (auto& part : build_parts)
                    steps_left = steps_left || (current_layer[part->getId()] < part->countStepPairs());

            } // end while(steps left)
        }
        else if(order_method == LayerOrdering::kByLayerNumber)
        {
            // look at all the parts to find the maximum number of steps
            // this will be the number of global layers
            int max_steps = 0;
            for (auto part: build_parts)
                max_steps = qMax(max_steps, part->countStepPairs());

            global_layers.reserve(max_steps);

            // for each global layer
            //     make a new layer
            //     add the steps/layers/scan layers from all the parts
            for (int step = 0; step < max_steps; ++step)
            {
                QSharedPointer<GlobalLayer> new_global_layer = QSharedPointer<GlobalLayer>::create(step);


                for (auto part: build_parts)
                {
                    if (step < part->countStepPairs())
                        new_global_layer->addStepPair(part->getId(), part->getStepPair(step));
                }

                global_layers.push_back(new_global_layer);
            }
        }
        else if ( order_method == LayerOrdering::kByPart)
        {
            // printing parts sequentially, so every part layer gets its own global layer
            int max_steps = 0;
            for (auto part: build_parts)
                max_steps += part->countStepPairs();

            global_layers.reserve(max_steps);

            int num_g_steps = 0;
            for (auto part: build_parts)
            {
                for (int s = 0, max_steps = part->countStepPairs(); s < max_steps; ++s)
                {
                    QSharedPointer<GlobalLayer> new_global_layer = QSharedPointer<GlobalLayer>::create(num_g_steps);
                    new_global_layer->addStepPair(part->getId(), part->getStepPair(s));
                    global_layers.push_back(new_global_layer);

                    ++num_g_steps;
                }
            }
        }
        else
        {
            Q_ASSERT(false); // invalid order method
        }

        //! \note combining laser scans is currently unsupported. If it were supported, it should be called somewhere else,
        //! after nozzle assignment. Maybe from slicing thread in final step of pre-processing or from the global layer
//                bool combine_scans = global_sb->setting<bool>(Constants::ProfileSettings::LaserScanner::kLaserScanner)
//                        && global_sb->setting<bool>(Constants::ProfileSettings::LaserScanner::kGlobalScan);
//                if(combine_scans)
//                {
//                    for(int i = 0; i < m_tool_count; ++i)
//                    {
//                        adjustLaserScanLayers(num_global_steps, global_sb, m_global_layers[num_global_steps][i]);
//                        for(int pId : m_global_layers[num_global_steps][0].keys())
//                        {

//                        }
//                    }
//                }

        return global_layers;
    }


    void LayerOrderOptimizer::logGlobalLayers(const QList<QSharedPointer<GlobalLayer>>& global_layers)
    {
    QFile logFile("global_layers_log.txt"); // 指定日志文件路径
    if (logFile.open(QIODevice::Append | QIODevice::Text)) // 追加模式
    {
        QTextStream logStream(&logFile);

        logStream << "Logging global_layers content:\n";
        for (int i = 0; i < global_layers.size(); ++i)
        {
            logStream << "Global Layer " << i << ":\n";
            const auto& layer = global_layers[i];

            //! // 使用 getStepPairs 获取 step pairs，并迭代输出内容
            const auto& step_pairs = layer->getStepPairs();
            for (auto it = step_pairs.constBegin(); it != step_pairs.constEnd(); ++it)
            {
                QUuid part_id = it.key();
                const QSharedPointer<Part::StepPair> &step_pair_ptr = it.value();

                // 确保 step_pair_ptr 非空
                if (step_pair_ptr)
                {
                logStream << "  Part ID: " << part_id.toString() << "\n";
/*                    if (step_pair_ptr->printing_layer)
                        logStream << "  Printing Layer: " << step_pair_ptr->printing_layer << "\n"; */ // 示例输出

                }
                else
                {
                    logStream << "  StepPair is null for Part ID: " << part_id.toString() << "\n";
                }

            }

                // 添加更多信息，如层高度、层位置等

        }
        logStream << "End of global_layers log\n\n";
    }
    logFile.close();
    }

    //! \note this function is unused and not updated in refactor. Should probably be moved to exist on the global layer
   /*
//    void LayerOrderOptimizer::adjustLaserScanLayers(int layer_index, QSharedPointer<SettingsBase> sb, GlobalLayer& global_layer)
//    {
//        QSharedPointer<SettingsBase> newSb = QSharedPointer<SettingsBase>::create(*sb);
//        if(layer_index == 0)
//            newSb->setSetting(Constants::ProfileSettings::Layer::kLayerHeight, 0.0);

//        QSharedPointer<Step> global_scan_layer = QSharedPointer<ScanLayer>::create(layer_index, newSb);
//        PolygonList combinedGeometry, combinedScanIsland;

//        float min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;

//        for(StepGroup& part_group : step_group)
//        {
//            if(part_group.contains(StepType::kScan))
//            {
//                QSharedPointer<Step> scan_step = part_group[StepType::kScan];

//                for(QSharedPointer<IslandBase> island : scan_step->getIslands())
//                {
//                    PolygonList poly_list = island->getGeometry();
//                    for(Polygon poly : poly_list)
//                    {
//                        for(Point pt : poly)
//                        {
//                            if(pt.x() < min_x)
//                                min_x = pt.x();
//                            if(pt.x() > max_x)
//                                max_x = pt.x();
//                            if(pt.y() < min_y)
//                                min_y = pt.y();
//                            if(pt.y() > max_y)
//                                max_y = pt.y();
//                        }
//                    }
//                }

//                combinedGeometry += scan_step->getGeometry();
//                part_group.remove(StepType::kScan);
//            }
//        }

//        Polygon poly = Polygon({Point(max_x, max_y), Point(min_x, max_y), Point(min_x, min_y), Point(max_x, min_y)});
//        combinedScanIsland += poly;

//        scan_layer->setOrientation(build_layer->getSlicingPlane(), shift, runningTotal);
//        scan_layer->updateIslands(IslandType::kLaserScan, newIslands);//        scan_layer->setGeometry(build_layer->getGeometry(), QVector3D());
//        scan_layer->setCompanionFileLocation(output_file);

//        // Create laser_scan_island and add it to the current layer
//        QSharedPointer<IslandBase> laser_scan_island = QSharedPointer<LaserScanIsland>::create(combinedScanIsland, newSb, QVector<SettingsPolygon>());
//        global_scan_layer->updateIslands(IslandType::kLaserScan, QVector<QSharedPointer<IslandBase>> { laser_scan_island });
//        global_scan_layer->setGeometry(combinedGeometry, QVector3D());

//        for(StepGroup& part_group : step_group)
//        {
//            part_group.insert(StepType::kScan, global_scan_layer);
//        }
//    }
*/

}
