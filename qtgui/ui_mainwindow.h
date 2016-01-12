/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Jun 25 11:10:53 2012
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *mainWidget;
    QTableWidget *mainList;
    QPushButton *mainLight;
    QPushButton *mainTv;
    QPushButton *mainReg;
    QPushButton *mainAir;
    QPushButton *mainStart;
    QWidget *zTvWidget;
    QPushButton *Back;
    QPushButton *Power;
    QPushButton *tvChUp;
    QPushButton *tvChDown;
    QPushButton *tvVoDown;
    QPushButton *tvVoUp;
    QGraphicsView *tvImage;
    QWidget *zLightWidget;
    QPushButton *Back_2;
    QPushButton *Power_2;
    QPushButton *lightBrUp;
    QPushButton *lightBrDown;
    QGraphicsView *lightImage;
    QWidget *zRefWidget;
    QPushButton *Back_3;
    QPushButton *Power_3;
    QPushButton *refTemUp;
    QPushButton *refTemDown;
    QGraphicsView *refImage;
    QWidget *zAirWidget;
    QPushButton *Back_4;
    QPushButton *Power_4;
    QPushButton *airTempUp;
    QPushButton *airTempDown;
    QPushButton *airPowerUp;
    QGraphicsView *airImage;
    QPushButton *airPowerDown;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 1600);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    mainWidget = new QWidget(centralWidget);
    mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
    mainWidget->setGeometry(QRect(0, 0, 800, 480));
    mainWidget->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Main3.bmp);"));
    mainList = new QTableWidget(mainWidget);
    mainList->setObjectName(QString::fromUtf8("mainList"));
    mainList->setGeometry(QRect(450, 100, 311, 210));
    mainList->setMouseTracking(false);
    mainList->setStyleSheet(QString::fromUtf8("background-image: url();"));
    mainLight = new QPushButton(mainWidget);
    mainLight->setObjectName(QString::fromUtf8("mainLight"));
    mainLight->setGeometry(QRect(50, 112, 121, 91));
    mainLight->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Air.bmp);"));
    mainLight->setFlat(true);
    mainTv = new QPushButton(mainWidget);
    mainTv->setObjectName(QString::fromUtf8("mainTv"));
    mainTv->setGeometry(QRect(190, 112, 121, 91));
    mainTv->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/TV_button.png);"));
    mainTv->setFlat(true);
    mainReg = new QPushButton(mainWidget);
    mainReg->setObjectName(QString::fromUtf8("mainReg"));
    mainReg->setGeometry(QRect(50, 218, 121, 91));
    mainReg->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Reg_button.bmp);"));
    mainReg->setFlat(true);
    mainAir = new QPushButton(mainWidget);
    mainAir->setObjectName(QString::fromUtf8("mainAir"));
    mainAir->setGeometry(QRect(190, 218, 121, 91));
    mainAir->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Air_button.png);"));
    mainAir->setFlat(true);
    mainStart = new QPushButton(mainWidget);
    mainStart->setObjectName(QString::fromUtf8("mainStart"));
    mainStart->setGeometry(QRect(550, 330, 210, 78));
    mainStart->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Select.bmp);"));
    mainStart->setFlat(true);
    zTvWidget = new QWidget(mainWidget);
    zTvWidget->setObjectName(QString::fromUtf8("zTvWidget"));
    zTvWidget->setGeometry(QRect(0, 600, 800, 480));
    zTvWidget->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Main3_tv.bmp);"));
    Back = new QPushButton(zTvWidget);
    Back->setObjectName(QString::fromUtf8("Back"));
    Back->setGeometry(QRect(330, 330, 210, 78));
    Back->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Back.bmp);"));
    Back->setFlat(true);
    Power = new QPushButton(zTvWidget);
    Power->setObjectName(QString::fromUtf8("Power"));
    Power->setGeometry(QRect(550, 330, 210, 78));
    Power->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Power.bmp);"));
    Power->setFlat(true);
    tvChUp = new QPushButton(zTvWidget);
    tvChUp->setObjectName(QString::fromUtf8("tvChUp"));
    tvChUp->setGeometry(QRect(510, 120, 200, 38));
    tvChUp->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_ch_up.bmp);"));
    tvChUp->setFlat(true);
    tvChDown = new QPushButton(zTvWidget);
    tvChDown->setObjectName(QString::fromUtf8("tvChDown"));
    tvChDown->setGeometry(QRect(510, 160, 200, 38));
    tvChDown->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_ch_dw.bmp);"));
    tvChDown->setFlat(true);
    tvVoDown = new QPushButton(zTvWidget);
    tvVoDown->setObjectName(QString::fromUtf8("tvVoDown"));
    tvVoDown->setGeometry(QRect(510, 260, 200, 38));
    tvVoDown->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_vo_dw.bmp);"));
    tvVoDown->setFlat(true);
    tvVoUp = new QPushButton(zTvWidget);
    tvVoUp->setObjectName(QString::fromUtf8("tvVoUp"));
    tvVoUp->setGeometry(QRect(510, 220, 200, 38));
    tvVoUp->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_vo_up.bmp);"));
    tvVoUp->setFlat(true);
    tvImage = new QGraphicsView(zTvWidget);
    tvImage->setObjectName(QString::fromUtf8("tvImage"));
    tvImage->setGeometry(QRect(40, 100, 325, 270));
    tvImage->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Tv.bmp);"));
    tvImage->setFrameShape(QFrame::NoFrame);
    zLightWidget = new QWidget(mainWidget);
    zLightWidget->setObjectName(QString::fromUtf8("zLightWidget"));
    zLightWidget->setGeometry(QRect(0, 600, 800, 480));
    zLightWidget->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Main3_light.bmp);"));
    Back_2 = new QPushButton(zLightWidget);
    Back_2->setObjectName(QString::fromUtf8("Back_2"));
    Back_2->setGeometry(QRect(330, 330, 210, 78));
    Back_2->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Back.bmp);"));
    Back_2->setFlat(true);
    Power_2 = new QPushButton(zLightWidget);
    Power_2->setObjectName(QString::fromUtf8("Power_2"));
    Power_2->setGeometry(QRect(550, 330, 210, 78));
    Power_2->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Power.bmp);"));
    Power_2->setFlat(true);
    lightBrUp = new QPushButton(zLightWidget);
    lightBrUp->setObjectName(QString::fromUtf8("lightBrUp"));
    lightBrUp->setGeometry(QRect(510, 120, 200, 38));
    lightBrUp->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Bright_up.bmp);"));
    lightBrUp->setFlat(true);
    lightBrDown = new QPushButton(zLightWidget);
    lightBrDown->setObjectName(QString::fromUtf8("lightBrDown"));
    lightBrDown->setGeometry(QRect(510, 160, 200, 38));
    lightBrDown->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Bright_dw.bmp);"));
    lightBrDown->setFlat(true);
    lightImage = new QGraphicsView(zLightWidget);
    lightImage->setObjectName(QString::fromUtf8("lightImage"));
    lightImage->setGeometry(QRect(60, 110, 140, 270));
    lightImage->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Light.bmp);"));
    lightImage->setFrameShape(QFrame::NoFrame);
    zRefWidget = new QWidget(mainWidget);
    zRefWidget->setObjectName(QString::fromUtf8("zRefWidget"));
    zRefWidget->setGeometry(QRect(0, 600, 800, 480));
    zRefWidget->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Main3_tv.bmp);"));
    Back_3 = new QPushButton(zRefWidget);
    Back_3->setObjectName(QString::fromUtf8("Back_3"));
    Back_3->setGeometry(QRect(330, 330, 210, 78));
    Back_3->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Back.bmp);"));
    Back_3->setFlat(true);
    Power_3 = new QPushButton(zRefWidget);
    Power_3->setObjectName(QString::fromUtf8("Power_3"));
    Power_3->setGeometry(QRect(550, 330, 210, 78));
    Power_3->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Power.bmp);"));
    Power_3->setFlat(true);
    refTemUp = new QPushButton(zRefWidget);
    refTemUp->setObjectName(QString::fromUtf8("refTemUp"));
    refTemUp->setGeometry(QRect(510, 120, 200, 38));
    refTemUp->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_temp_up.bmp);"));
    refTemUp->setFlat(true);
    refTemDown = new QPushButton(zRefWidget);
    refTemDown->setObjectName(QString::fromUtf8("refTemDown"));
    refTemDown->setGeometry(QRect(510, 160, 200, 38));
    refTemDown->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_temp_dw.bmp);"));
    refTemDown->setFlat(true);
    refImage = new QGraphicsView(zRefWidget);
    refImage->setObjectName(QString::fromUtf8("refImage"));
    refImage->setGeometry(QRect(60, 120, 144, 270));
    refImage->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Ref.bmp);"));
    refImage->setFrameShape(QFrame::NoFrame);
    zAirWidget = new QWidget(mainWidget);
    zAirWidget->setObjectName(QString::fromUtf8("zAirWidget"));
    zAirWidget->setGeometry(QRect(0, 500, 800, 480));
    zAirWidget->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Main3_tv.bmp);"));
    Back_4 = new QPushButton(zAirWidget);
    Back_4->setObjectName(QString::fromUtf8("Back_4"));
    Back_4->setGeometry(QRect(330, 330, 210, 78));
    Back_4->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Back.bmp);"));
    Back_4->setFlat(true);
    Power_4 = new QPushButton(zAirWidget);
    Power_4->setObjectName(QString::fromUtf8("Power_4"));
    Power_4->setGeometry(QRect(550, 330, 210, 78));
    Power_4->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_Power.bmp);"));
    Power_4->setFlat(true);
    airTempUp = new QPushButton(zAirWidget);
    airTempUp->setObjectName(QString::fromUtf8("airTempUp"));
    airTempUp->setGeometry(QRect(510, 120, 200, 38));
    airTempUp->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_temp_up.bmp);"));
    airTempUp->setFlat(true);
    airTempDown = new QPushButton(zAirWidget);
    airTempDown->setObjectName(QString::fromUtf8("airTempDown"));
    airTempDown->setGeometry(QRect(510, 160, 200, 38));
    airTempDown->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_temp_dw.bmp);"));
    airTempDown->setFlat(true);
    airPowerUp = new QPushButton(zAirWidget);
    airPowerUp->setObjectName(QString::fromUtf8("airPowerUp"));
    airPowerUp->setGeometry(QRect(510, 220, 200, 38));
    airPowerUp->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_wind_up.bmp);"));
    airPowerUp->setFlat(true);
    airImage = new QGraphicsView(zAirWidget);
    airImage->setObjectName(QString::fromUtf8("airImage"));
    airImage->setGeometry(QRect(70, 120, 84, 270));
    airImage->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/MainUI/Air.bmp);"));
    airImage->setFrameShape(QFrame::NoFrame);
    airPowerDown = new QPushButton(zAirWidget);
    airPowerDown->setObjectName(QString::fromUtf8("airPowerDown"));
    airPowerDown->setGeometry(QRect(510, 260, 200, 38));
    airPowerDown->setStyleSheet(QString::fromUtf8("background-image: url(/Diaimage/DeviceUI/Device_Main_wind_dw.bmp);"));
    airPowerDown->setFlat(true);
    MainWindow->setCentralWidget(centralWidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    if (mainList->columnCount() < 2)
        mainList->setColumnCount(2);

    QTableWidgetItem *__colItem = new QTableWidgetItem();
    __colItem->setText(QApplication::translate("MainWindow", "Device Name", 0, QApplication::UnicodeUTF8));
    mainList->setHorizontalHeaderItem(0, __colItem);

    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    __colItem1->setText(QApplication::translate("MainWindow", "Addr", 0, QApplication::UnicodeUTF8));
    mainList->setHorizontalHeaderItem(1, __colItem1);
    if (mainList->rowCount() < 6)
        mainList->setRowCount(6);

    QTableWidgetItem *__rowItem = new QTableWidgetItem();
    __rowItem->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
    mainList->setVerticalHeaderItem(0, __rowItem);

    QTableWidgetItem *__rowItem1 = new QTableWidgetItem();
    __rowItem1->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
    mainList->setVerticalHeaderItem(1, __rowItem1);

    QTableWidgetItem *__rowItem2 = new QTableWidgetItem();
    __rowItem2->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
    mainList->setVerticalHeaderItem(2, __rowItem2);

    QTableWidgetItem *__rowItem3 = new QTableWidgetItem();
    __rowItem3->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
    mainList->setVerticalHeaderItem(3, __rowItem3);

    QTableWidgetItem *__rowItem4 = new QTableWidgetItem();
    __rowItem4->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
    mainList->setVerticalHeaderItem(4, __rowItem4);

    QTableWidgetItem *__rowItem5 = new QTableWidgetItem();
    __rowItem5->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
    mainList->setVerticalHeaderItem(5, __rowItem5);

    bool __sortingEnabled = mainList->isSortingEnabled();
    mainList->setSortingEnabled(false);

    QTableWidgetItem *__item = new QTableWidgetItem();
    __item->setText(QString());
    mainList->setItem(0, 0, __item);

    QTableWidgetItem *__item1 = new QTableWidgetItem();
    __item1->setText(QString());
    mainList->setItem(0, 1, __item1);

    mainList->setSortingEnabled(__sortingEnabled);

    mainLight->setText(QString());
    mainTv->setText(QString());
    mainReg->setText(QString());
    mainAir->setText(QString());
    mainStart->setText(QString());
    Back->setText(QString());
    Power->setText(QString());
    tvChUp->setText(QString());
    tvChDown->setText(QString());
    tvVoDown->setText(QString());
    tvVoUp->setText(QString());
    Back_2->setText(QString());
    Power_2->setText(QString());
    lightBrUp->setText(QString());
    lightBrDown->setText(QString());
    Back_3->setText(QString());
    Power_3->setText(QString());
    refTemUp->setText(QString());
    refTemDown->setText(QString());
    Back_4->setText(QString());
    Power_4->setText(QString());
    airTempUp->setText(QString());
    airTempDown->setText(QString());
    airPowerUp->setText(QString());
    airPowerDown->setText(QString());
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_MAINWINDOW_H
