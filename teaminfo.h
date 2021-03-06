#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QtGui>
#include <QtSql>
#include "match.h"
#include "league.h"
namespace Ui {
    class TeamInfo;
}

class TeamInfo : public QDialog {
    Q_OBJECT
public:
    TeamInfo(QWidget *parent, Club club, QString nick,  Tournament *t);
    ~TeamInfo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TeamInfo *m_ui;
    Tournament *trn;
    void loadPlayerInfo(Player player);
    //matches
    void loadMatches();
    void buildItem (QString home, QString away, int hGoals, int aGoals, bool tp);
    void buildItem(Match m);
     Club c;
    QMap <QString, Match> matches;
    int curPlayer;
    void setStats ();
    void setPlayerStats (Player p);

private slots:
    void on_tblPlayers_itemClicked(QTableWidgetItem* item);
    void on_tblPlayers_itemDoubleClicked(QTableWidgetItem* item);
    void viewMatch (QListWidgetItem *item);
};

#endif // TEAMINFO_H
