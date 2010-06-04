#ifndef EXPORTER_H
#define EXPORTER_H

#include <QObject>
#include <QtGui>
/*!
Печатает таблицы в PDF, PS или на принтер
  */
    enum Format {PDF = 1, PS = 2};

class Exporter : public QObject
{

public:
    Exporter();
    static void printTable (QWidget *widget, Format format, QString fileName);
};

#endif // EXPORTER_H
