#include "modelvisu.h"

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif
#include <glm/gtx/euler_angles.hpp>

#include <fstream>
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


    objTransform_   = glm::rotate( glm::mat4{1.f}, glm::radians( 90.f ), glm::vec3( 1, 0, 0 ) );
    eulerTransform_ = glm::eulerAngleXYZ( yaw_, pitch_, roll_ );

    scaleTransform_ = glm::scale( glm::mat4{1.f}, glm::vec3{scale_, scale_, scale_} );
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




    simpleShader_.setVertexShader( "shader/color.vert" );
    simpleShader_.setFragmentShader( "shader/color.frag" );
    try
    {
        simpleShader_.Load();
    }
    catch ( std::exception const &e )
    {
        std::cerr << e.what() << "\n";
    }
    catch ( std::string const &errorStr )
    {
        std::cerr << errorStr << "\n";
    }
    catch ( ... )
    {
        std::cerr << "unknown exception\n";
    }


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
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glEnable( GL_DEPTH_TEST );

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

    int colorIndex     = 0;
    int const maxColor = 100;

    // set color for mesh
    std::for_each( mesh.vertices_begin(), mesh.vertices_end(),
                   [&mesh, &colorIndex]( auto &vertex ) {
                       MeshT::Color color1{1.0, 0., 0.};
                       MeshT::Color color2{0.0, 0., 1.};

                       float t    = colorIndex / static_cast<float>( maxColor );
                       auto color = color1 * ( 1.f - t ) + color2 * t;

                       colorIndex = ( colorIndex + 1 ) % maxColor;

                       mesh.set_color( vertex, color );
                   } );

    auto &meshNode = *meshNodePtr;

    meshView.refreshBuffer();

    makeCurrent();
    meshNode.updateVertexBuffer( positionLocation_, colorLocation_ );
    doneCurrent();

    // we need to repaint the widget
    update();
}

void ModelVisu::setYaw( int value )
{
    yaw_ = glm::radians( static_cast<float>( value ) );
    updateEuler_();
    update();
}

void ModelVisu::setPitch( int value )
{
    pitch_ = glm::radians( static_cast<float>( value ) );
    updateEuler_();
    update();
}

void ModelVisu::setRoll( int value )
{
    roll_ = glm::radians( static_cast<float>( value ) );
    updateEuler_();
    update();
}

void ModelVisu::setScale( double scale )
{
    scale_          = scale;
    scaleTransform_ = glm::scale( glm::mat4{}, glm::vec3{scale_, scale_, scale_} );
    update();
}

void ModelVisu::computeValenceRequested()
{
    // compute the valence here
    int minValence        = 0;
    int maxValence        = 0;
    double medianValence  = 0.;
    double averageValence = 0.;

    if ( mesh_.size() == 0 )
        return;

    valences_.clear();
    valences_.reserve( mesh_.size() );

    for ( auto const &mesh : mesh_ )
    {
        valences_.emplace_back( mesh->mesh );
    }

    auto const &valence = valences_.front();

    minValence = min_sorted( valence.cbegin(), valence.cend() );
    maxValence = max_sorted( valence.cbegin(), valence.cend() );

    medianValence  = mediane_sorted( valence.cbegin(), valence.cend() );
    averageValence = moyenne( valence.cbegin(), valence.cend() );


    minValenceChanged( minValence );
    maxValenceChanged( maxValence );
    medianValenceChanged( medianValence );
    averageValenceChanged( averageValence );

    updateValenceColor_();
}

void ModelVisu::computeDiedreRequested()
{
    // compute the diedreStat here
    double minDiedre     = 0.;
    double maxDiedre     = 0.;
    double medianDiedre  = 0.;
    double averageDiedre = 0.;

    if ( mesh_.size() == 0 )
        return;

    diedreStats_.clear();
    diedreStats_.reserve( mesh_.size() );

    for ( auto const &mesh : mesh_ )
    {
        diedreStats_.emplace_back( mesh->mesh );
    }

    auto const &diedreStat = diedreStats_.front();

    minDiedre = static_cast<double>( diedreStat.min() );
    maxDiedre = static_cast<double>( diedreStat.max() );

    medianDiedre  = static_cast<double>( diedreStat.median() );
    averageDiedre = static_cast<double>( diedreStat.average() );


    minDiedreChanged( minDiedre );
    maxDiedreChanged( maxDiedre );
    medianDiedreChanged( medianDiedre );
    averageDiedreChanged( averageDiedre );
}
void ModelVisu::saveDiedre( QString filename )
{
    if ( diedreStats_.size() == 0 )
        return;

    // for now we save only the first
    auto outFile = std::ofstream( filename.toStdString().c_str() );

    for ( auto const &angle : diedreStats_.front() )
    {
        outFile << angle << "\n";
    }

    outFile.close();
}

void ModelVisu::updateEuler_()
{
    eulerTransform_ = glm::eulerAngleXYZ( yaw_, pitch_, roll_ );
}

void ModelVisu::updateValenceColor_()
{
    using Color = decltype( std::declval<Mesh>().mesh )::Color;
    for ( int index = 0; index < mesh_.size(); ++index )
    {
        auto &mesh = mesh_[ index ]->mesh;

        auto const &valence  = valences_[ index ];
        int const minValence = min_sorted( valence.cbegin(), valence.cend() );
        int const maxValence = max_sorted( valence.cbegin(), valence.cend() );

        for ( auto vertIt = mesh.vertices_begin(); vertIt != mesh.vertices_end(); ++vertIt )
        {
            auto &vertex = *vertIt;

            Color color1{1.0, 0., 0.};
            Color color2{0.0, 0., 1.};


            int valenceValue = (int)mesh.valence(*vertIt);

            float t         = 0.f;
            int const range = maxValence - minValence;
            if ( range != 0 )
            {
                t = ( valenceValue - minValence ) / static_cast<float>( range );
            }
            auto color = color1 * ( 1.f - t ) + color2 * t;


            mesh.set_color( vertex, color );
        }
    }

    for ( auto &mesh : mesh_ )
    {
        mesh->refreshBuffer();
    }

    makeCurrent();
    for ( auto &meshNode : meshNode_ )
    {
        meshNode->updateVertexBuffer( positionLocation_, colorLocation_ );
    }
    doneCurrent();
    update();
}
