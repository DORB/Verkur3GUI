#-------------------------------------------------
#
# Project created by QtCreator 2014-12-13T12:46:19
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Verkur
TEMPLATE = app

INCLUDEPATH += Models \
    Repos \
    Services \


SOURCES += main.cpp\
        mainwindow.cpp \
    utilities.cpp \
    Models/computer.cpp \
    Models/person.cpp \
    Models/relation.cpp \
    Services/personservice.cpp \
    Repos/personrepository.cpp \
    Services/computerservice.cpp \
    Repos/computerrepository.cpp \
    addprogrammerdialog.cpp

HEADERS  += mainwindow.h \
    utilities.h \
    Models/computer.h \
    Models/person.h \
    Models/relation.h \
    Services/personservice.h \
    Repos/personrepository.h \
    Services/computerservice.h \
    Repos/computerrepository.h \
    addprogrammerdialog.h

FORMS    += mainwindow.ui \
    addprogrammerdialog.ui
