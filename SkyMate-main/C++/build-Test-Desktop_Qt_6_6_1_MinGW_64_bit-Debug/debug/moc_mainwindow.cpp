/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Test/mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "updateUIFromApiResponse",
    "",
    "jsonObject",
    "updateUIFromHourlyForecast",
    "forecastWeatherJsonObject",
    "updateUIFromFiveDayForecast",
    "Map_button",
    "Home_button",
    "Dashboard_button",
    "Search_button",
    "Setting_button",
    "on_comboBox_currentIndexChanged",
    "index"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[27];
    char stringdata5[26];
    char stringdata6[28];
    char stringdata7[11];
    char stringdata8[12];
    char stringdata9[17];
    char stringdata10[14];
    char stringdata11[15];
    char stringdata12[32];
    char stringdata13[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 23),  // "updateUIFromApiResponse"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 10),  // "jsonObject"
        QT_MOC_LITERAL(47, 26),  // "updateUIFromHourlyForecast"
        QT_MOC_LITERAL(74, 25),  // "forecastWeatherJsonObject"
        QT_MOC_LITERAL(100, 27),  // "updateUIFromFiveDayForecast"
        QT_MOC_LITERAL(128, 10),  // "Map_button"
        QT_MOC_LITERAL(139, 11),  // "Home_button"
        QT_MOC_LITERAL(151, 16),  // "Dashboard_button"
        QT_MOC_LITERAL(168, 13),  // "Search_button"
        QT_MOC_LITERAL(182, 14),  // "Setting_button"
        QT_MOC_LITERAL(197, 31),  // "on_comboBox_currentIndexChanged"
        QT_MOC_LITERAL(229, 5)   // "index"
    },
    "MainWindow",
    "updateUIFromApiResponse",
    "",
    "jsonObject",
    "updateUIFromHourlyForecast",
    "forecastWeatherJsonObject",
    "updateUIFromFiveDayForecast",
    "Map_button",
    "Home_button",
    "Dashboard_button",
    "Search_button",
    "Setting_button",
    "on_comboBox_currentIndexChanged",
    "index"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x0a,    1 /* Public */,
       4,    1,   71,    2, 0x0a,    3 /* Public */,
       6,    1,   74,    2, 0x0a,    5 /* Public */,
       7,    0,   77,    2, 0x08,    7 /* Private */,
       8,    0,   78,    2, 0x08,    8 /* Private */,
       9,    0,   79,    2, 0x08,    9 /* Private */,
      10,    0,   80,    2, 0x08,   10 /* Private */,
      11,    0,   81,    2, 0x08,   11 /* Private */,
      12,    1,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    5,
    QMetaType::Void, QMetaType::QJsonObject,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'updateUIFromApiResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'updateUIFromHourlyForecast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'updateUIFromFiveDayForecast'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'Map_button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Home_button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Dashboard_button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Search_button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Setting_button'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateUIFromApiResponse((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->updateUIFromHourlyForecast((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 2: _t->updateUIFromFiveDayForecast((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->Map_button(); break;
        case 4: _t->Home_button(); break;
        case 5: _t->Dashboard_button(); break;
        case 6: _t->Search_button(); break;
        case 7: _t->Setting_button(); break;
        case 8: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
