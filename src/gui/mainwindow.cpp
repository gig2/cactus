

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "modelwidget.h"

#include <QMainWindow>

#include <memory>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow{parent}
    , ui{std::make_unique<Ui::MainWindow>()}
{
    ui->setupUi( this );
    connect( this, &MainWindow::modelToLoad, ui->widget3d, &ModelWidget::loadModel );
}

MainWindow::~MainWindow()
{
    //
}

// Ouvre une boîte de dialogue pour la sélection d'un fichier OBJ, puis affiche
// l'objet dans une nouvelle fenêtre de classe OBJWindow
void MainWindow::loadObjRequested()
{
    QString filename;
    filename = QFileDialog::getOpenFileName( this, tr( "Select an obj file  ..." ), "",
                                             tr( "OBJ Files (*.obj)" ) );


    if ( !filename.isNull() )
    {
        modelToLoad( filename );
        qDebug() << filename;
    }
}
