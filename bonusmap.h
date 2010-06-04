#ifndef BONUSMAP_H
#define BONUSMAP_H

#include <QtGui>

namespace Ui {
    class BonusMap;
}

class BonusMap : public QDialog {
    Q_OBJECT
public:
    BonusMap(QWidget *parent, QString dir, bool league=true);
    ~BonusMap();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BonusMap *m_ui;
    QMap <int, int> map;
    QString dir;
    int convert (QString text);
    bool isLeague;
private slots:
    void on_cbCup_currentIndexChanged(QString );
    void on_buttonBox_accepted();
    void on_pushButton_clicked();
    void on_sbRank_valueChanged(int );
    void on_tableWidget_activated(QModelIndex index);
};

#endif // BONUSMAP_H
