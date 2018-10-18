#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/Attributes.hh>
#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <string>

struct MeshTraits : public OpenMesh::DefaultTraits
{
    // use floating point
    typedef OpenMesh::Vec3f Point;

    // use vertex normals and vertex colors
    VertexAttributes( OpenMesh::Attributes::Normal | OpenMesh::Attributes::Color );


    // use face normals
    FaceAttributes( OpenMesh::Attributes::Normal );
};

using MeshT = OpenMesh::TriMesh_ArrayKernelT<MeshTraits>;

class Mesh
{
public:
    explicit Mesh( std::string filename );

    MeshT mesh;
};
