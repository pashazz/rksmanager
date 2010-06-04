#ifndef GROUWIDGET_H
#define GROUWIDGET_H

#include <QtGui/QTabWidget>

namespace Ui {
    class grouwidget;
}

class grouwidget : public QTabWidget {
    Q_OBJECT
public:
    grouwidget(QWidget *parent = 0);
    ~grouwidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::grouwidget *m_ui;
};

#endif // GROUWIDGET_H
