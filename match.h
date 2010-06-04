#ifndef MATCH_H
#define MATCH_H
#include "club.h"
#include <QObject>
#include <QStringList>
#include <QtCore>
#include <QtSql>

class Match;
//old 
class Club {
   public:

    bool operator==(const  Club&) const;
    QString name;
    QString displayName;
    QList <Player> players;
    QList <Match> matches;
    Player getPlayer(int number);
    Player getPlayer(QString name);
};
typedef QPair<Player, Player> Change;
struct MatchStatistics {

  Club club;
  int goals;
  QList <Player> golaedors;
  QList <Player> start;
  QList <Player> traumas;
  QList <Change> changes;
  QList <Player> yellowCards;
  QList <Player> redCards;
  QList <Player> autogoals;
};


struct Match {
   MatchStatistics home;
   MatchStatistics away;
    QString matchfile;
    int tour;
};





#endif // MATCH_H
