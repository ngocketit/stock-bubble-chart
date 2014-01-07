#include "browserdialog.h"
#include "ui_browserdialog.h"

#include <QUrl>
#include <QWebSettings>
#include <QImage>
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QSize>

BrowserDialog::BrowserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowserDialog)
{
    ui->setupUi(this);

    connect(ui->btnExport, SIGNAL(clicked()), this, SLOT(saveChart()));

    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::Window;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowMaximizeButtonHint;
    flags &= ~Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);

    QWebSettings *settings = QWebSettings::globalSettings();
    settings->setAttribute (QWebSettings::PluginsEnabled, true);

    ui->webView->setContextMenuPolicy(Qt::NoContextMenu);
}

void BrowserDialog::setChartFile(const QString &file)
{
    if (QFile::exists(file)) {
        ui->webView->setUrl(file);
    } else {
        ui->webView->setHtml("<b>Chart file does not exist!</b>");
    }
}

void BrowserDialog::setChartSize(const QSize &size)
{
    const int margin = 8;
    int width  = size.width() + 2 * margin;
    int height = size.height() + 2 * margin;

    ui->webView->setMinimumSize(width, height);
    ui->webView->setMaximumSize(width, height);

    QSize s = this->size();
    setMaximumSize(s);
}

void BrowserDialog::show()
{
    ui->webView->show();
    exec();
}

BrowserDialog::~BrowserDialog()
{
    delete ui;
}

void BrowserDialog::saveChart()
{
    QString saveFile = QFileDialog::getSaveFileName(this, tr("Save as"), QString(), tr("Image files (*.png)"));
    if (!saveFile.isEmpty()) {
        if (!saveFile.endsWith(".png")) {
            saveFile = saveFile + ".png";
        }

        QImage img(ui->webView->size(), QImage::Format_ARGB32_Premultiplied );
        QPainter painter(&img);
        ui->webView->render(&painter);

        if (!img.save(saveFile, 0, 100)) {
            QMessageBox::warning(this, tr("Failed"), tr("Failed to export image file"), QMessageBox::Close);
        }
    }
}
