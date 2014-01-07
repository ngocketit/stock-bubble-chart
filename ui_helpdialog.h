/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created: Tue Dec 4 21:07:54 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(644, 602);
        gridLayout = new QGridLayout(HelpDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(HelpDialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(540, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(HelpDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setDefault(true);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(HelpDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), HelpDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "Help", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("HelpDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
