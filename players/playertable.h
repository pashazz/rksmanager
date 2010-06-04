#ifndef PLAYERTABLE_H
#define PLAYERTABLE_H

#include <QtGui>
#include <QtSql>
namespace Ui {
    class PlayerTable;
}

class PlayerTable : public QDialog {
    Q_OBJECT
public:
    PlayerTable(QWidget *parent = 0);
    ~PlayerTable();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PlayerTable *m_ui;
    void loadTable();
private slots:
    void on_actAdd_triggered();
};

#endif // PLAYERTABLE_H
