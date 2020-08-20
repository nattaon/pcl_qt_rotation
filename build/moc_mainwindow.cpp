/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "ButtonLoadPressed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "ButtonSavePressed"
QT_MOC_LITERAL(4, 48, 19), // "ButtonFilterPressed"
QT_MOC_LITERAL(5, 68, 24), // "ButtonResetCameraPressed"
QT_MOC_LITERAL(6, 93, 19), // "ButtonViewUpPressed"
QT_MOC_LITERAL(7, 113, 21), // "ButtonViewDownPressed"
QT_MOC_LITERAL(8, 135, 22), // "ButtonViewRightPressed"
QT_MOC_LITERAL(9, 158, 21), // "ButtonViewLeftPressed"
QT_MOC_LITERAL(10, 180, 27), // "ButtonAlignAxisMajorPressed"
QT_MOC_LITERAL(11, 208, 28), // "ButtonAlignAxisMiddlePressed"
QT_MOC_LITERAL(12, 237, 27), // "ButtonAlignAxisMinorPressed"
QT_MOC_LITERAL(13, 265, 16), // "ButtonPCAPressed"
QT_MOC_LITERAL(14, 282, 24), // "ButtonBoundingBoxPressed"
QT_MOC_LITERAL(15, 307, 17), // "ButtonXrotPressed"
QT_MOC_LITERAL(16, 325, 17), // "ButtonYrotPressed"
QT_MOC_LITERAL(17, 343, 17) // "ButtonZrotPressed"

    },
    "MainWindow\0ButtonLoadPressed\0\0"
    "ButtonSavePressed\0ButtonFilterPressed\0"
    "ButtonResetCameraPressed\0ButtonViewUpPressed\0"
    "ButtonViewDownPressed\0ButtonViewRightPressed\0"
    "ButtonViewLeftPressed\0ButtonAlignAxisMajorPressed\0"
    "ButtonAlignAxisMiddlePressed\0"
    "ButtonAlignAxisMinorPressed\0"
    "ButtonPCAPressed\0ButtonBoundingBoxPressed\0"
    "ButtonXrotPressed\0ButtonYrotPressed\0"
    "ButtonZrotPressed"
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
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->ButtonLoadPressed(); break;
        case 1: _t->ButtonSavePressed(); break;
        case 2: _t->ButtonFilterPressed(); break;
        case 3: _t->ButtonResetCameraPressed(); break;
        case 4: _t->ButtonViewUpPressed(); break;
        case 5: _t->ButtonViewDownPressed(); break;
        case 6: _t->ButtonViewRightPressed(); break;
        case 7: _t->ButtonViewLeftPressed(); break;
        case 8: _t->ButtonAlignAxisMajorPressed(); break;
        case 9: _t->ButtonAlignAxisMiddlePressed(); break;
        case 10: _t->ButtonAlignAxisMinorPressed(); break;
        case 11: _t->ButtonPCAPressed(); break;
        case 12: _t->ButtonBoundingBoxPressed(); break;
        case 13: _t->ButtonXrotPressed(); break;
        case 14: _t->ButtonYrotPressed(); break;
        case 15: _t->ButtonZrotPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
