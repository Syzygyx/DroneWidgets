#ifndef MISSIONPLANNERGAUGES_H
#define MISSIONPLANNERGAUGES_H

#include <QWidget>
#include "FuelGauge.h"
#include "WeightGauge.h"
#include "DurationGauge.h"

//! This class is used to show mission planning gauges
class MissionPlannerGauges : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	MissionPlannerGauges(QWidget* pParent = 0);
	//! Destructor
	~MissionPlannerGauges();

public slots:
	//! Sets the fuel level
	void SetFuel(double dVal);
	//! Sets the weight at weight gauge
	void SetWeight(double dVal);
	//! Sets the flight duration
	void SetDuration(double dVal);

protected:
	//! Builds the GUI
	void BuildGUI();

private:
	//! Pointer to the fuel gauge
	FuelGauge* m_pFuelGauge;
	//! Pointer to the weight gauge
	WeightGauge* m_pWeightGauge;
	//! Pointer to the duration gauge
	DurationGauge* m_pDurationGauge;
};

#endif // MISSIONPLANNERGAUGES_H
