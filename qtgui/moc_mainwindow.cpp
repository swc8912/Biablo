/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Jun 25 12:33:48 2012
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      23,   12,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     284,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     330,   11,   11,   11, 0x08,
     351,   11,   11,   11, 0x08,
     371,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,
     433,   11,   11,   11, 0x08,
     455,   11,   11,   11, 0x08,
     474,   11,   11,   11, 0x08,
     492,   11,   11,   11, 0x08,
     513,   11,   11,   11, 0x08,
     536,   11,   11,   11, 0x08,
     557,   11,   11,   11, 0x08,
     577,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0row,column\0"
    "on_mainList_cellClicked(int,int)\0"
    "on_airTempUp_clicked()\0on_airTempDown_clicked()\0"
    "on_airPowerUp_clicked()\0"
    "on_airPowerDown_clicked()\0"
    "on_Power_4_clicked()\0on_Back_4_clicked()\0"
    "on_lightBrUp_clicked()\0on_lightBrDown_clicked()\0"
    "on_Power_2_clicked()\0on_Back_2_clicked()\0"
    "on_refTemUp_clicked()\0on_refTemDown_clicked()\0"
    "on_Power_3_clicked()\0on_Back_3_clicked()\0"
    "on_tvVoUp_clicked()\0on_tvVoDown_clicked()\0"
    "on_tvChUp_clicked()\0on_tvChDown_clicked()\0"
    "on_Power_clicked()\0on_Back_clicked()\0"
    "on_mainReg_clicked()\0on_mainLight_clicked()\0"
    "on_mainAir_clicked()\0on_mainTv_clicked()\0"
    "on_mainStart_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
	return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_mainList_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: on_airTempUp_clicked(); break;
        case 2: on_airTempDown_clicked(); break;
        case 3: on_airPowerUp_clicked(); break;
        case 4: on_airPowerDown_clicked(); break;
        case 5: on_Power_4_clicked(); break;
        case 6: on_Back_4_clicked(); break;
        case 7: on_lightBrUp_clicked(); break;
        case 8: on_lightBrDown_clicked(); break;
        case 9: on_Power_2_clicked(); break;
        case 10: on_Back_2_clicked(); break;
        case 11: on_refTemUp_clicked(); break;
        case 12: on_refTemDown_clicked(); break;
        case 13: on_Power_3_clicked(); break;
        case 14: on_Back_3_clicked(); break;
        case 15: on_tvVoUp_clicked(); break;
        case 16: on_tvVoDown_clicked(); break;
        case 17: on_tvChUp_clicked(); break;
        case 18: on_tvChDown_clicked(); break;
        case 19: on_Power_clicked(); break;
        case 20: on_Back_clicked(); break;
        case 21: on_mainReg_clicked(); break;
        case 22: on_mainLight_clicked(); break;
        case 23: on_mainAir_clicked(); break;
        case 24: on_mainTv_clicked(); break;
        case 25: on_mainStart_clicked(); break;
        }
        _id -= 26;
    }
    return _id;
}
