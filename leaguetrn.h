#ifndef LEAGUETRN_H
#define LEAGUETRN_H
#include "league.h"
class League : public Tournament
{
public:
    League(QString dir) :Tournament(dir) {}
    League (QString dir, QString title, QString country, QStringList teams, QStringList gmrs, bool views);
    void addMatch(QString home, QString away, TechResult::Result res, int tour)
    {doAddMatch(home, away, res, tour);
    finish = finished();

    }
    void addMatch(Match m, int tour) {doAddMatch(m, tour);
    finish = finished();

    }
    QString description () const {return "Лига";}
    virtual bool checkPlanning(QString *message);
        virtual void writeResults();

 protected:
    virtual bool finished();


};

#endif // LEAGUETRN_H
