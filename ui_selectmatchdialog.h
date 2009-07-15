/********************************************************************************
** Form generated from reading ui file 'selectmatchdialog.ui'
**
** Created: Wed 15. Jul 16:58:35 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SELECTMATCHDIALOG_H
#define UI_SELECTMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SelectMatchDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *sbTours;
    QListWidget *lstMatches;
    QDialogButtonBox *buttonBox;
    QLabel *lblData;

    void setupUi(QDialog *SelectMatchDialog)
    {
        if (SelectMatchDialog->objectName().isEmpty())
            SelectMatchDialog->setObjectName(QString::fromUtf8("SelectMatchDialog"));
        SelectMatchDialog->resize(663, 314);
        gridLayout = new QGridLayout(SelectMatchDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SelectMatchDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        sbTours = new QSpinBox(SelectMatchDialog);
        sbTours->setObjectName(QString::fromUtf8("sbTours"));

        horizontalLayout->addWidget(sbTours);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lstMatches = new QListWidget(SelectMatchDialog);
        lstMatches->setObjectName(QString::fromUtf8("lstMatches"));

        gridLayout->addWidget(lstMatches, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SelectMatchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        lblData = new QLabel(SelectMatchDialog);
        lblData->setObjectName(QString::fromUtf8("lblData"));

        gridLayout->addWidget(lblData, 2, 0, 1, 1);


        retranslateUi(SelectMatchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectMatchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectMatchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectMatchDialog)
    {
        SelectMatchDialog->setWindowTitle(QApplication::translate("SelectMatchDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SelectMatchDialog", "\320\242\321\203\321\200", 0, QApplication::UnicodeUTF8));
        lblData->setText(QApplication::translate("SelectMatchDialog", "Data", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SelectMatchDialog);
    } // retranslateUi

};

namespace Ui {
    class SelectMatchDialog: public Ui_SelectMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMATCHDIALOG_H
