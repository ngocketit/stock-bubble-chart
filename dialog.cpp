#include "dialog.h"
#include "ui_dialog.h"
#include "chartdata.h"
#include "aboutdialog.h"
#include "helpdialog.h"
#include "browserdialog.h"
#include <cmath>

#include <QPalette>
#include <QColorDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include <QFileInfo>
#include <QSettings>
#include <QDir>
#include <QSize>

#define MIN_RADIUS_FOR_LABEL    15
#define NUM_COLUMNS 5
#define MIN_RADIUS  5
#define MIN_Y_STEP_PIXEL    20


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setDefaultParams();

    connect(ui->btnRun, SIGNAL(clicked()), this, SLOT(run()));
    connect(ui->btnBrowseInputFile, SIGNAL(clicked()), this, SLOT(selectInputFile()));
    connect(ui->btnAbout, SIGNAL(clicked()), this, SLOT(showAbout()));
    connect(ui->btnHelp, SIGNAL(clicked()), this, SLOT(showHelp()));
    connect(ui->chkYStepAutoCalculated, SIGNAL(toggled(bool)), this, SLOT(enableYStep(bool)));

    QSettings settings;
    ui->txtInputFile->setText(settings.value("last_input_file").toString());

    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::Window;
    flags |= Qt::WindowMinimizeButtonHint;
    flags &= ~Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);

    setMaximumSize(size());
    setMinimumSize(size());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::selectInputFile()
{
    QFileInfo fi(ui->txtInputFile->text());
    QString dir = fi.dir().path();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select data file"), dir, tr("Text files (*.txt)"));
    if (!fileName.isEmpty()) {
        ui->txtInputFile->setText(fileName);
    }
}

void Dialog::selectOutputFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Select data file"), "", tr("XML files (*.xml)"));
    if (!fileName.isEmpty()) {
        if (!fileName.endsWith(".xml")) {
            fileName = fileName + ".xml";
        }
    }
}

