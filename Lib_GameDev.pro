#-------------------------------------------------
#
# Project created by QtCreator 2018-06-11T17:23:00
#
#-------------------------------------------------

QT       -= gui
QT += xml

TARGET = Lib_GameDev
TEMPLATE = lib

DEFINES += LIB_GAMEDEV_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button_widget.cpp \
    texture_widget.cpp \
    xml_tools.cpp \
    text_switch_widget.cpp \
    text_field_widget.cpp \
    file_tools.cpp

HEADERS += \
        lib_gamedev_global.h \ 
    button_widget.h \
    texture_widget.h \
    xml_tools.h \
    text_switch_widget.h \
    text_field_widget.h \
    file_tools.h \
    matrix.h \
    event_handler.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/SFML-2.5.1/include
DEPENDPATH += $$PWD/SFML-2.5.1/include

unix:!macx: LIBS += -L$$PWD/../JeuDeLaVie/SFML-2.5.1/linux/lib -lsfml-window
unix:!macx: LIBS += -L$$PWD/../JeuDeLaVie/SFML-2.5.1/linux/lib -lsfml-graphics
unix:!macx: LIBS += -L$$PWD/../JeuDeLaVie/SFML-2.5.1/linux/lib -lsfml-network
unix:!macx: LIBS += -L$$PWD/../JeuDeLaVie/SFML-2.5.1/linux/lib -lsfml-system
unix:!macx: LIBS += -L$$PWD/../JeuDeLaVie/SFML-2.5.1/linux/lib -lsfml-audio

win32: LIBS += -L$$PWD/SFML-2.5.1/window/lib -lsfml-window
win32: LIBS += -L$$PWD/SFML-2.5.1/window/lib -lsfml-graphics
win32: LIBS += -L$$PWD/SFML-2.5.1/window/lib -lsfml-network
win32: LIBS += -L$$PWD/SFML-2.5.1/window/lib -lsfml-system
win32: LIBS += -L$$PWD/SFML-2.5.1/window/lib -lsfml-audio

