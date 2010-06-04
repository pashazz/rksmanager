#ifndef CUP_H
#define CUP_H
#include "league.h"
class Cup : public Tournament
{
public:
    Cup(QString dir,QString title, QString country, QStringList teams, QStringList gmrs, bool views);
    Cup (QString dir) :Tournament (dir) {finish = finished();}
  virtual  QString description() const {return "Кубок";}
virtual void addMatch(Match, int);
      virtual void addMatch(QString home, QString away, TechResult::Result res, int tour);
      virtual QVariant getData(int role);
     virtual bool checkPlanning(QString *message);
              virtual void writeResults();

      protected:

        virtual bool finished();
private:

      void drop(QString table);
};

#endif // CUP_H
