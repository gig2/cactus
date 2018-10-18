#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>


namespace Ui
{
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = nullptr );

    virtual ~MainWindow();

private slots:
    void loadObjRequested();

signals:
    void modelToLoad( QString model );

private:
    std::unique_ptr<Ui::MainWindow> ui;
};

#endif // MAINWINDOW_H
