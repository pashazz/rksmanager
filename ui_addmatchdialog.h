/********************************************************************************
** Form generated from reading ui file 'addmatchdialog.ui'
**
** Created: Fri Jul 10 15:40:44 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDMATCHDIALOG_H
#define UI_ADDMATCHDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMatchDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblHomeEmblem;
    QLabel *label;
    QLabel *lblAwayEmblem;
    QToolBox *toolHome;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QPushButton *cmdAddHomeEvent;
    QListWidget *lstHome;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *cmdHomeStart;
    QListWidget *lstHomeStart;
    QDialogButtonBox *buttonBox;
    QLabel *lblHomeScore;
    QLabel *lblAwayScore;
    QLabel *lblAway;
    QLabel *lblHome;
    QToolBox *toolBox;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *cmdAddAwayEvent;
    QListWidget *lstAway;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *cmdAwayStart;
    QListWidget *lstAwayStart;

    void setupUi(QDialog *AddMatchDialog)
    {
        if (AddMatchDialog->objectName().isEmpty())
            AddMatchDialog->setObjectName(QString::fromUtf8("AddMatchDialog"));
        AddMatchDialog->resize(655, 579);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddMatchDialog->sizePolicy().hasHeightForWidth());
        AddMatchDialog->setSizePolicy(sizePolicy);
        AddMatchDialog->setModal(true);
        gridLayout = new QGridLayout(AddMatchDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblHomeEmblem = new QLabel(AddMatchDialog);
        lblHomeEmblem->setObjectName(QString::fromUtf8("lblHomeEmblem"));

        gridLayout->addWidget(lblHomeEmblem, 0, 0, 1, 1);

        label = new QLabel(AddMatchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(16);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 4, 1, 1);

        lblAwayEmblem = new QLabel(AddMatchDialog);
        lblAwayEmblem->setObjectName(QString::fromUtf8("lblAwayEmblem"));

        gridLayout->addWidget(lblAwayEmblem, 0, 8, 1, 1);

        toolHome = new QToolBox(AddMatchDialog);
        toolHome->setObjectName(QString::fromUtf8("toolHome"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 270, 463));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cmdAddHomeEvent = new QPushButton(page);
        cmdAddHomeEvent->setObjectName(QString::fromUtf8("cmdAddHomeEvent"));

        verticalLayout->addWidget(cmdAddHomeEvent);

        lstHome = new QListWidget(page);
        lstHome->setObjectName(QString::fromUtf8("lstHome"));

        verticalLayout->addWidget(lstHome);

        toolHome->addItem(page, QString::fromUtf8("\320\241\320\276\320\261\321\213\321\202\320\270\321\217"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 142, 124));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        cmdHomeStart = new QPushButton(page_2);
        cmdHomeStart->setObjectName(QString::fromUtf8("cmdHomeStart"));

        verticalLayout_4->addWidget(cmdHomeStart);

        lstHomeStart = new QListWidget(page_2);
        lstHomeStart->setObjectName(QString::fromUtf8("lstHomeStart"));

        verticalLayout_4->addWidget(lstHomeStart);

        toolHome->addItem(page_2, QString::fromUtf8("\320\241\320\276\321\201\321\202\320\260\320\262"));

        gridLayout->addWidget(toolHome, 1, 0, 1, 3);

        buttonBox = new QDialogButtonBox(AddMatchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(false);
        buttonBox->setLocale(QLocale(QLocale::Russian, QLocale::RussianFederation));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 7);

        lblHomeScore = new QLabel(AddMatchDialog);
        lblHomeScore->setObjectName(QString::fromUtf8("lblHomeScore"));
        lblHomeScore->setFont(font);

        gridLayout->addWidget(lblHomeScore, 0, 3, 1, 1);

        lblAwayScore = new QLabel(AddMatchDialog);
        lblAwayScore->setObjectName(QString::fromUtf8("lblAwayScore"));
        lblAwayScore->setFont(font);

        gridLayout->addWidget(lblAwayScore, 0, 5, 1, 1);

        lblAway = new QLabel(AddMatchDialog);
        lblAway->setObjectName(QString::fromUtf8("lblAway"));
        lblAway->setFont(font);

        gridLayout->addWidget(lblAway, 0, 6, 1, 1);

        lblHome = new QLabel(AddMatchDialog);
        lblHome->setObjectName(QString::fromUtf8("lblHome"));
        lblHome->setFont(font);

        gridLayout->addWidget(lblHome, 0, 2, 1, 1);

        toolBox = new QToolBox(AddMatchDialog);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 270, 463));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cmdAddAwayEvent = new QPushButton(page_3);
        cmdAddAwayEvent->setObjectName(QString::fromUtf8("cmdAddAwayEvent"));

        verticalLayout_2->addWidget(cmdAddAwayEvent);

        lstAway = new QListWidget(page_3);
        lstAway->setObjectName(QString::fromUtf8("lstAway"));

        verticalLayout_2->addWidget(lstAway);

        toolBox->addItem(page_3, QString::fromUtf8("\320\241\320\276\320\261\321\213\321\202\320\270\321\217"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 142, 124));
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cmdAwayStart = new QPushButton(page_4);
        cmdAwayStart->setObjectName(QString::fromUtf8("cmdAwayStart"));

        verticalLayout_3->addWidget(cmdAwayStart);

        lstAwayStart = new QListWidget(page_4);
        lstAwayStart->setObjectName(QString::fromUtf8("lstAwayStart"));

        verticalLayout_3->addWidget(lstAwayStart);

        toolBox->addItem(page_4, QString::fromUtf8("\320\241\320\276\321\201\321\202\320\260\320\262"));

        gridLayout->addWidget(toolBox, 1, 6, 1, 3);


        retranslateUi(AddMatchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddMatchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddMatchDialog, SLOT(reject()));

        toolHome->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *AddMatchDialog)
    {
        AddMatchDialog->setWindowTitle(QString());
        lblHomeEmblem->setText(QString());
        label->setText(QApplication::translate("AddMatchDialog", "-", 0, QApplication::UnicodeUTF8));
        lblAwayEmblem->setText(QString());
        cmdAddHomeEvent->setText(QApplication::translate("AddMatchDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\261\321\213\321\202\320\270\320\265", 0, QApplication::UnicodeUTF8));
        toolHome->setItemText(toolHome->indexOf(page), QApplication::translate("AddMatchDialog", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", 0, QApplication::UnicodeUTF8));
        cmdHomeStart->setText(QApplication::translate("AddMatchDialog", "\320\227\320\260\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \321\201\320\276\321\201\321\202\320\260\320\262", 0, QApplication::UnicodeUTF8));
        toolHome->setItemText(toolHome->indexOf(page_2), QApplication::translate("AddMatchDialog", "\320\241\320\276\321\201\321\202\320\260\320\262", 0, QApplication::UnicodeUTF8));
        lblHomeScore->setText(QApplication::translate("AddMatchDialog", "0", 0, QApplication::UnicodeUTF8));
        lblAwayScore->setText(QApplication::translate("AddMatchDialog", "0", 0, QApplication::UnicodeUTF8));
        lblAway->setText(QApplication::translate("AddMatchDialog", "Jason", 0, QApplication::UnicodeUTF8));
        lblHome->setText(QApplication::translate("AddMatchDialog", "Drakula", 0, QApplication::UnicodeUTF8));
        cmdAddAwayEvent->setText(QApplication::translate("AddMatchDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\261\321\213\321\202\320\270\320\265", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("AddMatchDialog", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", 0, QApplication::UnicodeUTF8));
        cmdAwayStart->setText(QApplication::translate("AddMatchDialog", "\320\227\320\260\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \321\201\320\276\321\201\321\202\320\260\320\262", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("AddMatchDialog", "\320\241\320\276\321\201\321\202\320\260\320\262", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AddMatchDialog);
    } // retranslateUi

};

namespace Ui {
    class AddMatchDialog: public Ui_AddMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMATCHDIALOG_H
