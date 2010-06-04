#include "common.h"

Match readToMatch (QString matchfile, Club home, Club away) {

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "match");
db.setDatabaseName(matchfile);
if (!db.open()) {
qDebug() << "cannot open matchfile " + matchfile;
    Match m;
    return m;
}
QSqlQuery q(db);
Match m;

m.home.club = home;
m.away.club = away;
m.home.goals = 0;
m.away.goals = 0;
q.prepare("SELECT player FROM HomeStart");
 q.exec();

 while (q.next()) {
     m.home.start.append(m.home.club.getPlayer(q.value(0).toString()));
 }
 q.prepare("SELECT player FROM AwayStart");
  q.exec();
  while (q.next()) {
     m.away.start.append(m.away.club.getPlayer(q.value(0).toString()));
 }
q.prepare("SELECT player, type FROM HomeEvents");
 q.exec();
  while (q.next()) {
     int type = q.value(1).toInt();
     switch (type) {
     case 1:
         m.home.golaedors.append(m.home.club.getPlayer(q.value(0).toString()));
         m.home.goals ++;
         break;
     case 2:
         m.home.yellowCards.append(m.home.club.getPlayer(q.value(0).toString()));
         break;
    case 3:
        m.home.redCards.append(m.home.club.getPlayer(q.value(0).toString()));
    case 4:
        m.home.traumas.append(m.home.club.getPlayer(q.value(0).toString()));
    }
 }
q.prepare("SELECT player, type FROM AwayEvents");
 q.exec();
  while (q.next()) {
     int type = q.value(1).toInt();
     switch (type) {
     case 1:
         m.away.golaedors.append(m.away.club.getPlayer(q.value(0).toString()));
         m.away.goals ++;
         break;
     case 2:
         m.away.yellowCards.append(m.away.club.getPlayer(q.value(0).toString()));
         break;
    case 3:
        m.away.redCards.append(m.away.club.getPlayer(q.value(0).toString()));
    case 4:
        m.away.traumas.append(m.away.club.getPlayer(q.value(0).toString()));
    }
 }
q.prepare("SELECT poff, pon FROM HomeChanges");
 q.exec();
  while (q.next()) {
     Change ch;
     ch.first = m.home.club.getPlayer(q.value(0).toString());
     ch.second = m.home.club.getPlayer(q.value(1).toString());
m.home.changes.append(ch);
 }
q.prepare("SELECT poff, pon FROM AwayChanges");
 q.exec();
  while (q.next()) {
     Change ch;
     ch.first = m.away.club.getPlayer(q.value(0).toString());
     ch.second = m.away.club.getPlayer(q.value(1).toString());
m.away.changes.append(ch);
}
 db.close();
 return m;
}
