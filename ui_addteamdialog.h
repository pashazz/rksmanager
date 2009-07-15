/********************************************************************************
** Form generated from reading ui file 'addteamdialog.ui'
**
** Created: Thu Jul 9 23:05:25 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDTEAMDIALOG_H
#define UI_ADDTEAMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addTeamDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblPlayer;
    QLineEdit *txtPlayer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cbTeams;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addTeamDialog)
    {
        if (addTeamDialog->objectName().isEmpty())
            addTeamDialog->setObjectName(QString::fromUtf8("addTeamDialog"));
        addTeamDialog->resize(406, 94);
        verticalLayout = new QVBoxLayout(addTeamDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblPlayer = new QLabel(addTeamDialog);
        lblPlayer->setObjectName(QString::fromUtf8("lblPlayer"));

        horizontalLayout->addWidget(lblPlayer);

        txtPlayer = new QLineEdit(addTeamDialog);
        txtPlayer->setObjectName(QString::fromUtf8("txtPlayer"));

        horizontalLayout->addWidget(txtPlayer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(addTeamDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cbTeams = new QComboBox(addTeamDialog);
        cbTeams->setObjectName(QString::fromUtf8("cbTeams"));

        horizontalLayout_2->addWidget(cbTeams);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(addTeamDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(addTeamDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), addTeamDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addTeamDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(addTeamDialog);
    } // setupUi

    void retranslateUi(QDialog *addTeamDialog)
    {
        addTeamDialog->setWindowTitle(QApplication::translate("addTeamDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\263\321\200\320\276\320\272\320\260", 0, QApplication::UnicodeUTF8));
        lblPlayer->setText(QApplication::translate("addTeamDialog", "\320\235\320\270\320\272 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addTeamDialog", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(addTeamDialog);
    } // retranslateUi

};

namespace Ui {
    class addTeamDialog: public Ui_addTeamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEAMDIALOG_H
