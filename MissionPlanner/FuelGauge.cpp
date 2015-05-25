#include "QcPixmapItem.h"
#include "FuelGauge.h"

//-----------------------------------------------------------------------------

FuelGauge::FuelGauge(double dCapacity, QWidget *pParent) :
	QcGaugeWidget(pParent)
{
	m_dCapacity = dCapacity;

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

	// the white arc above the scale
	QcArcItem* pai = addArc(75);
	pai->setColor(Qt::white);
	pai->setMinDegree(30);
	pai->setMaxDegree(150);

	QcDegreesItem* pdi;
	// small scales
	pdi = addDegrees(65);
	pdi->setValueRange(0.0, m_dCapacity);
	pdi->setColor(Qt::white);
	pdi->setMinDegree(30);
	pdi->setMaxDegree(150);
	pdi->setStep(m_dCapacity/16.0);
	pdi->setSubDegree(true);

	// big scales
	pdi = addDegrees(65);
	pdi->setValueRange(0.0, m_dCapacity);
	pdi->setColor(Qt::white);
	pdi->setMinDegree(30);
	pdi->setMaxDegree(150);
	pdi->setStep(m_dCapacity/4.0);

	// empty label "E"
	QcLabelItem* plbi;
	plbi = addLabel(45);
	plbi->setAngle(30);
	plbi->setText("E");
	plbi->setColor(Qt::white);

	// full label "F"
	plbi = addLabel(45);
	plbi->setAngle(150);
	plbi->setText("F");
	plbi->setColor(Qt::white);

	// gas station label
	QPixmap pix(":/files/GasStation.png");
	QcPixmapItem* ppi = new QcPixmapItem(pix, 7, this);
	ppi->setAngle(90);
	addItem(ppi, 45);

	// a cool glass effect
	QcGlassItem* pgi = addGlass(88);

	// needle
	m_pNeedle = addNeedle(60);
	m_pNeedle->setDgereeRange(30, 150);
	m_pNeedle->setMinValue(0.0);
	m_pNeedle->setMaxValue(m_dCapacity);
	m_pNeedle->setCurrentValue(0.0);
	m_pNeedle->setNeedle(QcNeedleItem::FeatherNeedle);
	m_pNeedle->setColor(Qt::red);

	// needle covering button
	pbg = addBackground(8);
	pbg->clearrColors();
	pbg->addColor(0.9, QColor(32, 32, 32));
	pbg->addColor(1.0, Qt::black);
}

//-----------------------------------------------------------------------------

FuelGauge::~FuelGauge()
{	}

//-----------------------------------------------------------------------------

void FuelGauge::SetFuel(double dFuel)
{
	m_pNeedle->setCurrentValue(dFuel);
	update();
}

//-----------------------------------------------------------------------------


