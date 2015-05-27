#include <QDebug>

#include "TemperatureGauge.h"

//-----------------------------------------------------------------------------

TemperatureGauge::TemperatureGauge(double dMinT, double dMaxT, QWidget *pParent) :
	QcGaugeWidget(pParent)
{
	m_dMin = dMinT;
	m_dMax = dMaxT;
	setMinimumSize(100, 100);

	// some background items
	QcBackgroundItem* pbg = addBackground(99);
	pbg->clearrColors();
	pbg->addColor(0.1, QColor(240, 240, 240));
	pbg->addColor(1.0, QColor(16, 16, 16));

	pbg = addBackground(95);
	pbg->clearrColors();
	pbg->addColor(0.1, QColor(32, 32, 32));
	pbg->addColor(1.0, QColor(224, 224, 224));

	pbg = addBackground(88);
	pbg->clearrColors();
	pbg->addColor(0.1, QColor(32, 32, 32));
	pbg->addColor(1.0, QColor(64, 64, 64));

	m_pNeedle = 0;
}

//-----------------------------------------------------------------------------

TemperatureGauge::~TemperatureGauge()
{	}

//-----------------------------------------------------------------------------

void TemperatureGauge::Init()
{

	// add the color band
	QcColorBand* pcb = addColorBand(80);
	// create the color list
	QList<QPair<QColor, float> > li;
	QPair<QColor, float> pair;
	pair.first = Qt::blue;
	pair.second = 10.0f;
	li << pair;
	pair.first = Qt::darkGreen;
	pair.second = 70.0f;
	li << pair;
	pair.first = Qt::yellow;
	pair.second = 90.0f;
	li << pair;
	pair.first = Qt::red;
	pair.second = 100.0f;
	li << pair;
	pcb->setColors(li);
	pcb->setDgereeRange(-45, 225);

	// scales
	QcDegreesItem* pdi;
	pdi = addDegrees(84);
	pdi->setColor(Qt::white);
	pdi->setValueRange(m_dMin, m_dMax);
	pdi->setStep((m_dMax - m_dMin)/8);
	pdi->setDgereeRange(-45, 225);

	// value labels
	QString qsNum;
	double dVal;
	for (int i = 0; i <= 4; i++) {
		QcLabelItem* plbi = addLabel(55);
		plbi->setColor(Qt::white);
		dVal = m_dMin + i*(m_dMax - m_dMin)/4;
		qsNum.setNum(dVal, 'f', 0);
		plbi->setText(qsNum);
		plbi->setAngle(-45 + 270*i/4);
	}

	// unit label
	QChar chDeg(0x00b0);
	QString qsUnit = chDeg;
	qsUnit += "F";
	QcLabelItem* plbi = addLabel(30);
	plbi->setColor(Qt::white);
	plbi->setAngle(-90);
	plbi->setText(qsUnit);

	m_pNeedle = addNeedle(75);
	m_pNeedle->setColor(Qt::red);
	m_pNeedle->setCurrentValue(0.0);
	m_pNeedle->setNeedle(QcNeedleItem::FeatherNeedle);
	m_pNeedle->setDgereeRange(-45, 225);
	m_pNeedle->setMinValue(m_dMin);
	m_pNeedle->setMaxValue(m_dMax);
}

//-----------------------------------------------------------------------------

void TemperatureGauge::SetTemperature(double dTemp)
{
	if (m_pNeedle != 0) {
		m_pNeedle->setCurrentValue(dTemp);
		update();
	}	else {
		qWarning() << "TemperatureGauge not initialized! Call TemperatureGauge::Init method after construction";
	}
}

//-----------------------------------------------------------------------------

void TemperatureGauge::SetTemperature(int iTemp)
{
	double dTemp = 1.0*iTemp;
	SetTemperature(dTemp);
}

//-----------------------------------------------------------------------------

