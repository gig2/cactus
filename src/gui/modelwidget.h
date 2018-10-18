#pragma once

#include "modelvisu.h"


#include <QWidget>


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
