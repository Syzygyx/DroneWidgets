#include "math.h"

#include <QLabel>
#include <QDebug>

#include "QuantityScrollBar.h"

#include "MissionPlannerDataWidget.h"

//-----------------------------------------------------------------------------

MissionPlannerDataWidget::MissionPlannerDataWidget(QWidget* pParent) :
	QWidget(pParent)
{
	m_iRow = 0;
	setAutoFillBackground(true);
	BuildGUI();

	// connect the signals, so that values will be recalculated at every change
	connect(m_psbWeight, SIGNAL(valueChanged(int)), this, SLOT(Calculate()));
	connect(m_pqsbFuel, SIGNAL(SignalValueChanged(double)), this, SLOT(Calculate()));
	connect(m_psbFuelEfficiency, SIGNAL(valueChanged(int)), this, SLOT(Calculate()));
	connect(m_psbHPW, SIGNAL(valueChanged(int)), this, SLOT(Calculate()));

	for (int i = 0; i < PAYLOAD_COUNT; i++)
		connect(m_pqsbPayload[i], SIGNAL(SignalValueChanged(double)), this, SLOT(Calculate()));

	// make sure the external objects know about fuel change
	connect(m_pqsbFuel, SIGNAL(SignalValueChanged(double)), this, SIGNAL(SignalFuel(double)));

	// make initial calculation
	Calculate();
}

//-----------------------------------------------------------------------------

MissionPlannerDataWidget::~MissionPlannerDataWidget()
{
	// nothing to do here
}

//-----------------------------------------------------------------------------

void MissionPlannerDataWidget::Calculate()
{
	// Get fuel quantity
	double dFuelQuantity = m_pqsbFuel->GetValue();
	// Get fuel weight per gallon
	double dFuelWeightPG = m_plbFWPG->text().toDouble();
	// Calculate total fuel weight
	double dFuelWeight = dFuelQuantity*dFuelWeightPG;
	m_plbTotalFuelW->setText(QString::number(dFuelWeight, 'f', 2));

	// Get fuel density
	double dFuelDensity = m_plbFuelDensity->text().replace(",", "").toDouble();
	// Get fuel efficiency
	int iFuelEfficiency = m_psbFuelEfficiency->value();
	// Calculate the fuel Wh
	double dFWh;
	dFWh = dFuelQuantity*dFuelDensity*iFuelEfficiency/100.0;
	m_plbFuelWh->setText(QString::number(round(dFWh), 'f', 0));

	// Get vehicle weight
	double dVehicleWeight = 1.0*m_psbWeight->value();
	// Add vehicle weight, fuel weight and payload weights
	double dTotalWeight = dVehicleWeight + dFuelWeight;
	for (int i = 0; i < PAYLOAD_COUNT; i++)
		dTotalWeight += m_pqsbPayload[i]->GetValue();
	m_plbTotalWeight->setText(QString::number(dTotalWeight, 'f', 1));

	// Get the hover power/weight
	double dHoverPowerPKg = 1.0*m_psbHPW->value();
	double dHoverPower = dTotalWeight*dHoverPowerPKg;
	m_plbHoverPower->setText(QString::number(dHoverPower, 'f', 1));

	// Calculate hover duration in [h]
	double dHoverTime = dFWh/dHoverPower;
	double dHours = floor(dHoverTime);
	double dMinutes = floor(60.0*(dHoverTime - dHours));
	QString qsTime = QString::number(dHours, 'f', 0) + ":";
	qsTime += QString::number(dMinutes, 'f', 0).rightJustified(2, '0');
	m_plbHoverTime->setText(qsTime);

	// weight can change in many different ways, so it's easier to send signal
	// from here, even though many times the weight might not change at all
	emit SignalWeight(dTotalWeight);
	// signal the new flight duration in minutes (for now it's 50% of hover time)
	emit SignalDuration(60.0*dHoverTime/2.0);
}

//-----------------------------------------------------------------------------

