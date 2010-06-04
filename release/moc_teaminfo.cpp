/****************************************************************************
** Meta object code from reading C++ file 'teaminfo.h'
**
** Created: Sat 25. Jul 23:30:05 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/teaminfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teaminfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TeamInfo[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x08,
      60,   10,    9,    9, 0x08,
     111,   10,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TeamInfo[] = {
    "TeamInfo\0\0item\0"
    "on_tblPlayers_itemClicked(QTableWidgetItem*)\0"
    "on_tblPlayers_itemDoubleClicked(QTableWidgetItem*)\0"
    "viewMatch(QListWidgetItem*)\0"
};

const QMetaObject TeamInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TeamInfo,
      qt_meta_data_TeamInfo, 0 }
};

const QMetaObject *TeamInfo::metaObject() const
{
    return &staticMetaObject;
}

void *TeamInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TeamInfo))
        return static_cast<void*>(const_cast< TeamInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int TeamInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_tblPlayers_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: on_tblPlayers_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: viewMatch((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