void Dialog::setDefaultParams()
{
    setButtonBackgroundColor(ui->btnBgColor, mChartParams.mBackgroundColor);
    ui->btnBgColor->setFlat(true);
    connect(ui->btnBgColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnTextColor, mChartParams.mTextColor);
    ui->btnTextColor->setFlat(true);
    connect(ui->btnTextColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnBorderColor, mChartParams.mBorderColor);
    ui->btnBorderColor->setFlat(true);
    connect(ui->btnBorderColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnLegendColor, mChartParams.mLegendColor);
    ui->btnLegendColor->setFlat(true);
    connect(ui->btnLegendColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnGridColor, mChartParams.mGridColor);
    ui->btnGridColor->setFlat(true);
    connect(ui->btnGridColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnGiamSanColor, mChartParams.mGiamSanColor);
    ui->btnGiamSanColor->setFlat(true);
    connect(ui->btnGiamSanColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnGiamGiaColor, mChartParams.mGiamGiaColor);
    ui->btnGiamGiaColor->setFlat(true);
    connect(ui->btnGiamGiaColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnTangGiaColor, mChartParams.mTangGiaColor);
    ui->btnTangGiaColor->setFlat(true);
    connect(ui->btnTangGiaColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnDungGiaColor, mChartParams.mDungGiaColor);
    ui->btnDungGiaColor->setFlat(true);
    connect(ui->btnDungGiaColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnTangTranColor, mChartParams.mTangTranColor);
    ui->btnTangTranColor->setFlat(true);
    connect(ui->btnTangTranColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    setButtonBackgroundColor(ui->btnChartBgColor, mChartParams.mChartBgColor);
    ui->btnChartBgColor->setFlat(true);
    connect(ui->btnChartBgColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    ui->txtChartTitle->setText(QString("%1").arg(mChartParams.mChartTitle));
    ui->txtChartWidth->setText(QString("%1").arg(mChartParams.mChartWidth));
    ui->txtChartHeight->setText(QString("%1").arg(mChartParams.mChartHeight));

    ui->txtChartBgWidth->setText(QString("%1").arg(mChartParams.mChartBgWidth));
    ui->txtChartBgHeight->setText(QString("%1").arg(mChartParams.mChartBgHeight));

    ui->sbYAxisStep->setValue(mChartParams.mYAxisStep);
    ui->txtChartSubTitle->setText(mChartParams.mChartSubTitle);
    ui->txtXMaxValue->setText(QString("%1").arg(mChartParams.mXAxisMaxValue));
}

void Dialog::selectColor()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QColor initialColor = btn->palette().color(QPalette::Button);

    QColor selectedColor = QColorDialog::getColor(initialColor, this);
    if (selectedColor.isValid()) {
        setParamColor(btn, selectedColor);
    }
}

void Dialog::setButtonBackgroundColor(QPushButton *btn, const QColor &color)
{
    QPalette p = btn->palette();
    p.setColor(QPalette::Button, color);
    btn->setPalette(p);
}

void Dialog::setParamColor(QPushButton *btn, const QColor &color)
{
    setButtonBackgroundColor(btn, color);
    if (btn == ui->btnBgColor) {
        mChartParams.mBackgroundColor = color;
    } else if (btn == ui->btnBorderColor) {
        mChartParams.mBorderColor = color;
    } else if (btn == ui->btnLegendColor) {
        mChartParams.mLegendColor = color;
    } else if (btn == ui->btnTextColor) {
        mChartParams.mTextColor = color;
    } else if (btn == ui->btnGiamGiaColor) {
        mChartParams.mGiamGiaColor = color;
    } else if (btn == ui->btnGiamSanColor) {
        mChartParams.mGiamSanColor = color;
    } else if (btn == ui->btnTangGiaColor) {
        mChartParams.mTangGiaColor = color;
    } else if (btn == ui->btnTangTranColor) {
        mChartParams.mTangTranColor = color;
    } else if (btn == ui->btnDungGiaColor) {
        mChartParams.mDungGiaColor = color;
    } else if (btn == ui->btnGridColor) {
        mChartParams.mGridColor = color;
    } else if (btn == ui->btnChartBgColor) {
        mChartParams.mChartBgColor = color;
    }
}

bool Dialog::checkParams()
{
    bool ok;
    int chartWidth = ui->txtChartWidth->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, tr("Failed"), tr("Invalid chart area width"), QMessageBox::Ok);
        ui->txtChartWidth->setFocus();
        return false;
    }

    int chartHeight = ui->txtChartHeight->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, tr("Failed"), tr("Invalid chart area height"), QMessageBox::Ok);
        ui->txtChartHeight->setFocus();
        return false;
    }

    int chartBgWidth = ui->txtChartBgWidth->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, tr("Failed"), tr("Invalid chart background area width"), QMessageBox::Ok);
        ui->txtChartBgWidth->setFocus();
        return false;
    }

    int chartBgHeight = ui->txtChartBgHeight->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, tr("Failed"), tr("Invalid chart background area height"), QMessageBox::Ok);
        ui->txtChartBgHeight->setFocus();
        return false;
    }

    if (chartWidth > chartBgWidth || chartHeight > chartBgHeight) {
        QMessageBox::warning(this, tr("Failed"), tr("Chart rect must not be greater than chart size"), QMessageBox::Ok);
        return false;
    }

    int xMaxValue = ui->txtXMaxValue->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, tr("Failed"), tr("Invalid X max value"), QMessageBox::Ok);
        ui->txtXMaxValue->setFocus();
        return false;
    }

    if (xMaxValue % 5 > 0) {
        QMessageBox::warning(this, tr("Failed"), tr("X max value must be divisible by 5"), QMessageBox::Ok);
        ui->txtXMaxValue->setFocus();
        return false;
    }

    mChartParams.mChartWidth = chartWidth;
    mChartParams.mChartHeight = chartHeight;
    mChartParams.mChartBgWidth = chartBgWidth;
    mChartParams.mChartBgHeight = chartBgHeight;
    mChartParams.mChartTitle = ui->txtChartTitle->text();
    mChartParams.mChartSubTitle = ui->txtChartSubTitle->text();

    mChartParams.mBackgroundColor = ui->btnBgColor->palette().color(QPalette::Button);
    mChartParams.mTextColor = ui->btnTextColor->palette().color(QPalette::Button);
    mChartParams.mBorderColor = ui->btnBorderColor->palette().color(QPalette::Button);
    mChartParams.mLegendColor = ui->btnLegendColor->palette().color(QPalette::Button);

    mChartParams.mGiamSanColor = ui->btnGiamSanColor->palette().color(QPalette::Button);
    mChartParams.mGiamGiaColor = ui->btnGiamGiaColor->palette().color(QPalette::Button);
    mChartParams.mDungGiaColor = ui->btnDungGiaColor->palette().color(QPalette::Button);
    mChartParams.mTangGiaColor = ui->btnTangGiaColor->palette().color(QPalette::Button);
    mChartParams.mTangTranColor = ui->btnTangTranColor->palette().color(QPalette::Button);
    mChartParams.mGridColor = ui->btnGridColor->palette().color(QPalette::Button);
    mChartParams.mChartBgColor = ui->btnChartBgColor->palette().color(QPalette::Button);

    mChartParams.mYAxisStep = ui->sbYAxisStep->value();
    mChartParams.mXAxisMaxValue = xMaxValue;

    return true;
}

