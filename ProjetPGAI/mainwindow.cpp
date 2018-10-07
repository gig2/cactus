#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btn1 = new QPushButton("See an OBJ File ...", this);
    btn1->resize(200,50);
    //La fonction clickEvent est appelée lorsqu'on clique sur le bouton btn1.
    connect(btn1, SIGNAL(clicked()), this, SLOT(clickEvent()));
}

//Ouvre une boîte de dialogue pour la sélection d'un fichier OBJ, puis affiche
//l'objet dans une nouvelle fenêtre (WIP)
void MainWindow::clickEvent()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("Select an obj file  ..."), "", tr("OBJ Files (*.obj)"));
    if(!filename.isNull()){
        qDebug() << filename;
        Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
        Qt3DCore::QEntity * rootEntity = new Qt3DCore::QEntity();
        Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);
        Qt3DCore::QEntity * chestEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QMesh * myMesh = new Qt3DRender::QMesh(rootEntity);
        myMesh->setSource(QUrl::fromLocalFile(filename));
        chestEntity->addComponent(myMesh);
        chestEntity->addComponent(material);
        view->setRootEntity(rootEntity);
        Qt3DRender::QCamera *camera = view->camera();
        camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
        camera->setPosition(QVector3D(5.0, 5.0, 25.0f));
        camera->setViewCenter(QVector3D(0, 0, 0));
        view->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
