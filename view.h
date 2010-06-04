#ifndef VIEW_H
#define VIEW_H

#include <QtCore>
#include <QSharedData>
#include "match.h"

class ViewData : public QSharedData
{
    public:
    ViewData() {name.clear();}
    ViewData(const ViewData &other) :QSharedData(other), name (other.name), clubs (other.clubs) {}
    ~ViewData () {}
    QString name;
QString filename;
    QList<Club> clubs;
};
class View
{
public:
    View() {d = new ViewData();}
    View (QString name,  QList<Club> c, QString filename) {
        d = new ViewData();
        setFileName(filename);
        setName(name);
        setClubs(c);
    }
    View(QString filename, QList<Club> all);
    void setFileName (QString file) {d->filename = file;
    QFile f;
    if (!f.exists()) {f.open(QIODevice::WriteOnly); f.close();}
    }
    void setName (QString name) {d->name = name;
    QSettings stg (d->filename, QSettings::IniFormat);
stg.beginGroup("Settings");
stg.setValue("name", name);
stg.endGroup();
stg.sync();


}
    QString filename () const {return d->filename;}
    void setClubs (QList <Club> clubs) {d->clubs = clubs;
        QSettings stg (d->filename, QSettings::IniFormat);
stg.beginGroup("Teams");
foreach (Club c, clubs)
{
    stg.setValue("club" + QVariant(clubs.indexOf(c)).toString(), c.name);
}
stg.endGroup();
stg.sync();
    }
    QString name() const {return d->name;}
    QList <Club> clubs () const {return d->clubs;}
    private:
    QSharedDataPointer<ViewData> d;

    };


#endif // VIEW_H
