/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../filterBanks/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[507];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 26), // "on_gaussBlurButton_clicked"
QT_MOC_LITERAL(4, 61, 26), // "on_levelSlider_sliderMoved"
QT_MOC_LITERAL(5, 88, 8), // "position"
QT_MOC_LITERAL(6, 97, 27), // "on_levelSlider_valueChanged"
QT_MOC_LITERAL(7, 125, 5), // "value"
QT_MOC_LITERAL(8, 131, 30), // "on_commitChangesButton_clicked"
QT_MOC_LITERAL(9, 162, 32), // "on_actionGaussian_Blur_triggered"
QT_MOC_LITERAL(10, 195, 32), // "on_actionMedian_Filter_triggered"
QT_MOC_LITERAL(11, 228, 29), // "on_actionBox_Filter_triggered"
QT_MOC_LITERAL(12, 258, 35), // "on_actionBilateral_Filter_tri..."
QT_MOC_LITERAL(13, 294, 29), // "on_actionCanny_Edge_triggered"
QT_MOC_LITERAL(14, 324, 27), // "on_actionNL_Means_triggered"
QT_MOC_LITERAL(15, 352, 24), // "on_biSlider_valueChanged"
QT_MOC_LITERAL(16, 377, 27), // "on_actionFilter2D_triggered"
QT_MOC_LITERAL(17, 405, 24), // "on_actionErode_triggered"
QT_MOC_LITERAL(18, 430, 42), // "on_actionNormalized_Block_Fil..."
QT_MOC_LITERAL(19, 473, 33) // "on_actionColor_Transfer_trigg..."

    },
    "MainWindow\0on_openButton_clicked\0\0"
    "on_gaussBlurButton_clicked\0"
    "on_levelSlider_sliderMoved\0position\0"
    "on_levelSlider_valueChanged\0value\0"
    "on_commitChangesButton_clicked\0"
    "on_actionGaussian_Blur_triggered\0"
    "on_actionMedian_Filter_triggered\0"
    "on_actionBox_Filter_triggered\0"
    "on_actionBilateral_Filter_triggered\0"
    "on_actionCanny_Edge_triggered\0"
    "on_actionNL_Means_triggered\0"
    "on_biSlider_valueChanged\0"
    "on_actionFilter2D_triggered\0"
    "on_actionErode_triggered\0"
    "on_actionNormalized_Block_Filter_triggered\0"
    "on_actionColor_Transfer_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    1,   96,    2, 0x08 /* Private */,
       6,    1,   99,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openButton_clicked(); break;
        case 1: _t->on_gaussBlurButton_clicked(); break;
        case 2: _t->on_levelSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_levelSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_commitChangesButton_clicked(); break;
        case 5: _t->on_actionGaussian_Blur_triggered(); break;
        case 6: _t->on_actionMedian_Filter_triggered(); break;
        case 7: _t->on_actionBox_Filter_triggered(); break;
        case 8: _t->on_actionBilateral_Filter_triggered(); break;
        case 9: _t->on_actionCanny_Edge_triggered(); break;
        case 10: _t->on_actionNL_Means_triggered(); break;
        case 11: _t->on_biSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_actionFilter2D_triggered(); break;
        case 13: _t->on_actionErode_triggered(); break;
        case 14: _t->on_actionNormalized_Block_Filter_triggered(); break;
        case 15: _t->on_actionColor_Transfer_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
