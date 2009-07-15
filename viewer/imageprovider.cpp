#include "imageprovider.h"
#include <QPainter>
ImageProvider::ImageProvider()
{
}
QPixmap ImageProvider::getClubEmblem(QString name) {
    if (QFile::exists(QDir::homePath() + "/.rks/emblems/" + name + ".png")) {
        QPixmap image(QDir::homePath() + "/.rks/emblems/" + name + ".png");
        return image;
    }
    else {
        //maybe return federation
     return stub();
       }
}

QPixmap ImageProvider::stub() {
return QPixmap(":/images/images/stub.png");
}
