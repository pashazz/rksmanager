/****************************************************************************
** Meta object code from reading C++ file 'addprofiledialog.h'
**
** Created: Sat 25. Jul 23:31:02 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/players/addprofiledialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addprofiledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddProfileDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      44,   17,   17,   17, 0x08,
      70,   17,   17,   17, 0x08,
     104,  102,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddProfileDialog[] = {
    "AddProfileDialog\0\0on_buttonBox_2_rejected()\0"
    "on_buttonBox_2_accepted()\0"
    "on_txtNick_textChanged(QString)\0,\0"
    "on_txtNick_cursorPositionChanged(int,int)\0"
};

const QMetaObject AddProfileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddProfileDialog,
      qt_meta_data_AddProfileDialog, 0 }
};

const QMetaObject *AddProfileDialog::metaObject() const
{
    return &staticMetaObject;
}

void *AddProfileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddProfileDialog))
        return static_cast<void*>(const_cast< AddProfileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddProfileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonBox_2_rejected(); break;
        case 1: on_buttonBox_2_accepted(); break;
        case 2: on_txtNick_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_txtNick_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
