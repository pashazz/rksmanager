/********************************************************************************
** Form generated from reading ui file 'teaminfo.ui'
**
** Created: Wed Jul 15 01:15:15 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEAMINFO_H
#define UI_TEAMINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamInfo
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblEmblem;
    QLabel *lblTeamName;
    QTabWidget *tab;
    QWidget *tabTeam;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tblPlayers;
    QWidget *tabResults;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbWin;
    QVBoxLayout *verticalLayout_3;
    QListWidget *lstWin;
    QGroupBox *gbDraw;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *lstDraw;
    QGroupBox *gbLose;
    QVBoxLayout *verticalLayout_4;
    QListWidget *lstLose;
    QWidget *tabX11;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tblGoals;
    QWidget *tabYellow;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tblYellow;
    QWidget *tabRed;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tblRed;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeamInfo)
    {
        if (TeamInfo->objectName().isEmpty())
            TeamInfo->setObjectName(QString::fromUtf8("TeamInfo"));
        TeamInfo->resize(563, 806);
        verticalLayout = new QVBoxLayout(TeamInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblEmblem = new QLabel(TeamInfo);
        lblEmblem->setObjectName(QString::fromUtf8("lblEmblem"));
        lblEmblem->setPixmap(QPixmap(QString::fromUtf8(":/images/images/stub.png")));

        horizontalLayout->addWidget(lblEmblem);

        lblTeamName = new QLabel(TeamInfo);
        lblTeamName->setObjectName(QString::fromUtf8("lblTeamName"));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(20);
        lblTeamName->setFont(font);

        horizontalLayout->addWidget(lblTeamName);


        verticalLayout->addLayout(horizontalLayout);

        tab = new QTabWidget(TeamInfo);
        tab->setObjectName(QString::fromUtf8("tab"));
        tabTeam = new QWidget();
        tabTeam->setObjectName(QString::fromUtf8("tabTeam"));
        horizontalLayout_4 = new QHBoxLayout(tabTeam);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tblPlayers = new QTableWidget(tabTeam);
        if (tblPlayers->columnCount() < 3)
            tblPlayers->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblPlayers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblPlayers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblPlayers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblPlayers->setObjectName(QString::fromUtf8("tblPlayers"));

        horizontalLayout_4->addWidget(tblPlayers);

        tab->addTab(tabTeam, QString());
        tabResults = new QWidget();
        tabResults->setObjectName(QString::fromUtf8("tabResults"));
        verticalLayout_2 = new QVBoxLayout(tabResults);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gbWin = new QGroupBox(tabResults);
        gbWin->setObjectName(QString::fromUtf8("gbWin"));
        verticalLayout_3 = new QVBoxLayout(gbWin);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lstWin = new QListWidget(gbWin);
        lstWin->setObjectName(QString::fromUtf8("lstWin"));

        verticalLayout_3->addWidget(lstWin);


        verticalLayout_2->addWidget(gbWin);

        gbDraw = new QGroupBox(tabResults);
        gbDraw->setObjectName(QString::fromUtf8("gbDraw"));
        horizontalLayout_2 = new QHBoxLayout(gbDraw);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lstDraw = new QListWidget(gbDraw);
        lstDraw->setObjectName(QString::fromUtf8("lstDraw"));

        horizontalLayout_2->addWidget(lstDraw);


        verticalLayout_2->addWidget(gbDraw);

        gbLose = new QGroupBox(tabResults);
        gbLose->setObjectName(QString::fromUtf8("gbLose"));
        verticalLayout_4 = new QVBoxLayout(gbLose);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lstLose = new QListWidget(gbLose);
        lstLose->setObjectName(QString::fromUtf8("lstLose"));

        verticalLayout_4->addWidget(lstLose);


        verticalLayout_2->addWidget(gbLose);

        tab->addTab(tabResults, QString());
        tabX11 = new QWidget();
        tabX11->setObjectName(QString::fromUtf8("tabX11"));
        horizontalLayout_3 = new QHBoxLayout(tabX11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tblGoals = new QTableWidget(tabX11);
        if (tblGoals->columnCount() < 2)
            tblGoals->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblGoals->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblGoals->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tblGoals->setObjectName(QString::fromUtf8("tblGoals"));

        horizontalLayout_3->addWidget(tblGoals);

        tab->addTab(tabX11, QString());
        tabYellow = new QWidget();
        tabYellow->setObjectName(QString::fromUtf8("tabYellow"));
        verticalLayout_5 = new QVBoxLayout(tabYellow);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tblYellow = new QTableWidget(tabYellow);
        if (tblYellow->columnCount() < 2)
            tblYellow->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblYellow->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblYellow->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        tblYellow->setObjectName(QString::fromUtf8("tblYellow"));

        verticalLayout_5->addWidget(tblYellow);

        tab->addTab(tabYellow, QString());
        tabRed = new QWidget();
        tabRed->setObjectName(QString::fromUtf8("tabRed"));
        verticalLayout_6 = new QVBoxLayout(tabRed);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tblRed = new QTableWidget(tabRed);
        if (tblRed->columnCount() < 2)
            tblRed->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblRed->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblRed->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        tblRed->setObjectName(QString::fromUtf8("tblRed"));

        verticalLayout_6->addWidget(tblRed);

        tab->addTab(tabRed, QString());

        verticalLayout->addWidget(tab);

        buttonBox = new QDialogButtonBox(TeamInfo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeamInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), TeamInfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TeamInfo, SLOT(reject()));

        tab->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(TeamInfo);
    } // setupUi

    void retranslateUi(QDialog *TeamInfo)
    {
        TeamInfo->setWindowTitle(QApplication::translate("TeamInfo", "Dialog", 0, QApplication::UnicodeUTF8));
        lblEmblem->setText(QString());
        lblTeamName->setText(QApplication::translate("TeamInfo", "My Favorite Team\n"
"(pashazz)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tblPlayers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TeamInfo", "#", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tblPlayers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TeamInfo", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tblPlayers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TeamInfo", "\320\230\320\274\321\217", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabTeam), QApplication::translate("TeamInfo", "\320\241\320\276\321\201\321\202\320\260\320\262", 0, QApplication::UnicodeUTF8));
        gbWin->setTitle(QApplication::translate("TeamInfo", "\320\222\321\213\320\270\320\263\321\200\321\213\321\210\320\270", 0, QApplication::UnicodeUTF8));
        gbDraw->setTitle(QApplication::translate("TeamInfo", "\320\235\320\270\321\207\321\214\320\270", 0, QApplication::UnicodeUTF8));
        gbLose->setTitle(QApplication::translate("TeamInfo", "\320\237\320\276\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabResults), QApplication::translate("TeamInfo", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tblGoals->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("TeamInfo", "\320\230\320\263\321\200\320\276\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tblGoals->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("TeamInfo", "\320\223\320\276\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabX11), QApplication::translate("TeamInfo", "\320\221\320\276\320\274\320\261\320\260\321\200\320\264\320\270\321\200\321\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tblYellow->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("TeamInfo", "\320\230\320\263\321\200\320\276\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tblYellow->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("TeamInfo", "\320\232\320\260\321\200\321\202\320\276\321\207\320\265\320\272", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabYellow), QApplication::translate("TeamInfo", "\320\226\320\265\320\273\321\202\321\213\320\265 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tblRed->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("TeamInfo", "\320\230\320\263\321\200\320\276\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tblRed->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("TeamInfo", "\320\232\320\260\321\200\321\202\320\276\321\207\320\265\320\272", 0, QApplication::UnicodeUTF8));
        tab->setTabText(tab->indexOf(tabRed), QApplication::translate("TeamInfo", "\320\232\321\200\320\260\321\201\320\275\321\213\320\265 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TeamInfo);
    } // retranslateUi

};

namespace Ui {
    class TeamInfo: public Ui_TeamInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMINFO_H
