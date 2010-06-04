#include "exporter.h"

Exporter::Exporter()
{
}
static void printTable(QWidget *widget, Format format, QString fileName) {
   QPrinter *printer =  new QPrinter();
   QPainter p (printer);
   if (format == PDF)
       printer->setOutputFormat(QPrinter::PdfFormat);
   else if (format == PS)
       printer->setOutputFormat(QPrinter::PostScriptFormat);

   printer->setOutputFileName(fileName);

    QPixmap pix = QPixmap::grabWidget(widget);
    p.drawPixmap(0,0,pix);

}
