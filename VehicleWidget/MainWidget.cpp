#include "VehicleWidget.h"
#include "TemperatureGauge.h"
#include "MainWidget.h"

//-----------------------------------------------------------------------------

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(1000, 800);

	m_pVehicle = new VehicleWidget(this);
	m_pVehicle->setGeometry(10, 100, 800, 600);

	m_pSlider = new QSlider(Qt::Horizontal, this);
	m_pSlider->setGeometry(10, 720, 800, 40);
	m_pSlider->setRange(0, 400);

	AddTemperatureGauge(225, 196, 120);
	AddTemperatureGauge(399, 97, 120);
	AddTemperatureGauge(573, 196, 120);
	AddTemperatureGauge(574, 397, 120);
	AddTemperatureGauge(398, 496, 120);
	AddTemperatureGauge(226, 396, 120);
	AddTemperatureGauge(400, 297, 200);
}

//-----------------------------------------------------------------------------

MainWidget::~MainWidget()
{

}

//-----------------------------------------------------------------------------

void MainWidget::AddTemperatureGauge(int iX, int iY, int iR)
{
	TemperatureGauge* pTG;
	pTG = new TemperatureGauge(0, 400);
	pTG->setFixedSize(iR, iR);
	pTG->Init();
	// manually adding gauges at correct position.
	m_pVehicle->AddGauge(QPoint(iX, iY), pTG);

	// make sure that change in slider is passed to the temperature gauge
	connect(m_pSlider, SIGNAL(valueChanged(int)), pTG, SLOT(SetTemperature(int)));
}

//-----------------------------------------------------------------------------

