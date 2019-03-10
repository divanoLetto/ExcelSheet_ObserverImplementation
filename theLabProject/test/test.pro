include(gtest_dependency.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
    ../labProject/calcolo.h \
    ../labProject/cellainput.h \
    ../labProject/cellaoutput.h \
    ../labProject/mainwindow.h \
    ../labProject/massimo.h \
    ../labProject/media.h \
    ../labProject/minimo.h \
    ../labProject/observer.h \
    ../labProject/prodotto.h \
    ../labProject/sommatoria.h \
    ../labProject/subject.h \
tst_casename.h

SOURCES += \
        main.cpp \
    ../labProject/mainwindow.cpp

FORMS += \
    ../labProject/mainwindow.ui

