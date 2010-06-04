#include "tourdialog.h"
#include "ui_tourdialog.h"
#include "bonusmap.h"
#include "cup.h"
#include "leaguetrn.h"
TourDialog::TourDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::TourDialog)
{
    //сначала выводим диалог с папками
    dir = QFileDialog::getExistingDirectory(this, tr("Выберите папку для турнира"), QDir::homePath(), QFileDialog::ShowDirsOnly);
    if (dir.isEmpty()) {close();}
    m_ui->setupUi(this);
    appendBoxes();
}

TourDialog::~TourDialog()
{
    delete m_ui;
}

void TourDialog::changeEvent(QEvent *e)
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
void TourDialog::appendBoxes (){
    m_ui->cbType->addItem(tr("Лига"));
    m_ui->cbType->addItem("Кубок");
    //получить страны
    QDir confdir = QDir::homePath() +"/.rks/teams";
    qDebug() << confdir;
    foreach (QString country, confdir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        m_ui->cbCountry->addItem(country.at(0).toUpper() + country.right(country.count() -1));
        countries.append( confdir.path() + "/" + country);
    }

m_ui->cbViews->addAction(QWhatsThis::createAction(m_ui->cbViews));
//Also append players
QSqlDatabase db = QSqlDatabase::database("players");
QSqlQuery q(db);
q.prepare("SELECT nick FROM players");
q.exec();
while (q.next())
    gamers << q.value(0).toString();
}
QStringList TourDialog::getTeams(QString dir) {
    QDir d (dir);
    QString team;
    QStringList l;
    foreach (team, d.entryList(QDir::Files | QDir::NoDotAndDotDot)) {
        l << d.path() + "/" +
                team;

    }
    return l;
}

void TourDialog::on_buttonBox_accepted()
{
    if (m_ui->cbType->currentIndex()  == 0) {
    if (teams.count() < 2) {QMessageBox::warning(this, "WARNING!", "мало игроков!");    setResult(QDialog::Rejected); return;}
    Tournament *t = new League(dir, m_ui->txtName->text(), m_ui->cbCountry->currentText(), teams, players, m_ui->cbViews->isChecked());
    t->setChangeList(changes);
    emit getTounament(t);
}
    else if (m_ui->cbType->currentIndex() == 1) {
        QList <int> possibleTeams;
        possibleTeams <<2 << 4 << 8 << 16;
        if (!possibleTeams.contains(teams.count())) {
            QMessageBox::warning(this, "Ошибка", tr("Недопустимое кол-во команд: %1").arg(teams.count()));
            setResult(QDialog::Rejected);
            return;
         }
        qDebug() << "adding cup!";
        Cup    *t = new Cup(dir, m_ui->txtName->text(), m_ui->cbCountry->currentText(), teams, players, m_ui->cbViews->isChecked());
        t->setChangeList(changes);
    emit getTounament(t);
    }
}

void TourDialog::onTeam(QString nick, QString team) {
 //   qDebug() << nick << team;
    players<<nick;
    teams << team;
    avalTeams.removeAt(avalTeams.indexOf(team));
    gamers.removeOne(nick);

QListWidgetItem *item = new QListWidgetItem(nick, m_ui->lstPlayers);
item->setData(Qt::UserRole, team);
}
void TourDialog::on_cmdNew_clicked()
{

  //формируем список команд
   addTeamDialog *dlg = new addTeamDialog(this, avalTeams, gamers);
   connect(dlg, SIGNAL(teamAdded(QString,QString)), this, SLOT(onTeam(QString,QString)));
   dlg->exec();
}

void TourDialog::on_cmdOK_clicked()
{
    m_ui->cmdOK->setEnabled(false);
    m_ui->cbCountry->setEnabled(false);
    m_ui->cmdNew->setEnabled(true);
    m_ui->buttonBox->setEnabled(true);
    //формируем список команд

    QStringList files = getTeams(countries.at(m_ui->cbCountry->currentIndex()));
    foreach (QString file, files) {
       QFile f (file);
       if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {qDebug() << "Warning: cannot open file: " + f.fileName() << f.errorString();}
       QTextStream in (&f);
       QStringList data = in.readLine().split(",");
       avalTeams << data.at(0);
    }
}

void TourDialog::on_lstPlayers_itemChanged(QListWidgetItem* item)
{
   // m_ui->lblTeam->setText(item->data(Qt::UserRole).toString());
}

void TourDialog::on_lstPlayers_itemClicked(QListWidgetItem* item)
{
        m_ui->lblTeam->setText(item->data(Qt::UserRole).toString());

}

void TourDialog::on_cmdChange_clicked()
{
    QString nick = QInputDialog::getItem(this, "Замена", "Выберите игрока", gamers);
    if (nick.isEmpty()) {return;}
    changes.append(nick);
    m_ui->lstChange->addItem(nick);
    gamers.removeOne(nick);}

void TourDialog::on_cmdBonus_clicked()
{
BonusMap *dlg = new BonusMap(this, dir);
dlg->exec();

}

