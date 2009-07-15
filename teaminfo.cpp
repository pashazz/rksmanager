#include "teaminfo.h"
#include "ui_teaminfo.h"

TeamInfo::TeamInfo(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::TeamInfo)
{
    m_ui->setupUi(this);
}

TeamInfo::~TeamInfo()
{
    delete m_ui;
}

void TeamInfo::changeEvent(QEvent *e)
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
