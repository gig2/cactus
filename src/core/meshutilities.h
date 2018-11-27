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
