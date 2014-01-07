#include <QtGui/QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("Chung khoan Kim Long");
    a.setOrganizationDomain("www.kls.vn");
    a.setApplicationName("BubbleChartDataGenerator");

    Dialog w;
    w.show();

    return a.exec();
}

