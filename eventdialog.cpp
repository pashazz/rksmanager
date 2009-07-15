#include "eventdialog.h"
#include "ui_eventdialog.h"

EventDialog::EventDialog(QWidget *parent, QStringList s, QStringList ch) :
    QDialog(parent),
    m_ui(new Ui::EventDialog)
{
    m_ui->setupUi(this);
    m_ui->cbPlayer->addItems(s);
    m_ui->cbChange->addItems(ch);
    curIndex = 0;
}

EventDialog::~EventDialog()
{
    delete m_ui;
}

void EventDialog::changeEvent(QEvent *e)
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
/*!
  коды событий:
  0 - гол
  1 - ЖК
  2 - КК
  3 - травма
  4 - замена
  */
QStringList EventDialog::getData() {
    QStringList data;
    data.append(m_ui->cbPlayer->currentText());
    if (curIndex == 0) {curIndex = 5;}
    qDebug() << curIndex;
    data.append(QVariant(curIndex).toString());
    if (m_ui->cbAction->currentIndex() == 4)
        data.append(m_ui->cbChange->currentText());
    return data;
}

void EventDialog::on_cbAction_currentIndexChanged(int index)
{
    curIndex = index;
    if (index == 4) {
        m_ui->cbChange->setEnabled(true);
     }
    else {
                m_ui->cbChange->setEnabled(false);

    }
}