void Dialog::run()
{
    if (ui->txtInputFile->text().isEmpty()) {
        QMessageBox::warning(this, tr("No input file"), tr("Please select input data file"), QMessageBox::Ok);
        ui->txtInputFile->setFocus();
        return;
    }

    if (!mChartData.parseData(ui->txtInputFile->text())) {
        QMessageBox::warning(this, tr("Failed"), tr("Failed to parse data file"), QMessageBox::Ok);
        return;
    }

    if (!checkParams()) {
        return;
    }

    if (!outputData()) {
        QMessageBox::warning(this, tr("Failed"), tr("Failed to write data to output file"), QMessageBox::Ok);
        return;
    }

    if (!generateChartFile()) {
        QMessageBox::warning(this, tr("Failed"), tr("Failed to generate chart file"), QMessageBox::Ok);
        return;
    }

    showChartView();
}

QString Dialog::outputFile()
{
    QString currentDir = QDir::current().absolutePath();
    return currentDir + "/data.xml";
}

QString Dialog::chartFile()
{
    QString currentDir = QDir::current().absolutePath();
    return currentDir + "/index.html";
}

bool Dialog::generateChartFile()
{
    QFile sampleFile(":/root/sample.html");
    if (!sampleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed";
        return false;
    }

    QTextStream in(&sampleFile);
    QString content = in.readAll();
    content = content.replace("'width', '970',", QString("'width', '%1',").arg(mChartParams.mChartBgWidth));
    content = content.replace("'height', '500',", QString("'height', '%1',").arg(mChartParams.mChartBgHeight));

    QFile outFile(chartFile());
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&outFile);
    out << content;
    out.flush();
    outFile.close();

    return true;
}

bool Dialog::outputData()
{
    mXMLData.clear();

    mXMLData << "<chart>";
    printData();
    printHeader();
    printFooter();
    mXMLData << "</chart>";

    QString content = mXMLData.join("\n");

    QFile file(outputFile());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out << content;
    out.flush();
    file.close();

    return true;
}

QString Dialog::colorPureCode(const QColor &color)
{
    QString name = color.name();
    return name.replace("#", "");
}

double Dialog::adjustYMaxValue()
{
    int yMax = qRound(mChartData.maxYScale);
    int yMin = qRound(mChartData.minYScale);

    QList<BubbleData> all;
    all.append(mChartData.dungGia);
    all.append(mChartData.giamSan);
    all.append(mChartData.giamGia);
    all.append(mChartData.tangGia);
    all.append(mChartData.tangTran);

    int maxYVal = 0;
    int yVal = 0;
    BubbleData maxBubble;
    double maxRadiusVal = (mChartParams.mChartWidth/NUM_COLUMNS)/2;

    foreach (BubbleData bd, all) {
        yVal = maxRadiusVal * bd.radius/mChartData.maxRadius + bd.y * mChartParams.mChartHeight/(yMax - yMin);
        if (yVal > maxYVal) {
            maxYVal = yVal;
            maxBubble.radius =bd.radius;
            maxBubble.y = bd.y;
        }
    }

    while (maxYVal > mChartParams.mChartHeight) {
        yMax++;
        maxYVal = maxRadiusVal * maxBubble.radius/mChartData.maxRadius + maxBubble.y * mChartParams.mChartHeight/(yMax - yMin);
    }

    return yMax;
}

