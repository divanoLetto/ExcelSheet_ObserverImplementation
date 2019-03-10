include(gtest_dependency.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS
TARGET = labProject
CONFIG += c++11
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
        mainwindow.h \
    subject.h \
    observer.h \
    cellaInput.h \
    calcolo.h \
    cellaoutput.h \
    sommatoria.h \
    prodotto.h \
    massimo.h \
    minimo.h \
    media.h
SOURCES += \
        main.cpp \
    mainwindow.cpp
FORMS += \
    mainwindow.ui
