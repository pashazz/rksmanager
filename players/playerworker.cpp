#include "playerworker.h"
#include <QtDebug>
PlayerWorker::PlayerWorker()
{
}
void PlayerWorker::addPlayer(QString nick, QString name, QString table) {
    qDebug() << nick;
QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
q.prepare("CREATE TABLE " + table + " (id INTEGER PRIMARY KEY, team TEXT, result TEXT)");
      if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.prepare("INSERT INTO Players (smallname, nick, name) VALUES (:smallname, :nick, :name)");
q.bindValue(":smallname", table);
q.bindValue(":nick", nick);
q.bindValue(":name", name);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   //                                                                                                                                                                1 23 45 6 7  8
   q.prepare("INSERT INTO Rating (nick, matches, win,draw, lose, tp, unreg, bonus, points) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
q.addBindValue(nick);
q.addBindValue(0);
q.addBindValue(0);
q.addBindValue(0);
q.addBindValue(0);
q.addBindValue(0);
q.addBindValue(0);
q.addBindValue(0);
q.addBindValue(0);

       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}

}
void PlayerWorker::win(QString nick) {
    qDebug() << nick;
   QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
    q.prepare("UPDATE Rating SET win=(SELECT win FROM Rating WHERE nick=?)+1, points=(SELECT points FROM Rating WHERE nick=?)+10 WHERE nick=?");
    q.addBindValue(nick);
        q.addBindValue(nick);
    q.addBindValue(nick);
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
}
void PlayerWorker::draw(QString nick) {
        qDebug() << nick;

       QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
    q.prepare("UPDATE Rating SET draw=(SELECT draw FROM Rating WHERE nick=?)+1, points=(SELECT points FROM Rating WHERE nick=?)+5 WHERE nick=?");
    q.addBindValue(nick);
        q.addBindValue(nick);
    q.addBindValue(nick);
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}

}
void PlayerWorker::lose(QString nick) {
    qDebug() << nick;

       QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
    q.prepare("UPDATE Rating SET lose=(SELECT lose FROM Rating WHERE nick=?)+1, points=(SELECT points FROM Rating WHERE nick=?)+1 WHERE nick=?");
    q.addBindValue(nick);
        q.addBindValue(nick);
    q.addBindValue(nick);
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
}
void PlayerWorker::unreg(QString  nick) {
          QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
    q.prepare("UPDATE Rating SET unreg=(SELECT unreg FROM Rating WHERE nick=?)+1, points=(SELECT points FROM Rating WHERE nick=?)-30 WHERE nick=?");
    q.addBindValue(nick);
        q.addBindValue(nick);
    q.addBindValue(nick);
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}

}
void PlayerWorker::tp(QString nick) {
              QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
    q.prepare("UPDATE Rating SET tp=(SELECT tp FROM Rating WHERE nick=?)+1, points=(SELECT points FROM Rating WHERE nick=?)-5 WHERE nick=?");
    q.addBindValue(nick);
        q.addBindValue(nick);
    q.addBindValue(nick);
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}

}
