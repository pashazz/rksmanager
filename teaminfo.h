#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QtGui/QDialog>

namespace Ui {
    class TeamInfo;
}

class TeamInfo : public QDialog {
    Q_OBJECT
public:
    TeamInfo(QWidget *parent = 0);
    ~TeamInfo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TeamInfo *m_ui;
};

#endif // TEAMINFO_H
