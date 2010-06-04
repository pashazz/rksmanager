#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectmatchdialog.h"
#include "changedialog.h"
#include "playertable.h"
#include "viewdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        checkPlayers();
            qDebug() << "open database " ;

    //QSQLITE check
    if (!QSqlDatabase::drivers().contains("QSQLITE"))
    {
        QMessageBox::critical(this, "Ошибка", "Драйвер SQLite не найден, выход");
        qApp->exit(2);
    }
    //test

QDir dir = QDir::homePath() + "/.rks";
if (!dir.exists()) {dir.mkpath(QDir::homePath() + "/.rks/teams");}
ui->mnuLeague->setEnabled(false);
ui->mnuStats->setEnabled(false);
//временно
leag = true;
loaded = false;
ui->tableWidget->setSortingEnabled(true);
ui->tableWidget->sortByColumn(8);
//статусбар
infolabel = new QLabel (this);
statusBar()->addWidget(infolabel);
}

MainWindow::~MainWindow()
{
    delete ui;
     QSqlDatabase db = QSqlDatabase::database("player");
    db.close();
}

void MainWindow::on_actNew_triggered()
{
TourDialog *t = new TourDialog(this);
connect(t, SIGNAL(getTounament(Tournament*)), this, SLOT(getTournament(Tournament*)));
t->exec();
}

void MainWindow::on_actOpen_triggered()
{
    if (loaded) {

    }

    QString dir = QFileDialog::getExistingDirectory(this, "Выберите папку турнира", QDir::homePath(), QFileDialog::ShowDirsOnly);
    QDir d (dir);
    if (!d.exists(dir + "/tour.db"))
    {
        QMessageBox::critical(this, "Ошибка", "Не найдена БД турнира");
          return;
            }
trn = new Tournament (dir);
QStringList lst = trn->getData(1).toStringList();
   qDebug() << lst;
     ui->tableWidget->setRowCount(lst.size());

   foreach (QString row, lst) {
       QStringList data = row.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setFlags(Qt::ItemIsEnabled);
           it->setText(data.at(i));
           ui->tableWidget->setItem(lst.indexOf(row), i, it);

       }

       }





   createMenus();
      setWindowTitle(tr("%1 - RKS Manager").arg(trn->title()));
      QString *message = new QString();
 if (trn->checkPlanning(message))
     ui->actPlanning->setText(tr("Спланировать тур: %1").arg(QVariant(*message).toString()));
else
    ui->mnuLeague->removeAction(ui->actPlanning);
ui->tableWidget->sortByColumn(8);

   loaded = true;
   createStatusBar();
}

void MainWindow::getTournament(Tournament *t) {

    trn = t;
   QStringList lst = trn->getData(1).toStringList();
     ui->tableWidget->setRowCount(lst.size());

   foreach (QString row, lst) {

       QStringList data = row.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setText(data.at(i));
           it->setFlags(Qt::ItemIsEnabled);
           ui->tableWidget->setItem(lst.indexOf(row), i, it);

       }

       }
   createMenus();
   setWindowTitle(tr("%1 - RKS Manager").arg(trn->title()));
   //set planning
ui->actPlanning->setText(tr("Спланировать тур: 1"));
loaded = true;ui->tableWidget->sortByColumn(8);

createStatusBar();
   }



void MainWindow::on_actExit_triggered()
{
    close();
}

void MainWindow::on_actHelp_triggered()
{
       AboutDialog *dlg = new AboutDialog(this);
       dlg->exec();
}


void MainWindow::createMenus() {
    ui->mnuLeague->setEnabled(true);
    ui->mnuStats->setEnabled(true);
    ui->actView->setEnabled(trn->isViewsEnabled());
    ui->actManageViews->setEnabled(trn->isViewsEnabled());
}


void MainWindow::on_actPlay_triggered()
{
SelectMatchDialog *dlg = new SelectMatchDialog (this, trn);
dlg->exec();
appendTable();
}

void MainWindow::on_actPlanning_triggered()
{
    if (leag) {
    PlanningDialog *dlg = new PlanningDialog(this, trn);
    if (dlg->exec() == QDialog::Accepted) {
         QString *message = new QString();
 if (trn->checkPlanning(message))
     ui->actPlanning->setText(tr("Спланировать тур: %1").arg(*message));
else
    ui->mnuLeague->removeAction(ui->actPlanning);
}
    }
}



