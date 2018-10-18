#include "mesh.h"

Mesh::Mesh( std::string filename )
{
    if ( !OpenMesh::IO::read_mesh( mesh, filename ) )
    {
        throw std::runtime_error( "Mesh loading error" );
    }
}
