
#ifndef ADDMATCHDIALOG_H
#define ADDMATCHDIALOG_H

#include <QtGui>
#include <QtSql>

#include "match.h"
#include "league.h"
#include "eventdialog.h"

namespace Ui {
    class AddMatchDialog;
}

class AddMatchDialog : public QDialog {
    Q_OBJECT
public:
    AddMatchDialog(QWidget *parent, Tournament *t);
    ~AddMatchDialog();
    Match getMatch() ;
    QString saveMatch();
    void setData (QStringList data);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddMatchDialog *m_ui;
    QStringList homePlayers;
    QStringList awayPlayers;
    bool checkPlayer(QString player, QString club);
    void createLists();
    void doAction (QListWidget *list, QListWidget *playersList);
    Match m;
    Tournament *trn;
  //  QString getMatchfile();
    QString workdir;
private slots:
    void on_AddMatchDialog_finished(int result);
    void on_buttonBox_accepted();
    void addEvent();
    void on_cmdAwayStart_clicked();
    void on_cmdHomeStart_clicked();
};

#endif // ADDMATCHDIALOG_H