void Dialog::printHeader()
{
    // X axis
    mXMLData << QString("<axis_category shadow=\"low\" prefix=\"\" min=\"0\" max=\"%1\" steps=\"5\" decimals=\"0\" size=\"13\" color=\"ff0000\" alpha=\"0\" orientation=\"circular\"/>")
                .arg(mChartParams.mXAxisMaxValue);

    mXMLData << "<axis_ticks value_ticks=\"false\" category_ticks=\"false\"/>";

    int yStep = mChartParams.mYAxisStep;
    if (ui->chkYStepAutoCalculated->isChecked()) {
        yStep = calculateYStep();
    }

    int yMax = qRound(mChartData.maxYScale);
    yMax = adjustYMaxValue();

    int yMin = qRound(mChartData.minYScale);
    int yNumSteps = (yMax - yMin)/yStep;

    // Adjust the yMax so that the one with largest radius is not partly hidden

    // Y axix
    mXMLData << QString("<axis_value shadow=\"low\" show_min=\"false\" min=\"%1\" max=\"%2\" steps=\"%3\" size=\"13\" color=\"%4\" alpha=\"75\" prefix=\"\" suffix=\"K\"/>")
                .arg(yMin)
                .arg(yMax)
                .arg(yNumSteps)
                .arg(colorPureCode(mChartParams.mTextColor));

    mXMLData << QString("<chart_border color=\"%1\" bottom_thickness=\"1\" left_thickness=\"1\" top_thickness=\"0\" right_thickness=\"1\"/>")
                .arg(colorPureCode(mChartParams.mBorderColor));
}

int Dialog::calculateYStep()
{
    int yStep = 1;
    int yMax = qRound(mChartData.maxYScale) + 5;
    int yMin = qRound(mChartData.minYScale);
    int yNumSteps = (yMax - yMin)/yStep;
    int stepPixel = mChartParams.mChartHeight/yNumSteps;

    while (stepPixel < MIN_Y_STEP_PIXEL) {
        yStep++;
        yNumSteps = (yMax - yMin)/yStep;
        stepPixel = mChartParams.mChartHeight/yNumSteps;
    }

    return yStep;
}

