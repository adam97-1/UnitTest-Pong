 # Unit Test for Pong Game

## Introduction
This project consists of unit tests for Pong Game. I used GTest to test my game, focusing on two classes: RectangleObject and Player. The unit tests for Player are simple, as they test only the methods addPoints and setPoints. The unit tests for RectangleObject focus on testing collisions between two RectangleObjects and RectangleObject and GameBounds.

## Instructions for compilation

To compile this project, you need to install the SFML library (I used SFML 2.5.1), Google Test and project of Pong Game. You can open this project in Qt Creator.

### Linux
1. SFML installation: https://www.sfml-dev.org/tutorials/2.5/start-linux.php
2. Download Google Test: https://github.com/google/googletest
3. Extract ZIP
4. Change path to GOOGLETEST_DIR in gtest_dependency.pri, change on extract path to Google Test
    ```
        unix{
    HOME = $$system(echo $HOME)
    isEmpty(GOOGLETEST_DIR):GOOGLETEST_DIR=$$(GOOGLETEST_DIR)

    isEmpty(GOOGLETEST_DIR) {
        GOOGLETEST_DIR = $$HOME/GTest
        !isEmpty(GOOGLETEST_DIR) {
            warning("Using googletest src dir specified at Qt Creator wizard")
            message("set GOOGLETEST_DIR as environment variable or qmake variable to get rid of this message")
        }
    }
5. Download Pong Game: https://github.com/adam97-1/Pong
6. Both projects (Unit Tests and Pong Game) have to be in the same directory
7. Open the project in Qt Creator and run.

### Windows
1. Download SFML for MinGW: https://www.sfml-dev.org/download.php
2. Extract ZIP
3. Open Pong.pro
4. Change path to INCLUDEPATH and LIBS on extract path to SFML

    ```
        win32{
        DESTDIR = ./Binary/win/
        INCLUDEPATH += C:/Lib/SFML-2.5.1/include
        INCLUDEPATH += ./inc
        LIBS += -LC:/Lib/SFML-2.5.1/lib
        LIBS += -LC:/Lib/SFML-2.5.1/bin
        CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
        CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
    }

5. Download Google Test: https://github.com/google/googletest
6. Extract ZIP
7. Change path to GOOGLETEST_DIR in gtest_dependency.pri, change on extract path to Google Test
    ```
        win32{
    isEmpty(GOOGLETEST_DIR):GOOGLETEST_DIR=$$(GOOGLETEST_DIR)

    isEmpty(GOOGLETEST_DIR) {
        GOOGLETEST_DIR = C:\Lib\Gtest
        !isEmpty(GOOGLETEST_DIR) {
            warning("Using googletest src dir specified at Qt Creator wizard")
            message("set GOOGLETEST_DIR as environment variable or qmake variable to get rid of this message")
        }
    }
8. Both projects (Unit Tests and Pong Game) have to be in the same directory
9. Open the project in Qt Creator and run.     