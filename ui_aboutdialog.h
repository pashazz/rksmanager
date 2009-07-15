/********************************************************************************
** Form generated from reading ui file 'aboutdialog.ui'
**
** Created: Thu Jul 9 23:05:25 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(583, 497);
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(AboutDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\320\236 RKS Manager", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\321\202\320\260 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\261\321\213\320\273\320\260 \321\201\320\276\320\267\320\264\320\260\320\275\320\260<span style=\" font-weight:600;\"> </span><span style=\" font-weight:600; color:#ff0000;\">Pash</span><span style=\" font-weight:600; color:#0000ff;\">azz </span><span style=\" color:#000000;\">\321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276 \320\264\320\273\321\217 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\217"
                        " \321\202\321\203\321\200\320\275\320\270\321\200\320\276\320\262 </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">\320\241\320\265\321\200\320\263\320\270\320\265\320\262\320\276-\320\237\320\276\321\201\320\260\320\264\321\201\320\272\320\276\320\271 FIFA-\320\273\320\270\320\263\320\270.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\320\241\320\277\320\260\321\201\320\270\320\261\320\276 \320\262\321\201\320\265\320\274, \320\272\321\202\320\276 \320\277\320\276\320\274\320\276\320\263\320\260\320\273 \320\274\320\275\320\265, \320\270 \320\276\321\201\320\276\320\261\320\265\320\275\320\275\320\276 </span><span style=\" color:#ff0000;\">Jamil</span><span style=\" color:#55aa00;\"> (\320\234\320\260\321\200\320\272)</span><span style=\""
                        " color:#000000;\"> \320\267\320\260 \320\277\321\200\320\265\320\264\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\275\321\213\320\265 \320\263\320\265\321\200\320\261\321\213 \320\272\320\273\321\203\320\261\320\276\320\262 \320\230\321\201\320\277\320\260\320\275\320\270\320\270, \320\220\320\275\320\263\320\273\320\270\320\270, \320\223\320\265\321\200\320\274\320\260\320\275\320\270\320\270 \320\270 \320\244\321\200\320\260\320\275\321\206\320\270\320\270</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\320\236\320\275\320\270 \320\262\320\267\321\217\321\202\321\213 \321\201 \321\201\320\260\320\271\321\202\320\260 </span><a href=\"http://sportbox.ru\"><span style=\" text-decoration: underline; color:#3c7dbe;\">Sportbox.ru</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AboutDialog);
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
