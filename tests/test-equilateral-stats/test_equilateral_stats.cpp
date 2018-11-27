#include "cube.h"

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




template <typename MeshType, typename FaceHandle>
auto minmaxAngleInTriangle( MeshType const& mesh, FaceHandle const& faceHandle )
{
    // Here we assume that a faces contains only 3 vertices
    auto firstPointIt  = mesh.cfv_iter( faceHandle );
    auto secondPointIt = std::next( firstPointIt );
    auto thirdPointIt  = std::next( secondPointIt );


    // this should be a function
    auto vecFromPoint = [&mesh]( auto const& originIt, auto const& destinationIt ) {
        return mesh.point( *destinationIt ) - mesh.point( *originIt );
    };

    auto edge0 = vecFromPoint( firstPointIt, secondPointIt );
    auto edge1 = vecFromPoint( secondPointIt, thirdPointIt );
    auto edge2 = vecFromPoint( thirdPointIt, firstPointIt );

    edge0.normalize();
    edge1.normalize();
    edge2.normalize();

    auto firstCosTheta  = dot( edge0, edge1 );
    auto secondCosTheta = dot( edge1, edge2 );
    auto thirdCosTheta  = dot( edge2, edge0 );

    auto restrictAcos = []( auto const& value ) {
        if ( value > -1.f || value < 1.f )
        {
            return value;
        }
        else if ( value >= 1.f )
        {
            return 1.f;
        }
        else
        {
            return -1.f;
        }
    };

    firstCosTheta  = restrictAcos( firstCosTheta );
    secondCosTheta = restrictAcos( secondCosTheta );
    thirdCosTheta  = restrictAcos( thirdCosTheta );

    std::array<float, 3> angles{static_cast<float>( M_PI ) - std::acos( firstCosTheta ),
                                static_cast<float>( M_PI ) - std::acos( secondCosTheta ),
                                static_cast<float>( M_PI ) - std::acos( thirdCosTheta )};

    auto minmax = std::minmax_element( std::begin( angles ), std::end( angles ) );

    return std::make_pair( *minmax.first, *minmax.second );
}

TEST( anIsoceleRectangularTriangle, haveAngleOfPiOver4AndPiOver2 )
{
    //
    MeshT mesh;

    std::array<MeshT::VertexHandle, 3> vhandle;

    float sqrt2 = std::sqrt( 2.f );

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
TEST( aCube, haveIsoceleTriangulation )
{
    auto cube = constructCube();
#if 1
    for ( auto faceIt = cube.faces_begin(); faceIt != cube.faces_end(); ++faceIt )
    {
        //
        auto minmax = minmaxAngleInTriangle( cube, *faceIt );

        EXPECT_THAT( minmax.first, FloatEq( M_PI / 4.f ) );
        EXPECT_THAT( minmax.second, FloatEq( M_PI / 2.f ) );
    }
#endif
}
