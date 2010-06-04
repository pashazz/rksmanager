#include "addmatchdialog.h"
#include "ui_addmatchdialog.h"
#include "imageprovider.h"
/*!
  Этот компонент записывает результат матча в т.н. matchfile и возвращает объект match
  Разработка этого компонента закончена

  */
    static QStringList homeStart, homeChanges, awayStart, awayChanges;

AddMatchDialog::AddMatchDialog(QWidget *parent, Tournament *t) :
    QDialog(parent),
    m_ui(new Ui::AddMatchDialog)
{
    m_ui->setupUi(this);
    workdir = t->getWorkingDirectory();
trn = t;
//tune
m_ui->lstAwayStart->setSelectionMode(QAbstractItemView::MultiSelection);
m_ui->lstHomeStart->setSelectionMode(QAbstractItemView::MultiSelection);
connect (m_ui->cmdAddAwayEvent, SIGNAL(clicked()), this, SLOT(addEvent()));
connect(m_ui->cmdAddHomeEvent, SIGNAL(clicked()), this, SLOT(addEvent()));
}

AddMatchDialog::~AddMatchDialog()
{
    delete m_ui;
}

void AddMatchDialog::changeEvent(QEvent *e)
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

bool AddMatchDialog::checkPlayer(QString player, QString club) {
    QSqlQuery q;
    qDebug() << "Player is " + player;
    qDebug() << "club is " + club;
    q.prepare("SELECT * FROM Skips WHERE player=:name AND club=:club");
    q.bindValue(":name", player);
    q.bindValue(":club", club);
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
      else {qDebug() << "Query done" << q.executedQuery();}

return q.first();
}
void AddMatchDialog::createLists() {
    qDebug() << "Creating lists";
    qDebug() << m.home.club.name << m.away.club.name;
    m.home.goals = 0;
    m.away.goals  = 0;
    foreach (Player p, m.home.club.players) {
        if (checkPlayer(p.name, m.home.club.name)) {continue;}
        //add player to list
        QListWidgetItem *it = new QListWidgetItem ( 0);
        it->setText(p.name);
        m_ui->lstHomeStart->addItem(it);
    }
        foreach (Player p, m.away.club.players) {
        if (checkPlayer(p.name, m.away.club.name)) {continue;}
        //add player to list
        QListWidgetItem *it = new QListWidgetItem (0);
        it->setText(p.name);
        qDebug() << p.name;
        m_ui->lstAwayStart->addItem(it);
    }
//disable
        m_ui->cmdAddAwayEvent->setEnabled(false);
        m_ui->cmdAddHomeEvent->setEnabled(false);
        if (!m_ui->cmdHomeStart->isEnabled())
            m_ui->buttonBox->setEnabled(true);
}

void AddMatchDialog::on_cmdHomeStart_clicked()
{
    //check if 11 players
    if (m_ui->lstHomeStart->selectedItems().count() != 11) {
        QMessageBox::warning(this, tr("РКС"), tr("Выбрано %1 игроков. Для стартового состава необходимо 11 игроков").arg(QVariant(m_ui->lstHomeStart->selectedItems().count()).toString()));
    return;
}
    //setting m object
    foreach (QListWidgetItem *it, m_ui->lstHomeStart->selectedItems()){
    m.home.start.append(m.home.club.getPlayer(it->text()));
           }
    //buttons
    m_ui->cmdAddHomeEvent->setEnabled(true);
    m_ui->cmdHomeStart->setEnabled(false);
    m_ui->lstHomeStart->setEnabled(false);
    if (!m_ui->cmdAwayStart->isEnabled())
        m_ui->buttonBox->setEnabled(true);
}


void AddMatchDialog::on_cmdAwayStart_clicked()
{
       //check if 11 players
    if (m_ui->lstAwayStart->selectedItems().count() != 11) {
              QMessageBox::warning(this, tr("РКС"), tr("Выбрано %1 игроков. Для стартового состава необходимо 11 игроков").arg(QVariant(m_ui->lstAwayStart->selectedItems().count()).toString()));

    return;
}
    //setting m object
    foreach (QListWidgetItem *it, m_ui->lstAwayStart->selectedItems()){
    m.away.start.append(m.away.club.getPlayer(it->text()));
           }
    //buttons
    m_ui->cmdAddAwayEvent->setEnabled(true);
    m_ui->cmdAwayStart->setEnabled(false);
    //lists
    m_ui->lstAwayStart->setEnabled(false);
       if (!m_ui->cmdHomeStart->isEnabled())
        m_ui->buttonBox->setEnabled(true);
}



