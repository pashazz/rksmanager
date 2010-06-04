/****************************************************************************
** Meta object code from reading C++ file 'addteamdialog.h'
**
** Created: Sat 25. Jul 23:29:11 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/addteamdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addteamdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addTeamDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_addTeamDialog[] = {
    "addTeamDialog\0\0nick,team\0"
    "teamAdded(QString,QString)\0"
    "on_buttonBox_accepted()\0"
};

const QMetaObject addTeamDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addTeamDialog,
      qt_meta_data_addTeamDialog, 0 }
};

const QMetaObject *addTeamDialog::metaObject() const
{
    return &staticMetaObject;
}

void *addTeamDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addTeamDialog))
        return static_cast<void*>(const_cast< addTeamDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int addTeamDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: teamAdded((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: on_buttonBox_accepted(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void addTeamDialog::teamAdded(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
