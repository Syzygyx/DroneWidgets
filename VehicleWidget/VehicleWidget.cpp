#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

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

void VehicleWidget::AddGauge(QPoint ptCenter, QcGaugeWidget* pGauge)
{
	pGauge->setParent(this);
	// moving the center to ptCenter is like moving the topleft corner
	// to the center minus half of gauge's width and height respectively
	pGauge->move(
				ptCenter.x() - pGauge->width()/2,
				ptCenter.y() - pGauge->height()/2
				);
	m_liGauges << pGauge;
	pGauge->show();
}

//-----------------------------------------------------------------------------

void VehicleWidget::paintEvent(QPaintEvent* pPE)
{
	QPainter P(this);

	//P.fillRect(rect(), palette().color(QPalette::Window));

	P.fillRect(rect(), Qt::red);
	QRectF rectW = rect();

	// this should be removed once the correct SVG is in place
	double dW = rectW.width();
	double dH = rectW.height();
	rectW.setCoords(-dW/4, 0, 5*dW/4, 6*dH/4);

	m_pSvgRender->render(&P, rectW);
}

//-----------------------------------------------------------------------------

void VehicleWidget::mousePressEvent(QMouseEvent* pME)
{
	qDebug() << "Mouse pressed at" << pME->pos();
}

//-----------------------------------------------------------------------------

