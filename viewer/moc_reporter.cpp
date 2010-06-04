/****************************************************************************
** Reporter meta object code from reading C++ file 'reporter.h'
**
** Created: Sat Jul 25 23:39:10 2009
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "reporter.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Reporter::className() const
{
    return "Reporter";
}

QMetaObject *Reporter::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Reporter( "Reporter", &Reporter::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Reporter::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Reporter", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Reporter::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Reporter", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Reporter::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"on_table_customContextMenuRequested", 1, param_slot_0 };
    static const QUMethod slot_1 = {"on_buttonBox_accepted", 0, 0 };
    static const QUMethod slot_2 = {"onMenuClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "on_table_customContextMenuRequested(QPoint)", &slot_0, QMetaData::Private },
	{ "on_buttonBox_accepted()", &slot_1, QMetaData::Private },
	{ "onMenuClicked()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"Reporter", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Reporter.setMetaObject( metaObj );
    return metaObj;
}

void* Reporter::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Reporter" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Reporter::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: on_table_customContextMenuRequested((QPoint)(*((QPoint*)static_QUType_ptr.get(_o+1)))); break;
    case 1: on_buttonBox_accepted(); break;
    case 2: onMenuClicked(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Reporter::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Reporter::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Reporter::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
