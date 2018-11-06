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


template <typename MeshType, typename FaceHandle>
auto angleBetweenFaces( MeshType const& mesh, FaceHandle const& lhs, FaceHandle const& rhs )
{
    //

    auto originLhs = mesh.cfv_iter( lhs );

    auto head0 = std::next( originLhs );

    auto baseLhs0 = mesh.point( *head0 ) - mesh.point( *originLhs );

    auto head1 = std::next( head0 );

    auto baseLhs1 = mesh.point( *head1 ) - mesh.point( *head0 );


    auto originRhs = mesh.cfv_iter( rhs );

    head0 = std::next( originRhs );

    auto baseRhs0 = mesh.point( *head0 ) - mesh.point( *originRhs );

    head1 = std::next( head0 );

    auto baseRhs1 = mesh.point( *head1 ) - mesh.point( *head0 );


    auto normalLhs = cross( baseLhs0, baseLhs1 );

    auto normalRhs = cross( baseRhs0, baseRhs1 );

    normalLhs.normalize();
    normalRhs.normalize();

    return std::acos( dot( normalLhs, normalRhs ) );
}
