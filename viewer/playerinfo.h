#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QtGui>
#include "player.h"
#include "club.h"
namespace Ui {
    class PlayerInfo;
}

class PlayerInfo : public QDialog {
    Q_OBJECT
public:
    PlayerInfo(QWidget *parent, Player p, Club c) ;
    ~PlayerInfo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PlayerInfo *m_ui;
    void createTable (QString player, Club c);
};

#endif // PLAYERINFO_H
