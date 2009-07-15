#include "league.h"
QList <Player> Tournament::getPlayers (QString club) {
    QSqlQuery q;
    QList <Player> list;
    q.prepare("SELECT * FROM " + club);
    if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
while (q.next()) {
 Player player;
 player.name = q.value(q.record().indexOf("name")).toString();
 player.number = q.value(q.record().indexOf("number")).toInt();
 player.emploi = toEmploi(q.value(q.record().indexOf("emploi")).toString());
 player.stats.goals = q.value(q.record().indexOf("goals")).toInt();
 player.stats.YellowCards = q.value(q.record().indexOf("yellow")).toInt();
 player.stats.redCards = q.value(q.record().indexOf("red")).toInt();
 list.append(player);
}
return list;
}
//Tournament - лига
Tournament::Tournament (QString dir, QString title, QString country, QStringList teams, QStringList gmrs)
       : workdir(dir), gamers(gmrs)
{
    QString CONFDIR = "/.rks";
    QDir mydir(workdir + "/matches");
    if(!mydir.exists())
        mydir.mkpath(workdir + "/matches");
    //first create db;
this->_title = title;
    //open db connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dir + "/tour.db");
    db.open();
    //read teams
    QDir teamdir (QDir::homePath() + CONFDIR + "/teams/" + country.toLower());
    QStringList files =  teamdir.entryList(QDir::Files | QDir::Readable);
    //some sql instuctions
    QSqlQuery q;
    //                              0                       1           2            3              4             5               6                      7                   8              9
    q.prepare("CREATE TABLE Teams (id INTEGER PRIMARY KEY, nick TEXT, club TEXT, displayname TEXT, win INTEGER, draw INTEGER, lose INTEGER,  goalsScored INTEGER, goalsMissing INTEGER, points INTEGER)");
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
    else {qDebug() << "Query done" << q.executedQuery();}
   q.prepare("CREATE TABLE Matches (id INTEGER PRIMARY KEY, home TEXT, away TEXT, tour INTEGER,  matchfile TEXT)");
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
           else {qDebug() << "Query done" << q.executedQuery();}
                                                                            //       1- карточки; 2 - травма
    q.prepare("CREATE TABLE Skips (id INTEGER PRIMARY KEY, player TEXT, club TEXT, reason INTEGER, matches INTEGER)");
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
           else {qDebug() << "Query done" << q.executedQuery();}


    foreach (QString teamfile, files) {

        QFile file (teamdir.path() + "/" +teamfile) ;
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {qDebug() << "cannot open file " + file.fileName() << file.errorString();}
        QTextStream in (&file);
        //first get info about team
        QString info = in.readLine();
        QStringList infolist = info.split(",");

        if (infolist.count() != 2) {qDebug() << "syntax error, returning";return;}

        if (!teams.contains(infolist.at(0))) {continue;}
Club club;
club.name = infolist.at(1);
club.displayName = infolist.at(0);

//read players
//create table for club
QSqlQuery clubQuery;
QString table = infolist.at(1);
qDebug() << table;
clubQuery.prepare("CREATE TABLE " + table+ "(id INTEGER PRIMARY KEY, name TEXT, emploi INTEGER, number INTEGER, goals INTEGER, yellow INTEGER, red INTEGER)");
if (!clubQuery.exec()) {qDebug() << "SQL Error: " + clubQuery.lastError().text() + " in query " + clubQuery.lastQuery();}
else {qDebug() << "Query done" << clubQuery.executedQuery();}
        QStringList players;
        while (!in.atEnd()) {
            players.append(in.readLine());
        }
        file.close();
        //для каждого игрока
        foreach (QString player, players) {
            QStringList data = player.split(",");
            if (data.count() != 3) {qDebug() << "syntax error at line " + players.at(players.indexOf(player)) +", returning";return;}

 clubQuery.prepare("INSERT INTO "  +table + "(name, emploi, number,goals, yellow, red) VALUES(:name, :emploi, :number, 0, 0, 0)");
 clubQuery.bindValue(":name", data.at(2));
 clubQuery.bindValue(":emploi", toEmploi(data.at(1)));
 clubQuery.bindValue(":number", data.at(0));
 if (!clubQuery.exec()) {qDebug() << "SQL Error: " + clubQuery.lastError().text() + " in query " + clubQuery.lastQuery();}
 else {qDebug() << "player added:" << data;}
 Player player;
 player.number = QVariant(data.at(0)).toInt();
 player.emploi = toEmploi(data.at (1));
 player.name = data.at(2);
 club.players.append(player);


        }
        clubs.append(club);
        //добавить клуб в БД
        QString playerName = gamers.at(teams.indexOf(club.displayName));
        QString clubName = club.name;
        QString dispName = club.displayName;
  QSqlQuery query ;
  query.prepare("INSERT INTO Teams (nick, club, displayname, win, draw, lose, goalsScored, goalsMissing, points) VALUES (:nick, :club, :displayname, 0, 0, 0, 0, 0, 0)");
  query.bindValue(":nick", playerName);
  query.bindValue(":club", clubName);
  query.bindValue(":displayname", dispName);
  if (!query.exec()) {qDebug() << "SQL Error: " + query.lastError().text() + " in query " + query.lastQuery();}
 else {qDebug() << "team added:" << dispName;}
    }

    qDebug() << "creating index";
   QFile settings (dir+"/settings.ini");
   if (!settings.exists()) {settings.open(QIODevice::WriteOnly);settings.close();}
   QSettings stg(dir+"/settings.ini", QSettings::IniFormat, this);
   stg.beginGroup("Tournament");
   stg.setValue("title", title);
   stg.setValue("country", country);
   stg.endGroup();
}