void Dialog::printFooter()
{
    // Chart grid
    mXMLData << QString("<chart_grid_h alpha=\"2\" color=\"%1\" thickness=\"1\" type=\"solid\"/>").arg(colorPureCode(mChartParams.mGridColor));
    mXMLData << QString("<chart_grid_v alpha=\"2\" color=\"%1\" thickness=\"1\" type=\"solid\"/>").arg(colorPureCode(mChartParams.mGridColor));
    mXMLData << "<chart_label shadow=\"low\" alpha=\"100\" size=\"10\" position=\"center\" color=\"FFFFFF\"/>";

    // Calculate the (x,y) of the chart rect
    int chartX = (mChartParams.mChartBgWidth - mChartParams.mChartWidth)/2;
    int chartY = (mChartParams.mChartBgHeight - mChartParams.mChartHeight)/2 + 5;

    // Calculate the legend coordinates
    int legendHeight = 20;
    int legendMargin = 5;
    int legendY = chartY - legendHeight - 2 * legendMargin;
    int ttvhY = legendY + legendHeight + 10;
    chartY = ttvhY + 20;

    mXMLData << QString("<legend shadow=\"low\" x=\"%1\" y=\"%2\" width=\"%3\" height=\"%4\" margin=\"%5\" fill_alpha=\"10\" size=\"14\" bullet=\"circle\" color=\"%6\" alpha=\"90\"/>")
                .arg(chartX)
                .arg(legendY)
                .arg(mChartParams.mChartWidth)
                .arg(legendHeight)
                .arg(legendMargin)
                .arg(colorPureCode(mChartParams.mLegendColor));

    // Rect & Transition & type
    mXMLData << QString("<chart_rect glow=\"glow1\" bevel=\"bevel2\" x=\"%1\" y=\"%2\" width=\"%3\" height=\"%4\" positive_color=\"%5\" positive_alpha=\"100\"/>")
                .arg(chartX)
                .arg(chartY)
                .arg(mChartParams.mChartWidth)
                .arg(mChartParams.mChartHeight)
                .arg(colorPureCode(mChartParams.mChartBgColor));

    if (ui->chkAnimation->isChecked()) {
        mXMLData << "<chart_transition type=\"drop\" delay=\"0\" duration=\"3\" order=\"all\"/>";
    }
    mXMLData << "<chart_type>bubble</chart_type>";

    // Chart guide
    mXMLData << QString("<chart_guide vertical=\"false\" horizontal=\"true\" thickness=\"1\" color=\"ffffff\" alpha=\"60\" type=\"dashed\" snap_h=\"true\" snap_v=\"true\"") +
                QString(" connect=\"true\" radius=\"5\" fill_alpha=\"75\" fill_color=\"ffffff\" line_thickness=\"0\" text_h_alpha=\"90\" text_v_alpha=\"90\" text_color=\"0\"") +
                QString(" background_color=\"62A9FF\" size=\"12\"/>");

    // Draw the background layer (with color)
    mXMLData << "<draw>";

    // Whole chart background
    mXMLData << QString("<rect bevel=\"bg\" layer=\"background\" x=\"0\" y=\"0\" width=\"%1\" height=\"%2\" fill_color=\"%3\" line_thickness=\"0\"/>")
                .arg(mChartParams.mChartBgWidth + 40)
                .arg(mChartParams.mChartBgHeight)
                .arg(colorPureCode(mChartParams.mBackgroundColor));

    // Chart title
    mXMLData << QString("<text x=\"%1\" y=\"5\" width=\"%2\" height=\"20\" color=\"%3\" alpha=\"50\" size=\"22\" align=\"left\" valign=\"top\">%4</text>")
                .arg(chartX)
                .arg(mChartParams.mChartWidth)
                .arg(colorPureCode(mChartParams.mTextColor))
                .arg(mChartParams.mChartTitle);

    // Chart subtitle
    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"50\" size=\"14\" align=\"left\" valign=\"top\">%5</text>")
                .arg(chartX)
                .arg(chartY + mChartParams.mChartHeight + 10)
                .arg(mChartParams.mChartWidth/2)
                .arg(colorPureCode(mChartParams.mTextColor))
                .arg(mChartParams.mChartSubTitle);

    // Source text
    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"50\" size=\"14\" h_align=\"right\" valign=\"top\">%5</text>")
                .arg(mChartParams.mChartBgWidth/2)
                .arg(chartY + mChartParams.mChartHeight + 10)
                .arg(mChartParams.mChartWidth/2)
                .arg(colorPureCode(mChartParams.mTextColor))
                .arg(tr("Source: KLSTAT"));

    // TTVH
    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"90\" size=\"12\" h_align=\"left\" valign=\"top\">%5</text>")
                .arg(chartX)
                .arg(ttvhY)
                .arg(mChartParams.mChartWidth/5)
                .arg(colorPureCode(mChartParams.mGiamSanColor))
                .arg(QString("TTVH: %1%, %2 points").arg(QString().sprintf("%.3f", mChartData.ttvhGiamSan.percentage)).arg(QString().sprintf("%.3f", mChartData.ttvhGiamSan.point)));

    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"90\" size=\"12\" h_align=\"left\" valign=\"top\">%5</text>")
                .arg(chartX + mChartParams.mChartWidth/5)
                .arg(ttvhY)
                .arg(mChartParams.mChartWidth/5)
                .arg(colorPureCode(mChartParams.mGiamGiaColor))
                .arg(QString("TTVH: %1%, %2 points").arg(QString().sprintf("%.3f", mChartData.ttvhGiamGia.percentage)).arg(QString().sprintf("%.3f", mChartData.ttvhGiamGia.point)));

    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"90\" size=\"12\" h_align=\"center\" valign=\"top\">%5</text>")
                .arg(chartX + 2 * mChartParams.mChartWidth/5)
                .arg(ttvhY)
                .arg(mChartParams.mChartWidth/5)
                .arg(colorPureCode(mChartParams.mDungGiaColor))
                .arg(QString("TTVH: %1%, %2 points").arg(QString().sprintf("%.3f", mChartData.ttvhDungGia.percentage)).arg(QString().sprintf("%.3f", mChartData.ttvhDungGia.point)));

    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"90\" size=\"12\" h_align=\"center\" valign=\"top\">%5</text>")
                .arg(chartX + 3 * mChartParams.mChartWidth/5)
                .arg(ttvhY)
                .arg(mChartParams.mChartWidth/5)
                .arg(colorPureCode(mChartParams.mTangGiaColor))
                .arg(QString("TTVH: %1%, %2 points").arg(QString().sprintf("%.3f", mChartData.ttvhTangGia.percentage)).arg(QString().sprintf("%.3f", mChartData.ttvhTangGia.point)));

    mXMLData << QString("<text x=\"%1\" y=\"%2\" width=\"%3\" height=\"20\" color=\"%4\" alpha=\"90\" size=\"12\" h_align=\"right\" valign=\"top\">%5</text>")
                .arg(chartX + 4 * mChartParams.mChartWidth/5)
                .arg(ttvhY)
                .arg(mChartParams.mChartWidth/5)
                .arg(colorPureCode(mChartParams.mTangTranColor))
                .arg(QString("TTVH: %1%, %2 points").arg(QString().sprintf("%.3f", mChartData.ttvhTangTran.percentage)).arg(QString().sprintf("%.3f", mChartData.ttvhTangTran.point)));
    mXMLData << "</draw>";

    // Legend colors
    mXMLData << "<series_color>";
    mXMLData << "<color>" << colorPureCode(mChartParams.mGiamSanColor) << "</color>";
    mXMLData << "<color>" << colorPureCode(mChartParams.mGiamGiaColor) << "</color>";
    mXMLData << "<color>" << colorPureCode(mChartParams.mDungGiaColor) << "</color>";
    mXMLData << "<color>" << colorPureCode(mChartParams.mTangGiaColor) << "</color>";
    mXMLData << "<color>" << colorPureCode(mChartParams.mTangTranColor) << "</color>";
    mXMLData << "</series_color>";

    mXMLData << "<tooltip color=\"FFFFFF\" alpha=\"75\" size=\"12\" background_color_1=\"31849B\" background_alpha=\"85\" shadow=\"low\"/>";
    mXMLData << "<context_menu print=\"true\" full_screen=\"true\" save_as_jpeg=\"true\"/>";
}

