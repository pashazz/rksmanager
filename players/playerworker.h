#ifndef PLAYERWORKER_H
#define PLAYERWORKER_H

#include <QObject>
#include <QtSql>
class PlayerWorker : public QObject
{
public:
    PlayerWorker();
    static void tp(QString nick);
    static void win (QString nick);
    static void unreg (QString nick);
    static void lose (QString nick);
    static void draw (QString nick);
static void addPlayer (QString  nick, QString name, QString table);
};

#endif // PLAYERWORKER_H
