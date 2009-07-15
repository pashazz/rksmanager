/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue Jul 14 13:52:37 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actNew;
    QAction *actOpen;
    QAction *actExit;
    QAction *actPlanning;
    QAction *actPlay;
    QAction *actHelp;
    QAction *actFont;
    QAction *actColor;
    QAction *actPrint;
    QAction *actGoleadors;
    QAction *actYellow;
    QAction *actRed;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *mnuFile;
    QMenu *mnuLeague;
    QMenu *mnuView;
    QMenu *menu_2;
    QMenu *mnuStats;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(630, 430);
        actNew = new QAction(MainWindow);
        actNew->setObjectName(QString::fromUtf8("actNew"));
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QString::fromUtf8("actOpen"));
        actExit = new QAction(MainWindow);
        actExit->setObjectName(QString::fromUtf8("actExit"));
        actPlanning = new QAction(MainWindow);
        actPlanning->setObjectName(QString::fromUtf8("actPlanning"));
        actPlay = new QAction(MainWindow);
        actPlay->setObjectName(QString::fromUtf8("actPlay"));
        actHelp = new QAction(MainWindow);
        actHelp->setObjectName(QString::fromUtf8("actHelp"));
        actFont = new QAction(MainWindow);
        actFont->setObjectName(QString::fromUtf8("actFont"));
        actColor = new QAction(MainWindow);
        actColor->setObjectName(QString::fromUtf8("actColor"));
        actPrint = new QAction(MainWindow);
        actPrint->setObjectName(QString::fromUtf8("actPrint"));
        actGoleadors = new QAction(MainWindow);
        actGoleadors->setObjectName(QString::fromUtf8("actGoleadors"));
        actYellow = new QAction(MainWindow);
        actYellow->setObjectName(QString::fromUtf8("actYellow"));
        actRed = new QAction(MainWindow);
        actRed->setObjectName(QString::fromUtf8("actRed"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QFont font;
        font.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSortingEnabled(true);

        horizontalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 19));
        mnuFile = new QMenu(menuBar);
        mnuFile->setObjectName(QString::fromUtf8("mnuFile"));
        mnuLeague = new QMenu(menuBar);
        mnuLeague->setObjectName(QString::fromUtf8("mnuLeague"));
        mnuView = new QMenu(menuBar);
        mnuView->setObjectName(QString::fromUtf8("mnuView"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        mnuStats = new QMenu(menuBar);
        mnuStats->setObjectName(QString::fromUtf8("mnuStats"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(mnuFile->menuAction());
        menuBar->addAction(mnuLeague->menuAction());
        menuBar->addAction(mnuView->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(mnuStats->menuAction());
        mnuFile->addAction(actNew);
        mnuFile->addAction(actOpen);
        mnuFile->addSeparator();
        mnuFile->addAction(actPrint);
        mnuFile->addAction(actExit);
        mnuLeague->addAction(actPlanning);
        mnuLeague->addAction(actPlay);
        mnuView->addAction(actFont);
        mnuView->addAction(actColor);
        mnuStats->addAction(actGoleadors);
        mnuStats->addAction(actYellow);
        mnuStats->addAction(actRed);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RKS Manager", 0, QApplication::UnicodeUTF8));
        actNew->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\202\321\203\321\200\320\275\320\270\321\200", 0, QApplication::UnicodeUTF8));
        actNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actOpen->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\202\321\203\321\200\320\275\320\270\321\200", 0, QApplication::UnicodeUTF8));
        actOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        actExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actPlanning->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\273\320\260\320\275\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\321\203\321\200", 0, QApplication::UnicodeUTF8));
        actPlay->setText(QApplication::translate("MainWindow", "\320\241\321\213\320\263\321\200\320\260\321\202\321\214 \321\202\321\203\321\200", 0, QApplication::UnicodeUTF8));
        actHelp->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        actFont->setText(QApplication::translate("MainWindow", "\320\250\321\200\320\270\321\204\321\202 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0, QApplication::UnicodeUTF8));
        actColor->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0, QApplication::UnicodeUTF8));
        actPrint->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        actGoleadors->setText(QApplication::translate("MainWindow", "\320\221\320\276\320\274\320\261\320\260\321\200\320\264\320\270\321\200\321\213", 0, QApplication::UnicodeUTF8));
        actYellow->setText(QApplication::translate("MainWindow", "\320\226\320\265\320\273\321\202\321\213\320\265 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        actRed->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\265 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\230\320\263\321\200\320\276\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\222", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\235", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\234\320\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\234\320\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        mnuFile->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        mnuLeague->setTitle(QApplication::translate("MainWindow", "\320\233\320\270\320\263\320\260", 0, QApplication::UnicodeUTF8));
        mnuView->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        mnuStats->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
