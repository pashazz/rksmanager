#ifndef REPORTER_H
#define REPORTER_H

#include <QtGui>
#ifdef Q_WS_WIN
#include "../league.h"
#else
#include "league.h"
#endif

/*!
  Данный класс обеспечивает просмотр отчетов по турниру.
  */

namespace Ui {
    class Reporter;
}

class Reporter : public QDialog {
    Q_OBJECT
public:
    Reporter(QWidget *parent, Tournament *t, int m);
    ~Reporter();

protected:
    void changeEvent(QEvent *e);

private:
    int mode;
    Tournament *trn;
    Ui::Reporter *m_ui;
    /*!
      коды режимов:
      2 - бомбардиры
      3 - ЖК
      4 - КК
      ...
      */
    void appendTable();
private slots:
    void on_table_customContextMenuRequested(QPoint pos);
    void on_buttonBox_accepted();
    void onMenuClicked();
};

#endif // REPORTER_H
