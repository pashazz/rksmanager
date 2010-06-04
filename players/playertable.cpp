#include "playertable.h"
#include "ui_playertable.h"
#include "addprofiledialog.h"
PlayerTable::PlayerTable(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::PlayerTable)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "players");
    db.setDatabaseName(QDir::homePath() + "/.rks/players.db");
    m_ui->setupUi(this);
    m_ui->tableWidget->addAction(m_ui->actAdd);
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
