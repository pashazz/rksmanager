#include "league.h"
#include "playerworker.h"
int Tournament::syncPoints (QString nick) {
    QSqlQuery q(QSqlDatabase::database("players"));
    q.prepare("SELECT win,draw, lose, tp, unreg, bonus FROM Rating WHERE nick=:nick");
    q.bindValue(":nick", nick);
         if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.first();
   int win = q.value(0).toInt();
   int draw = q.value(1).toInt();
   int lose = q.value(2).toInt();
   int tp = q.value(3).toInt();
   int unreg = q.value(4).toInt();
   int bonus = q.value(5).toInt();
   int points = win*10+draw*5+lose+bonus-tp*5-unreg*30;
   qDebug() << nick << points;
   q.prepare("UPDATE Rating SET points=:points WHERE nick=:nick");
   q.bindValue(":points", points);
   q.bindValue(":nick", nick);
          if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   return points;
}
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
 player.stats.traumas = q.value(q.record().indexOf("traumas")).toInt();
 list.append(player);
}
return list;
}
//Tournament - лига
Tournament::Tournament (QString dir, QString title, QString country, QStringList teams, QStringList gmrs, bool isViews)
       : workdir(dir), gamers(gmrs), _view(isViews), finish(false)
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
clubQuery.prepare("CREATE TABLE " + table+ "(id INTEGER PRIMARY KEY, name TEXT, emploi INTEGER, number INTEGER, goals INTEGER, yellow INTEGER, red INTEGER, traumas INTEGER)");
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

 clubQuery.prepare("INSERT INTO "  +table + "(name, emploi, number,goals, yellow, red, traumas) VALUES(:name, :emploi, :number, 0, 0, 0, 0)");
 clubQuery.bindValue(":name", data.at(2));
 clubQuery.bindValue(":emploi", toEmploi(data.at(1)));
 clubQuery.bindValue(":number", data.at(0));
 if (!clubQuery.exec()) {qDebug() << "SQL Error: " + clubQuery.lastError().text() + " in query " + clubQuery.lastQuery();}
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
 //create views
    if (isViews){
QDir d(dir);
d.mkdir(dir+"/views");}
    qDebug() << "creating index";
   QFile settings (dir+"/settings.ini");
   if (!settings.exists()) {settings.open(QIODevice::WriteOnly);settings.close();}
   QSettings stg(dir+"/settings.ini", QSettings::IniFormat, this);
   stg.beginGroup("Tournament");
   stg.setValue("title", title);
   stg.setValue("country", country);
   stg.setValue("views", isViews);
   stg.setValue ("stored", false);
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


void Tournament::doAddMatch(Match m, int tour) {
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
          QString homeNick = getNick(m.home.club.name);
         QString awayNick = getNick(m.away.club.name);
QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery sq (db);
    int type = 0;
    if (m.home.goals > m.away.goals) //победа хозяев, тип 1
    {
        type = 1;
        //устанавливаем базовый рейтинг
   PlayerWorker::win(homeNick);
   PlayerWorker::lose(awayNick);
    }
    else if (m.home.goals == m.away.goals) //ничья, тип 2
    {
        type = 2;
        PlayerWorker::draw(homeNick);
        PlayerWorker::draw(awayNick);
           }
    else if (m.home.goals < m.away.goals) //победа гостей, тип 3
    {
        type = 3;
        PlayerWorker::win(awayNick);
        PlayerWorker::lose(homeNick);
            }
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
finish = finished();
}



Tournament::Tournament (QString dir)
    :workdir (dir)
{
 qDebug() << "reading tournament settings";
 QSettings stg (dir + "/settings.ini", QSettings::IniFormat, this);
 stg.beginGroup("Tournament");
 _title = stg.value("title").toString();
 _view = stg.value("views").toBool();
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
//checking FINISH
//finish = finished();
q.prepare("SELECT player FROM Changes");
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
while (q.next())
    changes.append(q.value(0).toString());

if (_view)
    loadViews();
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
currentValue.append(getMatches(q.value(3).toString()));
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
    else if (role ==6)
    {
        //возвращаем QTableWidget
;
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
           case 5:
           //показываем вьювы вместо команд
           QStringList list;
           foreach (View v, view) {
               QString name = v.name();
               QString nick;
               QStringList names;
               foreach (Club c, v.clubs())
                   names.append(c.name);
               int games, win, draw, lose, gs, gm, points;
               games =0;
               win  =0;
               draw = 0;
               lose = 0;
               gs = 0;
               gm = 0;
               points =0;

             QSqlQuery q;
        q.prepare("SELECT * FROM Teams  ORDER BY points");
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.lastQuery();}
else {qDebug() << "Query done: " + q.lastQuery();}
while (q.next()) {
    if (!names.contains(q.value(2).toString()))
        continue;
    if (!nick.isEmpty()) {
nick.append("/");
}

    nick.append(q.value(1).toString());
games += getMatches(q.value(3).toString()).toInt();
win += q.value(4).toInt();
draw += q.value(5).toInt();
lose += q.value(6).toInt();
gs += q.value(7).toInt();
gm += q.value(8).toInt();
points += q.value(9).toInt();
           }
QString currentVaue;
currentVaue.append(nick);
currentVaue.append(";");
currentVaue.append(name);
currentVaue.append(";");
currentVaue.append(QVariant(games).toString() + ";");
currentVaue.append(QVariant(win).toString() + ";");
currentVaue.append(QVariant(draw).toString() + ";");
currentVaue.append(QVariant(lose).toString() + ";");
currentVaue.append(QVariant(gs).toString() + ";");
currentVaue.append(QVariant(gm).toString() + ";");
currentVaue.append(QVariant(points).toString() + ";");
list.append(currentVaue);
       }
           return list;
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
  q.first();
  return q.value(0).toString();
}

