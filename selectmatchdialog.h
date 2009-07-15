#ifndef SELECTMATCHDIALOG_H
#define SELECTMATCHDIALOG_H
#include "viewer/addmatchdialog.h"
#include <QtGui>
#include <QtSql>
#include "league.h"

namespace Ui {
    class SelectMatchDialog;
}

class SelectMatchDialog : public QDialog {
    Q_OBJECT
public:
    SelectMatchDialog(QWidget *parent, Tournament *t);
    ~SelectMatchDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SelectMatchDialog *m_ui;
    void loadMatches(int );
    Tournament *trn;
     short int currentTour;
private slots:
    void on_lstMatches_itemClicked(QListWidgetItem* item);
    void on_lstMatches_itemDoubleClicked(QListWidgetItem* item);
    void on_sbTours_valueChanged(int );
};

#endif // SELECTMATCHDIALOG_H
