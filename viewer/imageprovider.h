#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H
#include <QtCore>
#include <QPixmap>
#include <QFile>
#include <QDir>
 class ImageProvider :public QObject
{
     Q_OBJECT
public:
    ImageProvider();
    static QPixmap getClubEmblem (QString name) ;
   static  QPixmap getFederationEbmblem (QString name);
   static QPixmap getCountryFlag (QString name);
   private:
   static QPixmap stub();
};

#endif // IMAGEPROVIDER_H
