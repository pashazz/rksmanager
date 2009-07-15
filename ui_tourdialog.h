/********************************************************************************
** Form generated from reading ui file 'tourdialog.ui'
**
** Created: Thu Jul 9 23:05:25 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TOURDIALOG_H
#define UI_TOURDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TourDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblName;
    QLineEdit *txtName;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cbCountry;
    QPushButton *cmdOK;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *cbType;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *lstPlayers;
    QLabel *lblTeam;
    QPushButton *cmdNew;

    void setupUi(QDialog *TourDialog)
    {
        if (TourDialog->objectName().isEmpty())
            TourDialog->setObjectName(QString::fromUtf8("TourDialog"));
        TourDialog->resize(512, 432);
        buttonBox = new QDialogButtonBox(TourDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(false);
        buttonBox->setGeometry(QRect(40, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(TourDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 481, 21));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblName = new QLabel(verticalLayoutWidget);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        horizontalLayout->addWidget(lblName);

        txtName = new QLineEdit(verticalLayoutWidget);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        horizontalLayout->addWidget(txtName);

        horizontalLayoutWidget = new QWidget(TourDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 50, 481, 25));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cbCountry = new QComboBox(horizontalLayoutWidget);
        cbCountry->setObjectName(QString::fromUtf8("cbCountry"));

        horizontalLayout_2->addWidget(cbCountry);

        cmdOK = new QPushButton(horizontalLayoutWidget);
        cmdOK->setObjectName(QString::fromUtf8("cmdOK"));

        horizontalLayout_2->addWidget(cmdOK);

        horizontalLayoutWidget_2 = new QWidget(TourDialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 80, 481, 21));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        cbType = new QComboBox(horizontalLayoutWidget_2);
        cbType->setObjectName(QString::fromUtf8("cbType"));

        horizontalLayout_3->addWidget(cbType);

        groupBox = new QGroupBox(TourDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 120, 491, 232));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lstPlayers = new QListWidget(groupBox);
        lstPlayers->setObjectName(QString::fromUtf8("lstPlayers"));

        verticalLayout->addWidget(lstPlayers);

        lblTeam = new QLabel(groupBox);
        lblTeam->setObjectName(QString::fromUtf8("lblTeam"));

        verticalLayout->addWidget(lblTeam);

        cmdNew = new QPushButton(TourDialog);
        cmdNew->setObjectName(QString::fromUtf8("cmdNew"));
        cmdNew->setEnabled(false);
        cmdNew->setGeometry(QRect(40, 360, 201, 18));

        retranslateUi(TourDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TourDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TourDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TourDialog);
    } // setupUi

    void retranslateUi(QDialog *TourDialog)
    {
        TourDialog->setWindowTitle(QApplication::translate("TourDialog", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \321\202\321\203\321\200\320\275\320\270\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lblName->setText(QApplication::translate("TourDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\321\203\321\200\320\275\320\270\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TourDialog", "\320\241\321\202\321\200\320\260\320\275\320\260 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        cmdOK->setText(QApplication::translate("TourDialog", "OK", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TourDialog", "\320\242\320\270\320\277 \321\202\321\203\321\200\320\275\320\270\321\200\320\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TourDialog", "\320\243\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        lblTeam->setText(QApplication::translate("TourDialog", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", 0, QApplication::UnicodeUTF8));
        cmdNew->setText(QApplication::translate("TourDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TourDialog);
    } // retranslateUi

};

namespace Ui {
    class TourDialog: public Ui_TourDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURDIALOG_H
