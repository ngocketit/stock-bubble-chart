#include "bubbledata.h"

BubbleData::BubbleData()
{
    x = 0;
    y = 0;
    radius = 0;
}

BubbleData::BubbleData(double x, double y, double radius, const QString &label, const QString &tooltip)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->label = label;
    this->tooltip = tooltip;
}
