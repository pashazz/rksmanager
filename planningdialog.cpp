#include "planningdialog.h"
#include "ui_planningdialog.h"

PlanningDialog::PlanningDialog(QWidget *parent, Tournament *t) :
    QDialog(parent),
    m_ui(new Ui::PlanningDialog)
{
    m_ui->setupUi(this);
    //set comboboxes
QList <Club> clubs = t->getClubs();
foreach (Club c, clubs) {
    avalPlayers.append(c.displayName);
    m_ui->cbHome->addItem (c.displayName);
   m_ui->cbGuest->addItem(c.displayName);
}
rowsNeed = t->getClubs().count();

     QString file = t->getWorkingDirectory() + "/planning.db";
    QFile f (file);
    if (!f.exists()) {f.open(QIODevice::WriteOnly);f.close();}
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "planning");
db.setDatabaseName(file);

currentTour = db.tables().count() + 1;
setWindowTitle(tr("Планирование"));
connect (m_ui->cbGuest, SIGNAL(currentIndexChanged(int)), this, SLOT(checkAddingPossible(int)));
connect (m_ui->cbHome, SIGNAL(currentIndexChanged(int)), this, SLOT(checkAddingPossible(int)));

}

PlanningDialog::~PlanningDialog()
{
    delete m_ui;
QSqlDatabase::removeDatabase("planning");
}

void PlanningDialog::changeEvent(QEvent *e)
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

void PlanningDialog::writeDB() {
//create db
        QSqlDatabase db = QSqlDatabase::database("planning");

table.append("Tour");
table.append(QVariant(currentTour).toString());
QSqlQuery q (db);
q.prepare("CREATE TABLE " +table+ " (id INTEGER PRIMARY KEY, home TEXT, away TEXT, played BOOLEAN)");
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   foreach (StringPair p, pairs) {
   q.prepare("INSERT INTO " +table + " (home, away, played) VALUES (:home, :away, :played)");

   q.bindValue(":home", p.first);
   q.bindValue(":away", p.second);
   q.bindValue(":played", false);
       if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   }
}

void PlanningDialog::on_btnAdd_clicked()
{

if( m_ui->cbHome->currentText() ==  m_ui->cbGuest->currentText()) {QMessageBox::warning(this, "", tr("Команды %1 и %2 совпадают").arg (m_ui->cbGuest->currentText(),m_ui->cbHome->currentText()));return;}

StringPair p;
p.first = m_ui->cbHome->currentText();
p.second = m_ui->cbGuest->currentText();
pairs.append(p);

 QTableWidgetItem *itHome = new QTableWidgetItem(m_ui->cbHome->currentText());

 m_ui->tblPairs->setRowCount(m_ui->tblPairs->rowCount() + 1);
 m_ui->tblPairs->setItem(m_ui->tblPairs->rowCount() -1, 0, itHome);
 QTableWidgetItem *itAway = new QTableWidgetItem(m_ui->cbGuest->currentText());
  m_ui->tblPairs->setItem(m_ui->tblPairs->rowCount() -1, 1, itAway);
  m_ui->cbHome->removeItem(m_ui->cbHome->currentIndex());
  m_ui->cbGuest->removeItem(m_ui->cbGuest->currentIndex());
  if (m_ui->tblPairs->rowCount() == rowsNeed)
      m_ui->buttonBox->setEnabled(true);
  else
            m_ui->buttonBox->setEnabled(false);

}


void PlanningDialog::on_buttonBox_accepted()
{
    writeDB();
}

void PlanningDialog::checkAddingPossible(int index) {
    Q_UNUSED(index)
            qDebug() << "on slot!";
        if (m_ui->cbHome->currentText() == m_ui->cbGuest->currentText())
        m_ui->btnAdd->setEnabled(false);
    else
        m_ui->btnAdd->setEnabled(true);
     //смотрим, может быть мы уже спланировали такой матч.
     QSqlDatabase db = QSqlDatabase::database("planning");
   QSqlQuery q (db);
   foreach (QString tb, db.tables()) {
q.prepare("SELECT COUNT (*) FROM "+tb+ " WHERE home=:home AND away=:away");
q.bindValue(":home", m_ui->cbHome->currentText());
q.bindValue(":away", m_ui->cbGuest->currentText());
 if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();close();}
   else {qDebug() << "Query done" << q.executedQuery();}
   while (q.next()) {
       if (q.value(0).toInt() > 0) {
       m_ui->btnAdd->setEnabled(false);
//hack
       if (m_ui->tblPairs->rowCount() == rowsNeed)
                  m_ui->btnAdd->setEnabled(false);

return;
       }
   }

   }

}
