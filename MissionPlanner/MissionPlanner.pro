#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T21:47:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MissionPlanner
TEMPLATE = app


SOURCES += main.cpp\
        MainWidget.cpp \
    MissionPlannerDataWidget.cpp \
    QuantityScrollBar.cpp \
    ../Qt-custom-gauge-widget/source/qcgaugewidget.cpp \
    FuelGauge.cpp \
    QcPixmapItem.cpp \
    MissionPlannerGauges.cpp \
    MissionPlannerWidget.cpp \
    WeightGauge.cpp \
    DurationGauge.cpp

HEADERS  += MainWidget.h \
    MissionPlannerDataWidget.h \
    QuantityScrollBar.h \
    ../Qt-custom-gauge-widget/source/qcgaugewidget.h \
    MissionPlannerGauges.h \
    FuelGauge.h \
    QcPixmapItem.h \
    MissionPlannerWidget.h \
    WeightGauge.h \
    DurationGauge.h

RESOURCES += \
    Files.qrc
