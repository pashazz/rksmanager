/****************************************************************************
** Meta object code from reading C++ file 'selectmatchdialog.h'
**
** Created: Sat 25. Jul 23:29:29 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/selectmatchdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectmatchdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectMatchDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      24,   19,   18,   18, 0x08,
      68,   19,   18,   18, 0x08,
     116,  112,   18,   18, 0x08,
     165,   19,   18,   18, 0x08,
     209,   19,   18,   18, 0x08,
     259,   18,   18,   18, 0x08,
     292,  288,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SelectMatchDialog[] = {
    "SelectMatchDialog\0\0item\0"
    "on_lstMatches_itemPressed(QListWidgetItem*)\0"
    "on_lstMatches_itemChanged(QListWidgetItem*)\0"
    "pos\0on_lstMatches_customContextMenuRequested(QPoint)\0"
    "on_lstMatches_itemClicked(QListWidgetItem*)\0"
    "on_lstMatches_itemDoubleClicked(QListWidgetItem*)\0"
    "on_sbTours_valueChanged(int)\0act\0"
    "onTP(QAction*)\0"
};

const QMetaObject SelectMatchDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectMatchDialog,
      qt_meta_data_SelectMatchDialog, 0 }
};

const QMetaObject *SelectMatchDialog::metaObject() const
{
    return &staticMetaObject;
}

void *SelectMatchDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectMatchDialog))
        return static_cast<void*>(const_cast< SelectMatchDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectMatchDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_lstMatches_itemPressed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: on_lstMatches_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: on_lstMatches_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: on_lstMatches_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: on_lstMatches_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: on_sbTours_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: onTP((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE