#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "tourdialog.h"
#include "randomgenerator.h"
#include "league.h"
#include "planningdialog.h"
#include "aboutdialog.h"
#include "reporter.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

 

private:
    Ui::MainWindow *ui;
    Tournament *trn;
    void createMenus();
    void appendTable();
    bool loaded;
    // для будущего функционала
    bool leag;
private slots:
    void on_actRed_triggered();
    void on_actYellow_triggered();
    void on_actGoleadors_triggered();
    void on_actFont_triggered();
    void on_actColor_triggered();
    void on_actPlanning_triggered();
    void on_actPlay_triggered();
    void on_actHelp_triggered();
    void on_actExit_triggered();
    void on_actOpen_triggered();
    void on_actNew_triggered();
    void getTournament (Tournament *t);
};

#endif // MAINWINDOW_H
