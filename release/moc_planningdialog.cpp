/****************************************************************************
** Meta object code from reading C++ file 'planningdialog.h'
**
** Created: Sat 25. Jul 23:29:20 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/planningdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planningdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlanningDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      40,   15,   15,   15, 0x08,
      66,   60,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlanningDialog[] = {
    "PlanningDialog\0\0on_buttonBox_accepted()\0"
    "on_btnAdd_clicked()\0index\0"
    "checkAddingPossible(int)\0"
};

const QMetaObject PlanningDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PlanningDialog,
      qt_meta_data_PlanningDialog, 0 }
};

const QMetaObject *PlanningDialog::metaObject() const
{
    return &staticMetaObject;
}

void *PlanningDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlanningDialog))
        return static_cast<void*>(const_cast< PlanningDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PlanningDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonBox_accepted(); break;
        case 1: on_btnAdd_clicked(); break;
        case 2: checkAddingPossible((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
