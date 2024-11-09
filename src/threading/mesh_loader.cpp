// Header
#include "threading/mesh_loader.h"

// Qt
#include <QLinkedList>
#include <QStack>
#include <QtDebug>

// C++
#include <utility>

// Local
#include "geometry/mesh/mesh_base.h"
#include "geometry/mesh/closed_mesh.h"
#include "geometry/mesh/open_mesh.h"
#include "managers/session_manager.h"
#include "managers/preferences_manager.h"
#include "managers/settings/settings_manager.h"

namespace ORNL
{
    MeshLoader::MeshLoader(QString file_path, MeshType mt, QMatrix4x4 transform, Distance unit) :
    m_file_path(file_path), m_mesh_type(mt), m_transform(transform), m_unit(unit)
    {
    }

    void MeshLoader::run()
    {
        auto meshes = LoadMeshes(m_file_path, m_mesh_type, m_transform, m_unit);

        if(meshes.isEmpty())
            emit error("Error importing mesh: " + QFileInfo(m_file_path).fileName());

        for(auto mesh_data : meshes)
            emit newMesh(mesh_data);
    }

    QVector<MeshLoader::MeshData> MeshLoader::LoadMeshes(QString file_path, MeshType mt, QMatrix4x4 transform, Distance unit, void* raw_data, size_t file_size)
    {
        QVector<MeshData> loaded_meshes;

        QFileInfo file_info(file_path);

        std::pair<void*, size_t> file_data;

        if(raw_data == nullptr || file_size == 0) // Data not provided, so load from file
        {
            if(!file_info.exists())
                return loaded_meshes;

            file_data = LoadRawData(file_info.absoluteFilePath());
        }
        else
            file_data = std::make_pair(raw_data, file_size);//返回的是键值对 (data,size)

        const aiScene* scene = nullptr;//all imported data,everything can be accessed from here

        Assimp::Importer importer;

        auto model_type = file_info.suffix();

        if(model_type == "stl" || model_type == "STL")
        {
            scene = importer.ReadFileFromMemory(file_data.first, file_data.second,//缓冲区和size 对应的键值对
                    aiProcess_DropNormals |//法线是 3D 模型的每个顶点或面片的方向信息，常用于光照计算。如果模型本身不需要法线（比如只需要几何结构），可以选择丢弃它们，减少模型大小和内存消耗。
                    aiProcess_JoinIdenticalVertices |//3D 模型有时可能包含重复的顶点（即不同的面片引用同样的坐标，但这些顶点在数据结构中是独立的）。这个处理步骤会合并这些顶点，减少内存占用，并提高渲染效率。
                    aiProcess_SortByPType,//3D 模型可能包含不同类型的几何图元，比如点、线、三角形、多边形等。aiProcess_SortByPType 将不同类型的图元分离成不同的部分，便于后续的处理或渲染。
                    "stl"); // Tell assimp we are using STL.
        }else if(model_type == "3mf" || model_type == "3MF")
        {
            scene = importer.ReadFileFromMemory(file_data.first, file_data.second,
                    aiProcess_DropNormals |
                    aiProcess_JoinIdenticalVertices |
                    aiProcess_SortByPType,
                    "3mf"); // Tell assimp we are using 3mf.
        }else if(model_type == "obj" || model_type == "OBJ")
        {
            scene = importer.ReadFileFromMemory(file_data.first, file_data.second,
                    aiProcess_DropNormals |
                    aiProcess_JoinIdenticalVertices |
                    aiProcess_Triangulate |//将所有的多边形转化为三角形，方便大部分渲染引擎处理。
                    aiProcess_SortByPType,
                    "obj"); // Tell assimp we are using obj.
        }else if(model_type == "amf" || model_type == "AMF")
        {
            scene = importer.ReadFileFromMemory(file_data.first, file_data.second,
                    aiProcess_DropNormals |
                    aiProcess_JoinIdenticalVertices |
                    aiProcess_Triangulate |
                    aiProcess_SortByPType,
                    "amf"); // Tell assimp we are using obj.
        }
        else{
            scene = importer.ReadFileFromMemory(file_data.first, file_data.second,
                    aiProcess_DropNormals |
                    aiProcess_JoinIdenticalVertices |
                    aiProcess_SortByPType);
        }

        if (scene == nullptr)
            return loaded_meshes;

        if(scene->HasMeshes())
        {
            // extracts meshes that have both faces and vertices
            int num_models_added = 0;
            for(int i = 0, end = scene->mNumMeshes; i < end; ++i)
            {
                auto mesh = scene->mMeshes[i];
                if(mesh->mNumFaces > 0 && mesh->mNumVertices > 0)
                {
                    QString name = file_info.baseName();

                    if(scene->mNumMeshes > 1)
                        name += "_" + QString::number(num_models_added);

                     QSharedPointer<MeshBase> new_mesh;

                    // Try to build a closed mesh first
                    MeshTypes::Polyhedron polyhedron;
                    MeshBuilderAssimp<MeshTypes::HalfedgeDescriptor> builder(mesh);
                    polyhedron.delegate(builder);

                    if(GSM->getGlobal()->setting<bool>(Constants::ProfileSettings::SpecialModes::kEnableFixModel))
                        ClosedMesh::CleanPolyhedron(polyhedron);

                    if(builder.wasError() || !polyhedron.is_closed())
                    {
                        MeshTypes::SurfaceMesh sm = BuildSurfaceMesh(mesh);
                        new_mesh = QSharedPointer<OpenMesh>::create(sm, name, file_info.fileName());
                        dynamic_cast<OpenMesh*>(new_mesh.data())->shortestPath();

                    }else{
                        new_mesh = QSharedPointer<ClosedMesh>::create(polyhedron, name, file_info.fileName());

                    }
                    new_mesh->setType(mt);

                    // Center the mesh about itself
                    auto center = new_mesh->originalCentroid();
                    new_mesh->center();

                    if(transform.isIdentity()) // If the transform was not provided
                    {
                        // Scale to the default unit
                        Distance conv(unit);
                        conv = conv.to(mm);
                        transform.scale(QVector3D(conv(), conv(), conv()));
                        new_mesh->setUnit(unit);

                        if(PM->getUseImplicitTransforms())
                            transform.translate(center.toQVector3D());
                    }

                    // Apply transform
                    new_mesh->setTransformation(transform);

                    loaded_meshes.push_back({ new_mesh, file_data.first, file_data.second });//The final mesh is stored in loaded_meshes along with the raw data and size

                    ++num_models_added;
                }
            }
        }

        return loaded_meshes;
    }

