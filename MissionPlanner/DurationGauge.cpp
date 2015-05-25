#include <math.h>

#include <QPainter>
#include <QFontMetrics>
#include <QRadialGradient>
#include <QLinearGradient>
#include "DurationGauge.h"

#define OFFSET_X				8
#define OFFSET_Y				10
#define INDICATOR_H			15
#define INDICATOR_R			12
#define SCALE_LEN				6
#define SMALL_SCALE_LEN		4

//-----------------------------------------------------------------------------

DurationGauge::DurationGauge(QWidget* pParent)
{
	m_dMax = 105.0;
	m_dStep = 10.0;
	m_dDuration = 0.0;
	setAutoFillBackground(true);

	setMinimumSize(300, 50);
}

//-----------------------------------------------------------------------------

DurationGauge::~DurationGauge()
{	}

//-----------------------------------------------------------------------------

void DurationGauge::SetMaxDuration(double dMax)
{
	m_dMax = dMax;
}

//-----------------------------------------------------------------------------

void DurationGauge::SetStep(double dStep)
{
	m_dStep = dStep;
}

//-----------------------------------------------------------------------------

void DurationGauge::SetCurrentDuration(double dDuration)
{
	// some safety checks
	if (dDuration < 0.0)
		dDuration = 0.0;
	else if (dDuration > m_dMax)
		dDuration = m_dMax;

	m_dDuration = dDuration;
	update();
}

//-----------------------------------------------------------------------------

void DurationGauge::paintEvent(QPaintEvent* pPE)
{
	QPainter P(this);
	P.setRenderHints(QPainter::Antialiasing);
	QPalette pal = palette();
	P.fillRect(rect(), pal.color(QPalette::Window));

	// draw frame
	int iLeft = OFFSET_X + 2*INDICATOR_R;
	int iTop = OFFSET_Y;
	int iRight = width() - 2*OFFSET_X; // leave more space for the last number
	int iBottom = OFFSET_Y + INDICATOR_H;
	P.setPen(QPen(Qt::darkGray, 2));
	P.drawLine(iLeft, iBottom, iLeft, iTop);
	P.drawLine(iLeft, iTop, iRight, iTop);
	P.setPen(QPen(Qt::lightGray, 2));
	P.drawLine(iRight, iTop, iRight, iBottom);
	P.drawLine(iRight, iBottom, iLeft, iBottom);

	// scale
	int iW = iRight - iLeft;
	int iH = iBottom - iTop;	// note the reversed y axis!
	int iX;

	// small scales
	P.setPen(pal.color(QPalette::Text));
	for (double dVal = 0.0; dVal <= m_dMax; dVal += m_dStep/5) {
		iX = iLeft + (int)round(iW*dVal/m_dMax);
		P.drawLine(iX, iBottom, iX, iBottom + SMALL_SCALE_LEN);
	}

	// big scales
	QString qsNum;
	QFontMetrics fm(P.font());
	P.setPen(QPen(pal.color(QPalette::Text), 2));

	for (double dVal = 0.0; dVal <= m_dMax; dVal += m_dStep) {
		iX = iLeft + (int)round(iW*dVal/m_dMax);
		P.drawLine(iX, iBottom, iX, iBottom + SCALE_LEN);
		qsNum.setNum(dVal, 'f', 0);
		P.drawText(iX - fm.width(qsNum)/2, iBottom + SCALE_LEN + fm.ascent(), qsNum);
	}

	// red dot
	P.setPen(Qt::red);
	QRadialGradient rg(QPointF(iLeft - 3*INDICATOR_R/2, iTop + iH/2 - INDICATOR_R/2), 3*INDICATOR_R/2);
	rg.setColorAt(0, Qt::white);
	rg.setColorAt(0.8, Qt::red);
	rg.setColorAt(1, Qt::darkRed);
	P.setBrush(QBrush(rg));
	P.drawEllipse(QPoint(iLeft - INDICATOR_R + 2, iTop + iH/2), INDICATOR_R, INDICATOR_R);

	// red track
	int iTW = (int)round(iW*m_dDuration/m_dMax);
	QLinearGradient lg;
	lg.setStart(iLeft, iTop);
	lg.setFinalStop(QPointF(iLeft, iBottom));
	lg.setColorAt(0.0, Qt::red);
	lg.setColorAt(0.45, Qt::red);
	lg.setColorAt(1.0, Qt::darkRed);
	P.setBrush(QBrush(lg));
	P.drawRect(iLeft, iTop, iTW, iH);
}

//-----------------------------------------------------------------------------

