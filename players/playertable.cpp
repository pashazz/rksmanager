#include "playertable.h"
#include "ui_playertable.h"
#include "addprofiledialog.h"
int ksyncPoints (QString nick) {
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
PlayerTable::PlayerTable(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::PlayerTable)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "players");
    db.setDatabaseName(QDir::homePath() + "/.rks/players.db");
    m_ui->setupUi(this);
    m_ui->tableWidget->addAction(m_ui->actAdd);
    m_ui->tableWidget->addAction(m_ui->actBonus);
    loadTable();
}

PlayerTable::~PlayerTable()
{
    delete m_ui;
}

void PlayerTable::changeEvent(QEvent *e)
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

void PlayerTable::on_actAdd_triggered()
{
AddProfileDialog *dlg = new AddProfileDialog();
dlg->exec();
loadTable();

}

void PlayerTable::loadTable() {
    for (int i=0; i < m_ui->tableWidget->rowCount(); ++i)
        m_ui->tableWidget->removeRow(i);

QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q (db);
q.prepare("SELECT nick, matches, win, draw, lose, tp, unreg, bonus, points  FROM Rating");
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
int i = 0;
while (q.next()) {
    m_ui->tableWidget->setRowCount(i+1);
    for (int x = 0; x <= 8; ++x) {
    QTableWidgetItem *it  = new QTableWidgetItem(0);
it->setFlags(Qt::ItemIsEnabled);
    it->setText (q.value(x).toString());

    m_ui->tableWidget->setItem(i, x, it);
}
i++;
}
m_ui->tableWidget->setSortingEnabled(true);
m_ui->tableWidget->sortByColumn(8);
}

void PlayerTable::on_actBonus_triggered()
{
    if (!m_ui->tableWidget->currentItem())
        return;
    bool ok;
    QTableWidgetItem *it =m_ui->tableWidget->item(m_ui->tableWidget->currentItem()->row(), 7);
    QTableWidgetItem *nick =m_ui->tableWidget->item(m_ui->tableWidget->currentItem()->row(), 0);
    int bonus = QInputDialog::getInt(this, "Бонус", "Введите бонус", it->text().toInt(), 0, 999999, 1,&ok);
    if (ok) {
   QSqlQuery q(QSqlDatabase::database("players"));
   q.prepare("UPDATE Rating SET bonus=:bonus WHERE nick=:nick");
q.bindValue(":bonus",   bonus);
q.bindValue(":nick", nick->text());
if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
 int points = ksyncPoints(nick->text());

   it->setText(QVariant(bonus).toString());
   m_ui->tableWidget->item(m_ui->tableWidget->currentItem()->row(), 8)->setText(QVariant(points).toString());
}
}
