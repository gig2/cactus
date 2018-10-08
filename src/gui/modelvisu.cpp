#include "modelvisu.h"

#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>

#include <memory>

ModelVisu::ModelVisu( QString filename )
    : Qt3DExtras::Qt3DWindow()
{
    // Variables pour le déplacement caméra.
    xspeed = yspeed = zspeed = 1.f;
    // Set-up nécessaire pour l'affichage de l'objet en 3D
    rootEntity  = std::make_unique<Qt3DCore::QEntity>();
    material    = std::make_unique<Qt3DExtras::QPhongMaterial>( rootEntity.get() );
    chestEntity = std::make_unique<Qt3DCore::QEntity>( rootEntity.get() );
    myMesh      = std::make_unique<Qt3DRender::QMesh>( rootEntity.get() );

    myMesh->setSource( QUrl::fromLocalFile( filename ) );
    chestEntity->addComponent( myMesh.get() );
    chestEntity->addComponent( material.get() );
    this->setRootEntity( rootEntity.get() );
    // Opérations sur la caméra.
    // camera()->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera()->setPosition( QVector3D( 5.0, 5.0, 25.0f ) );
    camera()->setViewCenter( QVector3D( 0, 0, 0 ) );
}

void ModelVisu::keyPressEvent( QKeyEvent* event )
{
    switch ( event->key() )
    {
        case Qt::Key_D:
            // Déplace la caméra vers la droite
            camera()->translate( QVector3D( xspeed, 0, 0 ) );
            break;
        case Qt::Key_Q:
            // Déplace la caméra vers la gauche
            camera()->translate( QVector3D( -xspeed, 0, 0 ) );
            break;
        case Qt::Key_S:
            // Déplace la caméra vers le bas
            camera()->translate( QVector3D( 0, -yspeed, 0 ) );
            break;
        case Qt::Key_Z:
            // Déplace la caméra vers le haut
            camera()->translate( QVector3D( 0, yspeed, 0 ) );
            break;
        case Qt::Key_Up:
            // Avancer la caméra
            camera()->translate( QVector3D( 0, 0, zspeed ) );
            break;
        case Qt::Key_Down:
            // Reculer la caméra
            camera()->translate( QVector3D( 0, 0, -zspeed ) );
            break;
        default: break;
    }
}

void ModelVisu::mouseMoveEvent( QMouseEvent* event )
{
    /*qDebug() << "yo";
    camera()->rotateAboutViewCenter(QQuaternion::rotationTo(QVector3D(event->pos().x(),
    event->pos().y(), 0),QVector3D(0.f,0.f,0.f)));*/
}
