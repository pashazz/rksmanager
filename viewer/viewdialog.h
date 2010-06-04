#ifndef VIEWDIALOG_H
#define VIEWDIALOG_H

#include <QtGui>
#include "league.h"
#include "view.h"
namespace Ui {
    class ViewDialog;
}

class ViewDialog : public QDialog {
    Q_OBJECT
public:
    ViewDialog(QWidget *parent, Tournament *t);
    ~ViewDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ViewDialog *m_ui;
    Tournament *trn;

private slots:
    void on_lstViews_currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous);
    void on_pushButton_clicked();
    void on_cmdAdd_clicked();
};

#endif // VIEWDIALOG_H
