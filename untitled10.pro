#-------------------------------------------------
#
# Project created by QtCreator 2017-12-28T15:31:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled10
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    test.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


TRANSLATIONS += zh_CN.ts

QT += printsupport
FORMS += main
lupdate_only
{
    SOURCES+=  \
    entry.cc \
    main.qml
}
