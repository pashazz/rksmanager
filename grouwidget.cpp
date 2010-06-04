#include "grouwidget.h"
#include "ui_grouwidget.h"

grouwidget::grouwidget(QWidget *parent) :
    QTabWidget(parent),
    m_ui(new Ui::grouwidget)
{
    m_ui->setupUi(this);
}

grouwidget::~grouwidget()
{
    delete m_ui;
}

void grouwidget::changeEvent(QEvent *e)
{
    QTabWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
