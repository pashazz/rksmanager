#ifndef ADDPROFILEDIALOG_H
#define ADDPROFILEDIALOG_H

#include <QtGui>

namespace Ui {
    class AddProfileDialog;
}

class AddProfileDialog : public QDialog {
    Q_OBJECT
public:
    AddProfileDialog(QWidget *parent = 0);
    ~AddProfileDialog();
    AddProfileDialog(QWidget *parent, QString player);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddProfileDialog *m_ui;
    bool isEdit;
    QString nick;
private slots:
    void on_buttonBox_2_rejected();
    void on_buttonBox_2_accepted();
    void on_txtNick_textChanged(QString );
    void on_txtNick_cursorPositionChanged(int , int );
};

#endif // ADDPROFILEDIALOG_H
