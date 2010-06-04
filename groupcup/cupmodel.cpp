#include "cupmodel.h"
#include "common.h"
CupModel::CupModel(QObject *parent)
        :QAbstractTableModel(parent)
{
}
QVariant CupModel::headerData (int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
            if (!matches.count()){return QVariant();}

        if (orientation == Qt::Horizontal) {
            switch (section) {
              case 0:
                return "Хозяева";
             case 1:
                return "Гости";
             case 2:
            return "Счет";
            }
        }
            else if (orientation ==Qt::Vertical) {
             QString tour = matches.at(section).at(2);
             switch (tour.toInt()) {
                 case 1:
                 return "Финал";
                case 2:
                 return "Полуфинал";
                 case 3:
                 return "1/4 финала";
                 case 4:
                 return "1/8 финала";
                 case 5:
                 return "1/16 финала";
                 default:
                 return "Ошибка";
             }
            }
        }
return QAbstractTableModel::headerData(section, orientation, role);
}




void CupModel::loadData() {
    matches.clear();
    QSqlQuery q;
    q.prepare("SELECT * FROM Matches ORDER BY ABS(tour) DESC");
             if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   while (q.next()) {
       QStringList lst;
       lst.append(q.value(1).toString());
       lst.append(q.value(2).toString());
       lst.append(q.value(3).toString());
       lst.append(q.value(4).toString());
       matches.append(lst);
   }

}
QVariant CupModel::data(const QModelIndex &index, int role)  const{

    if (role == Qt::DisplayRole) {
       if (!matches.count()){return QVariant();}
       Match m;
      QString  score;
      QStringList tps = QStringList () << "0-0" << "0-7" << "7-0";
              switch (index.column()) {
           case 0:
           return matches.at(index.row()).at(0);
           case 1:
           return matches.at(index.row()).at(1);
            case 2:
      if (tps.contains(matches.at(index.row()).at(3))){
          score = matches.at(index.row()).at(3);

      }
      else {
          Club home, away;
          foreach (Club c, cup->getClubs()) {
              if (c.displayName == matches.at(index.row()).at(0))
                  home = c;
              else if (c.displayName == matches.at(index.row()).at(1))
                  away = c;
          }
          m = readToMatch(matches.at(index.row()).at(3), home,away);
        score = QString("%1 - %2").arg(QVariant(m.home.goals).toString()).arg(QVariant(m.away.goals).toString());
       }
      return score;
      default:
      break;
   }
    }
    else{
        //return QAbstractTableModel::data(index,  role);
    }
}

Qt::ItemFlags CupModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsEnabled;

}
bool CupModel::hasChildren(const QModelIndex &parent) const {
   return !parent.isValid();
}
