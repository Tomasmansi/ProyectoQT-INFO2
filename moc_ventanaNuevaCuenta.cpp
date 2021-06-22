/****************************************************************************
** Meta object code from reading C++ file 'ventanaNuevaCuenta.h'
**
** Created: Wed 25. Nov 13:50:33 2020
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaNuevaCuenta.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaNuevaCuenta.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_nuevaCuenta[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      31,   12,   12,   12, 0x0a,
      50,   12,   46,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_nuevaCuenta[] = {
    "nuevaCuenta\0\0volverPrincipal()\0"
    "verFinalizar()\0int\0verificarDatos()\0"
};

void nuevaCuenta::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        nuevaCuenta *_t = static_cast<nuevaCuenta *>(_o);
        switch (_id) {
        case 0: _t->volverPrincipal(); break;
        case 1: _t->verFinalizar(); break;
        case 2: { int _r = _t->verificarDatos();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData nuevaCuenta::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject nuevaCuenta::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nuevaCuenta,
      qt_meta_data_nuevaCuenta, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &nuevaCuenta::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *nuevaCuenta::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *nuevaCuenta::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nuevaCuenta))
        return static_cast<void*>(const_cast< nuevaCuenta*>(this));
    return QWidget::qt_metacast(_clname);
}

int nuevaCuenta::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
