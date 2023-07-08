#-------------------------------------------------
#
# Project created by QtCreator 2023-05-26T10:23:16
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia #使用QSound 的必要条件
QT       += widgets #使用QLabel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = jigsaw_copy
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#可能是为了被调用
TARGET = jigsaw_copy
TEMPLATE = lib
DEFINES += JIGSAW_COPY_LIBRARY

SOURCES += \
        mainscene.cpp \
    gamehelp.cpp \
    mypushbutton.cpp \
    gameplayer.cpp \
    jigsaw.cpp

HEADERS += \
        mainscene.h \
    gamehelp.h \
    mypushbutton.h \
    gameplayer.h \
    jigsaw_copy_global.h

FORMS += \
        mainscene.ui \
    gamehelp.ui \
    gameplayer.ui

RESOURCES += \
    res.qrc