QString AddMatchDialog::saveMatch() {
    //get filename
QString fileName = workdir + "/matches/" + m.home.club.name + "-" + m.away.club.name + ".mch";
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "match");
  db.setDatabaseName(fileName);
  qDebug() << fileName;
  if(!db.open()) {
      qDebug() << "Error open database \"match\" "+ db.lastError().text();
  }
  else {
      qDebug() << "Match file opened sucsess!";

  }

   QSqlQuery q(db);
//muhahahaha
//home
q.prepare("CREATE TABLE HomeStart (id INTEGER PRIMARY KEY, player TEXT)");
 if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 foreach (Player p,  m.home.start) {
     q.prepare("INSERT INTO HomeStart (player) VALUES (:player)");
     q.bindValue(":player", p.name);
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
       else {qDebug() << "Query done" << q.executedQuery();}}

 q.prepare("CREATE TABLE AwayStart (id INTEGER PRIMARY KEY, player TEXT)");
 if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}

 foreach (Player p,  m.away.start) {
     q.prepare("INSERT INTO AwayStart (player) VALUES (:player)");
     q.bindValue(":player", p.name);
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 }
//events                                                                 1 -goal 2 - yellow 3 - red 4 - trauma
 q.prepare("CREATE TABLE HomeEvents (id INTEGER PRIMARY KEY, player TEXT, type INTEGER)");
        if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 foreach (Player p, m.home.yellowCards) {
 q.prepare("INSERT INTO HomeEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 2);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 }
 foreach (Player p, m.home.golaedors) {
  q.prepare("INSERT INTO HomeEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 1);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
}
 foreach (Player p, m.home.redCards) {
   q.prepare("INSERT INTO HomeEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 3);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
}
 foreach (Player p, m.home.traumas) {
   q.prepare("INSERT INTO HomeEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 4);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}


 }
 q.prepare("CREATE TABLE AwayEvents (id INTEGER PRIMARY KEY, player TEXT, type INTEGER)");
        if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 foreach (Player p, m.away.yellowCards) {
 q.prepare("INSERT INTO AwayEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 2);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 }
 foreach (Player p, m.away.golaedors) {
  q.prepare("INSERT INTO AwayEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 1);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
}
 foreach (Player p, m.away.redCards) {
   q.prepare("INSERT INTO AwayEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 3);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
}
 foreach (Player p, m.away.traumas) {
   q.prepare("INSERT INTO AwayEvents (player, type) VALUES (:player, :type)");
 q.bindValue(":player", p.name);
 q.bindValue(":type", 4);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}


 }
//changes
 q.prepare("CREATE TABLE HomeChanges (id INTEGER PRIMARY KEY, poff TEXT, pon TEXT)");
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 foreach (Change ch, m.home.changes) {
     q.prepare("INSERT INTO HomeChanges (poff, pon) VALUES (:poff, :pon)");
     q.bindValue(":poff", ch.first.name);
     q.bindValue(":pon", ch.second.name);
         if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 }
 q.prepare("CREATE TABLE AwayChanges (id INTEGER PRIMARY KEY, poff TEXT, pon TEXT)");
   if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 foreach (Change ch, m.away.changes) {
     q.prepare("INSERT INTO AwayChanges (poff, pon) VALUES (:poff, :pon)");
     q.bindValue(":poff", ch.first.name);
     q.bindValue(":pon", ch.second.name);
         if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 }
 //запись информации о матче
 q.prepare("CREATE TABLE MatchInfo (id INTEGER PRIMARY KEY name TEXT value TEXT)");
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
 else {qDebug() << "Query done" << q.executedQuery();}
 q.prepare("INSERT INTO MatchInfo (name, value) VALUES (:name, :value");
 q.bindValue(":name", "homegoals");
 q.bindValue(":value", m.home.goals);

 db.close();
 return fileName;

}

Match AddMatchDialog::getMatch() {
 QString filename = saveMatch();
  m.matchfile = filename;
return m;
}
void AddMatchDialog::setData(QStringList data) {
    qDebug() << data;
foreach (Club c, trn->getClubs()) {
    if (c.name == data.at(0)){
        m.home.club = c;}
 else if (c.name == data.at(2))
    {m.away.club = c;}
}
//гербы
 m_ui->lblHomeEmblem->setPixmap(ImageProvider::getClubEmblem(m.home.club.name));
 m_ui->lblAwayEmblem->setPixmap(ImageProvider::getClubEmblem(m.away.club.name));
//названия
 qDebug() << trn->getGamers();
 qDebug() << trn->getClubs().count();
 QList<Club> clubs =  trn->getClubs();
 QStringList gamers = trn->getGamers();

 m_ui->lblHome->setText(gamers.at(clubs.indexOf(m.home.club)) + "\n(" + m.home.club.displayName + ")");
 m_ui->lblAway->setText(gamers.at(clubs.indexOf(m.away.club)) + "\n(" +m.away.club.displayName + ")");
 //составчики
 createLists();


}
void AddMatchDialog::doAction(QListWidget *list, QListWidget *playersList)
    {
    //prepare
    MatchStatistics *stats;
    QLabel *score;
    QStringList *s, *ch;
    if (list == m_ui->lstHome) {
        stats = &m.home;
        s = &homeStart;
        ch = &homeChanges;
        score = m_ui->lblHomeScore;
    }
    else if (list == m_ui->lstAway) {
        stats = &m.away;
        s = &awayStart;
        ch = &awayChanges;
        score = m_ui->lblAwayScore;
    }
    else {return;}
    if (s->isEmpty() && ch->isEmpty()) {
        foreach (Player p, stats->club.players) {
            if (stats->start.contains(p))
                s->append(p.name);
            else
                ch->append(p.name);
        }

    }

  //счетчик желтых карточек
 static QStringList yellowCarders;
        EventDialog *dlg = new EventDialog(this, *s, *ch);
        if (dlg->exec() == QDialog::Accepted) {
            QStringList data = dlg->getData();
             QListWidgetItem *it = new QListWidgetItem(0);

            switch (QVariant (data.at(1)).toInt()) {
                qDebug() << data.at(1);
                case 5:
                stats->golaedors.append(stats->club.getPlayer(data.at(0)));
                it->setIcon(QIcon(":/images/images/ball.png"));
                it->setText(data.at(0));
                list->addItem(it);
                     stats->goals ++;
                score->setText(QVariant(stats->goals).toString());
                break;
                case 1:
                if (!yellowCarders.contains(data.at(0))) {
                stats->yellowCards.append(stats->club.getPlayer(data.at(0)));
                it->setIcon(QIcon(":/images/images/yellow"));
                it->setText(data.at(0));
                list->addItem(it);
                yellowCarders.append(data.at(0));}
                else {
                 stats->yellowCards.append(stats->club.getPlayer(data.at(0)));
                stats->redCards.append(stats->club.getPlayer(data.at(0)));
                it->setIcon(QIcon(":/images/images/cards.png"));
                it->setText(data.at(0));
                list->addItem(it);
                s->removeAt(s->indexOf(data.at(0)));
                playersList->clear();
                playersList->addItems(*s);
                yellowCarders.removeAt(yellowCarders.indexOf(data.at(0)));

                }
                break;
                case 2:
                stats->redCards.append(stats->club.getPlayer(data.at(0)));
                it->setIcon(QIcon(":/images/images/cards.png"));
                it->setText(data.at(0));
                list->addItem(it);
                s->removeAt(s->indexOf(data.at(0)));
                playersList->clear();
                playersList->addItems(*s);
                break;
                case 3:
                stats->traumas.append(stats->club.getPlayer(data.at(0)));
                it->setIcon(QIcon(":/images/traumas"));
                it->setText(data.at(0));
                list->addItem(it);
                break;
                case 4:
                {
                Change change;
                change.first = stats->club.getPlayer(data.at(0));
                change.second = stats->club.getPlayer(data.at(2));
                stats->changes.append(change);
                //item
                it->setIcon(QIcon (":/images/images/change.png"));
                it->setText(data.at(0) + " ➨ " + data.at(2));
                list->addItem(it);
                //change!
               s->removeAt(s->indexOf(data.at(0)));
               ch->removeAt (ch->indexOf(data.at(2)));
               s->append(data.at(2));
               playersList->clear();
               playersList->addItems(*s);
            }
                break;
                default:
                delete it;
                break;
            }
        }

    }
void AddMatchDialog::addEvent() {
if (sender() == m_ui->cmdAddHomeEvent)
    doAction(m_ui->lstHome, m_ui->lstHomeStart);
else if (sender() == m_ui->cmdAddAwayEvent)
    doAction(m_ui->lstAway, m_ui->lstAwayStart);
}

void AddMatchDialog::on_buttonBox_accepted()
{
}

void AddMatchDialog::on_AddMatchDialog_finished(int result)
{
   homeStart.clear();
   homeChanges.clear();
   homePlayers.clear();
   homeStart.clear();
}
