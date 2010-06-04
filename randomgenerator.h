#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <QtCore>
#include <QPair>
#include <QObject>
#include <QStringList>
    typedef QPair<QString,QString> pair;

class RandomGenerator : public QObject
{
public:
    RandomGenerator();
    static QList<pair> getTeams (QStringList players, QStringList teams);
 private:

};

#endif // RANDOMGENERATOR_H
