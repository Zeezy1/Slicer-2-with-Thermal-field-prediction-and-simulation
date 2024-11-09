#ifndef MESHLOADER_H
#define MESHLOADER_H

// Qt
#include <QFileInfo>
#include <QThread>

//在 Qt 中，QThread 用来创建和管理线程。默认情况下，所有的 Qt 应用程序都在一个单线程中运行，即所谓的主线程或 GUI 线程。
//通过使用 QThread，可以将一些耗时的操作放在后台线程中执行，以确保主线程（特别是 GUI 线程）保持响应状态，不被阻塞。

// 线程安全
// 多线程编程中的一个重要问题是线程安全。不同线程访问相同数据时，必须通过加锁等机制防止数据竞争。Qt 提供了多种锁机制，如 QMutex、QSemaphore、QWaitCondition 等。

//GUI 线程与后台线程的区别
//Qt 要求所有的 GUI 相关操作必须在主线程中执行，因此不能在后台线程中直接操作 UI 控件。可以通过信号和槽机制，将需要更新 UI 的信号发送到主线程中处理。

//线程的生命周期管理
//创建线程时要注意线程的生命周期管理，避免资源泄露或异常退出时没有正确结束线程。


// Local
#include <utilities/enums.h>
#include "geometry/mesh/closed_mesh.h"

// Assimp
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include "assimp/Importer.hpp"

struct aiMesh;
struct aiScene;


namespace ORNL
{
    class Mesh;
    class MeshVertex;
    class MeshFace;

    /*!
     * \class MeshLoader
     * \brief Loads a mesh from a file in a separate thread.
     */
    class MeshLoader : public QThread {
        Q_OBJECT
        public:
            //! \struct MeshData
            //! \brief Holds a pointer to a mesh and the raw data/ size
            struct MeshData
            {
                QSharedPointer<MeshBase> mesh = nullptr;
                void* raw_data = nullptr;
                size_t size = 0;
            };

            //! \brief Constructor for thread
            MeshLoader(QString file_path, MeshType mt = MeshType::kBuild, QMatrix4x4 transform = QMatrix4x4(), Distance unit = Distance(mm));

            //! \brief Function that is run when start is called on this thread.
            void run() override;

            //! \brief loads meshes from a file off the thread
            //! \param file_path the path to the file
            //! \param mt the mesh type
            //! \param transform the transform to apply
            //! \param unit the unit to scale with
            //! \param raw_data optional raw data
            //! \param file_size optional file size
            //! \return a list of loaded meshes and their data
            //! \note if raw_data and file_size are not provided, the mesh will be loaded from the file directly
            static QVector<MeshData> LoadMeshes(QString file_path, MeshType mt = MeshType::kBuild, QMatrix4x4 transform = QMatrix4x4(), Distance unit = Distance(mm), void* raw_data = nullptr, size_t file_size = 0);

        signals:
            //! \brief Sends the model to the project manager
            void newMesh(MeshData data);

            //! \brief Emits error signal
            void error(QString msg);

        private:

            //! \brief loads raw data from a path
            //! \param file_path the path to load from
            //! \return a pair containing the raw data as a void ptr and the size in bytes
            static std::pair<void*, size_t> LoadRawData(QString file_path);

            //! \brief builds a surface mesh from an assimp mesh
            //! \param mesh the assimp mesh
            //! \return a surface mesh
            static MeshTypes::SurfaceMesh BuildSurfaceMesh(aiMesh* mesh);

            //! \class MeshBuilderAssimp
            //! \brief CGAL builder to convert an assimp mesh into a CGAL polyhedron
            template <class HDS>
            class MeshBuilderAssimp : public CGAL::Modifier_base<HDS>
            {
                public:
                    //! \brief Builds a polyhedron incrementally using faces
                    //! \param vertices: the mesh's vertices
                    //! \param faces: the mesh's faces
                    MeshBuilderAssimp(aiMesh* mesh) : m_mesh(mesh) {};//使用初始化列表 : m_mesh(mesh) 把传入的参数 mesh 赋值给成员变量 m_mesh

                    void operator()(HDS& hds)
                    {
                        CGAL::Polyhedron_incremental_builder_3<HDS> builder(hds, false);

                        builder.begin_surface(m_mesh->mNumVertices, m_mesh->mNumFaces);

                        // Add all vertices
                        for(unsigned int i = 0; i < m_mesh->mNumVertices; i++)
                        {
                            builder.add_vertex(MeshTypes::Point_3(m_mesh->mVertices[i].x * 1000, // Scale from mm to micron
                                                                  m_mesh->mVertices[i].y * 1000,
                                                                  m_mesh->mVertices[i].z * 1000));
                        }

                        for (unsigned int i = 0; i < m_mesh->mNumFaces; i++)
                        {
                            builder.begin_facet();
                            for (unsigned int j = 0; j < m_mesh->mFaces[i].mNumIndices; j++)
                            {
                                int index = m_mesh->mFaces[i].mIndices[j];
                                builder.add_vertex_to_facet(index);
                            }

                            if (builder.error())
                            {
                                m_error = true;
                                builder.rollback();
                                return;
                            }

                            builder.end_facet();
                        }

                        if (builder.error())
                        {
                            m_error = true;
                            builder.rollback();
                        }

                        builder.end_surface();

                        if (builder.check_unconnected_vertices())
                            builder.remove_unconnected_vertices();
                    }

                    bool wasError()
                    {
                        return m_error;
                    }
                private:
                    aiMesh* m_mesh;
                    bool m_error = false;
            };

            //! \brief path to file
            QString m_file_path;

            //! \brief Actual name.
            QString m_name;

            //! \brief The type of mesh this will be
            MeshType m_mesh_type;

            //! \brief the default transform to apply
            QMatrix4x4 m_transform;

            //! \brief the default unit scaling to apply
            Distance m_unit;

    };  // class MeshLoader
}  // namespace ORNL
#endif  // MESHLOADER_H
