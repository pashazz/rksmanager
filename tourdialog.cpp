#include "tourdialog.h"
#include "ui_tourdialog.h"

TourDialog::TourDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::TourDialog)
{
    //сначала выводим диалог с папками
    dir = QFileDialog::getExistingDirectory(this, tr("Выберите папку для турнира"), QDir::homePath(), QFileDialog::ShowDirsOnly);
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
    //получить страны
    QDir confdir = QDir::homePath() +"/.rks/teams";
    qDebug() << confdir;
    foreach (QString country, confdir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        m_ui->cbCountry->addItem(country.at(0).toUpper() + country.right(country.count() -1));
        countries.append( confdir.path() + "/" + country);

    }


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
    Tournament *t = new Tournament(dir, m_ui->txtName->text(), m_ui->cbCountry->currentText(), teams, players);
    emit getTounament(t);

}

void TourDialog::onTeam(QString nick, QString team) {
 //   qDebug() << nick << team;
    players<<nick;
    teams << team;
    avalTeams.removeAt(avalTeams.indexOf(team));
QListWidgetItem *item = new QListWidgetItem(nick, m_ui->lstPlayers);
item->setData(Qt::UserRole, team);
}
void TourDialog::on_cmdNew_clicked()
{

  //формируем список команд
   addTeamDialog *dlg = new addTeamDialog(this, avalTeams);
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
