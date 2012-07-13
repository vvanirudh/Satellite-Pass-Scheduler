/****************************************************************************
** Meta object code from reading C++ file 'pass_scheduler.h'
**
** Created: Thu Jul 12 12:01:35 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pass_scheduler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pass_scheduler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Pass_scheduler[] = {

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
      16,   15,   15,   15, 0x0a,
      27,   15,   15,   15, 0x0a,
      42,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Pass_scheduler[] = {
    "Pass_scheduler\0\0showtime()\0readfromfile()\0"
    "window()\0"
};

void Pass_scheduler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Pass_scheduler *_t = static_cast<Pass_scheduler *>(_o);
        switch (_id) {
        case 0: _t->showtime(); break;
        case 1: _t->readfromfile(); break;
        case 2: _t->window(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Pass_scheduler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Pass_scheduler::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Pass_scheduler,
      qt_meta_data_Pass_scheduler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Pass_scheduler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Pass_scheduler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Pass_scheduler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Pass_scheduler))
        return static_cast<void*>(const_cast< Pass_scheduler*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Pass_scheduler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
