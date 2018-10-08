#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "objwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QPushButton *btn1;
    ~MainWindow();

private slots:
    void clickEvent();

private:
    Ui::MainWindow *ui;
    OBJWindow * owin;
};

#endif // MAINWINDOW_H
