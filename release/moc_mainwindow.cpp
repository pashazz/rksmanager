/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat 25. Jul 23:28:52 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "B:/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      50,   42,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     133,  128,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     283,   11,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,
     334,   11,   11,   11, 0x08,
     357,   11,   11,   11, 0x08,
     380,   11,   11,   11, 0x08,
     403,   11,   11,   11, 0x08,
     426,   11,   11,   11, 0x08,
     450,  448,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actManageViews_triggered()\0"
    "checked\0on_actView_triggered(bool)\0"
    "on_actPlayers_triggered()\0"
    "on_actChange_triggered()\0item\0"
    "on_tableWidget_itemDoubleClicked(QTableWidgetItem*)\0"
    "on_actRed_triggered()\0on_actYellow_triggered()\0"
    "on_actGoleadors_triggered()\0"
    "on_actFont_triggered()\0on_actColor_triggered()\0"
    "on_actPlanning_triggered()\0"
    "on_actPlay_triggered()\0on_actHelp_triggered()\0"
    "on_actExit_triggered()\0on_actOpen_triggered()\0"
    "on_actNew_triggered()\0t\0"
    "getTournament(Tournament*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actManageViews_triggered(); break;
        case 1: on_actView_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_actPlayers_triggered(); break;
        case 3: on_actChange_triggered(); break;
        case 4: on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: on_actRed_triggered(); break;
        case 6: on_actYellow_triggered(); break;
        case 7: on_actGoleadors_triggered(); break;
        case 8: on_actFont_triggered(); break;
        case 9: on_actColor_triggered(); break;
        case 10: on_actPlanning_triggered(); break;
        case 11: on_actPlay_triggered(); break;
        case 12: on_actHelp_triggered(); break;
        case 13: on_actExit_triggered(); break;
        case 14: on_actOpen_triggered(); break;
        case 15: on_actNew_triggered(); break;
        case 16: getTournament((*reinterpret_cast< Tournament*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
