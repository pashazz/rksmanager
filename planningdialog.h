#ifndef PLANNINGDIALOG_H
#define PLANNINGDIALOG_H

#include <QtGui>
#include <QtSql>
#include "league.h"
namespace Ui {
    class PlanningDialog;
}
typedef QPair <QString, QString> StringPair;
class PlanningDialog : public QDialog {
    Q_OBJECT
public:
    PlanningDialog(QWidget *parent, Tournament *t);
    ~PlanningDialog();
    int tour () const {return currentTour;}
protected:
    void changeEvent(QEvent *e);

private:
    Ui::PlanningDialog *m_ui;
    void appendBoxes();
    QStringList avalPlayers;
    QList <StringPair> pairs;
    void writeDB();
    QString table;
    int rowsNeed;
    int currentTour;
    QStringList planned;
private slots:
    void on_buttonBox_accepted();
    void on_btnAdd_clicked();

    void checkAddingPossible(int index);
};

#endif // PLANNINGDIALOG_H