void MainWindow::on_actColor_triggered()
{

}

void MainWindow::on_actFont_triggered()
{
    bool ok;
   QFont font = QFontDialog::getFont(&ok, this);
   if (ok)
       ui->tableWidget->setFont(font);

}

void MainWindow::appendTable(bool v) {
    int n;
if (v)
    n = 5;
else
    n = 1;
    ui->tableWidget->clear();
    QStringList labels;
    labels << "Игрок" << "Команда" << "И" << "В" << "Н" << "П" << "MЗ" << "МП" << "Очки";
    QStringList lst = trn->getData(n).toStringList();
     ui->tableWidget->setRowCount(lst.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
   foreach (QString row, lst) {

       QStringList data = row.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setFlags(Qt::ItemIsEnabled);
           it->setText(data.at(i));
           ui->tableWidget->setItem(lst.indexOf(row), i, it);

       }

       }
ui->tableWidget->sortByColumn(8);
createStatusBar();
}

void MainWindow::on_actGoleadors_triggered()
{
    Reporter *dlg = new Reporter(this, trn, 2);
    dlg->exec();
}

void MainWindow::on_actYellow_triggered()
{
     Reporter *dlg = new Reporter(this, trn, 3);
    dlg->exec();
}

void MainWindow::on_actRed_triggered()
{
      Reporter *dlg = new Reporter(this, trn, 4);
    dlg->exec();
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem* item)
{
    QTableWidgetItem *it = ui->tableWidget->item(item->row(), 1);
    if (!it) {return;}
    Club club;
    foreach (Club c, trn->getClubs())
    {
        if (c.displayName == it->text()) {club = c;}
    }
    if (club.name.isEmpty()) {qDebug() << "Club not found!"; return;}
    TeamInfo *dlg = new TeamInfo (this, club, ui->tableWidget->item(item->row(), 0)->text(), trn);
    dlg->exec();
}

void MainWindow::createStatusBar() {
   QString str;
    str.append("Матчей:");
    QSqlQuery q;
    q.prepare("SELECT COUNT (*) FROM Matches");
    q.exec();
    q.first();
    str.append(q.value(0).toString());
    str.append("  Команд: ");
      q.prepare("SELECT COUNT (*) FROM Teams");
    q.exec();
    q.first();
    str.append(q.value(0).toString());
    str.append("  Дисквалификаций:");
   q.prepare("SELECT COUNT (*) FROM Skips");
    q.exec();
    q.first();
    str.append(q.value(0).toString());

   str.append(" Запасных: ");
    q.prepare("SELECT COUNT (*) FROM Changes");
    q.exec();
    q.first();
    str.append(q.value(0).toString());

    infolabel->setText(str);
}

void MainWindow::on_actChange_triggered()
{
    ChangeDialog *dlg = new ChangeDialog (this, trn);
    if (dlg->exec() == QDialog::Accepted) {
        appendTable();
    }

}

void MainWindow::on_actPlayers_triggered()
{
PlayerTable *dlg = new PlayerTable(this);
dlg->exec();
}
void MainWindow::checkPlayers() {
            qDebug() << "open database " ;

    QFile f(QDir::homePath() + "/.rks/players.db");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "players");
           db.setDatabaseName(f.fileName());

    if (!f.exists()) {
        //create
        qDebug() << "open database " << db;
        if (!db.open()) {QMessageBox::critical(this, "Критическая ошибка!",  db.lastError().text());}

    QSqlQuery q (db);
q.prepare("CREATE TABLE Players (id INTEGER PRIMARY KEY, smallname TEXT, nick TEXT, name TEXT)");
q.exec();
q.prepare("CREATE TABLE Rating (id INTEGER PRIMARY KEY, nick TEXT, matches INTEGER, win INTEGER,  draw INTEGER, lose INTEGER, tp INTEGER,  unreg INTEGER, bonus INTEGER, points INTEGER)");
q.exec();
db.close();
    }

            if (!db.open()) {QMessageBox::critical(this, "Критическая ошибка!",  db.lastError().text());}
}



void MainWindow::on_actView_triggered(bool checked)
{
appendTable(checked);
}
void MainWindow::appendTable() {
    appendTable(false);
}

void MainWindow::on_actManageViews_triggered()
{
    ViewDialog *dlg = new ViewDialog(this, trn);
    dlg->exec();
}
