#ifndef MATCHINFO_H
#define MATCHINFO_H
#include "player.h"
#include "match.h"
#include <QtGui>
#include <QtSql>
namespace Ui {
    class MatchInfo;
}

class MatchInfo : public QDialog {
    Q_OBJECT
public:
    MatchInfo(QWidget *parent, Match m);
    ~MatchInfo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MatchInfo *m_ui;
    Match *match;
private slots:
void viewPlayer (QListWidgetItem *it);

};

#endif // MATCHINFO_H
