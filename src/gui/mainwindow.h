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
    void saveDiedreRequested();

signals:
    void modelToLoad( QString model );
    void diedreFilename( QString file );

private:
    std::unique_ptr<Ui::MainWindow> ui;
};

#endif // MAINWINDOW_H