double Dialog::adjustXValue(double initVal, int colIndex, double radius)
{
    int minXPixel = radius + (mChartParams.mXAxisMaxValue/NUM_COLUMNS) * colIndex * mChartParams.mChartWidth/(mChartParams.mXAxisMaxValue);
    double xVal = initVal;
    double xPixel = xVal * mChartParams.mChartWidth/(mChartParams.mXAxisMaxValue);

    while (xPixel < minXPixel) {
        xVal++;
        xPixel = xVal * mChartParams.mChartWidth/(mChartParams.mXAxisMaxValue);
    }

    return xVal;
}

void Dialog::printColumnData(const QString &legend, const QList<BubbleData> &rowData, int colIndex, int maxElements)
{
    int rowSize = rowData.size();

    mXMLData << "<row>";
    mXMLData << QString("<string>%1 (%2)</string>").arg(legend).arg(rowSize);

    // Get the max radius of the bubble, which should be half size of one column
    double maxRadius = (mChartParams.mChartWidth/NUM_COLUMNS)/2;

    // Get the max, min TC
    double minX = 1000000;
    double maxX = 0;

    foreach (BubbleData bubble, rowData) {
        if (bubble.x < minX) minX = bubble.x;
        if (bubble.x > maxX) maxX = bubble.x;
    }

    QTime time;

    int i = 0;
    foreach(BubbleData bubble, rowData) {
        time = QTime::currentTime();
        qsrand((uint)(time.msec() + bubble.x + bubble.y));

        double radius = maxRadius * bubble.radius/mChartData.maxRadius;
        if (radius < MIN_RADIUS) radius = MIN_RADIUS;

        int randX = qrand() % (mChartParams.mXAxisMaxValue/NUM_COLUMNS);
        if (randX == 0) randX = 1;

        // Check if X position is too close to the Y axis
        double xVal = (mChartParams.mXAxisMaxValue/NUM_COLUMNS) * colIndex + randX;

        xVal = adjustXValue(xVal, colIndex, radius);
        xVal += (++i % 2);

        // Check if radius is too big to make the bubble hidden partly at the top

        // Show maCK if radius is big enough
        if (radius >= MIN_RADIUS_FOR_LABEL) {
            // X axis
            mXMLData << QString("<number label=\"%1\">%2</number>").arg(bubble.label).arg(xVal);
        } else {
            mXMLData << QString("<number label=\"\">%1</number>").arg((mChartParams.mXAxisMaxValue/NUM_COLUMNS) * colIndex + randX);
        }
        // Y axis
        mXMLData << QString("<number>%1</number>").arg(bubble.y);
        // Radius with tooltip
        mXMLData << QString("<number tooltip=\"%1\">%2</number>").arg(bubble.tooltip).arg(radius);
    }

    // Null elements
    int nulls = 3 * (maxElements - rowSize);

    for(int i = 1; i <= nulls; ++i) {
        mXMLData << "<null/>";
    }

    mXMLData << "</row>";
}

