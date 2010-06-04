#ifndef Tournament_H
#define Tournament_H
#include <QtSql>
#include "club.h"
#include "view.h"
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
    Tournament(QString dir, QString title, QString country, QStringList teams, QStringList gmrs, bool views);
    Tournament() {qDebug() << "emty";}
Tournament(QString dir); //загрузка турнира
    QList<Club> getClubs () const {return clubs;}
    QList <Match> getMatches()const {return matches;}
    QStringList getGamers() const {return gamers;}
    QString title () const {return _title;}
    QString getWorkingDirectory () const {return workdir;}
  virtual QVariant getData(int role); //будет заменено скоро на модели
 virtual  void finalize();
  virtual void addMatch ( Match m, int tour) = 0;
  //виды ТП
  virtual void addMatch(QString home, QString away, TechResult::Result res, int tour) = 0;
  virtual  ~Tournament();
  void addView (QString name, QList <Club> c);
  void removeView (View v);
  QList <View> views () const {return this->view;}
 virtual bool checkPlanning(QString *message) = 0;
    void checkSkips (QString home, QString away);
    void setChangeList (QStringList lst);
    QStringList changeList () const {return changes;}
    bool isViewsEnabled () const {return _view;}
    bool makeChange (QString before, QString after);
    bool isFinished() const {return finish;}
    virtual QString description ()  const = 0;
    void addToChanges (QString nick);
    //virtual LeagueModel model() const {return mdl;}
        virtual void writeResults () = 0;

protected:
    virtual bool finished() = 0;
    void doAddMatch (Match, int);
    void doAddMatch (QString home, QString away, TechResult::Result res, int tour) ;
    int syncPoints (QString nick);
QList <Club> clubs;
QList <Match> matches;
QString _title;
Emploi toEmploi (QString str);
QString workdir;
QStringList gamers;
QList <Player> getPlayers(QString str);
QString getMatches(QString team) ;
void loadMatches();
void loadViews();
QString getNick(QString);
QStringList changes;
QList <View> view;
bool _view;
bool finish;
QMap <int, int> bonuses;
private:
};
#endif // Tournament_H