void MissionPlannerDataWidget::BuildGUI()
{
	// this will be the main widget layout
	m_pLayout = new QGridLayout(this);

	// create the vehicle weight edit widget
	m_psbWeight = new QSpinBox;
	m_psbWeight->setRange(0, 120);
	m_psbWeight->setSingleStep(1);
	m_psbWeight->setValue(50);				// set some default value

	CreateRow(tr("Vehicle Base Weight"), m_psbWeight, "kg");

	// Fuel type label
	QLabel* plbFuel = new QLabel(tr("Gasoline"));
	plbFuel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	plbFuel->setStyleSheet("color: rgb(0, 255, 0);");
	CreateRow(tr("Fuel type"), plbFuel);

	// Fuel quantity field
	m_pqsbFuel = new QuantityScrollBar(0.25);
	m_pqsbFuel->SetRange(0.0, 15.0);
	CreateRow(tr("Fuel Quantity"), m_pqsbFuel, "gallons");

	// Weight of fuel/gallon field
	m_plbFWPG = new QLabel("6.8");
	m_plbFWPG->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	CreateRow(tr("Weight of fuel"), m_plbFWPG, "kg/gallon");

	// Fuel weight field
	m_plbTotalFuelW = new QLabel("");
	m_plbTotalFuelW->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	CreateRow(tr("Fuel Weight"), m_plbTotalFuelW, "kg");

	// Fuel density field
	m_plbFuelDensity = new QLabel("36,763");
	m_plbFuelDensity->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	CreateRow(tr("Fuel density"), m_plbFuelDensity, "Wh/gallon");

	// Fuel efficiency field
	m_psbFuelEfficiency = new QSpinBox;
	m_psbFuelEfficiency->setRange(0, 100);
	m_psbFuelEfficiency->setSingleStep(1);
	m_psbFuelEfficiency->setSuffix("%");
	m_psbFuelEfficiency->setValue(25);			// set some default value
	CreateRow(tr("Fuel efficiency"), m_psbFuelEfficiency);

	// Fuel Wh field
	m_plbFuelWh = new QLabel("");
	m_plbFuelWh->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	CreateRow(tr("Fuel Wh"), m_plbFuelWh, "Wh");

	// Payload fields
	for (int i = 0; i < PAYLOAD_COUNT; i++) {
		m_pqsbPayload[i] = new QuantityScrollBar(0.5);
		m_pqsbPayload[i]->SetRange(0.0, 10.0);
		CreateRow(tr("Payload %1 Weight").arg(i + 1), m_pqsbPayload[i], "kg");
	}

	// Total weight field
	m_plbTotalWeight = new QLabel("");
	m_plbTotalWeight->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	m_plbTotalWeight->setStyleSheet("QLabel { color: red; }");
	CreateRow(tr("Total Vehicle Weight"), m_plbTotalWeight, "kg");

	// Hover power/weight field
	m_psbHPW = new QSpinBox;
	m_psbHPW->setRange(1, 1000);
	m_psbHPW->setSingleStep(1);
	m_psbHPW->setValue(222);			// set some default value
	CreateRow(tr("Hover power/weight"), m_psbHPW, "W/kg");

	// Hover power field
	m_plbHoverPower = new QLabel("");
	CreateRow(tr("Hover power"), m_plbHoverPower, "W");

	// Hover duration field
	m_plbHoverTime = new QLabel("");
	m_plbHoverTime->setStyleSheet("color: red");
	CreateRow(tr("Hover duration"), m_plbHoverTime, "h");

}

//-----------------------------------------------------------------------------

void MissionPlannerDataWidget::CreateRow(QString qsText, QWidget *pW, QString qsUnit)
{
	// create text label widget and insert it into layout
	QLabel* plb = new QLabel(qsText);
	plb->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_pLayout->addWidget(plb, m_iRow, 0);
	// insert the main line widget into layout
	m_pLayout->addWidget(pW, m_iRow, 1, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
	// if unit given, create the unit label and insert it into layout
	if (qsUnit.length() > 0) {
		plb = new QLabel(qsUnit);
		plb->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
		m_pLayout->addWidget(plb, m_iRow, 2);
	}

	// increase the line counter
	m_iRow++;
}

//-----------------------------------------------------------------------------


