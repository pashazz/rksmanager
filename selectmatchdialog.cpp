#include "selectmatchdialog.h"
#include "ui_selectmatchdialog.h"

SelectMatchDialog::SelectMatchDialog(QWidget *parent, Tournament *t) :
    QDialog(parent),
    m_ui(new Ui::SelectMatchDialog), trn(t)
{
    m_ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database("QSQLITE", "planning");
    db.setDatabaseName(t->getWorkingDirectory() + "/planning.db");

   m_ui->sbTours->setMinimum (1);
   if (db.tables().count() > 1)
       currentTour = db.tables().count();
   else
        currentTour = 1;
 m_ui->sbTours->setMaximum(currentTour);
 loadMatches(currentTour);

}

SelectMatchDialog::~SelectMatchDialog()
{
    delete m_ui;
}

void SelectMatchDialog::changeEvent(QEvent *e)
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

void SelectMatchDialog::on_sbTours_valueChanged(int i)
{
loadMatches(i);
}
void SelectMatchDialog::loadMatches(int i) {
      QSqlDatabase db = QSqlDatabase::database("planning");
    QSqlQuery q (db);
   m_ui->lstMatches->clear();
   QString table = "Tour" + QVariant(i).toString();
   q.prepare("SELECT * FROM " +table+  " WHERE played=:played");
   q.bindValue(":played", false);
      if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   while (q.next()) {
      QListWidgetItem *it = new QListWidgetItem (q.value(1).toString() + "-" + q.value(2).toString());
      QStringList data;
      data << q.value(1).toString();
      data << q.value(2).toString();
      qDebug() << "matchdata is " << data;
      it->setData(Qt::UserRole, data);
      m_ui->lstMatches->addItem(it);
   }

}


void SelectMatchDialog::on_lstMatches_itemDoubleClicked(QListWidgetItem* item)
{
    Match m;
    QStringList itemdata = item->data(Qt::UserRole).toStringList();
    QStringList matchData;
    QString homeclub, homenick, awayclub, awaynick;
    QStringList gamers = trn->getGamers();
    QList <Club> clubs = trn->getClubs();
    for (int i; i < clubs.count(); ++i) {
        if (clubs.at(i).displayName == itemdata.at(0)) {
            homeclub = clubs.at(i).name;
            homenick = gamers.at(i);
            }
        else if (clubs.at(i).displayName == itemdata.at(1)) {
            awaynick = gamers.at(i);

            awayclub = clubs.at(i).name;
        }
    }
    matchData << homeclub;
    matchData << homenick;
    matchData << awayclub;
    matchData << awaynick;
        qDebug() << matchData;

    AddMatchDialog *dlg = new AddMatchDialog (this, trn);
    dlg->setData(matchData);
    if (dlg->exec() == QDialog::Accepted) {
     m =  dlg->getMatch();
     //Записываем матч в главную БД
     QSqlQuery q;

//обновляем достижения команды и игроков
//см. табл. Skips
q.prepare("SELECT player, matches FROM Skips WHERE club=:club");
q.bindValue(":club", m.home.club.name);
if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
else {qDebug() << "Query done" << q.executedQuery();}
while (q.next()) {
    QSqlQuery sq;
    if (q.value(1).toInt() <= 1) { //удолить!!1 - дисква закончилась
     sq.prepare("DELETE FROM Skips WHERE player=:player AND club=:club");
     sq.bindValue(":player", q.value(0));
     sq.bindValue(":club", m.home.club.name);
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
q.bindValue(":club", m.away.club.name);
if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
else {qDebug() << "Query done" << q.executedQuery();}
while (q.next()) {
    QSqlQuery sq;
    if (q.value(1).toInt() <= 1) { //удолить!!1 - дисква закончилась
     sq.prepare("DELETE FROM Skips WHERE player=:player AND club=:club");
     sq.bindValue(":player", q.value(0));
     sq.bindValue(":club", m.away.club.name);
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
   //хозяева


   foreach (Player p, m.home.golaedors) {
    QSqlQuery q;
   q.prepare("UPDATE " + m.home.club.name + " SET goals=(SELECT goals FROM " + m.home.club.name +" WHERE name=:name1) +1 WHERE name=:name");
   q.bindValue(":name1", p.name);
   q.bindValue(":name", p.name);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}


   }
   foreach (Player p, m.home.redCards) {
         q.prepare("UPDATE " + m.home.club.name + " SET red=(SELECT red FROM " + m.home.club.name +" WHERE name=:name1)+1 WHERE name=:name");
   q.bindValue(":name1", p.name);
   q.bindValue(":name", p.name);
   //выписываем дисквалификация на 3 матча
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.prepare("INSERT INTO Skips (player, club, reason, matches) VALUES (:player, :club, :reason, :matches)");
   q.bindValue(":player", p.name);
   q.bindValue(":club", m.home.club.name);
   q.bindValue(":reason", 1);
   q.bindValue(":matches", 3);
          if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   }
   foreach (Player p, m.home.yellowCards) {
       q.prepare("UPDATE " + m.home.club.name + " SET yellow=(SELECT yellow FROM  "+ m.home.club.name +" WHERE name=:name1)+1 WHERE name=:name");
   q.bindValue(":name1", p.name);
   q.bindValue(":name", p.name);
   //выписываем желтую
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}

   }
    foreach (Player p, m.away.golaedors) {
    QSqlQuery q;
   q.prepare("UPDATE " + m.away.club.name + " SET goals=(SELECT goals FROM " + m.away.club.name +" WHERE name=:name1) +1 WHERE name=:name");
   q.bindValue(":name1", p.name);
   q.bindValue(":name", p.name);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}


   }
   foreach (Player p, m.away.redCards) {
         q.prepare("UPDATE " + m.away.club.name + " SET red=(SELECT red FROM " + m.away.club.name +" WHERE name=:name1)+1 WHERE name=:name");
   q.bindValue(":name1", p.name);
   q.bindValue(":name", p.name);
   //выписываем дисквалификация на 3 матча
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   q.prepare("INSERT INTO Skips (player, club, reason, matches) VALUES (:player, :club, :reason, :matches)");
   q.bindValue(":player", p.name);
   q.bindValue(":club", m.away.club.name);
   q.bindValue(":reason", 1);
   q.bindValue(":matches", 3);
          if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   }
   foreach (Player p, m.away.yellowCards) {
    q.prepare("UPDATE " + m.away.club.name + " SET yellow=(SELECT yellow FROM  "+ m.away.club.name +" WHERE name=:name1)+1 WHERE name=:name");
   q.bindValue(":name1", p.name);
   q.bindValue(":name", p.name);
   //выписываем желтую
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}

   }

   trn->addMatch(m, m_ui->sbTours->value());
    QSqlDatabase db = QSqlDatabase::database("planning");
    QSqlQuery sq (db);
    QString table = "Tour" + QVariant(m_ui->sbTours->value()).toString();
    sq.prepare("UPDATE "+table+" SET played=:played WHERE home=:home AND away=:away");
    sq.bindValue(":played", true);
    sq.bindValue(":home", m.home.club.displayName);
    sq.bindValue(":away", m.away.club.displayName);
    if (!sq.exec()) {qDebug() << "SQL Error: "  +sq.lastError().text() + " in query " + sq.lastQuery();}
   else {qDebug() << "Query done" << sq.executedQuery();}
//tune
   loadMatches(1);

    }

}


void SelectMatchDialog::on_lstMatches_itemClicked(QListWidgetItem* item)
{
    m_ui->lblData->setText(item->data(Qt::UserRole).toStringList().join(";"));
}