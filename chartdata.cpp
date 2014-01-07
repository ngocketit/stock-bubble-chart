#include "chartdata.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

#define NUM_FILEDS  11

ChartData::ChartData(QObject *parent) :
    QObject(parent)
{
}

void ChartData::resetData()
{
    giamGia.clear();
    giamSan.clear();
    dungGia.clear();
    tangTran.clear();
    tangGia.clear();

    ttvhGiamSan.reset();
    ttvhGiamGia.reset();
    ttvhDungGia.reset();
    ttvhTangGia.reset();
    ttvhTangTran.reset();
}

bool ChartData::parseData(const QString &dataFile)
{
    QFile file(dataFile);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream stream(&file);
    mRawData.clear();

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        line = line.trimmed();
        if (!parseDataLine(line)) continue;
    }

    if (mRawData.isEmpty()) return false;

    resetData();

    BubbleData bd;

    double minY = 0;
    double maxY = 0;

    double minR = 1000000;
    double maxR = 0;

    int i = 0;
    foreach (LineData data, mRawData) {
        if (data.giaKhop < minY) minY = data.giaKhop;
        if (data.giaKhop > maxY) maxY = data.giaKhop;

        if (data.anhHuongVonHoa < minR) minR = data.anhHuongVonHoa;
        if (data.anhHuongVonHoa > maxR) maxR = data.anhHuongVonHoa;

        bd.x = (++i) * data.giaTC + data.giaSan;
        bd.y = data.giaKhop;
        bd.radius = data.anhHuongVonHoa;
        bd.label = data.maCK;
        bd.tooltip = QString("%1 - %2(%3; %4%)\nKLNY: %5\nKLGD: %6 - GTGD: %7\nTLAH: %8 - DiemAH: %9")
                .arg(data.maCK)
                .arg(data.giaKhop)
                .arg(data.deltaGia)
                .arg(data.deltaGiaPercent)
                .arg(data.KLNY)
                .arg(data.KLGD)
                .arg(data.GTGD)
                .arg(QString("%1%").arg(data.anhHuongVonHoa))
                .arg(QString().sprintf("%.3f", data.diemAnhHuong));

        if (data.giaKhop == data.giaSan) {
            giamSan.append(bd);
            ttvhGiamSan.percentage += data.anhHuongVonHoa;
            ttvhGiamSan.point += data.diemAnhHuong;
        } else if (data.giaKhop == data.giaTran) {
            tangTran.append(bd);
            ttvhTangTran.percentage += data.anhHuongVonHoa;
            ttvhTangTran.point += data.diemAnhHuong;
        } else if (data.giaKhop > data.giaTC && data.giaKhop < data.giaTran) {
            tangGia.append(bd);
            ttvhTangGia.percentage += data.anhHuongVonHoa;
            ttvhTangGia.point += data.diemAnhHuong;
        } else if (data.giaKhop == data.giaTC) {
            dungGia.append(bd);
            ttvhDungGia.percentage += data.anhHuongVonHoa;
            ttvhDungGia.point += data.diemAnhHuong;
        } else if (data.giaKhop > data.giaSan && data.giaKhop < data.giaTC) {
            giamGia.append(bd);
            ttvhGiamGia.percentage += data.anhHuongVonHoa;
            ttvhGiamGia.point += data.diemAnhHuong;
        }
    }

    minYScale = minY;
    maxYScale = maxY;

    minRadius = minR;
    maxRadius = maxR;

    return true;
}

bool ChartData::parseDataLine(const QString &line)
{
    QStringList parts = line.split("\t");

    // Not a valid line, abort
    if (parts.count() < NUM_FILEDS) {
        return false;
    }

    QString maCK = parts[0];

    // Check if it's a data line or header line
    bool ok;
    double giaTran = parts[1].toDouble(&ok);
    if (!ok) return false;

    double giaSan = parts[2].toDouble(&ok);
    if (!ok) return false;

    double giaTC = parts[3].toDouble(&ok);
    if (!ok) return false;

    double giaKhop = parts[4].toDouble(&ok);
    if (!ok) return false;

    double tdGia = parts[5].toDouble(&ok);
    if (!ok) return false;

    double tdGiaPercent = parts[6].replace("%", "").toDouble(&ok);
    if (!ok) return false;

    QString klgd = parts[7];
    QString gtgd = parts[8];

    double anhHuongVonHoa = parts[9].replace("%", "").toDouble(&ok);
    if (!ok) return false;

    double anhHuongThucTe = parts[10].replace("%", "").toDouble(&ok);
    if (!ok) return false;

    double diemAnhHuong = parts[11].replace("%", "").toDouble(&ok);
    if (!ok) return false;

    QString klny = parts[12];

    LineData data = LineData(maCK, giaTran, giaSan, giaTC, giaKhop, anhHuongVonHoa,
                             anhHuongThucTe, diemAnhHuong, tdGia, tdGiaPercent, klgd, gtgd, klny);

    mRawData.append(data);

    return true;
}

