#pragma once

#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <QtWidgets>

#include <memory>

class ModelVisu : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT
public:
    explicit ModelVisu( QString filename );
    void keyPressEvent( QKeyEvent* event );
    void mouseMoveEvent( QMouseEvent* event );

private:
    std::unique_ptr<Qt3DCore::QEntity> rootEntity;
    std::unique_ptr<Qt3DRender::QMaterial> material;
    std::unique_ptr<Qt3DCore::QEntity> chestEntity;
    std::unique_ptr<Qt3DRender::QMesh> myMesh;
    float xspeed, yspeed, zspeed;

signals:

public slots:
};
