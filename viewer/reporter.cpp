#include "reporter.h"
#include "ui_reporter.h"

Reporter::Reporter(QWidget *parent, Tournament *t, int m) :
    QDialog(parent), mode (m), trn(t),
    m_ui(new Ui::Reporter)
{
    m_ui->setupUi(this);
    appendTable();
    m_ui->table->setSortingEnabled(true);
    }

Reporter::~Reporter()
{
    delete m_ui;
}

void Reporter::changeEvent(QEvent *e)
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

void Reporter::on_buttonBox_accepted()
{

}

void Reporter::on_table_customContextMenuRequested(QPoint pos)
{

}
void Reporter::onMenuClicked() {}
void Reporter::appendTable() {
       QStringList lst = trn->getData(mode).toStringList();
    QStringList labels;
    labels << "Игрок" << "Кол-во" << "Команда";
    switch (mode) {
      case 2:
        setWindowTitle("Голы");
        break;
      case 3:
        setWindowTitle("Желтые карточки");
        break;
     case 4:
        setWindowTitle("Красные карточки");
        break;
    }
    m_ui->table->setRowCount(lst.size());
    m_ui->table->setHorizontalHeaderLabels(labels);
foreach (QString row, lst) {
       QStringList data = row.split(";");
       for (int i = 0; i < data.count(); ++i) {
           QTableWidgetItem *it = new QTableWidgetItem (0);
           it->setFlags(Qt::ItemIsEnabled);
           it->setText(data.at(i));
           m_ui->table->setItem(lst.indexOf(row), i, it);

       }

       }
}