void Tournament::checkSkips(QString home, QString away) {
 QSqlQuery q;
 q.prepare("SELECT player, matches FROM Skips WHERE club=:club");
q.bindValue(":club", home);
if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
else {qDebug() << "Query done" << q.executedQuery();}
while (q.next()) {
    QSqlQuery sq;
    if (q.value(1).toInt() <= 1) { //удолить!!1 - дисква закончилась
     sq.prepare("DELETE FROM Skips WHERE player=:player AND club=:club");
     sq.bindValue(":player", q.value(0));
     sq.bindValue(":club", home);
     if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
else {qDebug() << "Query done" << sq.executedQuery();}
}
    else {
        sq.prepare("UPDATE Skips SET matches=:matches WHERE player=:player");
        sq.bindValue(":matches", q.value(1).toInt() - 1);
        sq.bindValue(":player", q.value(0));
        if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
else {qDebug() << "Query done" << sq.executedQuery();}
    }
}
q.prepare("SELECT player, matches FROM Skips WHERE club=:club");
q.bindValue(":club", away);
if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
else {qDebug() << "Query done" << q.executedQuery();}
while (q.next()) {
    QSqlQuery sq;
    if (q.value(1).toInt() <= 1) { //удолить!!1 - дисква закончилась
     sq.prepare("DELETE FROM Skips WHERE player=:player AND club=:club");
     sq.bindValue(":player", q.value(0));
     sq.bindValue(":club", away);
     if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
else {qDebug() << "Query done" << sq.executedQuery();}
}
    else {
        sq.prepare("UPDATE Skips SET matches=:matches WHERE player=:player");
        sq.bindValue(":matches", q.value(1).toInt() - 1);
        sq.bindValue(":player", q.value(0));
        if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
else {qDebug() << "Query done" << sq.executedQuery();}
    }
}
}

void Tournament::doAddMatch(QString home, QString away, TechResult::Result res, int tour) { //краткие имена
    qDebug() << "Техническое поражение!" << home << away;
    QSqlQuery q;
QString homeDisplay, awayDisplay;
   foreach(Club c, clubs) {
       if (c.displayName == home)
           homeDisplay = c.name;
       else if (c.displayName == away)
           awayDisplay = c.name;

   }
QString homeNick = getNick(homeDisplay);
QString awayNick = getNick(awayDisplay);
    q.prepare("INSERT INTO Matches (home, away, tour, matchfile) VALUES (:home, :away,:tour, :matchfile)");
    q.bindValue(":home", home);
    q.bindValue(":away", away);
    q.bindValue(":tour", tour);
    switch (res) {
        case TechResult::HomeWin:
        q.bindValue(":matchfile", "7-0");
PlayerWorker::tp(awayNick);
        break;
        case TechResult::AwayWin:
        q.bindValue(":matchfile", "0-7");
        PlayerWorker::tp (homeNick);
        break;
        case TechResult::Draw:
        q.bindValue(":matchfile", "0-0");
        PlayerWorker::tp(homeNick);
        PlayerWorker::tp(awayNick);
        break;

    }
          if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
else {qDebug() << "Query done" << q.executedQuery();}
switch (res) {
    case TechResult::HomeWin:
    //
     q.prepare("UPDATE Teams SET win=(SELECT win FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+7, points=(SELECT points FROM Teams WHERE club=:club3)+3 WHERE club=:club");
        q.bindValue(":club1", homeDisplay); //win
        q.bindValue(":club2", homeDisplay); //goalsscore
        q.bindValue(":club3", homeDisplay); //goalsmissing
        q.bindValue(":club", homeDisplay);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}


       //гости
           q.prepare("UPDATE Teams SET lose=(SELECT lose FROM Teams WHERE club=:club1)+1,  goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club2)+7 WHERE club=:club");
        q.bindValue(":club1", awayDisplay);
        q.bindValue(":club2", awayDisplay);
        q.bindValue(":club", awayDisplay);
        if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.executedQuery();}

        break;
  case TechResult::AwayWin:
       q.prepare("UPDATE Teams SET lose=(SELECT lose FROM Teams WHERE club=:club1)+1, goalsMissing=(SELECT goalsMissing FROM Teams WHERE club=:club2)+7 WHERE club=:club");
        q.bindValue(":club1", homeDisplay); //win
        q.bindValue(":club2", homeDisplay); //goalsscore
         q.bindValue(":club", homeDisplay);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}


