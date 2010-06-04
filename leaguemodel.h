#ifndef LEAGUEMODEL_H
#define LEAGUEMODEL_H
#include "league.h"


class LeagueModel : public QAbstractTableModel
{
public:
    LeagueModel(QObject *parent) :QAbstractTableModel(parent){views = false;}
    bool hasChildren(const QModelIndex &parent) const {return !parent.isValid();}
    void setViews (bool v) {this->views = v;}
    QVariant headerData (int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)  const{return 8;}
    int columnCount(const QModelIndex &parent) const {return teams.count();}
    Qt::ItemFlags flags (const QModelIndex &index) const {return Qt::ItemIsEnabled;}
    void loadData();
    void setTournament(Tournament *trn);
  private:
 QList<QStringList> teams;
 Tournament *t;
 bool views;
 QString getMatches (QString);
};

#endif // LEAGUEMODEL_H
