#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QtGui>
#include <QComboBox>
#include "league.h"
namespace Ui {
    class ChangeDialog;
}

class ChangeDialog : public QDialog {
    Q_OBJECT
public:
    ChangeDialog(QWidget *parent,Tournament *t);
    ~ChangeDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Tournament *trn;

    Ui::ChangeDialog *m_ui;
private slots:
    void on_buttonBox_accepted();
};

#endif // CHANGEDIALOG_H
