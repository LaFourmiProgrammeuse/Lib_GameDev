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

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-main

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-window

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-system

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

