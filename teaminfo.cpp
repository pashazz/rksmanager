#include "teaminfo.h"
#include "ui_teaminfo.h"
#include "imageprovider.h"
#include "playerinfo.h"
#include "matchinfo.h"
#include "common.h"
TeamInfo::TeamInfo(QWidget *parent, Club club, QString nick, Tournament *t) :
    QDialog(parent),
    m_ui(new Ui::TeamInfo), trn(t), c(club)
{
    m_ui->setupUi(this);
    curPlayer = 0;
    m_ui->lblEmblem->setPixmap(ImageProvider::getClubEmblem(c.name));
    m_ui->lblTeamName->setText(c.displayName + "\n(" + nick + ")");
    loadMatches();
    setStats();
    m_ui->tblPlayers->setRowCount(club.players.size());
    foreach (Player p, club.players) {
        loadPlayerInfo(p);
    }
//connects
  connect(m_ui->lstDraw, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewMatch(QListWidgetItem*)));
  connect(m_ui->lstWin, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewMatch(QListWidgetItem*)));
  connect(m_ui->lstLose, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewMatch(QListWidgetItem*)));

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

void TeamInfo::loadPlayerInfo(Player p) {
    QString emploi;
    switch (p.emploi) {
        case 1:
        emploi = "Вратарь"; break;
        case 2:
        emploi = "Защитник"; break;
        case 3:
        emploi = "Полузащитник"; break;
        case 4:
        emploi = "Нападающий";

    }


QString str = QVariant(p.number).toString() + ";" + emploi + ";" + p.name;
QStringList data = str.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setFlags(Qt::ItemIsEnabled);
           it->setText(data.at(i));
        m_ui->tblPlayers->setItem(curPlayer, i, it);

       }
       curPlayer++;
       //set statistics

   }
