QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test.cpp \
    ../zadacha1/zadacha/functions.cpp

HEADERS += \
    ../zadacha1/zadacha/functions.h
