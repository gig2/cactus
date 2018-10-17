#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <string>

using MeshTraits = OpenMesh::DefaultTraits;
using MeshT      = OpenMesh::TriMesh_ArrayKernelT<MeshTraits>;

class Mesh
{
private:
    MeshT mesh_;

public:
    Mesh() = default;

    void loadMesh( std::string fileadress );
};
