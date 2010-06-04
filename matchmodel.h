#ifndef MATCHMODEL_H
#define MATCHMODEL_H

#include <QtGui>
#include "league.h"
class MatchModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MatchModel(QObject *parent  =0);
    ~MatchModel() {}
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
 QVariant headerData(int section,Qt::Orientation orientation, int role) const;
 Qt::ItemFlags flags (const QModelIndex& parent = QModelIndex()) const;
 QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
  bool hasChildren(const QModelIndex &parent = QModelIndex()) const;
void setTournament (Tournament *t);

private:
Tournament *trn;
};

#endif // MATCHMODEL_H
