#-------------------------------------------------
#
# Project created by QtCreator 2023-07-07T01:02:28
#
#-------------------------------------------------

QT       += core gui widgets multimedia multimediawidgets


TARGET = MainStory
TEMPLATE = app
CONFIG += resources_big
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        main.cpp \
    mainwidget.cpp \
    imagedialog.cpp

HEADERS += \
    mainwidget.h \
    imagedialog.h

FORMS += \
    mainwidget.ui \

LIBS += $$PWD/lib/libjigsaw_copy.a
LIBS += $$PWD/lib/libMyRhythmGame.a
LIBS += $$PWD/lib/libplanegame.a
LIBS += $$PWD/lib/libninja_fruit.a

INCLUDEPATH += $$PWD/include/planegame
INCLUDEPATH += $$PWD/include/jigsaw_copy
INCLUDEPATH += $$PWD/include/MyRhythmGame
INCLUDEPATH += $$PWD/include/NinjaFruit
INCLUDEPATH += $$PWD/include

DISTFILES += \
    ../planegame/plane.rcc \
    ../planegame/app.png

RESOURCES += \
    images.qrc
