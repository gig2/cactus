#include "cube.h"
#include "meshutilities.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <OpenMesh/Core/Geometry/Vector11T.hh>
#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

#include <algorithm>
#include <cmath>
#include <functional>

using testing::Eq;
using testing::FloatEq;


// So what do we need here
// first we need to check that an equilateral triangle
// will be seen as an equilateral triangle
// then we will change one angle to check that it will
// be less equilateral

// we have two main case of non equilaterality
// the pointy one : like an arrow -> one angle near to 0.
// the flat triangle: one angle near pi
// so basically we have minmax.second - minmax.first that is a good metrics
// to know how much we are not equilateral




TEST( anIsoceleRectangularTriangle, haveAngleOfPiOver4AndPiOver2 )
{
    //
    MeshT mesh;

    std::array<MeshT::VertexHandle, 3> vhandle;

    vhandle[ 0 ] = mesh.add_vertex( MeshT::Point{0., 0., 0.} );
    vhandle[ 1 ] = mesh.add_vertex( MeshT::Point{0., 1., 0.} );
    vhandle[ 2 ] = mesh.add_vertex( MeshT::Point{1., 0., 0.} );

    std::vector<MeshT::VertexHandle> faceVhandles;

    faceVhandles.push_back( vhandle[ 0 ] );
    faceVhandles.push_back( vhandle[ 1 ] );
    faceVhandles.push_back( vhandle[ 2 ] );

    mesh.add_face( faceVhandles );


    for ( auto faceIt = mesh.faces_begin(); faceIt != mesh.faces_end(); ++faceIt )
    {
        //
        auto minmax = minmaxAngleInTriangle( mesh, *faceIt );

        EXPECT_THAT( minmax.first, FloatEq( M_PI / 4.f ) );
        EXPECT_THAT( minmax.second, FloatEq( M_PI / 2.f ) );
    }
}

TEST( anEquilateralTriangle, haveAngleOfPiOver3 )
{
    //
    MeshT mesh;

    std::array<MeshT::VertexHandle, 3> vhandle;

    float sqrt3o2 = std::sqrt( 3.f ) / 2.f;

    vhandle[ 0 ] = mesh.add_vertex( MeshT::Point{0., 0., 0.} );
    vhandle[ 1 ] = mesh.add_vertex( MeshT::Point{1., 0., 0.} );
    vhandle[ 2 ] = mesh.add_vertex( MeshT::Point{0.5, sqrt3o2, 0.} );

    std::vector<MeshT::VertexHandle> faceVhandles;

    faceVhandles.push_back( vhandle[ 0 ] );
    faceVhandles.push_back( vhandle[ 1 ] );
    faceVhandles.push_back( vhandle[ 2 ] );

    mesh.add_face( faceVhandles );


    for ( auto faceIt = mesh.faces_begin(); faceIt != mesh.faces_end(); ++faceIt )
    {
        //
        auto minmax = minmaxAngleInTriangle( mesh, *faceIt );

        EXPECT_THAT( minmax.first, FloatEq( M_PI / 3.f ) );
        EXPECT_THAT( minmax.second, FloatEq( M_PI / 3.f ) );
    }
}

//
TEST( aCube, haveRectangularIsoceleTriangulation )
{
    auto cube = constructCube();

    for ( auto faceIt = cube.faces_begin(); faceIt != cube.faces_end(); ++faceIt )
    {
        auto minmax = minmaxAngleInTriangle( cube, *faceIt );

        EXPECT_THAT( minmax.first, FloatEq( M_PI / 4.f ) );
        EXPECT_THAT( minmax.second, FloatEq( M_PI / 2.f ) );
    }
}
