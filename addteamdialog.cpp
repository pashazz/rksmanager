#include "addteamdialog.h"
#include "ui_addteamdialog.h"
#include <QFile>
#include <QTextStream>
addTeamDialog::addTeamDialog(QWidget *parent, QStringList teams, QStringList players) :
    QDialog(parent),
    m_ui(new Ui::addTeamDialog)
{
    m_ui->setupUi(this);
    //получить доступные команды
    m_ui->cbTeams->addItems(teams);
    m_ui->cbPlayer->addItems(players);


}

addTeamDialog::~addTeamDialog()
{
    delete m_ui;
}

void addTeamDialog::changeEvent(QEvent *e)
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

void addTeamDialog::on_buttonBox_accepted()
{
    emit teamAdded(m_ui->cbPlayer->currentText(), m_ui->cbTeams->currentText());
}
