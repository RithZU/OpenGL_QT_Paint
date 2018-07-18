#-------------------------------------------------
#
# Project created by QtCreator 2018-02-06T13:36:35
#
#-------------------------------------------------

QT       += core gui opengl
LIBS += -lglut -lopengl32
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FreeDrawing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    drawtools.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    drawtools.h \
    common.h \
    drawtools.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc
