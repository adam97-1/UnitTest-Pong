include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_LFLAGS += -static-libgcc

OBJECTS_DIR = ./Binary/Obj
INCLUDEPATH += ../Pong/inc

win32{
    DESTDIR = ./Binary/win/
    INCLUDEPATH += C:/Lib/SFML-2.5.1/include
    LIBS += -LC:/Lib/SFML-2.5.1/lib
    LIBS += -LC:/Lib/SFML-2.5.1/bin
    CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
    CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
}

unix{
    DESTDIR = ./Binary/unix
    LIBS += -lsfml-audio
    LIBS += -lsfml-graphics
    LIBS += -lsfml-network
    LIBS += -lsfml-window
    LIBS += -lsfml-system
}


SOURCES += \
        ../Pong/src/player.cpp          \
        ../Pong/src/rectangleobject.cpp \
        ../Pong/src/gamebounds.cpp      \
        main.cpp                        \
        tst_player.cpp                  \
        tst_rectangleobject.cpp

