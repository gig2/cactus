#ifndef OBJWINDOW_H
#define OBJWINDOW_H

#include <QtWidgets>
#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>

class OBJWindow : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT
public:
    explicit OBJWindow(QString filename);
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

private:
    Qt3DCore::QEntity * rootEntity;
    Qt3DRender::QMaterial *material;
    Qt3DCore::QEntity * chestEntity;
    Qt3DRender::QMesh * myMesh;
    float xspeed, yspeed, zspeed;

signals:

public slots:
};

#endif // OBJWINDOW_H
