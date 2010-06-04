#include "viewdialog.h"
#include "ui_viewdialog.h"

ViewDialog::ViewDialog(QWidget *parent, Tournament *t) :
    QDialog(parent),
    m_ui(new Ui::ViewDialog), trn(t)
{
    m_ui->setupUi(this);
    QList <Club> viewteams;
    QStringList teams;
    foreach (View v, t->views()) {
        QListWidgetItem *it = new QListWidgetItem (m_ui->lstViews, 0);
        it->setText(v.name());
        it->setFlags(Qt::ItemIsEnabled);
        m_ui->lstViews->addItem(it);
        viewteams.append(v.clubs());
    }
    foreach (Club c, t->getClubs()) {
        if (!viewteams.contains(c))
            teams << c.displayName;
    }
    m_ui->lstTeams->setSelectionMode(QAbstractItemView::MultiSelection);
    m_ui->lstTeams->addItems(teams);
}

ViewDialog::~ViewDialog()
{
    delete m_ui;
}

void ViewDialog::changeEvent(QEvent *e)
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

void ViewDialog::on_cmdAdd_clicked()
{
    if (m_ui->lstTeams->selectedItems().count() < 2){
        QMessageBox::warning(this, "WARNING!", "Мало команд");
        return;
    }
    QList <Club> clubs;
    QStringList texts;
    foreach  (QListWidgetItem *it, m_ui->lstTeams->selectedItems())
        texts << it->text();

    foreach (Club c, trn->getClubs()){
        if (texts.contains(c.displayName)) {

            clubs.append(c);
        }
    }
    QString name = QInputDialog::getText(this, "Введите обозначение представления", "Этот текст будет отображаться в турнирной таблице");
    if (name.isEmpty()) {return;}
     trn->addView(name, clubs);
m_ui->lstViews->addItem(name);


}

void ViewDialog::on_pushButton_clicked()
{
    foreach (View v, trn->views())

        if (v.name() == m_ui->lstViews->currentItem()->text())
        trn->removeView(v);
}
