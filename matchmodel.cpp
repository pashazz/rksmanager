#include "matchmodel.h"
#include "common.h"
MatchModel::MatchModel(QObject *parent)
        :QAbstractTableModel(parent)
{
}
 Match getMatch (Club home, Club away) {
     QSqlQuery q;
     q.prepare("SELECT matchfile FROM Matches WHERE home=:home AND away=:away");
     q.bindValue(":home", home.displayName);
     q.bindValue(":away", away.displayName);
q.exec();
q.first();
QString matchfile = q.value(0).toString();
if (QFile::exists(matchfile)) {
Match m = readToMatch(matchfile, home, away);

return m;
}
else
{   Match m;
m.home.club = home;
m.away.club = away;
m.home.goals = 0;
m.away.goals = 0;
return m;
}
 }

int MatchModel::rowCount(const QModelIndex &parent) const {

    if ( trn == 0)
        return 0;
    else
               return trn->getClubs().count();
}
 int MatchModel::columnCount(const QModelIndex &parent) const {
            if (trn == 0)
        return 0;
    else
        return trn->getClubs().count();

    }
 QVariant MatchModel::headerData(int section, Qt::Orientation orientation, int role) const{
     //нам пох, у нас лейблы горизонтальных и вертикальных столбцов одинаковы

     if (role == Qt::DisplayRole) {
return QVariant(trn->getClubs().at(section).displayName);
}
     return QAbstractTableModel::headerData(section, orientation, role);

 }
 Qt::ItemFlags MatchModel::flags(const QModelIndex &parent) const {
     if (parent.row() != parent.column())
     return Qt::ItemIsEnabled;
else
    return Qt::NoItemFlags;
 }
 QVariant MatchModel::data(const QModelIndex &index, int role) const {
     if (!trn)
         return QVariant();
    if (!index.isValid() || !trn->getClubs().count())
        return QVariant();
    if (index.row() == index.column())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        Match m = getMatch(trn->getClubs().at(index.row()), trn->getClubs().at(index.column()));
        QString text = QVariant(m.home.goals).toString() + " - " + QVariant(m.away.goals).toString();
        return text;
     }

    if (role == Qt::ToolTipRole){
        QString toolTip;
            Match m = getMatch(trn->getClubs().at(index.row()), trn->getClubs().at(index.column()));

    toolTip.append("<p><b>" + m.home.club.displayName + ":</b></p>");
    foreach(Player p, m.home.golaedors){
        toolTip.append(QString ("<p>%1</p>").arg(p.name));
    }
    toolTip.append("<p>");
        toolTip.append("<p><b>" + m.away.club.displayName + ":</b></p>");
    foreach(Player p, m.away.golaedors){
        toolTip.append(QString ("<p>%1</p>").arg(p.name));
    }
    return toolTip;
}
    return QVariant();
 }

 bool MatchModel::hasChildren(const QModelIndex &parent)const {
     return !parent.isValid();
 }
 void MatchModel::setTournament(Tournament *t)
 {
     trn = t;
 }

 // ***************************************************************************
