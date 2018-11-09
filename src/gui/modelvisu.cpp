#include "modelvisu.h"

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif
#include <glm/gtx/euler_angles.hpp>

#include <memory>

ModelVisu::ModelVisu( QWidget *parent )
    : QOpenGLWidget( parent )
{
    int major = 3;
    int minor = 2;

    QSurfaceFormat format;

    format.setDepthBufferSize( 24 );
    format.setStencilBufferSize( 8 );
    format.setVersion( major, minor );
    format.setProfile( QSurfaceFormat::CoreProfile );

    setFormat( format );

    create();


    objTransform_   = glm::rotate( objTransform_, glm::radians( 90.f ), glm::vec3( 1, 0, 0 ) );
    eulerTransform_ = glm::eulerAngleXYZ( yaw, pitch, roll );

    scaleTransform_ = glm::scale( glm::mat4{}, glm::vec3{scale_, scale_, scale_} );
}



void ModelVisu::initializeGL()
{
    glewExperimental = GL_TRUE;
    GLenum initGlew{glewInit()};

    if ( initGlew != GLEW_OK )
    {
        throw std::runtime_error(
            reinterpret_cast<const char *>( glewGetErrorString( initGlew ) ) );
    }



    simpleShader_.SetFile( "shader/color.vert", "shader/color.frag", "shader/color.geom" );


    modelview_
        = glm::lookAt( glm::vec3( -1., -1., 1. ), glm::vec3( 0., 0., 0. ), glm::vec3( 0, 0, 1 ) );

    //
    glClearColor( .0f, 0.f, 0.f, .0f );
}

void ModelVisu::resizeGL( int width, int height )
{
    //
    float near = 0.01;
    float far  = 100;
    float fov  = 70.;

    projection_ = glm::perspective( fov, static_cast<float>( width ) / height, near, far );
}

void ModelVisu::paintGL()
{
    //
    glClear( GL_COLOR_BUFFER_BIT );

    for ( auto &meshNode : meshNode_ )
    {
        if ( meshNode->needToUpdate )
        {
            meshNode->needToUpdate = false;
            meshNode->updateVertexBuffer( positionLocation_, colorLocation_ );
        }
    }

    simpleShader_.Enable();

    glm::mat4 mvp = projection_ * modelview_;

    auto mvpLoc = simpleShader_.GetUniformLocation( "MVP" );

    // applyBunny Transforms

    glm::mat4 bunnyMvp = mvp * objTransform_ * eulerTransform_ * scaleTransform_;


    glUniformMatrix4fv( mvpLoc, 1, GL_FALSE, glm::value_ptr( bunnyMvp ) );

    for ( auto const &node : meshNode_ )
    {
        node->draw();
    }

    simpleShader_.Disable();
}


void ModelVisu::addMesh( QString model )
{
    auto meshPtr = std::make_shared<Mesh>( model.toStdString() );
    mesh_.push_back( meshPtr );

    auto &meshView = *meshPtr;

    auto meshNodePtr = std::make_shared<MeshNode<Mesh>>( meshView );

    meshNode_.push_back( meshNodePtr );

    auto &mesh = meshPtr->mesh;

    // set color for mesh
    std::for_each( mesh.vertices_begin(), mesh.vertices_end(), [&mesh]( auto &vertex ) {
        MeshT::Color color{1.0, 0.5, 0.25};
        mesh.set_color( vertex, color );
    } );

    auto &meshNode = *meshNodePtr;

    meshNode.needToUpdate = true;

    meshView.refreshBuffer();

    // we need to repaint the widget
    update();
}

void ModelVisu::setYaw( int value )
{
    yaw = glm::radians( static_cast<float>( value ) );
    updateEuler();
    update();
}

void ModelVisu::setPitch( int value )
{
    pitch = glm::radians( static_cast<float>( value ) );
    updateEuler();
    update();
}

void ModelVisu::setRoll( int value )
{
    roll = glm::radians( static_cast<float>( value ) );
    updateEuler();
    update();
}

void ModelVisu::setScale( double scale )
{
    scale_          = scale;
    scaleTransform_ = glm::scale( glm::mat4{}, glm::vec3{scale_, scale_, scale_} );
    update();
}

void ModelVisu::updateEuler()
{
    eulerTransform_ = glm::eulerAngleXYZ( yaw, pitch, roll );
}
