#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T13:35:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3ProyectoCorto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    ordenar.cpp

HEADERS  += mainwindow.h \
    Constants.h \
    linked_list.h \
    Node.h \
    image.h \
    NodeSimple.h \
    listaSimple.h \
    listaAdyacente.h \
    NodoAdyacente.h \
    ordenar.h

FORMS    += mainwindow.ui

RESOURCES += \
    rec.qrc
