/****************************************************************************
** Meta object code from reading C++ file 'admicompany.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../widgets/admicompany.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admicompany.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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
struct qt_meta_tag_ZN11AdmiCompanyE_t {};
} // unnamed namespace

template <> constexpr inline auto AdmiCompany::qt_create_metaobjectdata<qt_meta_tag_ZN11AdmiCompanyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AdmiCompany",
        "gestionarDepartamentos",
        "",
        "gestionarUsuarios",
        "gestionarUsuariosSolicitado",
        "on_btnGestionDepartamentos_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'gestionarDepartamentos'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gestionarUsuarios'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gestionarUsuariosSolicitado'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_btnGestionDepartamentos_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AdmiCompany, qt_meta_tag_ZN11AdmiCompanyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AdmiCompany::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AdmiCompanyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AdmiCompanyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11AdmiCompanyE_t>.metaTypes,
    nullptr
} };

void AdmiCompany::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AdmiCompany *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->gestionarDepartamentos(); break;
        case 1: _t->gestionarUsuarios(); break;
        case 2: _t->gestionarUsuariosSolicitado(); break;
        case 3: _t->on_btnGestionDepartamentos_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AdmiCompany::*)()>(_a, &AdmiCompany::gestionarDepartamentos, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AdmiCompany::*)()>(_a, &AdmiCompany::gestionarUsuarios, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AdmiCompany::*)()>(_a, &AdmiCompany::gestionarUsuariosSolicitado, 2))
            return;
    }
}

const QMetaObject *AdmiCompany::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdmiCompany::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AdmiCompanyE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdmiCompany::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AdmiCompany::gestionarDepartamentos()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdmiCompany::gestionarUsuarios()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AdmiCompany::gestionarUsuariosSolicitado()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
