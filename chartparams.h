#ifndef CHARTPARAMS_H
#define CHARTPARAMS_H

#include <QColor>

class ChartParams : public QObject
{
public:
    ChartParams();

    QColor mBackgroundColor;
    QColor mTextColor;
    QColor mBorderColor;
    QColor mLegendColor;
    QColor mGiamSanColor;
    QColor mGiamGiaColor;
    QColor mDungGiaColor;
    QColor mTangGiaColor;
    QColor mTangTranColor;
    QColor mGridColor;
    QColor mChartBgColor;

    QString mChartTitle;
    QString mChartSubTitle;
    int mChartWidth;
    int mChartHeight;

    int mChartBgWidth;
    int mChartBgHeight;

    int mYAxisStep;
    int mXAxisMaxValue;

};

#endif // CHARTPARAMS_H
