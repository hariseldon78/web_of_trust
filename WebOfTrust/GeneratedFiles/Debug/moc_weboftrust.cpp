/****************************************************************************
** Meta object code from reading C++ file 'weboftrust.h'
**
** Created: Tue 1. Jun 00:46:18 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../weboftrust.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weboftrust.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebOfTrust[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      20,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WebOfTrust[] = {
    "WebOfTrust\0\0login()\0emetti()\0"
    "impostazioni()\0"
};

const QMetaObject WebOfTrust::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WebOfTrust,
      qt_meta_data_WebOfTrust, 0 }
};

const QMetaObject *WebOfTrust::metaObject() const
{
    return &staticMetaObject;
}

void *WebOfTrust::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebOfTrust))
        return static_cast<void*>(const_cast< WebOfTrust*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WebOfTrust::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: login(); break;
        case 1: emetti(); break;
        case 2: impostazioni(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
