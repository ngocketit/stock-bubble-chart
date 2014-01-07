#ifndef BROWSERDIALOG_H
#define BROWSERDIALOG_H

#include <QDialog>

namespace Ui {
    class BrowserDialog;
}

class BrowserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrowserDialog(QWidget *parent = 0);
    ~BrowserDialog();
    void setChartFile(const QString &file);
    void show();
    void setChartSize(const QSize &size);

private:
    Ui::BrowserDialog *ui;

private slots:
    void saveChart();
};

#endif // BROWSERDIALOG_H
