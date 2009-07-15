/********************************************************************************
** Form generated from reading ui file 'reporter.ui'
**
** Created: Tue Jul 14 13:52:37 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_REPORTER_H
#define UI_REPORTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Reporter
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *table;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Reporter)
    {
        if (Reporter->objectName().isEmpty())
            Reporter->setObjectName(QString::fromUtf8("Reporter"));
        Reporter->resize(616, 323);
        verticalLayout = new QVBoxLayout(Reporter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        table = new QTableWidget(Reporter);
        if (table->columnCount() < 3)
            table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table->setObjectName(QString::fromUtf8("table"));
        table->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout->addWidget(table);

        buttonBox = new QDialogButtonBox(Reporter);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Reporter);
        QObject::connect(buttonBox, SIGNAL(accepted()), Reporter, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Reporter, SLOT(reject()));

        QMetaObject::connectSlotsByName(Reporter);
    } // setupUi

    void retranslateUi(QDialog *Reporter)
    {
        Reporter->setWindowTitle(QApplication::translate("Reporter", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Reporter", "\320\230\320\263\321\200\320\276\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Reporter", "\320\232\320\276\320\273-\320\262\320\276", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Reporter", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Reporter);
    } // retranslateUi

};

namespace Ui {
    class Reporter: public Ui_Reporter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTER_H
