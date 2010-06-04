#include "gamer.h"
#include <QtSql>
Gamer::Gamer()
{
}
 Gamer Gamer::create(QString table, QString nick, QString name) {
    QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
q.prepare("CREATE TABLE " + table + " (id INTEGER PRIMARY KEY, team TEXT, result TEXT)");
      if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.prepare("INSERT INTO Players (smallname, nick, name) VALUES (?, ?, ?)");
   q.addBindValue(table);
   q.addBindValue(nick);
   q.addBindValue(name);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   //                                                                                                                                                                1 23 45 6 7  8
   q.prepare("INSERT INTO Rating (nick, matches, win,draw, lose, tp, unreg, bonus, points) VALUES (:nick, 0,0,0,0,0,0,0,0");
   q.bindValue(":nick");
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
    Gamer g;}
