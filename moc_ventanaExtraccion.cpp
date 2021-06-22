/****************************************************************************
** Meta object code from reading C++ file 'ventanaExtraccion.h'
**
** Created: Wed 25. Nov 13:50:33 2020
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaExtraccion.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaExtraccion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_extraccion[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_extraccion[] = {
    "extraccion\0\0volverCuenta()\0verContinuar()\0"
};

void extraccion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        extraccion *_t = static_cast<extraccion *>(_o);
        switch (_id) {
        case 0: _t->volverCuenta(); break;
        case 1: _t->verContinuar(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData extraccion::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject extraccion::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_extraccion,
      qt_meta_data_extraccion, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &extraccion::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *extraccion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *extraccion::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_extraccion))
        return static_cast<void*>(const_cast< extraccion*>(this));
    return QWidget::qt_metacast(_clname);
}

int extraccion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
