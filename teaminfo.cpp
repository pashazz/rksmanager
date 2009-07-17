#include "teaminfo.h"
#include "ui_teaminfo.h"
#include "imageprovider.h"
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
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 while (q.next()) {
     m.home.start.append(m.home.club.getPlayer(q.value(0).toString()));
 }
 q.prepare("SELECT player FROM AwayStart");
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 while (q.next()) {
     m.away.start.append(m.away.club.getPlayer(q.value(0).toString()));
 }
q.prepare("SELECT player, type FROM HomeEvents");
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
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
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
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
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 while (q.next()) {
     Change ch;
     ch.first = m.home.club.getPlayer(q.value(0).toString());
     ch.second = m.home.club.getPlayer(q.value(1).toString());
m.home.changes.append(ch);
 }
q.prepare("SELECT poff, pon FROM AwayChanges");
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 while (q.next()) {
     Change ch;
     ch.first = m.away.club.getPlayer(q.value(0).toString());
     ch.second = m.away.club.getPlayer(q.value(1).toString());
m.away.changes.append(ch);
}
 return m;
}

TeamInfo::TeamInfo(QWidget *parent, Club club, QString nick, Tournament *t) :
    QDialog(parent),
    m_ui(new Ui::TeamInfo), trn(t), c(club)
{
    m_ui->setupUi(this);
    m_ui->lblEmblem->setPixmap(ImageProvider::getClubEmblem(c.name));
    m_ui->lblTeamName->setText(c.displayName + "\n(" + nick + ")");
    loadMatches();
    m_ui->tblPlayers->setRowCount(club.players.size());
    foreach (Player p, club.players) {
        loadPlayerInfo(p);
    }

}

TeamInfo::~TeamInfo()
{
    delete m_ui;
}

void TeamInfo::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void TeamInfo::loadMatches() {
QSqlQuery q;
q.prepare("SELECT * FROM Matches WHERE home=:home OR away=:away");
q.bindValue(":home", c.displayName);
q.bindValue(":away", c.displayName);
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 while (q.next()) {
     QString homeTeam = q.value(1).toString();
     QString awayTeam = q.value(2).toString();
     if (q.value(4).toString() == "0-0") {
// Тех Н
    buildItem(homeTeam, awayTeam, 0, 0, true);
     }
     else if (q.value(4).toString() == "7-0") {
         buildItem(homeTeam, awayTeam, 7, 0, true);
     }
     else if (q.value(4).toString() == "0-7") {
           buildItem(homeTeam, awayTeam, 0, 7, true);
       }
     else {
Club home, away;
foreach (Club c, trn->getClubs())  {
if (c.displayName == homeTeam)
    home = c;
else if (c.displayName == awayTeam)
    away = c;
}
Match m;
m = readToMatch(q.value(4).toString(), home, away);
buildItem(m);
}
 }

}
void TeamInfo::buildItem(QString home, QString away, int hGoals, int aGoals, bool tp) {
   qDebug() << "build item";
    QListWidget *target;
    if (c.displayName == home) {
        if (hGoals > aGoals)  //победа
            target = m_ui->lstWin;
       else if (hGoals < aGoals)
            target = m_ui->lstLose;

}
    else if (c.displayName == away) {
                if (hGoals > aGoals)
            target = m_ui->lstLose;
       else if (hGoals < aGoals)
            target = m_ui->lstWin;

    }
    if (hGoals == aGoals)
        target = m_ui->lstDraw;

    QListWidgetItem *it = new QListWidgetItem (target, 0);
    QString str;
    str.append(home);
    str.append(" ");
    str.append(QVariant(hGoals).toString());
    str.append(" - ");
    str.append(QVariant (aGoals).toString());
    str.append(" ");
    str.append(away);
    if (tp) {
        str.append(" (тп)");
        it->setData(Qt::UserRole, "TP");
       }
    else
        it->setData(Qt::UserRole, home + "-" + away);
    it->setText(str);
    target->addItem(it);
}


void TeamInfo::buildItem(Match m) {
buildItem(m.home.club.displayName, m.away.club.displayName, m.home.goals, m.away.goals, false);
matches.insert(m.home.club.displayName + "-" + m.away.club.displayName, m);
}

void TeamInfo::loadPlayerInfo(Player player) {
    QString emploi;
    switch (player.emploi) {
        case 1:
        emploi = "Вратарь"; break;
        case 2:
        emploi = "Защитник"; break;
        case 3:
        emploi = "Полузащитник"; break;
        case 4:
        emploi = "Нападающий";
    }
    static int curItem = 0;

QString str = QVariant(player.number).toString() + ";" + emploi + ";" + player.name;
QStringList data = str.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setFlags(Qt::ItemIsEnabled);
           it->setText(data.at(i));
        m_ui->tblPlayers->setItem(curItem, i, it);

       }
       curItem++;
       //set statistics
      m_ui->lstStats->clear();
      QListWidgetItem *itGames = new QListWidgetItem (0);
      itGames->setFlags(Qt::ItemIsEnabled);
      QSqlQuery q;

}
