#ifndef CHARTDATA_H
#define CHARTDATA_H

#include "bubbledata.h"
#include <QObject>
#include <QList>

class ChartData : public QObject
{
    Q_OBJECT

public:
    struct LineData {
        QString maCK;
        double giaTran;
        double giaSan;
        double giaTC;
        double giaKhop;
        double anhHuongVonHoa;
        double anhHuongThucTe;
        double deltaGia;
        double deltaGiaPercent;
        double diemAnhHuong;

        QString KLGD;
        QString GTGD;
        QString KLNY;

        LineData(const QString &ma, double tran, double san, double tc, double khop,
                 double ahvh, double ahtt, double diemah, double dtGia, double dtGiaPercent, const QString &klgd,
                 const QString &gtgd, const QString &klny)
        {
            maCK = ma;
            giaTran = tran;
            giaSan = san;
            giaTC = tc;
            giaKhop = khop;
            anhHuongVonHoa = ahvh;
            anhHuongThucTe = ahtt;
            diemAnhHuong = diemah;
            deltaGia = dtGia;
            deltaGiaPercent = dtGiaPercent;
            KLGD = klgd;
            KLNY = klny;
            GTGD = gtgd;
        }
    };

    struct TTVH {
        double percentage;
        double point;

        TTVH() {
            reset();
        }

        void reset() {
            percentage = 0;
            point = 0;
        }
    };

    explicit ChartData(QObject *parent = 0);
    bool parseData(const QString &dataFile);
    bool parseDataLine(const QString &line);

    QList<BubbleData> giamSan;
    QList<BubbleData> giamGia;
    QList<BubbleData> dungGia;
    QList<BubbleData> tangGia;
    QList<BubbleData> tangTran;

    TTVH ttvhGiamSan;
    TTVH ttvhGiamGia;
    TTVH ttvhDungGia;
    TTVH ttvhTangGia;
    TTVH ttvhTangTran;

    double minYScale;
    double maxYScale;

    double minRadius;
    double maxRadius;

private:
    QList<LineData> mRawData;

private:
    void resetData();
};

#endif // CHARTDATA_H
