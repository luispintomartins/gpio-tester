message("Including: Beaglebone Black module.")

DEFINES += \
    "__BEAGLEBONE_BLACK__"

INCLUDEPATH += \
    $$PWD/beaglebone-black/gpio

DEPENDPATH += \
    $$PWD/beaglebone-black/gpio

HEADERS += \
    $$PWD/beaglebone-black/gpio/GPIOConst.h \
    $$PWD/beaglebone-black/gpio/GPIOManager.h

SOURCES += \
    $$PWD/beaglebone-black/gpio/GPIOConst.cpp \
    $$PWD/beaglebone-black/gpio/GPIOManager.cpp
