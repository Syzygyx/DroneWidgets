#include "VehicleWidget.h"
#include "TemperatureGauge.h"
#include "MainWidget.h"

#define SLIDER_COUNT					7


//-----------------------------------------------------------------------------

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(1280, 700);

	m_pVehicle = new VehicleWidget(this);
	m_pVehicle->setGeometry(430, 10, 400, 600);
	m_pVehicle->setStyleSheet("background-color: rgb(64, 64, 64);");

	m_pSlider = new QSlider*[SLIDER_COUNT];
	for (int i = 0; i < SLIDER_COUNT; i++) {
		m_pSlider[i] = new QSlider(Qt::Horizontal, this);
		m_pSlider[i]->setGeometry(10, 130+40*i, 400, 40);
		m_pSlider[i]->setRange(0, 400);
	}

	AddTemperatureGauge(0);
	AddTemperatureGauge(1);
	AddTemperatureGauge(2);
	AddTemperatureGauge(3);
	AddTemperatureGauge(4);
	AddTemperatureGauge(5);
	AddTemperatureGauge(6);
}

//-----------------------------------------------------------------------------

MainWidget::~MainWidget()
{
	delete [] m_pSlider;
}

//-----------------------------------------------------------------------------

void MainWidget::AddTemperatureGauge(int iS)
{
	TemperatureGauge* pTG;
	pTG = new TemperatureGauge(0, 400);
	pTG->Init();
	// manually adding gauges at correct position.
	m_pVehicle->SetGauge(iS, pTG);

	// make sure that change in slider is passed to the temperature gauge
	connect(m_pSlider[iS], SIGNAL(valueChanged(int)), pTG, SLOT(SetTemperature(int)));
}

//-----------------------------------------------------------------------------

