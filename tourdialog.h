#ifndef TOURDIALOG_H
#define TOURDIALOG_H
#include "league.h"
#include "addteamdialog.h"
#include <QtGui>

namespace Ui {
    class TourDialog;
}

class TourDialog : public QDialog {
    Q_OBJECT
public:
    TourDialog(QWidget *parent = 0);
    ~TourDialog();
 signals:
   void getTounament (Tournament *t);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TourDialog *m_ui;
    QString dir;
    void appendBoxes();
    QStringList getTeams(QString dir);
    QStringList players, teams;
    QStringList countries;
    QStringList avalTeams;
private slots:
    void on_lstPlayers_itemClicked(QListWidgetItem* item);
    void on_lstPlayers_itemChanged(QListWidgetItem* item);
    void on_cmdOK_clicked();
    void on_cmdNew_clicked();
    void on_buttonBox_accepted();
    void onTeam (QString, QString);
};

#endif // TOURDIALOG_H
