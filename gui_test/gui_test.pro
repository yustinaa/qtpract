TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    ../chisla_widg \
    chisla_widg \
    Chisla_gui_test
    # указываем путь к .pro файлу вручную
    chisla_widg.file = ../chisla_widg/chisla_widg.pro
    chisla_widg.subdir = ../chisla_widg