q.prepare("UPDATE Teams SET win=(SELECT win FROM Teams WHERE club=:club1)+1, goalsScored=(SELECT goalsScored FROM Teams WHERE club=:club2)+7, points=(SELECT points FROM Teams WHERE club=:club3)+3 WHERE club=:club");
        q.bindValue(":club1", awayDisplay); //win
        q.bindValue(":club2", awayDisplay); //goalsscore
        q.bindValue(":club3", awayDisplay); //goalsmissing
        q.bindValue(":club", awayDisplay);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
break;
case TechResult::Draw:
                //хозяева
        q.prepare("UPDATE Teams SET draw=(SELECT draw FROM Teams WHERE club=:club1)+1, points=(SELECT points FROM Teams WHERE club=:club2)+1 WHERE club=:club");
        q.bindValue(":club1", homeDisplay); //win
        q.bindValue(":club2", homeDisplay); //goalsscore
        q.bindValue(":club", homeDisplay);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}


       //гости
        q.prepare("UPDATE Teams SET draw=(SELECT draw FROM Teams WHERE club=:club1)+1, points=(SELECT points FROM Teams WHERE club=:club2)+1 WHERE club=:club");
        q.bindValue(":club1", awayDisplay);
        q.bindValue(":club2", awayDisplay);
        q.bindValue(":club", awayDisplay);
        if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.executedQuery();}

        break;
}
finish = finished();
}

//this is BASE function for use in all Tournament ierarchy
//calls in constructor
void Tournament::loadMatches() {
//coming soon

}

void Tournament::setChangeList(QStringList lst) {
    //можно вызвать только 1 раз, далее makeChange или просто добавить запись в таблицу
    QSqlQuery q;
    q.prepare("CREATE TABLE Changes (id INTEGER PRIMARY KEY, player TEXT)");
      if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.executedQuery();}
        foreach (QString str,   lst) {
            q.prepare("INSERT INTO Changes (player) VALUES (?)");
            q.addBindValue(str);
                  if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.executedQuery();}
        }
changes = lst;
}

bool Tournament::makeChange(QString before, QString after) {
    if (before.isEmpty() || after.isEmpty())
        return false;

    //unreg this
    PlayerWorker::unreg(before);

QSqlQuery q;

q.prepare("UPDATE Teams SET nick=:after WHERE nick=:before");
q.bindValue(":before", before);
q.bindValue(":after", after);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.lastQuery();}
q.prepare("DELETE FROM Changes WHERE player=:after");
q.bindValue(":after", after);
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
        else {qDebug() << "Query done: " + q.lastQuery();}
   changes.removeOne(after);
   gamers.removeOne(before);
   gamers.append(after);

return true;
}

void Tournament::loadViews()
{
    view.clear();
QDir d(workdir+"/views");
foreach (QString file, d.entryList(QDir::NoDotAndDotDot | QDir::Files | QDir::Readable)) {
View v (d.absolutePath() + QDir::separator() + file, clubs);
view.append(v);
}
}


void Tournament::addView(QString name, QList <Club> c)
{
    View v;
QString fileName = name + ".ini";
v.setFileName(workdir + QDir::separator() +"views" + QDir::separator() +fileName);
    v.setName(name);
    v.setClubs(c);
    view.append(v);

}

void Tournament::removeView(View v)
{
    QFile::remove(v.filename());
    loadViews();
}

QString Tournament::getNick(QString s) {
    QSqlQuery q;
      q.prepare("SELECT nick FROM Teams WHERE club=:name");
        q.bindValue(":name", s);
        if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
        q.first();
        return q.value(0).toString();
}

/*!
  Здесь представлена функция finished() для лиги
  В потомках она ДОЛЖНА  быть переопределена
  */


void Tournament::addToChanges(QString nick) {
    QSqlQuery q;
    q.prepare("INSERT INTO Changes (player) VALUES (:player)");
    q.bindValue(":player", nick);
             if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.executedQuery();}
else {qDebug() << "Query done: " + q.executedQuery();}
    changes.append(nick);
}
