#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectmatchdialog.h"
#include "changedialog.h"
#include "playertable.h"
#include "viewdialog.h"
#include "matchmodel.h"
#include "common.h"
#include "leaguetrn.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "matchinfo.h"
const QString config = "/.rks/state.ini";
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
//положние
QFile f(QDir::homePath() + config);
if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {qDebug() << "Config read error."; return;}
QByteArray state = f.readAll();
restoreState(state);
f.close();
ui->dockWidget_2->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase::removeDatabase("planning");
    QSqlDatabase::removeDatabase("players");
    QSqlDatabase::removeDatabase("history");
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
    if (dir.isEmpty()) {return;}
    if (!d.exists(dir + "/tour.db"))
    {
        QMessageBox::critical(this, "Ошибка", "Не найдена БД турнира");
          return;
            }
    QSettings stg(dir+"/settings.ini", QSettings::IniFormat, this);
    stg.beginGroup("Tournament");
    QString type = stg.value("type", "FUCK").toString();
    if (type =="league") {
trn = new League (dir);
}
    else if (type == "cup") {
       trn= new Cup(dir);
          }
QStringList lst = trn->getData(1).toStringList();
 appendTable();
   createMenus();
      setWindowTitle(tr("%1 - RKS Manager").arg(trn->title()));
      QString *message = new QString();
 if (trn->checkPlanning(message))
     ui->actPlanning->setText(tr("Спланировать: %1").arg(QVariant(*message).toString()));
else
    ui->mnuLeague->removeAction(ui->actPlanning);
ui->tableWidget->sortByColumn(8);

   loaded = true;
   createStatusBar();
}

void MainWindow::getTournament(Tournament *t) {

    trn = t;
appendTable();
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
    if (trn->description() == "Кубок") {
        model = new CupModel (this);
        model->setCup(dynamic_cast<Cup*> (trn));
        model->loadData();
        ui->tbCup->setModel(model);
        ui->dockWidget_2->setVisible(true);
    }
    else {
        ui->dockWidget_2->setVisible(false);

    }
}


void MainWindow::on_actPlay_triggered()
{
SelectMatchDialog *dlg = new SelectMatchDialog (this, trn);
dlg->exec();
appendTable();
}

void MainWindow::on_actPlanning_triggered()
{
    if (trn->description() == "Лига") {
    PlanningDialog *dlg = new PlanningDialog(this, trn);
    if (dlg->exec() == QDialog::Accepted) {
         QString *message = new QString();
 if (trn->checkPlanning(message))
     ui->actPlanning->setText(tr("Спланировать : %1").arg(*message));
else
    ui->mnuLeague->removeAction(ui->actPlanning);
}
    }
    else if (trn->description() == "Кубок") {
        planningCup(dynamic_cast<Cup*> (trn));
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
    setMatches();
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
str.append(QString (" Турнир: %1").arg(trn->description()));
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

void MainWindow::on_actAddPlayer_triggered()
{
    QStringList players;
    QSqlQuery sq(QSqlDatabase::database("players"));
   sq.prepare("SELECT nick FROM Rating");
    sq.exec();
   while (sq.next())
       players.append(sq.value(0).toString());
   QSqlQuery q;
   q.prepare("SELECT nick FROM Teams");
   q.exec();
   while (q.next())
       players.removeOne(q.value(0).toString());

       q.prepare("SELECT player FROM Changes");
   q.exec();
   while (q.next())
       players.removeOne(q.value(0).toString());

   if (!players.isEmpty()){
       bool ok;
      QString nick = QInputDialog::getItem(this, "Добавить игрока", "Выберите игрока", players, 0, false, &ok);
       if (ok)
           trn->addToChanges(nick);
   }

}


void MainWindow::setMatches() {
        MatchModel *model = new MatchModel (this);
       model->setTournament(trn);
       ui->tbMatches->setModel(model);
    }
void MainWindow::planningCup(Cup *cup)
{
    //юзаем random_shuffle :)
    QVector<QString> vec;
    foreach (Club c, cup->getClubs()) {
        vec.append(c.displayName);

    }
      typedef QPair <QString, QString> MatchPair;
    QList <MatchPair> pairs;
    srand(time(0));
std::random_shuffle(vec.begin(),vec.end());
for (int i = 0; i < vec.count(); i+=2) {
    QPair<QString, QString> pair;
    pair.first = vec.at(i);
    pair.second = vec.at(i+1);
    pairs.append(pair);
}
QString table;
switch (pairs.count()) {
        case 8:
        table = "Tour4";
        case 4:
        table = "Tour3";
        case 2:
        table  = "Tour2";
        case 1:
        table = "Tour1";
        default:
        qDebug() << "count of pairs is " << pairs.count() << "error!";

      }
QSqlQuery q(QSqlDatabase::database("planning"));
q.prepare("CREATE TABLE " +table+ " (id INTEGER PRIMARY KEY, home TEXT, away TEXT, played BOOLEAN)");
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   QPair <QString, QString> p;
   foreach (p, pairs) {
       q.prepare("INSERT INTO " + table + " (home, away, played) VALUES (:home, :away, :played)");
       q.bindValue(":home", p.first);
q.bindValue(":away", p.second);
q.bindValue(":played", false);
    if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   }
}

 void MainWindow::closeEvent(QCloseEvent *e) {
     QList<int> possibleTeams;
     possibleTeams << 0 << 1<< 2<< 4<< 8<< 16;

    QFile f (QDir::homePath() + config);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
   f.write(saveState());
   f.close();
   e->accept();
}

void MainWindow::on_tbMatches_clicked(QModelIndex index)
{
    if (index.row() == index.column()) {return;}
    QString hstr = ui->tbMatches->model()->headerData(index.row(), Qt::Horizontal, Qt::DisplayRole).toString();
    QString astr =ui->tbMatches->model()->headerData(index.column(), Qt::Vertical, Qt::DisplayRole).toString();
   QSqlQuery q;
   q.prepare("SELECT matchfile FROM Matches WHERE home=:home AND away=:away");
   q.bindValue(":home", hstr);
   q.bindValue(":away", astr);
     if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   if(!q.first()) {return;}
   QString matchfile = q.value(0).toString();
   Club home, away;
   foreach (Club c, trn->getClubs()) {
if (c.displayName == hstr)
    home = c;
if (c.displayName == astr)
    away = c;
}
   Match m = readToMatch(matchfile, home,away);
   MatchInfo *dlg = new MatchInfo(this, m);
   dlg->exec();
}

void MainWindow::on_actWrite_triggered()
{
    trn->writeResults();
}

void MainWindow::on_cmdProperties_clicked()
{

}
