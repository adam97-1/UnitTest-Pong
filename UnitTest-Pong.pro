include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

unix{
    DESTDIR = ./Binary/unix
    OBJECTS_DIR = ./Binary/Obj
}

SOURCES += \
        main.cpp         tst_game.cpp
