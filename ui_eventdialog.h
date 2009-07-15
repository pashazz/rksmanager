/********************************************************************************
** Form generated from reading ui file 'eventdialog.ui'
**
** Created: Thu Jul 9 23:05:25 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EVENTDIALOG_H
#define UI_EVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbPlayer;
    QComboBox *cbAction;
    QComboBox *cbChange;

    void setupUi(QDialog *EventDialog)
    {
        if (EventDialog->objectName().isEmpty())
            EventDialog->setObjectName(QString::fromUtf8("EventDialog"));
        EventDialog->setEnabled(true);
        EventDialog->resize(826, 112);
        buttonBox = new QDialogButtonBox(EventDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(200, 80, 164, 18));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        horizontalLayoutWidget = new QWidget(EventDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 20, 801, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cbPlayer = new QComboBox(horizontalLayoutWidget);
        cbPlayer->setObjectName(QString::fromUtf8("cbPlayer"));
        cbPlayer->setMaxVisibleItems(11);

        horizontalLayout->addWidget(cbPlayer);

        cbAction = new QComboBox(horizontalLayoutWidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/ball.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbAction->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/whistle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbAction->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/cards.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbAction->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/boots.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbAction->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        cbAction->addItem(icon4, QString());
        cbAction->setObjectName(QString::fromUtf8("cbAction"));

        horizontalLayout->addWidget(cbAction);

        cbChange = new QComboBox(horizontalLayoutWidget);
        cbChange->setObjectName(QString::fromUtf8("cbChange"));
        cbChange->setEnabled(false);

        horizontalLayout->addWidget(cbChange);


        retranslateUi(EventDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EventDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EventDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EventDialog);
    } // setupUi

    void retranslateUi(QDialog *EventDialog)
    {
        EventDialog->setWindowTitle(QApplication::translate("EventDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        cbAction->setItemText(0, QApplication::translate("EventDialog", "\320\227\320\260\320\261\320\270\320\273 \320\263\320\276\320\273", 0, QApplication::UnicodeUTF8));
        cbAction->setItemText(1, QApplication::translate("EventDialog", "\320\237\320\276\320\273\321\203\321\207\320\270\320\273 \320\266\320\265\320\273\321\202\321\203\321\216 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\321\203", 0, QApplication::UnicodeUTF8));
        cbAction->setItemText(2, QApplication::translate("EventDialog", "\320\237\320\276\320\273\321\203\321\207\320\270\320\273 \320\272\321\200\320\260\321\201\320\275\321\203\321\216 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\321\203", 0, QApplication::UnicodeUTF8));
        cbAction->setItemText(3, QApplication::translate("EventDialog", "\320\237\320\276\320\273\321\203\321\207\320\270\320\273 \321\202\321\200\320\260\320\262\320\274\321\203", 0, QApplication::UnicodeUTF8));
        cbAction->setItemText(4, QApplication::translate("EventDialog", "\320\227\320\260\320\274\320\265\320\275\320\265\320\275 \320\275\320\260", 0, QApplication::UnicodeUTF8));

        Q_UNUSED(EventDialog);
    } // retranslateUi

};

namespace Ui {
    class EventDialog: public Ui_EventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTDIALOG_H
