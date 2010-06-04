#ifndef SELECTMATCHDIALOG_H
#define SELECTMATCHDIALOG_H
#include "addmatchdialog.h"
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
     void createMenus();
     QMenu *tp;
     QListWidgetItem *current;
private slots:
    void on_lstMatches_itemPressed(QListWidgetItem* item);
    void on_lstMatches_itemChanged(QListWidgetItem* item);
    void on_lstMatches_customContextMenuRequested(QPoint pos);
    void on_lstMatches_itemClicked(QListWidgetItem* item);
    void on_lstMatches_itemDoubleClicked(QListWidgetItem* item);
    void on_sbTours_valueChanged(int );
    void onTP(QAction *act);

};

#endif // SELECTMATCHDIALOG_H
