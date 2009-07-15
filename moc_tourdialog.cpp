/****************************************************************************
** Meta object code from reading C++ file 'tourdialog.h'
**
** Created: Tue Jul 14 10:35:12 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tourdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tourdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TourDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   40,   11,   11, 0x08,
      89,   40,   11,   11, 0x08,
     133,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     198,  196,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TourDialog[] = {
    "TourDialog\0\0t\0getTounament(Tournament*)\0"
    "item\0on_lstPlayers_itemClicked(QListWidgetItem*)\0"
    "on_lstPlayers_itemChanged(QListWidgetItem*)\0"
    "on_cmdOK_clicked()\0on_cmdNew_clicked()\0"
    "on_buttonBox_accepted()\0,\0"
    "onTeam(QString,QString)\0"
};

const QMetaObject TourDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TourDialog,
      qt_meta_data_TourDialog, 0 }
};

const QMetaObject *TourDialog::metaObject() const
{
    return &staticMetaObject;
}

void *TourDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TourDialog))
        return static_cast<void*>(const_cast< TourDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TourDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getTounament((*reinterpret_cast< Tournament*(*)>(_a[1]))); break;
        case 1: on_lstPlayers_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: on_lstPlayers_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: on_cmdOK_clicked(); break;
        case 4: on_cmdNew_clicked(); break;
        case 5: on_buttonBox_accepted(); break;
        case 6: onTeam((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TourDialog::getTounament(Tournament * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