void Dialog::printData()
{
    mXMLData << "<chart_data>";

    int sizes[5] = {
        mChartData.giamGia.size(),
        mChartData.giamSan.size(),
        mChartData.tangGia.size(),
        mChartData.tangTran.size(),
        mChartData.dungGia.size()
    };

    int max = 0;
    for (int i = 0; i < 5; ++i) {
        if (sizes[i] > max) max = sizes[i];
    }

    // Header data
    mXMLData << "<row>";
    mXMLData << "<null/>";
    for (int i = 1; i <= max; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (j == 1) mXMLData << "<string>x</string>";
            else if (j == 2) mXMLData << "<string>y</string>";
            else mXMLData << "<string>z</string>";
        }
    }
    mXMLData << "</row>";

    // Giam San data row
    printColumnData(tr("Giam San"), mChartData.giamSan, 0, max);

    // Giam Gia data row
    printColumnData(tr("Giam Gia"), mChartData.giamGia, 1, max);

    // Dung Gia data row
    printColumnData(tr("Dung Gia"), mChartData.dungGia, 2, max);

    // Tang Gia data row
    printColumnData(tr("Tang Gia"), mChartData.tangGia, 3, max);

    // Trang Tran data row
    printColumnData(tr("Tang Tran"), mChartData.tangTran, 4, max);

    mXMLData << "</chart_data>";
}

void Dialog::showAbout()
{
    AboutDialog dlg(this);
    dlg.exec();
}

void Dialog::showHelp()
{
    HelpDialog dlg(this);
    dlg.exec();
}

void Dialog::showChartView()
{
    BrowserDialog dlg(this);
    dlg.setChartFile(chartFile());
    dlg.setChartSize(QSize(mChartParams.mChartBgWidth, mChartParams.mChartBgHeight));
    dlg.show();
}

void Dialog::closeEvent(QCloseEvent *ev)
{
    ev->accept();
    saveSettings();
}

void Dialog::saveSettings()
{
    QSettings settings;
    settings.setValue("last_input_file", ui->txtInputFile->text());
    qDebug() << "Saved settings";
}

void Dialog::enableYStep(bool checked)
{
    ui->sbYAxisStep->setEnabled(!checked);
}
