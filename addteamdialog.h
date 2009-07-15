#ifndef ADDTEAMDIALOG_H
#define ADDTEAMDIALOG_H

#include <QtGui>

namespace Ui {
    class addTeamDialog;
}

class addTeamDialog : public QDialog {
    Q_OBJECT
public:
    addTeamDialog(QWidget *parent, QStringList teams);
    ~addTeamDialog();
signals:
    void teamAdded (QString nick, QString team);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::addTeamDialog *m_ui;
private slots:
    void on_buttonBox_accepted();
};

#endif // ADDTEAMDIALOG_H
