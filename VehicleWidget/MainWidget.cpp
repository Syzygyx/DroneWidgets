#include "VehicleWidget.h"
#include "TemperatureGauge.h"
#include "MainWidget.h"

#define SLIDER_COUNT					7


//-----------------------------------------------------------------------------

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(1280, 800);

	m_pVehicle = new VehicleWidget(this);
	m_pVehicle->setGeometry(10, 10, 800, 600);
	m_pVehicle->setStyleSheet("background-color: rgb(64, 64, 64);");

	m_pSlider = new QSlider*[SLIDER_COUNT];
	for (int i = 0; i < SLIDER_COUNT; i++) {
		m_pSlider[i] = new QSlider(Qt::Horizontal, this);
		m_pSlider[i]->setGeometry(820, 130+40*i, 400, 40);
		m_pSlider[i]->setRange(0, 400);
	}

	AddTemperatureGauge(0, 225, 196, 120);
	AddTemperatureGauge(1, 399, 97, 120);
	AddTemperatureGauge(2, 573, 196, 120);
	AddTemperatureGauge(3, 574, 397, 120);
	AddTemperatureGauge(4, 398, 496, 120);
	AddTemperatureGauge(5, 226, 396, 120);
	AddTemperatureGauge(6, 400, 297, 200);
}

//-----------------------------------------------------------------------------

MainWidget::~MainWidget()
{
	delete [] m_pSlider;
}

//-----------------------------------------------------------------------------

void MainWidget::AddTemperatureGauge(int iS, int iX, int iY, int iR)
{
	TemperatureGauge* pTG;
	pTG = new TemperatureGauge(0, 400);
	pTG->setFixedSize(iR, iR);
	pTG->Init();
	// manually adding gauges at correct position.
	m_pVehicle->AddGauge(QPoint(iX, iY), pTG);

	// make sure that change in slider is passed to the temperature gauge
	connect(m_pSlider[iS], SIGNAL(valueChanged(int)), pTG, SLOT(SetTemperature(int)));
}

//-----------------------------------------------------------------------------

