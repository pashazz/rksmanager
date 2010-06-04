#include "cup.h"

Cup::Cup(QString dir,QString title, QString country, QStringList teams, QStringList gmrs, bool views)
      :  Tournament(dir, title, country, teams, gmrs,  views)
{
QSettings stg(workdir + "/settings.ini");
stg.beginGroup("Tournament");
stg.setValue("type", "cup");
stg.endGroup();
stg.sync();
finish = finished();
          }
void Cup::addMatch(Match m, int tour)
    {
    doAddMatch(m, tour);
    finish = finished();
 MatchStatistics *loosers;
 if (m.home.goals > m.away.goals)
     loosers = &m.away;
 else if (m.home.goals < m.away.goals)
     loosers = &m.home;
 else {
     qDebug() << "Cup error: it`s a draw. Returning.";
             return;
 }
QSqlQuery q;
QString nick;
   q.prepare("SELECT nick FROM teams WHERE club=:club");
   q.bindValue(":club", loosers->club.name);
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.first();
   nick = q.value(0).toString();
q.prepare("DELETE FROM Teams WHERE club=:club");
q.bindValue(":club", loosers->club.name);
     if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   //записываем бонусы
   QSettings stg(workdir + "/bonus.ini");

  int points = stg.value(QVariant (tour).toString(), -1).toInt();
  if (points != -1) {
  QSqlQuery sq(QSqlDatabase::database("players"));
  sq.prepare("UPDATE Rating SET bonus=(SELECT bonus FROM Rating WHERE nick=:nick)+"+QVariant(points).toString()+" WHERE nick=:nick");
  sq.bindValue(":nick", nick);
      if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
}
drop(loosers->club.name);
clubs.removeOne(loosers->club);
}
void Cup::addMatch(QString home, QString away, TechResult::Result res, int tour)
{
doAddMatch(home, away, res, tour);
finish = finished();
     QSqlQuery q(QSqlDatabase::database("players"));
     QString loosers;
switch (res)
{
    case TechResult::HomeWin:
           loosers= away;
           break;
     case TechResult::AwayWin:
             loosers = home;
             break;
             default:
             qDebug() << "Cup error: it`s a draw. Returning.";
             return;
}
QString nick;
QString loosersName;
 foreach(Club c, clubs) {
     if (c.displayName == loosers){
           loosersName = c.name;
            clubs.removeOne(c);
       }
   }
QSqlQuery sq;
   sq.prepare("SELECT nick FROM teams WHERE club=:club");
   sq.bindValue(":club", loosers);
   if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
   sq.first();
   nick = sq.value(0).toString();
q.prepare("DELETE FROM Teams WHERE club=:club");
q.bindValue(":club", loosers);
     if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
    //записываем бонусы
   QSettings stg(workdir + "/bonus.ini");

  int points = stg.value(QVariant (tour).toString(), -1).toInt();
  if (points != -1) {
  QSqlQuery sq(QSqlDatabase::database("players"));
  sq.prepare("UPDATE Rating SET bonus=(SELECT bonus FROM Rating WHERE nick=:nick)+"+QVariant(points).toString()+" WHERE nick=:nick");
  sq.bindValue(":nick", nick);
      if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
}
   drop(loosersName);

}
void Cup::drop(QString table){
    QSqlQuery q;
    q.prepare("DROP TABLE " + table);
     if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
}
 void Cup::writeResults() {
    return;
   }
 bool Cup::finished() {
     QSqlQuery q;
     q.prepare("SELECT COUNT (*) FROM Teams");
     q.exec();
q.first();
if (q.value(0).toInt()  <= 1 /*&& q.lastError().type() == q.lastError().NoError*/) {
    q.prepare("SELECT nick, displayname FROM Teams");
         if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.first();
   QSqlQuery sq (QSqlDatabase::database("players"));
   //прочтем из INI файла, что победителю дают
   QSettings stg (workdir + "/bonus.ini", QSettings::IniFormat, this);
   int points = stg.value("0", -1).toInt();
     if (points != -1) {
  QSqlQuery sq(QSqlDatabase::database("players"));
  sq.prepare("UPDATE Rating SET bonus=(SELECT bonus FROM Rating WHERE nick=:nick)+"+QVariant(points).toString()+" WHERE nick=:nick");
   sq.bindValue(":nick", q.value(0));
      if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
   sq.prepare("SELECT smallname FROM Players WHERE nick=:nick");
   sq.bindValue(":nick", q.value(0));
      if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
   QString table = sq.value(0).toString();
   sq.prepare("INSERT INTO " + table + " (team, result, trn) VALUES (?, ?, ?)");
   sq.addBindValue(q.value(1).toString());
   sq.addBindValue("Чемпион");
   sq.addBindValue(_title);
         if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
   //done!!!!
  // q.prepare("DELETE FROM Teams");
  // q.exec();
   qDebug() << "All teams deleted!";
   }
}
else
    return false;
 }

 QVariant Cup::getData(int role) {
return Tournament::getData(role); //временно


 }
 bool Cup::checkPlanning(QString *message) {
 //считаем кол-во команд
     switch (clubs.count())
     {
         case 2:
         *message = "Финал";        return true;
         case 4:
         *message = "Полуфинал";        return true;
        case 8:
         *message = "Четвертьфинал" ;     return true;
        case 16:
         *message = "1/8 финала";           return true;
         default:
         qDebug() << "Cup error! teams count is " << clubs.count();
         return false;


     }

 }
