#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QPushButton *btn1;
    ~MainWindow();

private slots:
    void clickEvent();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
