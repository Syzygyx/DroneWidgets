#ifndef MISSIONPLANNERWIDGET_H
#define MISSIONPLANNERWIDGET_H

#include "MissionPlannerDataWidget.h"
#include "MissionPlannerGauges.h"

/** This class represents the entire mission planning widget with editable parameters
 *  and gauges
 */
class MissionPlannerWidget : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	MissionPlannerWidget(QWidget* pParent = 0);
	//! Destructor
	~MissionPlannerWidget();

protected:
	//! Builds the GUI
	void BuildGUI();

private:
	//! Pointer to the data widget
	MissionPlannerDataWidget* m_pwData;
	//! Pointer to the gauges widget
	MissionPlannerGauges* m_pwGauges;
};

#endif // MISSIONPLANNERWIDGET_H
