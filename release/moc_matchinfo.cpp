/****************************************************************************
** Meta object code from reading C++ file 'matchinfo.h'
**
** Created: Fri 24. Jul 01:17:16 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/viewer/matchinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matchinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MatchInfo[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   11,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MatchInfo[] = {
    "MatchInfo\0\0it\0viewPlayer(QListWidgetItem*)\0"
};

const QMetaObject MatchInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MatchInfo,
      qt_meta_data_MatchInfo, 0 }
};

const QMetaObject *MatchInfo::metaObject() const
{
    return &staticMetaObject;
}

void *MatchInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MatchInfo))
        return static_cast<void*>(const_cast< MatchInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int MatchInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: viewPlayer((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