Emploi Tournament::toEmploi(QString str) {
    if (str == "GK" || str =="1") {return Goalkeeper;}
  else   if (str == "DF" || str == "2") {return Defender;}
   else if (str == "MF" || str == "3") {return Middefender;}
   else if (str == "FW" || str == "4")  {return Forward;}


}

Tournament::~Tournament() {
 QSqlDatabase db = QSqlDatabase::database();
   db.close();
}


void Tournament::addMatch(Match m, int tour) {
//получаем имя matchfile
    QString filename = m.matchfile;
    QFile file (filename) ;
QSqlQuery q;
q.prepare("INSERT INTO Matches (home, away, tour, matchfile) VALUES (:home, :away,:tour, :matchfile)");
q.bindValue(":home", m.home.club.displayName);
q.bindValue(":away", m.away.club.displayName);
q.bindValue(":tour", tour);
q.bindValue(":matchfile", filename);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}

//обновляем табличку
//хозяева

    int type;
    if (m.home.goals > m.away.goals) //победа хозяев, тип 1
        type = 1;
    else if (m.home.goals == m.away.goals) //ничья, тип 2
        type = 2;
    else if (m.home.goals < m.away.goals) //победа гостей, тип 3
        type = 3;
   QString hg = QVariant (m.home.goals).toString();
   QString ag = QVariant(m.away.goals).toString();
    //обновляем дос-ния
    switch (type) {
        case 1:
        //хозяева
        q.prepare("UPDATE Teams SET win=(SELECT win FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+"+hg+", goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club3)+"+ag+", points=(SELECT points FROM Teams WHERE club=:club4)+3 WHERE club=:club");
        q.bindValue(":club1", m.home.club.name); //win
        q.bindValue(":club2", m.home.club.name); //goalsscore
        q.bindValue(":club3", m.home.club.name); //goalsmissing
        q.bindValue(":club4", m.home.club.name); //points+3
        q.bindValue(":club", m.home.club.name);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}


       //гости
           q.prepare("UPDATE Teams SET lose=(SELECT lose FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+"+ag+", goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club3)+"+hg+" WHERE club=:club");
        q.bindValue(":club1", m.away.club.name);
        q.bindValue(":club2", m.away.club.name);
        q.bindValue(":club3", m.away.club.name);
        q.bindValue(":club", m.away.club.name);
        if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.executedQuery();}

        break;
        case 2:
                //хозяева
        q.prepare("UPDATE Teams SET draw=(SELECT draw FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+"+hg+", goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club3)+"+ag+", points=(SELECT points FROM Teams WHERE club=:club4)+1 WHERE club=:club");
        q.bindValue(":club1", m.home.club.name); //win
        q.bindValue(":club2", m.home.club.name); //goalsscore
        q.bindValue(":club3", m.home.club.name); //goalsmissing
        q.bindValue(":club4", m.home.club.name); //points+3
        q.bindValue(":club", m.home.club.name);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}


       //гости
        q.prepare("UPDATE Teams SET draw=(SELECT draw FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+"+ag+", goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club3)+"+hg+", points=(SELECT points FROM Teams WHERE club=:club4)+1 WHERE club=:club");
        q.bindValue(":club1", m.away.club.name);
        q.bindValue(":club2", m.away.club.name);
        q.bindValue(":club3", m.away.club.name);
        q.bindValue(":club4", m.away.club.name);
        q.bindValue(":club", m.away.club.name);
        if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.executedQuery();}

        break;
        case 3:
        //хозяева
        q.prepare("UPDATE Teams SET lose=(SELECT lose FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+"+hg+", goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club3)+"+ag+" WHERE club=:club");
        q.bindValue(":club1", m.home.club.name); //win
        q.bindValue(":club2", m.home.club.name); //goalsscore
        q.bindValue(":club3", m.home.club.name); //goalsmissing
        q.bindValue(":club4", m.home.club.name); //points+3
        q.bindValue(":club", m.home.club.name);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}


