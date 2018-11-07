#include "cube.h"

MeshT constructCube()
{
    MeshT mesh;

    // let's generate a cube

    std::array<MeshT::VertexHandle, 8> vhandle;

    vhandle[ 0 ] = mesh.add_vertex( MeshT::Point{-1, -1, 1} );
    vhandle[ 1 ] = mesh.add_vertex( MeshT::Point{1, -1, 1} );
    vhandle[ 2 ] = mesh.add_vertex( MeshT::Point{1, 1, 1} );
    vhandle[ 3 ] = mesh.add_vertex( MeshT::Point{-1, 1, 1} );
    vhandle[ 4 ] = mesh.add_vertex( MeshT::Point{-1, -1, -1} );
    vhandle[ 5 ] = mesh.add_vertex( MeshT::Point{1, -1, -1} );
    vhandle[ 6 ] = mesh.add_vertex( MeshT::Point{1, 1, -1} );
    vhandle[ 7 ] = mesh.add_vertex( MeshT::Point{-1, 1, -1} );

    std::vector<MeshT::VertexHandle> faceVhandles;

    faceVhandles.clear();
    faceVhandles.push_back( vhandle[ 0 ] );
    faceVhandles.push_back( vhandle[ 1 ] );
    faceVhandles.push_back( vhandle[ 2 ] );
    faceVhandles.push_back( vhandle[ 3 ] );
    mesh.add_face( faceVhandles );


    faceVhandles.clear();
    faceVhandles.push_back( vhandle[ 7 ] );
    faceVhandles.push_back( vhandle[ 6 ] );
    faceVhandles.push_back( vhandle[ 5 ] );
    faceVhandles.push_back( vhandle[ 4 ] );
    mesh.add_face( faceVhandles );


    faceVhandles.clear();
    faceVhandles.push_back( vhandle[ 1 ] );
    faceVhandles.push_back( vhandle[ 0 ] );
    faceVhandles.push_back( vhandle[ 4 ] );
    faceVhandles.push_back( vhandle[ 5 ] );
    mesh.add_face( faceVhandles );

    faceVhandles.clear();
    faceVhandles.push_back( vhandle[ 2 ] );
    faceVhandles.push_back( vhandle[ 1 ] );
    faceVhandles.push_back( vhandle[ 5 ] );
    faceVhandles.push_back( vhandle[ 6 ] );
    mesh.add_face( faceVhandles );


    faceVhandles.clear();
    faceVhandles.push_back( vhandle[ 3 ] );
    faceVhandles.push_back( vhandle[ 2 ] );
    faceVhandles.push_back( vhandle[ 6 ] );
    faceVhandles.push_back( vhandle[ 7 ] );
    mesh.add_face( faceVhandles );


    faceVhandles.clear();
    faceVhandles.push_back( vhandle[ 0 ] );
    faceVhandles.push_back( vhandle[ 3 ] );
    faceVhandles.push_back( vhandle[ 7 ] );
    faceVhandles.push_back( vhandle[ 4 ] );
    mesh.add_face( faceVhandles );

    return mesh;
}
