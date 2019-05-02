/****************************************************************************
** Meta object code from reading C++ file 'OpenglWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OpenglWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenglWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenglWidget_t {
    QByteArrayData data[12];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenglWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenglWidget_t qt_meta_stringdata_OpenglWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OpenglWidget"
QT_MOC_LITERAL(1, 13, 6), // "setRed"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "val"
QT_MOC_LITERAL(4, 25, 8), // "setGreen"
QT_MOC_LITERAL(5, 34, 7), // "setBlue"
QT_MOC_LITERAL(6, 42, 8), // "setAlpha"
QT_MOC_LITERAL(7, 51, 7), // "setPosX"
QT_MOC_LITERAL(8, 59, 7), // "setPosY"
QT_MOC_LITERAL(9, 67, 9), // "setScaleX"
QT_MOC_LITERAL(10, 77, 9), // "setScaleY"
QT_MOC_LITERAL(11, 87, 12) // "setRotationZ"

    },
    "OpenglWidget\0setRed\0\0val\0setGreen\0"
    "setBlue\0setAlpha\0setPosX\0setPosY\0"
    "setScaleX\0setScaleY\0setRotationZ"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenglWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    1,   65,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x0a /* Public */,
       7,    1,   71,    2, 0x0a /* Public */,
       8,    1,   74,    2, 0x0a /* Public */,
       9,    1,   77,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    3,

       0        // eod
};

void OpenglWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenglWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setAlpha((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setPosX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setPosY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setScaleX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setScaleY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setRotationZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OpenglWidget::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_OpenglWidget.data,
    qt_meta_data_OpenglWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OpenglWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenglWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenglWidget.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int OpenglWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
