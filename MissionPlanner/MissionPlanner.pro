#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T21:47:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DroneControlWidgets
TEMPLATE = app


SOURCES += main.cpp\
        MainWidget.cpp \
    MissionPlannerDataWidget.cpp \
    QuantityScrollBar.cpp

HEADERS  += MainWidget.h \
    MissionPlannerDataWidget.h \
    QuantityScrollBar.h
