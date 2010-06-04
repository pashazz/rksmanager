#include "leaguetrn.h"

League::League(QString dir, QString title, QString country, QStringList teams, QStringList gmrs, bool views)
        :Tournament (dir, title, country, teams, gmrs, views)
{
    QSettings stg(workdir + "/settings.ini", QSettings::IniFormat, this);
    stg.beginGroup("Tournament");
    stg.setValue("type", "league");
stg.endGroup();
stg.sync();
}

bool League::finished() {
    //calculate games count
    //
    int max;
    if (clubs.count() %2 == 0)
    {
       max = ((clubs.count()-1)*2)*(clubs.count() /2);

    }
    else {
        int count = clubs.count() + 1;
        max = ((count-1)*2)*(count/2);
    }
//смотрим максимальный сыгранный тур
QSqlQuery q;
q.prepare("SELECT COUNT (*) FROM Matches");
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
q.first();
if (max <= q.value(0).toInt()) {
    writeResults();
    return true;
}
else
    return false;

}
/*!
  Эта реализация writeResults только для League!
  */
void League::writeResults() {
    //проверяем, мб мы уже записали
QSettings stg (workdir + "/settings.ini", QSettings::IniFormat, this);
bool isbonus = QFile::exists(workdir+"/bonus.ini");
QSettings bonus (workdir +"/bonus.ini", QSettings::IniFormat, this);
qDebug() << "writing final!";
stg.beginGroup("Tournament");
bool wrote  = false;
wrote = stg.value("stored", false).toBool();
qDebug() << wrote;

    QSqlDatabase db = QSqlDatabase::database("players");
    QSqlQuery q(db) ;
    QSqlQuery sq;
    QString team, nick;
    sq.prepare("SELECT nick, displayname, points FROM Teams ORDER by ABS (points)");
    if (!sq.exec()) {qDebug() << "write result error!" << sq.lastError().text();}
    else {qDebug() << "Query done! " << sq.lastQuery();}
    int rank = 0;
    while (sq.next()) {
        qDebug() << rank;
        rank ++;
        QString result;
        if (rank == 1)
            result.append("Чемпион, ");
         else
             result.append(QVariant (rank).toString() + " место, ");

         result.append(sq.value(2).toString() + " очко(а, ов)");
         nick = sq.value(0).toString();
         team = sq.value(1).toString();
         qDebug() << nick << team << result;
        q.prepare("SELECT smallname FROM Players WHERE nick=:nick");
        q.bindValue(":nick", nick);
        if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
q.first();

QString table = q.value(0).toString();
//проверяем
q.prepare("SELECT COUNT (*) FROM "+ table + " WHERE team=:team AND trn=:trn");
      if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
q.first();
if (q.value(0).toInt() == 0) {
q.prepare("INSERT INTO " + table + "(team, result) VALUES (:team, :result)");
q.bindValue(":team", team);
q.bindValue(":trn", _title);
 if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
//здесь будет выдача бонусов
if (isbonus)
{
    int bpoints = bonus.value(QVariant(rank).toString(), -1).toInt();
    if (bpoints != -1){
        q.prepare("UPDATE Rating SET bonus=(SELECT bonus FROM Rating WHERE nick=:nick)+"+QVariant(bpoints).toString()+" WHERE nick=:nick");
        q.bindValue(":nick", nick);
         if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
syncPoints(nick);
    }

}
}
    }
    stg.setValue("stored", true);
stg.endGroup();
stg.sync();
}
bool League::checkPlanning(QString *message) {
     QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE", "planning");
   db.setDatabaseName(workdir + "/planning.db");

   db.open();
   qDebug() << db.tables();
   int tour;
   if (db.tables().isEmpty())
       tour = 1;
    else
        tour = db.tables().count() +1;
   db.close();
   *message = QVariant(tour).toString() + "Тур";
   return !finished();
}
