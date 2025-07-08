/****************************************************************************
** Meta object code from reading C++ file 'tst_qt_test_chisla.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tst_qt_test_chisla.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_qt_test_chisla.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14Qt_test_chislaE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14Qt_test_chislaE = QtMocHelpers::stringData(
    "Qt_test_chisla",
    "test_case1",
    "",
    "test_nod",
    "test_nok",
    "test_prime",
    "test_arm",
    "test_nod_data",
    "test_nok_data",
    "test_prime_data",
    "test_arm_data"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14Qt_test_chislaE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Qt_test_chisla::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14Qt_test_chislaE.offsetsAndSizes,
    qt_meta_data_ZN14Qt_test_chislaE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14Qt_test_chislaE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Qt_test_chisla, std::true_type>,
        // method 'test_case1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_nod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_nok'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_prime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_arm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_nod_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_nok_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_prime_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_arm_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Qt_test_chisla::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Qt_test_chisla *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->test_case1(); break;
        case 1: _t->test_nod(); break;
        case 2: _t->test_nok(); break;
        case 3: _t->test_prime(); break;
        case 4: _t->test_arm(); break;
        case 5: _t->test_nod_data(); break;
        case 6: _t->test_nok_data(); break;
        case 7: _t->test_prime_data(); break;
        case 8: _t->test_arm_data(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Qt_test_chisla::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qt_test_chisla::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14Qt_test_chislaE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Qt_test_chisla::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
