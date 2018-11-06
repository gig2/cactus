//
#include "meshutilities.h"

#include "gmock/gmock-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

#include <array>

using MeshT = OpenMesh::TriMesh_ArrayKernelT<OpenMesh::DefaultTraits>;

using namespace testing;

TEST( anEmptyMesh, haveNoFaces )
{
    //
    MeshT mesh;
    auto numFaces = numberOfFaces( mesh );

    EXPECT_THAT( numFaces, Eq( 0u ) );
}

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


TEST( aCube, haveDiedreAngleEqualsToPi )
{
    auto cube = constructCube();


    float expectedAngle = M_PI / 2.0;

    float maxError = 1.e-5;

    for ( auto faceIt = cube.faces_begin(); faceIt != cube.faces_end(); ++faceIt )
    {
        auto nextFace = std::next( faceIt );
        if ( nextFace != cube.faces_end() )
        {
            // do stuff
            auto angle = angleBetweenFaces( cube, *faceIt, *nextFace );

            EXPECT_THAT( angle,
                         AnyOf( FloatNear( expectedAngle, maxError ), FloatNear( 0.f, maxError ),
                                FloatNear( static_cast<float>( M_PI ), maxError ) ) );
        }
    }
}



int main( int argc, char **argv )
{
    ::testing::InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}
