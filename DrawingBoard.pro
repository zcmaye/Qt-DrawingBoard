# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------
QT += gui widgets core
TEMPLATE = app
TARGET = DrawingBoard
DESTDIR = ./x64/Debug
CONFIG += debug console
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
HEADERS += ./Config.h \
    ./ShapeItem.h \
    ./mainwindow.h \
    ./shapescene.h
SOURCES += ./shapeItem.cpp \
    ./shapescene.cpp \
    ./mainwindow.cpp \
    ./main.cpp
RESOURCES += mainwindow.qrc