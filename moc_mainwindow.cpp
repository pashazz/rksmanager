/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Jul 14 13:52:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
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
      12,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      59,   11,   11,   11, 0x08,
      87,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     134,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     253,   11,   11,   11, 0x08,
     277,  275,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actRed_triggered()\0"
    "on_actYellow_triggered()\0"
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
        case 0: on_actRed_triggered(); break;
        case 1: on_actYellow_triggered(); break;
        case 2: on_actGoleadors_triggered(); break;
        case 3: on_actFont_triggered(); break;
        case 4: on_actColor_triggered(); break;
        case 5: on_actPlanning_triggered(); break;
        case 6: on_actPlay_triggered(); break;
        case 7: on_actHelp_triggered(); break;
        case 8: on_actExit_triggered(); break;
        case 9: on_actOpen_triggered(); break;
        case 10: on_actNew_triggered(); break;
        case 11: getTournament((*reinterpret_cast< Tournament*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
