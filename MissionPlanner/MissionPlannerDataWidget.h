#ifndef MISSIONPLANNERDATAWIDGET_H
#define MISSIONPLANNERDATAWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>

#include "QuantityScrollBar.h"

#define PAYLOAD_COUNT					3

/** This class lets the user modify some mission parameters and
 *	 calculates the others that depend on them
 */
class MissionPlannerDataWidget : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	MissionPlannerDataWidget(QWidget* pParent = 0);
	//! Destructor
	virtual ~MissionPlannerDataWidget();

public slots:
	//! Calculates the missing data
	void Calculate();

private:
	//! Build the entire GUI
	void BuildGUI();

	/** Creates one line of data with text label, main widget (maybe editable)
	 *  and unit displaying label and insert it into the main layout
	 */
	void CreateLine(QString qsText, QWidget* pW, QString qsUnit = "");

private:
	//! Pointer to the main widget layout
	QGridLayout* m_pLayout;
	//! Line counter
	int m_iLine;
	//! Pointer to the vehicle weight editing widget
	QSpinBox* m_psbWeight;
	//! Fuel per gallon weight label
	QLabel* m_plbFWPG;
	//! Total fuel weight label
	QLabel* m_plbTotalFuelW;
	//! Fuel density label
	QLabel* m_plbFuelDensity;
	//! Fuel efficiency spin box
	QSpinBox* m_psbFuelEfficiency;
	//! Fuel Wh label
	QLabel* m_plbFuelWh;
	//! Total vehicle weight label
	QLabel* m_plbTotalWeight;
	//! Hover power/weight spinbox
	QSpinBox* m_psbHPW;
	//! Hover power label
	QLabel* m_plbHoverPower;
	//! Hover duration label
	QLabel* m_plbHoverTime;
	//! Fuel quantity scroll bar
	QuantityScrollBar* m_pqsbFuel;
	//! Payload scroll bars
	QuantityScrollBar* m_pqsbPayload[PAYLOAD_COUNT];
};

#endif // MISSIONPLANNERDATAWIDGET_H
