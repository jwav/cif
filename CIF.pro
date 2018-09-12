#-------------------------------------------------
#
# Project created by QtCreator 2018-07-14T20:50:26
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cif
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    context.cpp \
    field.cpp \
    item.cpp \
    error.cpp \
    value.cpp

HEADERS  += mainwindow.h \
    context.h \
    field.h \
    item.h \
    error.h \
    value.h \
    utils.h

FORMS    += mainwindow.ui

#manually added by Vee
CONFIG += c++11
