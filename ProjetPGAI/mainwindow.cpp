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
//l'objet dans une nouvelle fenêtre de classe OBJWindow
void MainWindow::clickEvent()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("Select an obj file  ..."), "", tr("OBJ Files (*.obj)"));
    if(!filename.isNull()){
        qDebug() << filename;
        owin = new OBJWindow(filename);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
