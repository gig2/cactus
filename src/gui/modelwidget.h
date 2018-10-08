#pragma once

#include <QWidget>

#include "modelvisu.h"

class ModelWidget : public QWidget
{
    Q_OBJECT

public:
    ModelWidget( QWidget* parent = nullptr, Qt::WindowFlags f = 0 );

public slots:
    void loadModel( QString model );

private:
    QWidget* embededViews_;
};
