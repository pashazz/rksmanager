/****************************************************************************
** Meta object code from reading C++ file 'addmatchdialog.h'
**
** Created: Sat 25. Jul 23:29:50 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/viewer/addmatchdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addmatchdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddMatchDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x08,
      55,   15,   15,   15, 0x08,
      79,   15,   15,   15, 0x08,
      90,   15,   15,   15, 0x08,
     116,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddMatchDialog[] = {
    "AddMatchDialog\0\0result\0"
    "on_AddMatchDialog_finished(int)\0"
    "on_buttonBox_accepted()\0addEvent()\0"
    "on_cmdAwayStart_clicked()\0"
    "on_cmdHomeStart_clicked()\0"
};

const QMetaObject AddMatchDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddMatchDialog,
      qt_meta_data_AddMatchDialog, 0 }
};

const QMetaObject *AddMatchDialog::metaObject() const
{
    return &staticMetaObject;
}

void *AddMatchDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddMatchDialog))
        return static_cast<void*>(const_cast< AddMatchDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddMatchDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_AddMatchDialog_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_buttonBox_accepted(); break;
        case 2: addEvent(); break;
        case 3: on_cmdAwayStart_clicked(); break;
        case 4: on_cmdHomeStart_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
