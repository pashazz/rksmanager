#include "playerinfo.h"
#include "ui_playerinfo.h"
#include "imageprovider.h"

PlayerInfo::PlayerInfo(QWidget *parent, Player p, Club c) :
    QDialog(parent),
    m_ui(new Ui::PlayerInfo)
{
    m_ui->setupUi(this);
    //построение таблицы
m_ui->lblTeam->setPixmap(ImageProvider::getClubEmblem(c.name));
QString str;
str.append(p.name + "(");
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
str.append(emploi);
str.append(")");
m_ui->lblPlayer->setText(str);
createTable(p.name, c);
}

PlayerInfo::~PlayerInfo()
{
    delete m_ui;
}

void PlayerInfo::changeEvent(QEvent *e)
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

void PlayerInfo::createTable( QString player, Club c) {
     QSqlQuery q;
     int gamesHome  = 0;
     int gamesAway = 0;
     int changesHome = 0;
     int chAway = 0;

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
     mq.bindValue(":player", player);

      mq.exec();
     if( mq.first())
      gamesHome += mq.value(0).toInt();
     mq.prepare("SELECT COUNT(*) FROM AwayStart WHERE player=:player");
     mq.bindValue(":player", player);
      mq.exec();
    if(  mq.first())
      gamesAway += mq.value(0).toInt();

      mq.prepare("SELECT COUNT (*) FROM HomeChanges WHERE pon=:player");
     mq.bindValue(":player", player);
      mq.exec();
qDebug() << "Change error: " << mq.lastError().text();
while (mq.next())
    changesHome += mq.value(0).toInt();

      mq.prepare("SELECT COUNT (*) FROM AwayChanges WHERE pon=:player");
     mq.bindValue(":player", player);
      mq.exec();
qDebug() << "Change error: " << mq.lastError().text();
while (mq.next())
    chAway += mq.value(0).toInt();

   db.close();
}

QTableWidgetItem *itGamesHome = new QTableWidgetItem (0);
itGamesHome->setText(QVariant(gamesHome).toString());
itGamesHome->setFlags(Qt::ItemIsEnabled);
m_ui->tableWidget->setItem(0, 0, itGamesHome);

QTableWidgetItem *itGamesAway = new QTableWidgetItem (0);
itGamesAway->setText(QVariant(gamesAway).toString());
itGamesAway->setFlags(Qt::ItemIsEnabled);
m_ui->tableWidget->setItem(1, 0, itGamesAway);

QTableWidgetItem *itGames = new QTableWidgetItem (0);
itGames->setText(QVariant(gamesAway + gamesHome).toString());
itGames->setFlags(Qt::ItemIsEnabled);
m_ui->tableWidget->setItem(2, 0, itGames);

QTableWidgetItem *itChangesHome = new QTableWidgetItem (0);
itChangesHome->setText(QVariant(changesHome).toString());
itChangesHome->setFlags(Qt::ItemIsEnabled);
m_ui->tableWidget->setItem(0, 1, itChangesHome);

QTableWidgetItem *itChangesAway = new QTableWidgetItem (0);
itChangesAway->setText(QVariant(chAway).toString());
itChangesAway->setFlags(Qt::ItemIsEnabled);
m_ui->tableWidget->setItem(1, 1, itChangesAway);

QTableWidgetItem *itChanges = new QTableWidgetItem (0);
itChanges->setText(QVariant(chAway +changesHome).toString());
itChanges->setFlags(Qt::ItemIsEnabled);
m_ui->tableWidget->setItem(2, 1, itChanges);



}

