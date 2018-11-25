
#include "modelvisu.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>

#include <memory>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow{parent}
    , ui{std::make_unique<Ui::MainWindow>()}
{
    ui->setupUi( this );
    // connect( this, &MainWindow::modelToLoad, ui->widget3d, &ModelWidget::loadModel );
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

void MainWindow::saveDiedreRequested()
{
    QString filename;

    filename = QFileDialog::getSaveFileName( this, tr( "Select the filename of diedre" ) );

    if ( !filename.isNull() )
    {
        diedreFilename( filename );
    }
}
void MainWindow::saveValenceRequested()
{
    QString filename;

    filename = QFileDialog::getSaveFileName( this, tr( "Select the filename of valence" ) );

    if ( !filename.isNull() )
    {
        valenceFilename( filename );
    }
}
