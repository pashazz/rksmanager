/********************************************************************************
** Form generated from reading ui file 'planningdialog.ui'
**
** Created: Thu Jul 9 23:05:25 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PLANNINGDIALOG_H
#define UI_PLANNINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlanningDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tblPairs;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbHome;
    QComboBox *cbGuest;
    QPushButton *btnAdd;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlanningDialog)
    {
        if (PlanningDialog->objectName().isEmpty())
            PlanningDialog->setObjectName(QString::fromUtf8("PlanningDialog"));
        PlanningDialog->setWindowModality(Qt::ApplicationModal);
        PlanningDialog->resize(609, 357);
        PlanningDialog->setModal(true);
        verticalLayout = new QVBoxLayout(PlanningDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblPairs = new QTableWidget(PlanningDialog);
        if (tblPairs->columnCount() < 2)
            tblPairs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblPairs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblPairs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tblPairs->setObjectName(QString::fromUtf8("tblPairs"));

        verticalLayout->addWidget(tblPairs);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbHome = new QComboBox(PlanningDialog);
        cbHome->setObjectName(QString::fromUtf8("cbHome"));

        horizontalLayout->addWidget(cbHome);

        cbGuest = new QComboBox(PlanningDialog);
        cbGuest->setObjectName(QString::fromUtf8("cbGuest"));

        horizontalLayout->addWidget(cbGuest);

        btnAdd = new QPushButton(PlanningDialog);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout->addWidget(btnAdd);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(PlanningDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(false);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PlanningDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PlanningDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PlanningDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PlanningDialog);
    } // setupUi

    void retranslateUi(QDialog *PlanningDialog)
    {
        PlanningDialog->setWindowTitle(QApplication::translate("PlanningDialog", "\320\242\321\203\321\200:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tblPairs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PlanningDialog", "\320\245\320\276\320\267\321\217\320\265\320\262\320\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tblPairs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PlanningDialog", "\320\223\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("PlanningDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PlanningDialog);
    } // retranslateUi

};

namespace Ui {
    class PlanningDialog: public Ui_PlanningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNINGDIALOG_H
