#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QtGui>
#include "match.h"

namespace Ui {
    class EventDialog;
}

class EventDialog : public QDialog {
    Q_OBJECT
public:
    EventDialog(QWidget *parent, QStringList s, QStringList ch);
    ~EventDialog();
    QStringList getData();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::EventDialog *m_ui;
    int curIndex;
private slots:
    void on_cbAction_currentIndexChanged(int index);
};

#endif // EVENTDIALOG_H
