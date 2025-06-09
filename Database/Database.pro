QT += sql

TEMPLATE = lib
CONFIG += staticlib  # o shared si prefieres usar una DLL
TARGET = Database

DEFINES += DATABASE_LIBRARY
CONFIG += c++17

HEADERS += \
    database.h \
    departamentoDAO.h \
    empresaDAO.h \
    usuarioDAO.h

SOURCES += \
    database.cpp \
    departamentoDAO.cpp \
    empresaDAO.cpp \
    usuarioDAO.cpp

INCLUDEPATH += $$PWD  # ¡IMPORTANTE! Para que otros subproyectos encuentren database.h

# Instala la librería generada
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