q.prepare("UPDATE Teams SET win=(SELECT win FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+"+ag+", goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club3)+"+hg+", points=(SELECT points FROM Teams WHERE club=:club4)+3 WHERE club=:club");
        q.bindValue(":club1", m.away.club.name); //win
        q.bindValue(":club2", m.away.club.name); //goalsscore
        q.bindValue(":club3", m.away.club.name); //goalsmissing
        q.bindValue(":club4", m.away.club.name); //points+3
        q.bindValue(":club", m.away.club.name);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}

break;

    }

}



Tournament::Tournament (QString dir)
    :workdir (dir)
{
 qDebug() << "reading tournament settings";
 QSettings stg (dir + "/settings.ini", QSettings::IniFormat, this);
 stg.beginGroup("Tournament");
 _title = stg.value("title").toString();
 QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
 db.setDatabaseName(dir + "/tour.db");
 if (!QFile::exists(dir+"/tour.db")) {qDebug() << "file " + dir +"/tour.db not exists!";return;}
 db.open();
QSqlQuery q ;
q.prepare("SELECT club,displayname, nick FROM Teams  ORDER BY points");
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}

while (q.next()) {
    Club club;
   club.name = q.value(q.record().indexOf("club")).toString();
   club.displayName = q.value(q.record().indexOf("displayname")).toString();
club.players = getPlayers(club.name);
clubs.append(club);
gamers.append(q.value(q.record().indexOf("nick")).toString());

}

}

void Tournament::finalize() {
    //here before close
    ;

}

QVariant Tournament::getData(int role) {
    if (role == 1) {
        //турнирная таблмца
        QSqlQuery q;
        q.prepare("SELECT * FROM Teams  ORDER BY points");
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.lastQuery();}
else {qDebug() << "Query done: " + q.lastQuery();}
QStringList list;
while (q.next()) {
    QString currentValue;
currentValue.append(q.value(1).toString());
currentValue.append(";");
currentValue.append(q.value(3).toString());
currentValue.append(";");
currentValue.append(getMatches(q.value(2).toString()));
currentValue.append(";");
currentValue.append(q.value(4).toString());
currentValue.append(";");
currentValue.append(q.value(5).toString());
currentValue.append(";");
currentValue.append(q.value(6).toString());
currentValue.append(";");
currentValue.append(q.value(7).toString());
currentValue.append(";");
currentValue.append(q.value(8).toString());
currentValue.append(";");
currentValue.append(q.value(9).toString());
//последним идет краткое имя клуба
currentValue.append(";");

currentValue.append(q.value(2).toString());

list << currentValue;
}
    return list;

}
    else {
       QString target;
       switch (role) {
           case 2:
           target = "goals";
           break;
           case 3:
           target = "yellow";
           break;
           case 4:
           target = "red";
           break;
       }
       QSqlQuery q;
       QStringList list;
       foreach (Club c, clubs) {
           q.prepare("SELECT name, " + target + " FROM " + c.name + " ORDER BY " + target);
           if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.lastQuery();}
            else {qDebug() << "Query done: " + q.lastQuery();}
            while (q.next()) {
                if (q.value(1) == 0) {continue;}
                list.append(q.value(0).toString() + ";" + q.value(1).toString() + ";" + c.displayName);
             }
       }
       return list;
    }
}

QString Tournament::getMatches(QString team) {
    QSqlQuery q;
q.prepare ("SELECT COUNT (*) FROM Matches WHERE home = :home OR away = :away");
q.bindValue (":home", team);
q.bindValue (":away", team);
if (!q.exec()) {qDebug() << "SQL error" << q.lastError().text() << q.lastQuery();}
  q.next();
  return q.value(0).toString();
}
bool Tournament::checkPlanning(QString *message) {
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
   *message = QVariant(tour).toString();
   return (tour >= clubs.count()) ? false : true;
}
