QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_qt_test_chisla.cpp

HEADERS += \
    chisla.h \
    tst_qt_test_chisla.h
