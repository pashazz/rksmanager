#include "view.h"
View::View (QString filename, QList<Club> all) {
    d = new ViewData();
    d->filename = filename;
    qDebug() << "filename is "<< filename;
    QSettings stg (filename, QSettings::IniFormat);
    stg.beginGroup("Settings");
    d->name = stg.value("name").toString();
    stg.endGroup();
    stg.beginGroup("Teams");
    foreach (QString key, stg.allKeys()) {
        foreach (Club c, all) {
            if (c.name == stg.value(key).toString()) {d->clubs.append(c);
                break;
        }

    }
    }

    stg.endGroup();
    }

