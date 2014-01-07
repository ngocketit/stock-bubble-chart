/********************************************************************************
** Form generated from reading UI file 'browserdialog.ui'
**
** Created: Tue Dec 4 21:07:54 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSERDIALOG_H
#define UI_BROWSERDIALOG_H

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

class Ui_BrowserDialog
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;
    QPushButton *btnExport;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;

    void setupUi(QDialog *BrowserDialog)
    {
        if (BrowserDialog->objectName().isEmpty())
            BrowserDialog->setObjectName(QString::fromUtf8("BrowserDialog"));
        BrowserDialog->resize(742, 461);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/bubble.png"), QSize(), QIcon::Normal, QIcon::Off);
        BrowserDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(BrowserDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(BrowserDialog);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 3);

        btnExport = new QPushButton(BrowserDialog);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));

        gridLayout->addWidget(btnExport, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(518, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        btnClose = new QPushButton(BrowserDialog);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setDefault(true);

        gridLayout->addWidget(btnClose, 1, 2, 1, 1);


        retranslateUi(BrowserDialog);
        QObject::connect(btnClose, SIGNAL(clicked()), BrowserDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(BrowserDialog);
    } // setupUi

    void retranslateUi(QDialog *BrowserDialog)
    {
        BrowserDialog->setWindowTitle(QApplication::translate("BrowserDialog", "Chart view", 0, QApplication::UnicodeUTF8));
        btnExport->setText(QApplication::translate("BrowserDialog", "Export as PNG", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("BrowserDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BrowserDialog: public Ui_BrowserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSERDIALOG_H
