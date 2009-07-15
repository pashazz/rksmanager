#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectmatchdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

}

MainWindow::~MainWindow()
{
    delete ui;
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
      // ui->tableWidget->setRowCount(ui->tableWidget->rowCount () + 1);
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

   loaded = true;
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
           ui->tableWidget->setItem(lst.indexOf(row), i, it);

       }

       }
   createMenus();
   setWindowTitle(tr("%1 - RKS Manager").arg(trn->title()));
   //set planning
ui->actPlanning->setText(tr("Спланировать тур: 1"));
loaded = true;
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
    //TODO


}

void MainWindow::on_actFont_triggered()
{
    bool ok;
   QFont font = QFontDialog::getFont(&ok, this);
   if (ok)
       ui->tableWidget->setFont(font);

}

void MainWindow::appendTable() {
    ui->tableWidget->clear();
    QStringList labels;
    labels << "Игрок" << "Команда" << "И" << "В" << "Н" << "П" << "MЗ" << "МП" << "Очки";
    QStringList lst = trn->getData(1).toStringList();
     ui->tableWidget->setRowCount(lst.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);
   foreach (QString row, lst) {

       QStringList data = row.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setText(data.at(i));
           ui->tableWidget->setItem(lst.indexOf(row), i, it);

       }

       }


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
