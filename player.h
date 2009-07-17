#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

enum Emploi {
    Goalkeeper = 1, Defender = 2, Middefender = 3, Forward =4
};
struct PlayerStatistics {
    int redCards;
    int YellowCards;
    int goals;
    int skippingMatches;
    int traumas;
};
struct Player {
    bool operator==( Player p) {
        if (p.number == number && p.name == name) {//этого достаточно
            return true;
        } else {return false;}

     }
    int number;
    QString name;
    Emploi emploi;
    PlayerStatistics stats;
};


#endif // PLAYER_H
