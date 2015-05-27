#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

#include "VehicleWidget.h"

//-----------------------------------------------------------------------------

VehicleWidget::VehicleWidget(QWidget* pParent) : QWidget(pParent)
{
	QString qsFile = ":/files/Vehicle.svg";
	m_pSvgRender = new QSvgRenderer(qsFile, this);
	for (int i = 0; i < GAUGE_COUNT; i++)
		m_apGauges[i] = 0;
}

//-----------------------------------------------------------------------------

VehicleWidget::~VehicleWidget()
{
	delete m_pSvgRender;
}

//-----------------------------------------------------------------------------

void VehicleWidget::SetGauge(int i, QcGaugeWidget* pGauge)
{
	pGauge->setParent(this);
	int iW = GetSize(i);
	pGauge->setFixedSize(iW, iW);
	// moving the center to ptCenter is like moving the topleft corner
	// to the center minus half of gauge's width and height respectively
	QPoint ptCenter = GetCenter(i);
	pGauge->move(ptCenter.x() - iW/2, ptCenter.y() - iW/2);
	m_apGauges[i] = pGauge;
	pGauge->show();
}

//-----------------------------------------------------------------------------

QPoint VehicleWidget::GetCenter(int i) const
{
	// engine coordinates on 800 pix width
	// engine 0: 225, 196
	// engine 1: 399, 97
	// engine 2: 573, 196
	// engine 3: 574, 397
	// engine 4: 398, 496
	// engine 5: 226, 396
	// engine 6: 400, 297

	int aiX[] = { 225, 399, 573, 574, 398, 226, 400 };
	int aiY[] = { 196, 97, 196, 397, 496, 396, 297 };

	QPoint pt;
	if (i >= 0 &&  i < 7) {
		pt.setX((aiX[i]*width())/800);
		pt.setY((aiY[i]*width())/800);
	}	else {
		qWarning() << "Wrong engine index!";
		Q_ASSERT(i >= 0 && i < 7);
	}
	return pt;
}

//-----------------------------------------------------------------------------

int VehicleWidget::GetSize(int i) const
{
	// engines 0-5 have size 120 on 800 pix width
	// engine 6 has size 200 on 800 pix width
	if (i < 6)
		return (120*width())/800;
	else
		return (200*width())/800;
}

//-----------------------------------------------------------------------------

void VehicleWidget::paintEvent(QPaintEvent* pPE)
{
	QPainter P(this);

	P.fillRect(rect(), palette().color(QPalette::Window));

	QRectF rectW = rect();

	// this should be removed once the correct SVG is in place
	double dW = rectW.width();
	double dH = 3*dW/4; //rectW.height();
	rectW.setCoords(-dW/4, 0, 5*dW/4, 6*dH/4);


	m_pSvgRender->render(&P, rectW);
}

//-----------------------------------------------------------------------------

void VehicleWidget::mousePressEvent(QMouseEvent* pME)
{
	//qDebug() << "Mouse pressed at" << pME->pos();
}

//-----------------------------------------------------------------------------

void VehicleWidget::resizeEvent(QResizeEvent*)
{
	for (int i = 0; i < GAUGE_COUNT; i++) {
		if (m_apGauges[i] != 0) {
			int iW = GetSize(i);
			m_apGauges[i]->setFixedSize(iW, iW);
			// moving the center to ptCenter is like moving the topleft corner
			// to the center minus half of gauge's width and height respectively
			QPoint ptCenter = GetCenter(i);
			m_apGauges[i]->move(ptCenter.x() - iW/2, ptCenter.y() - iW/2);
		}
	}
}

//-----------------------------------------------------------------------------

