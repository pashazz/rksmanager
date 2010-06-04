#include "changedialog.h"
#include "ui_changedialog.h"

ChangeDialog::ChangeDialog(QWidget *parent, Tournament *t) :
    QDialog(parent), trn (t),
    m_ui(new Ui::ChangeDialog)
{
    m_ui->setupUi(this);
    m_ui->cbBefore->addItems (t->getGamers());
    m_ui->cbAfter->addItems (t->changeList());
  }

ChangeDialog::~ChangeDialog()
{
    delete m_ui;
}

void ChangeDialog::changeEvent(QEvent *e)
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

void ChangeDialog::on_buttonBox_accepted()
{
    if (!trn->makeChange(m_ui->cbBefore->currentText(), m_ui->cbAfter->currentText())) {
       QMessageBox::warning(this, "Ошибка при замене", "Ошибка запроса SQL");

    }
}
