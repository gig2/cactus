#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "objwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QtWidgets>

#include <memory>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );

private slots:
    void loadObjRequested();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<OBJWindow> owin;
};

#endif // MAINWINDOW_H
