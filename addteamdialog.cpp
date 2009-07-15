#include "addteamdialog.h"
#include "ui_addteamdialog.h"
#include <QFile>
#include <QTextStream>
addTeamDialog::addTeamDialog(QWidget *parent, QStringList teams) :
    QDialog(parent),
    m_ui(new Ui::addTeamDialog)
{
    m_ui->setupUi(this);
    //получить доступные команды
    foreach (QString team, teams) {
        m_ui->cbTeams->addItem(team);
    }


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
    emit teamAdded(m_ui->txtPlayer->text(), m_ui->cbTeams->currentText());
}
