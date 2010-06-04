#include "leaguemodel.h"
#include "league.h"

void LeagueModel::loadData() {
    teams.clear();
    if (views) {
                   QStringList list;
           foreach (View v, t->views()) {
               QString name = v.name();
               QString nick;
               QStringList names;
               foreach (Club c, v.clubs())
                   names.append(c.name);
               int games, win, draw, lose, gs, gm, points;
               games =0;
               win  =0;
               draw = 0;
               lose = 0;
               gs = 0;
               gm = 0;
               points =0;

             QSqlQuery q;
        q.prepare("SELECT * FROM Teams  ORDER BY ABS(points)");
if (!q.exec()) {qDebug() << "SQL Error: " + q.lastError().text() + ", query " + q.lastQuery();}
else {qDebug() << "Query done: " + q.lastQuery();}
while (q.next()) {
    if (!names.contains(q.value(2).toString()))
        continue;
    if (!nick.isEmpty()) {
nick.append("/");
}

    nick.append(q.value(1).toString());
games += getMatches(q.value(3).toString()).toInt();
win += q.value(4).toInt();
draw += q.value(5).toInt();
lose += q.value(6).toInt();
gs += q.value(7).toInt();
gm += q.value(8).toInt();
points += q.value(9).toInt();
           }
QStringList currentVaue;
currentVaue.append(nick);
currentVaue.append(name);
currentVaue.append(QVariant(games).toString());
currentVaue.append(QVariant(win).toString());
currentVaue.append(QVariant(draw).toString());
currentVaue.append(QVariant(lose).toString());
currentVaue.append(QVariant(gs).toString());
currentVaue.append(QVariant(gm).toString());
currentVaue.append(QVariant(points).toString());
teams.append(currentVaue);
    }
       }
    else{
    QSqlQuery q;
    q.prepare("SELECT * FROM Teams");
            if (!q.exec()) {qDebug() << "SQL Error: "  +q.lastError().text() + " in query " + q.lastQuery();}
   else {qDebug() << "Query done" << q.executedQuery();}
   while (q.next()) {
       QStringList lst;
lst.append(q.value(1).toString());
lst.append(q.value(3).toString());
lst.append(getMatches(q.value(3).toString()));
lst.append(q.value(4).toString());
lst.append(q.value(5).toString());
lst.append(q.value(6).toString());
lst.append(q.value(7).toString());
lst.append(q.value(8).toString());
lst.append(q.value(9).toString());
teams.append(lst);
   }
}
}

QString LeagueModel::getMatches(QString team) {
    QSqlQuery q;
q.prepare ("SELECT COUNT (*) FROM Matches WHERE home = :home OR away = :away");
q.bindValue (":home", team);
q.bindValue (":away", team);
if (!q.exec()) {qDebug() << "SQL error" << q.lastError().text() << q.lastQuery();}
  q.first();
  return q.value(0).toString();
}

QVariant LeagueModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        if (!teams.count()) {return QVariant();}
        return teams.at(index.row()).at(index.column());
    }
    //else {return QAbstractItemModel::data(index, role);}
}

QVariant LeagueModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Vertical)
            return section;
        else if (orientation == Qt::Horizontal)
        {
            switch (section) {
                case 0:
                return "Команда";
                case 1:
                return "Игрок";
                case 2:
                return "Игры";
                case 3:
                return "В";
                case 4:
                return "Н";
                case 5:
                return "П";
                case 6:
                return "МЗ";
                case 7:
                return "МП";
                case 8:
                return "Очки";
            }

            }


        }
    else {
        return QAbstractTableModel::headerData(section, orientation, role);
    }
    }


void LeagueModel::setTournament( Tournament *trn) {t = trn;}
