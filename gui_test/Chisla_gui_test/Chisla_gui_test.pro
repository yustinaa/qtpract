QT += widgets testlib
CONFIG += qt console c++17 testcase
CONFIG -= app_bundle
CONFIG += moc

TEMPLATE = app

# Подключаем заголовки и исходники из chisla_widg
INCLUDEPATH += ../../chisla_widg
DEPENDPATH  += ../../chisla_widg
FORMS += ../../chisla_widg/mainwindow.ui

SOURCES += \
    tst_gui_chisla_test.cpp \
    ../../chisla_widg/mainwindow.cpp

HEADERS += \
    ../../chisla_widg/mainwindow.h \
    ../../chisla_widg/chisla.h
