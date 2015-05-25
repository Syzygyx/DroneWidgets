#include <QPainter>
#include "VehicleWidget.h"

//-----------------------------------------------------------------------------

VehicleWidget::VehicleWidget(QWidget* pParent) : QWidget(pParent)
{
	QString qsFile = ":/files/Vehicle.svg";
	m_pSvgRender = new QSvgRenderer(qsFile, this);
}

//-----------------------------------------------------------------------------

VehicleWidget::~VehicleWidget()
{
	delete m_pSvgRender;
}

//-----------------------------------------------------------------------------

void VehicleWidget::paintEvent(QPaintEvent* pPE)
{
	QPainter P(this);

	P.fillRect(rect(), palette().color(QPalette::Window));

	QRectF rectW = rect();

	m_pSvgRender->render(&P, rectW);
}

//-----------------------------------------------------------------------------


