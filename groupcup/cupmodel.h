#ifndef CUPMODEL_H
#define CUPMODEL_H

#include <QtGui>
#include "cup.h"
class CupModel : public QAbstractTableModel
{
public:
    CupModel(QObject *parent);
  virtual  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    virtual Qt::ItemFlags flags (const QModelIndex& index) const;
  virtual   QVariant data (const QModelIndex & index, int role) const;
 virtual   bool hasChildren(const QModelIndex &parent) const;
    void setCup (Cup* tournament){cup = tournament;}
     void loadData();
    virtual int rowCount(const QModelIndex &parent) const {return matches.count();}
 virtual   int columnCount(const QModelIndex &parent) const {return 3;}

private:
    Cup *cup;  
QList<QStringList> matches;
};

#endif // CUPMODEL_H
