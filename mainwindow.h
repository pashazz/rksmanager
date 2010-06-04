#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "tourdialog.h"
#include "randomgenerator.h"
#include "league.h"
#include "planningdialog.h"
#include "aboutdialog.h"
#include "reporter.h"
#include "teaminfo.h"
#include "cup.h"
#include "cupmodel.h"

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
    CupModel *model;
    Ui::MainWindow *ui;
    Tournament *trn;
    void createMenus();
    void appendTable();
    void appendTable(bool);
    void createStatusBar();
    bool loaded;
    QLabel *infolabel;
    // для будущего функционала
    bool leag;
    void checkPlayers();
    void setMatches();
    void planningCup (Cup* cup);
private slots:
    void on_cmdProperties_clicked();
    void on_actWrite_triggered();
    void on_tbMatches_clicked(QModelIndex index);
    void on_actAddPlayer_triggered();
    void on_actManageViews_triggered();
    void on_actView_triggered(bool checked);
    void on_actPlayers_triggered();
    void on_actChange_triggered();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem* item);
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
    protected:
    virtual void closeEvent(QCloseEvent *e);
};

#endif // MAINWINDOW_H
