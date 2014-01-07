#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QCloseEvent>
#include "chartparams.h"
#include "chartdata.h"


namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    ChartParams mChartParams;
    ChartData mChartData;
    QStringList mXMLData;

private:
    void setDefaultParams();
    void setButtonBackgroundColor(QPushButton *btn, const QColor &color);
    void setParamColor(QPushButton *btn, const QColor &color);
    QString colorPureCode(const QColor &color);

    void printHeader();
    void printFooter();
    void printData();

    void printColumnData(const QString &legend, const QList<BubbleData> &data, int colIndex, int maxElements);
    bool checkParams();

    double adjustXValue(double initVal, int colIndex, double radius);
    double adjustYMaxValue();
    int calculateYStep();

    void showChartView();

protected:
    void closeEvent(QCloseEvent *ev);
    QString outputFile();
    QString chartFile();
    bool generateChartFile();
    bool outputData();

private slots:
    void run();
    void selectColor();

    void selectInputFile();
    void selectOutputFile();

    void showAbout();
    void showHelp();
    void saveSettings();
    void enableYStep(bool checked);

};

#endif // DIALOG_H