void TeamInfo::setStats () {
QMap <QString, QTableWidget*> views;
views.insert("goals",  m_ui->tblGoals);
views.insert ("yellow", m_ui->tblYellow);
views.insert("red", m_ui->tblRed);
int row = 0;
    QSqlQuery q;
    foreach (QString key, views.keys()) {
        q.prepare("SELECT name, " + key +  " FROM " + c.name);
        QTableWidget *target  = views.value(key);
  if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
        while (q.next()) {
            if (q.value(1).toString() != "0") {
QStringList data = QStringList () << q.value(0).toString() << q.value(1).toString();
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setFlags(Qt::ItemIsEnabled);
           it->setText(data.at(i));
           target->setRowCount(row + 1);
        target->setItem(row, i, it);
       }
         row++;
            }
         }
    }



}
void TeamInfo::setPlayerStats (Player p) {
    m_ui->lstStats->clear();

      QSqlQuery q;
     int games  = 0;
     int change = 0;

      q.prepare("SELECT * FROM Matches WHERE home=:club OR away=:club1");
      q.bindValue(":club", c.displayName);
      q.bindValue(":club1", c.displayName);
          if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   while (q.next()) {
       QString homeTeam = q.value(1).toString();
       QString awayTeam = q.value(2).toString();
       QStringList ex = QStringList () << "7-0" << "0-0" << "0-7";
       if (ex.contains(q.value(4).toString())) {
           continue;
       }

      //подсчитаем игры
      QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "match");
      db.setDatabaseName(q.value(4).toString());
      db.open();
      QSqlQuery mq (db);
     mq.prepare("SELECT COUNT(*) FROM HomeStart WHERE player=:player");
     mq.bindValue(":player", p.name);

      mq.exec();
     if( mq.first())
      games += mq.value(0).toInt();
     mq.prepare("SELECT COUNT(*) FROM AwayStart WHERE player=:player");
     mq.bindValue(":player", p.name);
      mq.exec();
    if(  mq.first())
      games += mq.value(0).toInt();

      mq.prepare("SELECT COUNT (*) FROM HomeChanges WHERE pon=:player");
     mq.bindValue(":player", p.name);
      mq.exec();
qDebug() << "Change error: " << mq.lastError().text();
while (mq.next())
    change += mq.value(0).toInt();

      mq.prepare("SELECT COUNT (*) FROM AwayChanges WHERE pon=:player");
     mq.bindValue(":player", p.name);
      mq.exec();
qDebug() << "Change error: " << mq.lastError().text();
while (mq.next())
    change += mq.value(0).toInt();

   db.close();
}
 //теперь добавляем итемы
   QListWidgetItem *itGames = new QListWidgetItem (0);
      itGames->setFlags(Qt::ItemIsEnabled);
      itGames->setIcon(QIcon (":/images/images/tactic.png"));
      itGames->setText(QVariant(games).toString());
      m_ui->lstStats->addItem(itGames);

      QListWidgetItem *itChanges  = new QListWidgetItem (0);
      itChanges->setFlags(Qt::ItemIsEnabled);
      itChanges->setIcon(QIcon (":/images/images/change.png"));
      itChanges->setText(QVariant(change).toString());
      m_ui->lstStats->addItem(itChanges);

      QListWidgetItem *itGoals = new QListWidgetItem (0);
      itGoals->setIcon(QIcon (":/images/images/ball.png"));
      itGoals->setToolTip("Голов");
    itGoals->setFlags(Qt::ItemIsEnabled);
    m_ui->lstStats->addItem(itGoals);

      QListWidgetItem *itYellow = new QListWidgetItem (0);
      itYellow->setIcon(QIcon (":/images/yellow"));
      itYellow->setToolTip("Желтых карточек");
 //     itYellow->setTextColor(Qt::yellow);
      itYellow->setFlags(Qt::ItemIsEnabled);
    m_ui->lstStats->addItem(itYellow);

      QListWidgetItem *itRed = new QListWidgetItem (0);
      itRed->setIcon(QIcon(":/images/images/cards.png"));
      itRed->setToolTip("Красных карточек");
      itRed->setTextColor (Qt::red);
      itRed->setFlags(Qt::ItemIsEnabled);
    m_ui->lstStats->addItem(itRed);
      QListWidgetItem *itTra = new QListWidgetItem (0);
      itTra->setIcon(QIcon (":/images/traumas"));
      itTra->setToolTip("Травм");
            itTra->setFlags(Qt::ItemIsEnabled);
    m_ui->lstStats->addItem(itTra);

     q.prepare("SELECT * FROM " + c.name + " WHERE name=:name");
     q.bindValue(":name", p.name);
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 while (q.next()) {
     itGoals->setText(q.value(4).toString());
     itYellow->setText(q.value(5).toString());
     itRed->setText(q.value(6).toString());
     itTra->setText(q.value(7).toString());
 }
}


void TeamInfo::on_tblPlayers_itemDoubleClicked(QTableWidgetItem* item)
{
            QTableWidgetItem *it = m_ui->tblPlayers->item(item->row(), 2);
    Player p = c.getPlayer(it->text());
    qDebug() << p.name << " - loading";
PlayerInfo *dlg = new PlayerInfo(this, p, c);
dlg->exec();
}

void TeamInfo::on_tblPlayers_itemClicked(QTableWidgetItem* item)
{
        QTableWidgetItem *it = m_ui->tblPlayers->item(item->row(), 2);
    Player p = c.getPlayer(it->text());
    setPlayerStats (p);
}

void TeamInfo::viewMatch(QListWidgetItem *item) {
    if (item->data(Qt::UserRole).toString() == "TP") {return;}
    Club home, away;
    QStringList data = item->data(Qt::UserRole).toString().split("-");
    QString ht = data.at(0);
    QString at = data.at(1);
    foreach (Club c, trn->getClubs())
    {
        if (c.displayName == ht){home = c;}

        if (c.displayName == at) {away = c;}
    }
    //получаем matchfile
    QSqlQuery q;
    q.prepare("SELECT matchfile FROM Matches WHERE home=:home AND away=:away");
    q.bindValue(":home", ht);
    q.bindValue(":away", at);
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 q.first();
 QString matchfile = q.value(0).toString();
 Match m = readToMatch(matchfile, home, away);
 MatchInfo *dlg = new MatchInfo (this, m);
 dlg->exec();
}
