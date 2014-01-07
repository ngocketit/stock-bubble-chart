#include "chartparams.h"

#include <QColor>
#include <QString>

ChartParams::ChartParams()
{
    mBackgroundColor = QColor("#000000");
    mTextColor = QColor("#ffffff");
    mBorderColor = QColor("#ffffff");
    mLegendColor = QColor("#ffffff");
    mGiamSanColor = QColor("#00CCCC");
    mGiamGiaColor = QColor("#FF0000");
    mDungGiaColor = QColor("#FFFF00");
    mTangGiaColor = QColor("#00FF00");
    mTangTranColor = QColor("#FF00CC");
    mGridColor = QColor("#ffffff");
    mChartBgColor = QColor("#000000");

    mChartTitle = tr("Bieu do phan vung gia ca");
    mChartSubTitle = tr("VN30-INDEX: 345.23 (-2.12, 0.61%)");
    mChartWidth = 880;
    mChartHeight = 360;

    mChartBgWidth = 960;
    mChartBgHeight = 500;

    mYAxisStep = 1;
    mXAxisMaxValue = 500;
}
