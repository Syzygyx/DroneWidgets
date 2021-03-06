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
    VehicleWidget.cpp \
    ../Qt-custom-gauge-widget/source/qcgaugewidget.cpp \
    TemperatureGauge.cpp

HEADERS  += MainWidget.h \
    VehicleWidget.h \
    ../Qt-custom-gauge-widget/source/qcgaugewidget.h \
    TemperatureGauge.h

RESOURCES += \
    Files.qrc
