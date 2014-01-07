#ifndef BUBBLEDATA_H
#define BUBBLEDATA_H

#include <QString>

class BubbleData
{
public:
    BubbleData();
    BubbleData(double x, double y, double radius, const QString &label, const QString &tooltip);

    double x;
    double y;
    double radius;
    QString label;
    QString tooltip;
};

#endif // BUBBLEDATA_H
