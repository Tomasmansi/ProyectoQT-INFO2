/****************************************************************************
** Meta object code from reading C++ file 'ventanaAccederCuenta.h'
**
** Created: Wed 25. Nov 13:50:32 2020
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaAccederCuenta.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaAccederCuenta.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ingresarCuenta[] = {

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
      16,   15,   15,   15, 0x0a,
      34,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ingresarCuenta[] = {
    "ingresarCuenta\0\0volverPrincipal()\0"
    "verCuenta()\0"
};

void ingresarCuenta::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ingresarCuenta *_t = static_cast<ingresarCuenta *>(_o);
        switch (_id) {
        case 0: _t->volverPrincipal(); break;
        case 1: _t->verCuenta(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ingresarCuenta::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ingresarCuenta::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ingresarCuenta,
      qt_meta_data_ingresarCuenta, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ingresarCuenta::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ingresarCuenta::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ingresarCuenta::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ingresarCuenta))
        return static_cast<void*>(const_cast< ingresarCuenta*>(this));
    return QWidget::qt_metacast(_clname);
}

int ingresarCuenta::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
