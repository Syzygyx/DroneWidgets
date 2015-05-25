#include "VehicleWidget.h"
#include "MainWidget.h"

//-----------------------------------------------------------------------------

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(800, 600);

	VehicleWidget* pVW = new VehicleWidget(this);
	pVW->setGeometry(10, 100, 500, 600);
}

//-----------------------------------------------------------------------------

MainWidget::~MainWidget()
{

}

//-----------------------------------------------------------------------------

