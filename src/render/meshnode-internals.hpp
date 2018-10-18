#include "meshnode.h"

#include <OpenMesh/Core/Mesh/Handles.hh>

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>


template <typename MeshT>
MeshNode<MeshT>::MeshNode( MeshT &meshView )
    : mesh_{meshView}
{
}

template <typename MeshT>
void MeshNode<MeshT>::updateVertexBuffer( int const positionLocation, int const colorLocation )
{
    //


    numIndexes_ = mesh_.n_faces() * verticesNumberPerFace_;

    auto *vertexPointBuffer = mesh_.points();

    std::vector<unsigned int> indexes;
    indexes.reserve( numIndexes_ );



    std::for_each( mesh_.faces_begin(), mesh_.faces_end(), [this, &indexes]( auto const &faces ) {
        std::transform( mesh_.cfv_begin( faces ), mesh_.cfv_end( faces ),
                        std::back_inserter( indexes ),
                        []( auto const &faceVertex ) { return faceVertex.idx(); } );
    } );


    // let's put a color
    std::vector<GLfloat> colors;
    colors.reserve( mesh_.n_vertices() * numberColors_ );


    std::for_each(
        mesh_.vertices_begin(), mesh_.vertices_end(), [this, &colors]( auto const &vertex ) {
            auto const &color = mesh_.color( vertex );

            std::copy( std::begin( color ), std::end( color ), std::back_inserter( colors ) );
        } );


    regenerateBuffers_();

    glBindVertexArray( vao_ );

    glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer_ );
    glBufferData( GL_ARRAY_BUFFER, sizeof( decltype( *vertexPointBuffer ) ) * mesh_.n_vertices(),
                  vertexPointBuffer, GL_STATIC_DRAW );

    glVertexAttribPointer( positionLocation, 3, GL_FLOAT, GL_FALSE,
                           sizeof( decltype( *vertexPointBuffer ) ), 0 );
    glEnableVertexAttribArray( positionLocation );

    glBindBuffer( GL_ARRAY_BUFFER, colorBuffer_ );
    glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * colors.size(), colors.data(),
                  GL_STATIC_DRAW );

    glVertexAttribPointer( colorLocation, 3, GL_FLOAT, GL_FALSE, sizeof( GLfloat ) * 3, 0 );
    glEnableVertexAttribArray( colorLocation );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBuffer_ );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * numIndexes_, indexes.data(),
                  GL_STATIC_DRAW );

    glBindVertexArray( 0 );
}

template <typename MeshT>
void MeshNode<MeshT>::draw() const
{
    //
    glBindVertexArray( vao_ );
    glDrawElements( GL_TRIANGLES, numIndexes_, GL_UNSIGNED_INT, 0 );
    glBindVertexArray( 0 );
}

template <typename MeshT>
MeshNode<MeshT>::~MeshNode()
{
    cleanBuffers_();
}

template <typename MeshT>
void MeshNode<MeshT>::cleanBuffers_()
{
    if ( glIsBuffer( vao_ ) )
    {
        glDeleteBuffers( 1, &vao_ );
    }
    if ( glIsBuffer( indexBuffer_ ) )
    {
        glDeleteBuffers( 1, &indexBuffer_ );
    }
    if ( glIsBuffer( vertexBuffer_ ) )
    {
        glDeleteBuffers( 1, &vertexBuffer_ );
    }
    if ( glIsBuffer( colorBuffer_ ) )
    {
        glDeleteBuffers( 1, &colorBuffer_ );
    }
}

template <typename MeshT>
void MeshNode<MeshT>::regenerateBuffers_()
{
    cleanBuffers_();

    glGenBuffers( 1, &vertexBuffer_ );
    glGenBuffers( 1, &indexBuffer_ );
    glGenBuffers( 1, &colorBuffer_ );

    glGenVertexArrays( 1, &vao_ );
}
