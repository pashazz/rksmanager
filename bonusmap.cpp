#include "bonusmap.h"
#include "ui_bonusmap.h"

BonusMap::BonusMap(QWidget *parent, QString dir, bool league) :
    QDialog(parent), isLeague(league),
    m_ui(new Ui::BonusMap)
{
    m_ui->setupUi(this);
    this->dir = dir;
    if (isLeague)
        m_ui->cbCup->setEnabled(false);
    else
        m_ui->sbRank->setEnabled(false);
}

BonusMap::~BonusMap()
{
    delete m_ui;
}

void BonusMap::changeEvent(QEvent *e)
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

void BonusMap::on_tableWidget_activated(QModelIndex index)
{

}

void BonusMap::on_sbRank_valueChanged(int i)
{
    if (map.contains(i))
        m_ui->sbBonus->setValue(map.value(i));


    else
        m_ui->sbBonus->setValue(0);

    m_ui->pushButton->setEnabled(!map.contains(i));
    m_ui->sbBonus->setEnabled(!map.contains(i));
}

void BonusMap::on_pushButton_clicked()
{
    int rank;
    if (isLeague)
        rank = m_ui->sbRank->value();
    else
        rank = convert(m_ui->cbCup->currentText());
    if (map.keys().contains(rank))
        return;
    QTableWidgetItem *itRank = new QTableWidgetItem (0);
    itRank->setText(QVariant(rank).toString());
    itRank->setFlags(Qt::ItemIsEnabled);
    m_ui->tableWidget->setRowCount(m_ui->tableWidget->rowCount() + 1);
    m_ui->tableWidget->setItem(m_ui->tableWidget->rowCount() -1, 0, itRank);
    QTableWidgetItem *itBonus = new QTableWidgetItem (0);

    itBonus->setText(QVariant(m_ui->sbBonus->value()).toString());
    itBonus->setFlags(Qt::ItemIsEnabled);

    m_ui->tableWidget->setItem(m_ui->tableWidget->rowCount() -1, 1, itBonus);
    map.insert(rank, m_ui->sbBonus->value());
}

void BonusMap::on_buttonBox_accepted()
{
    //записываем bonusmap
    qDebug() << "writing bonusmap!" << dir +"/bonus.ini";
    QFile f (dir+"/bonus.ini");
    f.open(QIODevice::WriteOnly);f.close();
            QSettings stg(dir+"/bonus.ini", QSettings::IniFormat, this);

    foreach (int key, map.keys()) {
stg.setValue(QVariant(key).toString(),   map.value(key));

    }
    stg.sync();
}

void BonusMap::on_cbCup_currentIndexChanged(QString s)
{
    int i = convert(s);
        if (map.contains(i))
        m_ui->sbBonus->setValue(map.value(i));
   else
        m_ui->sbBonus->setValue(0);

    m_ui->pushButton->setEnabled(!map.contains(i));
    m_ui->sbBonus->setEnabled(!map.contains(i));
}

int BonusMap::convert(QString text)
{
    if (text == "Финал")
        return 1;
    else if (text == "Чемпион")
        return 0;
    else if (text == "Полуфинал")
        return 2;
else if (text == "Четвертьфинал")
    return 3;

}
