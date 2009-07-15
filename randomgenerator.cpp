#include "randomgenerator.h"
#include <algorithm>
#include <QVector>
#include <ctime>
#include <cstdlib>
RandomGenerator::RandomGenerator()
{
}

QList<pair> RandomGenerator::getTeams(QStringList players, QStringList teams) {
QVector<QString> pl = players.toVector();
QVector<QString> tms = teams.toVector();
srand (time(0));
std::random_shuffle (pl.begin(), pl.end());
std::random_shuffle(tms.begin(), tms.end());
QList<pair> pairs;
for (int i = 0; i < pl.count(); ++i) {
    pair p;
    p.first = pl.at(i);
    p.second = tms.at(i);
    pairs.append(p);
}
qDebug() << pairs;
return pairs;
}


