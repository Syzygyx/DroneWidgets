#include <QHBoxLayout>

#include "MissionPlannerWidget.h"

//-----------------------------------------------------------------------------

MissionPlannerWidget::MissionPlannerWidget(QWidget *pParent) :
	QWidget(pParent)
{
	BuildGUI();

	// make sure the fuel gauge is updated on fuel change
	connect(m_pwData, SIGNAL(SignalFuel(double)), m_pwGauges, SLOT(SetFuel(double)));
	// make sure the weight gauge is updated on weight change
	connect(m_pwData, SIGNAL(SignalWeight(double)), m_pwGauges, SLOT(SetWeight(double)));
	// make sure the duration gauge is updated on flight duration change
	connect(m_pwData, SIGNAL(SignalDuration(double)), m_pwGauges, SLOT(SetDuration(double)));

	// This will update the weight gauge
	m_pwData->Calculate();
}

//-----------------------------------------------------------------------------

MissionPlannerWidget::~MissionPlannerWidget()
{	}

//-----------------------------------------------------------------------------

void MissionPlannerWidget::BuildGUI()
{
	// main widget layout
	QHBoxLayout* pLayout = new QHBoxLayout(this);

	m_pwData = new MissionPlannerDataWidget;
	pLayout->addWidget(m_pwData);
	m_pwGauges = new MissionPlannerGauges;
	pLayout->addWidget(m_pwGauges);
}

//-----------------------------------------------------------------------------


