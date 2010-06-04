#include "match.h"


bool Club::operator== (const Club& c) const {
    if (c.name == name && c.displayName == displayName && c.players == players)
        return true;
    else
        return false;

}

Player Club::getPlayer(int number)  {
    foreach (Player p, players) {
        if (p.number == number) {
            return p;
        }

    }

}

Player Club::getPlayer(QString name) {

    foreach (Player p, players) {
        if (p.name == name) {
            return p;
        }
}
}
