#pragma once

#include <cmath>
#include <iterator>

#include <OpenMesh/Core/Geometry/Vector11T.hh>
#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

template <typename MeshType>
auto numberOfFaces( MeshType const& mesh )
{
    return mesh.n_faces();
}


/** \brief Given a mesh and a faceHandle compute one normal from the first 3 vertices
 *
 * \pre faceHandle should be a valid handle for the mesh
 * \pre the face should have at least 3 vertices
 */
template <typename MeshType, typename FaceHandle>
auto normalFromTriangle( MeshType const& mesh, FaceHandle const& faceHandle )
{
    // Here we assume that a faces contains at least 3 vertices
    auto firstPointIt  = mesh.cfv_iter( faceHandle );
    auto secondPointIt = std::next( firstPointIt );
    auto thirdPointIt  = std::next( secondPointIt );

    auto vecFromPoint = [&mesh]( auto const& originIt, auto const& destinationIt ) {
        return mesh.point( *destinationIt ) - mesh.point( *originIt );
    };

    auto firstBaseElem = vecFromPoint( firstPointIt, secondPointIt );

    auto secondBaseElem = vecFromPoint( secondPointIt, thirdPointIt );

    return cross( firstBaseElem, secondBaseElem );
}



/** \brief Given a mesh and two faceHandle, compute the non signed angle between those two faces
 *
 * \pre lhs and rhs should each be a valid handle for the mesh
 * \pre each faces should have at least 3 vertices
 *
 */
template <typename MeshType, typename FaceHandle>
auto angleBetweenFaces( MeshType const& mesh, FaceHandle const& lhs, FaceHandle const& rhs )
{
    auto normalLhs = normalFromTriangle( mesh, lhs );

    auto normalRhs = normalFromTriangle( mesh, rhs );

    normalLhs.normalize();
    normalRhs.normalize();


    auto cosTheta = dot( normalLhs, normalRhs );

    // we need to restrict the cosTheta to -1.f , 1.f
    if ( cosTheta > 1.f )
    {
        cosTheta = 1.f;
    }
    else if ( cosTheta < -1.f )
    {
        cosTheta = -1.f;
    }

    return std::acos( cosTheta );
}


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

    // ok so we have edge0, edge1,edge2 circulating the triangle
    // the first angle is between edge0 and -edge2
    // the second angle is between -edge0 and edge1
    // the third angle is between -edge1 and edge2

    auto firstCosTheta  = dot( edge0, -edge2 );
    auto secondCosTheta = dot( -edge0, edge1 );
    auto thirdCosTheta  = dot( -edge1, edge2 );

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

    std::array<float, 3> angles{std::acos( firstCosTheta ), std::acos( secondCosTheta ),
                                std::acos( thirdCosTheta )};

    auto minmax = std::minmax_element( std::begin( angles ), std::end( angles ) );

    return std::make_pair( *minmax.first, *minmax.second );
}
