#include "MissionPlannerWidget.h"
#include "FuelGauge.h"

#include "MainWidget.h"

//-----------------------------------------------------------------------------

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(1000, 600);
	setStyleSheet("QWidget { background: rgb(32, 32, 32); color: white; }"
					  "QScrollBar:horizontal { border: 1px solid cyan; margin: 0px 10px 0 10px; }"
					  "QScrollBar::add-line:horizontal { border: 1px solid cyan; background: #c0c0c0; width: 10px; subcontrol-position: right; subcontrol-origin: margin;}"
					  "QScrollBar::sub-line:horizontal { border: 1px solid cyan; background: #c0c0c0; width: 10px; subcontrol-position: left; subcontrol-origin: margin;}"
					  "QScrollBar::handle:horizontal { background-color: cyan; min-width: 10px; border: 1px solid white; }"
					  "QScrollBar:left-arrow:horizontal, QScrollBar::right-arrow:horizontal { background-color: white; }"
					  );
	MissionPlannerWidget* pMPW = new MissionPlannerWidget(this);
	pMPW->move(10, 100);
}

//-----------------------------------------------------------------------------

Widget::~Widget()
{

}

//-----------------------------------------------------------------------------

