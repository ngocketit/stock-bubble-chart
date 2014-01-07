#-------------------------------------------------
#
# Project created by QtCreator 2012-11-25T21:54:32
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = BubbleChartXML
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp \
    chartparams.cpp \
    chartdata.cpp \
    bubbledata.cpp \
    aboutdialog.cpp \
    helpdialog.cpp \
    browserdialog.cpp

HEADERS  += dialog.h \
    chartparams.h \
    chartdata.h \
    bubbledata.h \
    aboutdialog.h \
    helpdialog.h \
    browserdialog.h

FORMS    += dialog.ui \
    aboutdialog.ui \
    helpdialog.ui \
    browserdialog.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    ico.rc \
    help.html

RC_FILE = ico.rc













