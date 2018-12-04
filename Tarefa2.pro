#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T10:29:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tarefa2
TEMPLATE = app

INCLUDEPATH += "/usr/local/include/opencv2"
LIBS += `pkg-config --cflags --libs opencv`


SOURCES += main.cpp\
        mainwindow.cpp \
    vision.cpp

HEADERS  += mainwindow.h \
    vision.h

FORMS    += mainwindow.ui
