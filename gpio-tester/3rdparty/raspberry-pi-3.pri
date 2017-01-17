message("Including: Raspberry Pi module.")

DEFINES += \
    "__RASPBERRY_PI_3__"

INCLUDEPATH += \
    $$PWD/raspberry-pi-3/gpio

DEPENDPATH += \
    $$PWD/raspberry-pi-3/gpio

HEADERS += \
    $$PWD/raspberry-pi-3/gpio/GPIOConst.h \
    $$PWD/raspberry-pi-3/gpio/GPIOManager.h

SOURCES += \
    $$PWD/raspberry-pi-3/gpio/GPIOConst.cpp \
    $$PWD/raspberry-pi-3/gpio/GPIOManager.cpp
