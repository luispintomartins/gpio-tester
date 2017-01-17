CONFIG -= \
    debug \
    debug_and_release

include(3rdparty/raspberry-pi-3.pri)

QT += core
QT -= gui

VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_BUGFIX = $$SVN_VERSION
VERSION = $$VERSION_MAJOR"."$$VERSION_MINOR"."$$VERSION_BUGFIX
message("Application version: "$$VERSION)

TEMPLATE = \
    app

TARGET = \
    gpio-tester

INCLUDEPATH +=

HEADERS  +=

SOURCES += \
    main.cpp

DEFINES += \
    "PROGRAM_NAME=\\\"$$TARGET\\\"" \
    "PROGRAM_VERSION=\\\"$$VERSION\\\""

release {
    DESTDIR =       build/release
    OBJECTS_DIR =   $$DESTDIR/.obj
    MOC_DIR =       $$DESTDIR/.moc
    RCC_DIR =       $$DESTDIR/.rcc
    UI_DIR =        $$DESTDIR/.ui
}

debug {
    DESTDIR =       build/debug
    OBJECTS_DIR =   $$DESTDIR/.obj
    MOC_DIR =       $$DESTDIR/.moc
    RCC_DIR =       $$DESTDIR/.rcc
    UI_DIR =        $$DESTDIR/.ui
}

target.path = /bin/
INSTALLS += target
