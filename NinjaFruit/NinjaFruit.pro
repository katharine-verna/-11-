QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = ninja_fruit
TEMPLATE = lib
DEFINES += NINJA_FRUIT_LIBRARY

SOURCES += \
    apple.cpp \
    banana.cpp \
    bomb.cpp \
    endgame.cpp \
    game.cpp \
    help.cpp \
    kinfe.cpp \
    ninjafruit.cpp \
    trap.cpp \
    watermelon.cpp

HEADERS += \
    apple.h \
    banana.h \
    bomb.h \
    endgame.h \
    game.h \
    help.h \
    kinfe.h \
    ninjafruit.h \
    trap.h \
    watermelon.h \
    ninja_fruit_global.h

FORMS += \
    ninjafruit.ui

RESOURCES += \
    picture.qrc
