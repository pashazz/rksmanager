/****************************************************************************
** Meta object code from reading C++ file 'playertable.h'
**
** Created: Sat 25. Jul 23:30:45 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/players/playertable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playertable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlayerTable[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlayerTable[] = {
    "PlayerTable\0\0on_actAdd_triggered()\0"
};

const QMetaObject PlayerTable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PlayerTable,
      qt_meta_data_PlayerTable, 0 }
};

const QMetaObject *PlayerTable::metaObject() const
{
    return &staticMetaObject;
}

void *PlayerTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerTable))
        return static_cast<void*>(const_cast< PlayerTable*>(this));
    return QDialog::qt_metacast(_clname);
}

int PlayerTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actAdd_triggered(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
