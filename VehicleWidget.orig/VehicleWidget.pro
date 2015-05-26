#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T22:19:15
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VehicleWidget
TEMPLATE = app


SOURCES += main.cpp\
        MainWidget.cpp \
    TemperatureGauge.cpp \
    VehicleWidget.cpp \
    ../Qt-custom-gauge-widget/source/qcgaugewidget.cpp

HEADERS  += MainWidget.h \
    TemperatureGauge.h \
    VehicleWidget.h \
    ../Qt-custom-gauge-widget/source/qcgaugewidget.h

DISTFILES += \
    ./files/Vehicle.svg
