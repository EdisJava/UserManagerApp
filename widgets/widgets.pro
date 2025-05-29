QT += core gui sql widgets

CONFIG += c++17

TEMPLATE = app
TARGET = widgets

SOURCES += \
    admicompany.cpp \
    dptoform.cpp \
    empresaform.cpp \
    guess.cpp \
    main.cpp \
    mainadmi.cpp \
    mainwindow.cpp \
    userform.cpp \
    users.cpp

HEADERS += \
    admicompany.h \
    dptoform.h \
    empresaform.h \
    guess.h \
    mainadmi.h \
    mainwindow.h \
    userform.h \
    users.h

FORMS += \
    admicompany.ui \
    dptoform.ui \
    empresaform.ui \
    guess.ui \
    mainadmi.ui \
    mainwindow.ui \
    userform.ui \
    users.ui

# Incluye la carpeta del subproyecto Database
INCLUDEPATH += $$PWD/../Database

LIBS += -L$$OUT_PWD/../Database/debug -lDatabase

# Si usas librerías compartidas (.dll/.so), añade esto
# QMAKE_RPATHDIR += $$OUT_PWD/../Database
