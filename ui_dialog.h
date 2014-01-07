/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Tue Dec 4 21:07:53 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnRun;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *txtInputFile;
    QPushButton *btnBrowseInputFile;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QPushButton *btnBgColor;
    QLabel *label_4;
    QPushButton *btnTextColor;
    QLabel *label_5;
    QPushButton *btnBorderColor;
    QLabel *label_6;
    QLineEdit *txtChartTitle;
    QLabel *label_7;
    QPushButton *btnLegendColor;
    QPushButton *btnGiamSanColor;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *btnGiamGiaColor;
    QPushButton *btnDungGiaColor;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *btnTangGiaColor;
    QLabel *label_12;
    QPushButton *btnTangTranColor;
    QLabel *label_13;
    QLineEdit *txtChartWidth;
    QLineEdit *txtChartHeight;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *txtChartBgWidth;
    QLabel *label_16;
    QLineEdit *txtChartBgHeight;
    QLabel *label_17;
    QPushButton *btnGridColor;
    QPushButton *btnChartBgColor;
    QLabel *label_18;
    QLabel *label_19;
    QSpinBox *sbYAxisStep;
    QCheckBox *chkYStepAutoCalculated;
    QLabel *label_2;
    QCheckBox *chkAnimation;
    QLabel *label_20;
    QLineEdit *txtChartSubTitle;
    QLineEdit *txtXMaxValue;
    QLabel *label_21;
    QPushButton *btnAbout;
    QPushButton *btnHelp;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(572, 691);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/bubble.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        btnRun = new QPushButton(Dialog);
        btnRun->setObjectName(QString::fromUtf8("btnRun"));
        btnRun->setGeometry(QRect(220, 630, 121, 41));
        btnRun->setDefault(true);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 531, 63));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 53, 16));
        txtInputFile = new QLineEdit(groupBox);
        txtInputFile->setObjectName(QString::fromUtf8("txtInputFile"));
        txtInputFile->setGeometry(QRect(96, 25, 311, 26));
        btnBrowseInputFile = new QPushButton(groupBox);
        btnBrowseInputFile->setObjectName(QString::fromUtf8("btnBrowseInputFile"));
        btnBrowseInputFile->setGeometry(QRect(420, 24, 85, 27));
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 90, 531, 521));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 280, 131, 16));
        btnBgColor = new QPushButton(groupBox_2);
        btnBgColor->setObjectName(QString::fromUtf8("btnBgColor"));
        btnBgColor->setGeometry(QRect(170, 276, 51, 27));
        btnBgColor->setAutoFillBackground(true);
        btnBgColor->setDefault(false);
        btnBgColor->setFlat(false);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 320, 111, 16));
        btnTextColor = new QPushButton(groupBox_2);
        btnTextColor->setObjectName(QString::fromUtf8("btnTextColor"));
        btnTextColor->setGeometry(QRect(170, 316, 51, 27));
        btnTextColor->setAutoFillBackground(true);
        btnTextColor->setDefault(false);
        btnTextColor->setFlat(false);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 360, 111, 16));
        btnBorderColor = new QPushButton(groupBox_2);
        btnBorderColor->setObjectName(QString::fromUtf8("btnBorderColor"));
        btnBorderColor->setGeometry(QRect(170, 356, 51, 27));
        btnBorderColor->setAutoFillBackground(true);
        btnBorderColor->setDefault(false);
        btnBorderColor->setFlat(false);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 34, 91, 16));
        txtChartTitle = new QLineEdit(groupBox_2);
        txtChartTitle->setObjectName(QString::fromUtf8("txtChartTitle"));
        txtChartTitle->setGeometry(QRect(110, 30, 391, 26));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 400, 111, 16));
        btnLegendColor = new QPushButton(groupBox_2);
        btnLegendColor->setObjectName(QString::fromUtf8("btnLegendColor"));
        btnLegendColor->setGeometry(QRect(170, 396, 51, 27));
        btnLegendColor->setAutoFillBackground(true);
        btnLegendColor->setDefault(false);
        btnLegendColor->setFlat(false);
        btnGiamSanColor = new QPushButton(groupBox_2);
        btnGiamSanColor->setObjectName(QString::fromUtf8("btnGiamSanColor"));
        btnGiamSanColor->setGeometry(QRect(450, 276, 51, 27));
        btnGiamSanColor->setAutoFillBackground(true);
        btnGiamSanColor->setDefault(false);
        btnGiamSanColor->setFlat(false);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 280, 111, 16));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(320, 320, 111, 16));
        btnGiamGiaColor = new QPushButton(groupBox_2);
        btnGiamGiaColor->setObjectName(QString::fromUtf8("btnGiamGiaColor"));
        btnGiamGiaColor->setGeometry(QRect(450, 316, 51, 27));
        btnGiamGiaColor->setAutoFillBackground(true);
        btnGiamGiaColor->setDefault(false);
        btnGiamGiaColor->setFlat(false);
        btnDungGiaColor = new QPushButton(groupBox_2);
        btnDungGiaColor->setObjectName(QString::fromUtf8("btnDungGiaColor"));
        btnDungGiaColor->setGeometry(QRect(450, 356, 51, 27));
        btnDungGiaColor->setAutoFillBackground(true);
        btnDungGiaColor->setDefault(false);
        btnDungGiaColor->setFlat(false);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(320, 360, 111, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(320, 400, 111, 16));
        btnTangGiaColor = new QPushButton(groupBox_2);
        btnTangGiaColor->setObjectName(QString::fromUtf8("btnTangGiaColor"));
        btnTangGiaColor->setGeometry(QRect(450, 396, 51, 27));
        btnTangGiaColor->setAutoFillBackground(true);
        btnTangGiaColor->setDefault(false);
        btnTangGiaColor->setFlat(false);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(320, 440, 111, 16));
        btnTangTranColor = new QPushButton(groupBox_2);
        btnTangTranColor->setObjectName(QString::fromUtf8("btnTangTranColor"));
        btnTangTranColor->setGeometry(QRect(450, 436, 51, 27));
        btnTangTranColor->setAutoFillBackground(true);
        btnTangTranColor->setDefault(false);
        btnTangTranColor->setFlat(false);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 120, 91, 16));
        txtChartWidth = new QLineEdit(groupBox_2);
        txtChartWidth->setObjectName(QString::fromUtf8("txtChartWidth"));
        txtChartWidth->setGeometry(QRect(110, 116, 51, 26));
        txtChartHeight = new QLineEdit(groupBox_2);
        txtChartHeight->setObjectName(QString::fromUtf8("txtChartHeight"));
        txtChartHeight->setGeometry(QRect(170, 116, 51, 26));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(230, 120, 151, 16));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(230, 160, 141, 16));
        txtChartBgWidth = new QLineEdit(groupBox_2);
        txtChartBgWidth->setObjectName(QString::fromUtf8("txtChartBgWidth"));
        txtChartBgWidth->setGeometry(QRect(110, 156, 51, 26));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 160, 91, 16));
        txtChartBgHeight = new QLineEdit(groupBox_2);
        txtChartBgHeight->setObjectName(QString::fromUtf8("txtChartBgHeight"));
        txtChartBgHeight->setGeometry(QRect(170, 156, 51, 26));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 440, 111, 16));
        btnGridColor = new QPushButton(groupBox_2);
        btnGridColor->setObjectName(QString::fromUtf8("btnGridColor"));
        btnGridColor->setGeometry(QRect(170, 436, 51, 27));
        btnGridColor->setAutoFillBackground(true);
        btnGridColor->setDefault(false);
        btnGridColor->setFlat(false);
        btnChartBgColor = new QPushButton(groupBox_2);
        btnChartBgColor->setObjectName(QString::fromUtf8("btnChartBgColor"));
        btnChartBgColor->setGeometry(QRect(170, 476, 51, 27));
        btnChartBgColor->setAutoFillBackground(true);
        btnChartBgColor->setDefault(false);
        btnChartBgColor->setFlat(false);
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 480, 91, 16));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 202, 91, 16));
        sbYAxisStep = new QSpinBox(groupBox_2);
        sbYAxisStep->setObjectName(QString::fromUtf8("sbYAxisStep"));
        sbYAxisStep->setEnabled(false);
        sbYAxisStep->setGeometry(QRect(110, 196, 51, 28));
        sbYAxisStep->setMinimum(1);
        sbYAxisStep->setMaximum(100);
        chkYStepAutoCalculated = new QCheckBox(groupBox_2);
        chkYStepAutoCalculated->setObjectName(QString::fromUtf8("chkYStepAutoCalculated"));
        chkYStepAutoCalculated->setGeometry(QRect(170, 201, 101, 18));
        chkYStepAutoCalculated->setChecked(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 240, 71, 16));
        chkAnimation = new QCheckBox(groupBox_2);
        chkAnimation->setObjectName(QString::fromUtf8("chkAnimation"));
        chkAnimation->setGeometry(QRect(108, 239, 141, 21));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 76, 91, 16));
        txtChartSubTitle = new QLineEdit(groupBox_2);
        txtChartSubTitle->setObjectName(QString::fromUtf8("txtChartSubTitle"));
        txtChartSubTitle->setGeometry(QRect(110, 72, 391, 26));
        txtXMaxValue = new QLineEdit(groupBox_2);
        txtXMaxValue->setObjectName(QString::fromUtf8("txtXMaxValue"));
        txtXMaxValue->setGeometry(QRect(450, 116, 51, 26));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(350, 120, 91, 16));
        btnAbout = new QPushButton(Dialog);
        btnAbout->setObjectName(QString::fromUtf8("btnAbout"));
        btnAbout->setGeometry(QRect(20, 630, 91, 41));
        btnHelp = new QPushButton(Dialog);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setGeometry(QRect(460, 630, 91, 41));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Bubble chart data generator", 0, QApplication::UnicodeUTF8));
        btnRun->setText(QApplication::translate("Dialog", "GO", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "Files", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Data file", 0, QApplication::UnicodeUTF8));
        btnBrowseInputFile->setText(QApplication::translate("Dialog", "Browse...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Options", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Background color", 0, QApplication::UnicodeUTF8));
        btnBgColor->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "Text color", 0, QApplication::UnicodeUTF8));
        btnTextColor->setText(QString());
        label_5->setText(QApplication::translate("Dialog", "Border color", 0, QApplication::UnicodeUTF8));
        btnBorderColor->setText(QString());
        label_6->setText(QApplication::translate("Dialog", "Chart title", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "Legend color", 0, QApplication::UnicodeUTF8));
        btnLegendColor->setText(QString());
        btnGiamSanColor->setText(QString());
        label_8->setText(QApplication::translate("Dialog", "Giam San color", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog", "Giam Gia color", 0, QApplication::UnicodeUTF8));
        btnGiamGiaColor->setText(QString());
        btnDungGiaColor->setText(QString());
        label_10->setText(QApplication::translate("Dialog", "Dung Gia color", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialog", "Tang Gia color", 0, QApplication::UnicodeUTF8));
        btnTangGiaColor->setText(QString());
        label_12->setText(QApplication::translate("Dialog", "Tang Tran color", 0, QApplication::UnicodeUTF8));
        btnTangTranColor->setText(QString());
        label_13->setText(QApplication::translate("Dialog", "Chart rect", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Dialog", "(width x height)", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Dialog", "(width x height)", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Dialog", "Chart size", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Dialog", "Grid color", 0, QApplication::UnicodeUTF8));
        btnGridColor->setText(QString());
        btnChartBgColor->setText(QString());
        label_18->setText(QApplication::translate("Dialog", "Chart area color", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Dialog", "Y axis step", 0, QApplication::UnicodeUTF8));
        chkYStepAutoCalculated->setText(QApplication::translate("Dialog", "Auto calculated", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Animation", 0, QApplication::UnicodeUTF8));
        chkAnimation->setText(QApplication::translate("Dialog", "Transition effect", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Dialog", "Chart sub title", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Dialog", "X axis max value", 0, QApplication::UnicodeUTF8));
        btnAbout->setText(QApplication::translate("Dialog", "&About", 0, QApplication::UnicodeUTF8));
        btnHelp->setText(QApplication::translate("Dialog", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
