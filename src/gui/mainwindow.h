#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "objwindow.h"

#include <QMainWindow>
#include <QtWidgets>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );
    QPushButton *btn1;
    ~MainWindow();

private slots:
    void clickEvent();

private:
    Ui::MainWindow *ui;
    OBJWindow *owin;
};

#endif // MAINWINDOW_H
