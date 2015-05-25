#include <QGridLayout>
#include <QLabel>

#include "MissionPlannerGauges.h"

//-----------------------------------------------------------------------------

MissionPlannerGauges::MissionPlannerGauges(QWidget* pParent) :
	QWidget(pParent)
{
	BuildGUI();
}

//-----------------------------------------------------------------------------

MissionPlannerGauges::~MissionPlannerGauges()
{	}

//-----------------------------------------------------------------------------

void MissionPlannerGauges::SetFuel(double dVal)
{
	m_pFuelGauge->SetFuel(dVal);
}

//-----------------------------------------------------------------------------

void MissionPlannerGauges::SetWeight(double dVal)
{
	m_pWeightGauge->SetWeight(dVal);
}

//-----------------------------------------------------------------------------

void MissionPlannerGauges::SetDuration(double dVal)
{
	m_pDurationGauge->SetCurrentDuration(dVal);
}

//-----------------------------------------------------------------------------

void MissionPlannerGauges::BuildGUI()
{
	// main layout
	QGridLayout* pLayout = new QGridLayout(this);

	// fuel gauge
	m_pFuelGauge = new FuelGauge(6.0);
	pLayout->addWidget(m_pFuelGauge, 0, 0);

	QLabel* plb = new QLabel(tr("Fuel gauge"));
	pLayout->addWidget(plb, 1, 0);

	// weight gauge
	m_pWeightGauge = new WeightGauge(200.0);
	pLayout->addWidget(m_pWeightGauge, 0, 1);

	plb = new QLabel(tr("Weight gauge"));
	pLayout->addWidget(plb, 1, 1);

	// duration gauge
	m_pDurationGauge = new DurationGauge;
	m_pDurationGauge->setStyleSheet("background-color: #D0D0D0; color: black;");
	m_pDurationGauge->SetMaxDuration(125);
	pLayout->addWidget(m_pDurationGauge, 2, 0, 1, 2);

	plb = new QLabel(tr("Distance/Duration gauge"));
	pLayout->addWidget(plb, 3, 0, 1, 2);
}

//-----------------------------------------------------------------------------

