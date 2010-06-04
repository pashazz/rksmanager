#include "addprofiledialog.h"
#include "ui_addprofiledialog.h"
#include "playerworker.h"
QString translate(QString str)
{
        QString fn;
        int i, rU, rL;
        QString validChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890-_,.()[]{}<>~!@#$%^&*+=?";
        QString rusUpper = QApplication::translate("pCommon","АБВГДЕЁЖЗИЙ� ЛМНОП� СТУФХЦЧШЩЫЭЮЯ", 0, QApplication::UnicodeUTF8);
        QString rusLower = QApplication::translate("pCommon","абвгдеёжзийклмнопрстуфхцчшщыэюя", 0, QApplication::UnicodeUTF8);
        QStringList latUpper, latLower;
        latUpper <<"A"<<"B"<<"V"<<"G"<<"D"<<"E"<<"Jo"<<"Zh"<<"Z"<<"I"<<"J"<<"K"<<"L"<<"M"<<"N"
                <<"O"<<"P"<<"R"<<"S"<<"T"<<"U"<<"F"<<"H"<<"C"<<"Ch"<<"Sh"<<"Sh"<<"I"<<"E"<<"Ju"<<"Ja";
        latLower <<"a"<<"b"<<"v"<<"g"<<"d"<<"e"<<"jo"<<"zh"<<"z"<<"i"<<"j"<<"k"<<"l"<<"m"<<"n"
                <<"o"<<"p"<<"r"<<"s"<<"t"<<"u"<<"f"<<"h"<<"c"<<"ch"<<"sh"<<"sh"<<"i"<<"e"<<"ju"<<"ja";
        for (i=0; i < str.size(); ++i){
                if ( validChars.contains(str[i]) ){
                        fn = fn + str[i];
                }else if (str[i] == ' '){  //replace spaces
                        fn = fn + "_";
                }else{
                        rU = rusUpper.indexOf(str[i]);
                        rL = rusLower.indexOf(str[i]);
                        if (rU > 0)         fn = fn + latUpper[rU];
                        else if (rL > 0)   fn = fn + latLower[rL];
                }
        }
        if (fn.isEmpty() ) fn = "file";
        return fn;
    }
AddProfileDialog::AddProfileDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AddProfileDialog)
{
    m_ui->setupUi(this);
}

AddProfileDialog::~AddProfileDialog()
{
    delete m_ui;
}

void AddProfileDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AddProfileDialog::on_txtNick_cursorPositionChanged(int , int )
{

}

void AddProfileDialog::on_txtNick_textChanged(QString s)
{
    s = translate(s);
    s = s.toLower();
    m_ui->lblTable->setText(s);
}

void AddProfileDialog::on_buttonBox_2_accepted()
{
    if (!isEdit) {
    if (!m_ui->txtNick->text().isEmpty()) {
        if (m_ui->txtName->text().isEmpty())
            m_ui->txtName->setText("Нет данных");
        PlayerWorker::addPlayer(m_ui->txtNick->text(), m_ui->txtName->text(), m_ui->lblTable->text());
    }
}
    else {
        QSqlDatabase db = QSqlDatabase::database("players");
        QSqlQuery q(db);
        q.prepare("UPDATE Players SET name=:name WHERE nick=:nick");
        q.bindValue(":name", m_ui->txtName->text());
        q.bindValue(":nick", m_ui->txtNick->text());
        q.exec();

    }
    close();
}

void AddProfileDialog::on_buttonBox_2_rejected()
{
    close();

}

AddProfileDialog::AddProfileDialog (QWidget *parent, QString player)
     :QDialog(parent), nick(player)
{
    m_ui->setupUi(this);
    isEdit = true;
    QSqlDatabase db = QSqlDatabase::database("players");
    QSqlQuery q(db);
    q.prepare("SELECT name FROM Players WHERE nick=:nick");
    q.bindValue(":nick", nick);
    q.exec();
    q.first();
    m_ui->txtName->setText(q.value(0).toString());
    m_ui->txtNick->setText(nick);
    m_ui->txtNick->setEnabled(false);
}
