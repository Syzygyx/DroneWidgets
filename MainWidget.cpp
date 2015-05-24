#include "MissionPlannerDataWidget.h"
#include "MainWidget.h"

//-----------------------------------------------------------------------------

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(800, 600);
	setStyleSheet("QWidget { background: black; color: white; }");
	MissionPlannerDataWidget* pMPDW = new MissionPlannerDataWidget(this);
	pMPDW->move(100, 100);
}

//-----------------------------------------------------------------------------

Widget::~Widget()
{

}

//-----------------------------------------------------------------------------