    std::pair<void*, size_t> MeshLoader::LoadRawData(QString file_path)
    {

        // Load raw data
        // Some C here to get a void pointer of the model.
        //fopen:这是一个标准的 C 函数，用于以 "二进制读" 模式（"rb"）打开文件。file_path.toUtf8() 将 QString 转换为 C 风格的 UTF-8 字符串。
        //fptr：这是一个指向文件的指针，如果 fopen 成功打开文件，fptr 将指向该文件，否则它会返回 nullptr。
        FILE* fptr = fopen(file_path.toUtf8(), "rb");

        fseek(fptr, 0L, SEEK_END);//将文件指针移动到文件末尾，以便测量文件大小
        size_t fsize = ftell(fptr);
        fseek(fptr, 0L, SEEK_SET);//将文件指针重新设置到文件的起始位置，准备读取文件内容。

        void* data = malloc(fsize);//memory allocation 分配内存
        if (data == nullptr)
            return std::make_pair(nullptr, 0);

        int readres = fread(data, 1, fsize, fptr);//从文件读取数据，读取到 data 中 ; 故初始data指向该内存块地址，是随机的内容，现在该内存块通过fread存储了文件的内容

        if (readres != fsize)
            return std::make_pair(nullptr, 0);

        fclose(fptr);

        return std::make_pair(data, fsize);
    }

    MeshTypes::SurfaceMesh MeshLoader::BuildSurfaceMesh(aiMesh *mesh)
    {
        MeshTypes::SurfaceMesh sm;
        typedef MeshTypes::SurfaceMesh::Vertex_index VertexIndex;
        QMap<uint, VertexIndex> points;

        for(uint i = 0, end = mesh->mNumVertices; i < end; ++i)
            points[i] = sm.add_vertex(MeshTypes::Point_3(mesh->mVertices[i].x * 1000, mesh->mVertices[i].y * 1000, mesh->mVertices[i].z * 1000));

        for(uint i = 0, end = mesh->mNumFaces; i < end; ++i)
        {
            auto& face = mesh->mFaces[i];
            auto face_desc = sm.add_face(points[face.mIndices[0]],
                                         points[face.mIndices[1]],
                                         points[face.mIndices[2]]);
        }
        return sm;
    }
}  // namespace ORNL
