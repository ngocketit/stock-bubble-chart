#include "helpdialog.h"
#include "ui_helpdialog.h"

#include <QUrl>
#include <QWebSettings>

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::Window;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowMaximizeButtonHint;
    flags &= ~Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);

    QWebSettings *settings = QWebSettings::globalSettings();
    settings->setAttribute (QWebSettings::PluginsEnabled, true);

    ui->webView->setContextMenuPolicy(Qt::NoContextMenu);
    ui->webView->setUrl(QUrl("qrc:/root/help.html"));
    ui->webView->show();
}

HelpDialog::~HelpDialog()
{
    delete ui;
}
