#ifndef Tournament_H
#define Tournament_H
#include <QtSql>
#include "club.h"
namespace TechResult {
    enum Result {
      HomeWin = 1,
      Draw = 2,
      AwayWin = 3
    };

}
class Tournament : public QObject
{

public:
    Tournament(QString dir, QString title, QString country, QStringList teams, QStringList gmrs);
    Tournament() {qDebug() << "emty";}
Tournament(QString dir); //загрузка турнира
    QList<Club> getClubs () const {return clubs;}
    QList <Match> getMatches()const {return matches;}
    QStringList getGamers() const {return gamers;}
    QString title () const {return _title;}
    QString getWorkingDirectory () const {return workdir;}
  virtual QVariant getData(int role);
 virtual  void finalize();
  virtual void addMatch ( Match m, int tour);
  //виды ТП
  virtual void addMatch(QString home, QString away, TechResult::Result res, int tour);
  virtual  ~Tournament();
 virtual bool checkPlanning(QString *message);
    void checkSkips (QString home, QString away);
protected:
QList <Club> clubs;
QList <Match> matches;
QString _title;
Emploi toEmploi (QString str);
QString workdir;
QStringList gamers;
QList <Player> getPlayers(QString str);
QString getMatches(QString team) ;
void loadMatches();
private:

};
#endif // Tournament_H
