#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
    MainWindow w;
    w.show();
    return a.exec();
}

