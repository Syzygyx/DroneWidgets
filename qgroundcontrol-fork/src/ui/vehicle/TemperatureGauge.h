#ifndef TEMPERATUREGAUGE_H
#define TEMPERATUREGAUGE_H

#include "gauge/qcgaugewidget.h"

//! This gauge is used to show the temperature
class TemperatureGauge : public QcGaugeWidget
{
	Q_OBJECT

public:
	//! Constructor
	TemperatureGauge(double dMinT, double dMaxT, QWidget* pParent = 0);
	//! Destructor
	~TemperatureGauge();

	//! Call this method after construction. Can be reimplemented in derived classes
	virtual void Init();

public slots:
	//! Sets the current temperature
	void SetTemperature(double dTemp);
	//! Just in case an integer value setter is needed
	void SetTemperature(int iTemp);

protected:
	//! Minimal temperature
	double m_dMin;
	//! Maximal temperature
	double m_dMax;
	//! Pointer to the needle
	QcNeedleItem* m_pNeedle;
};

#endif // TEMPERATUREGAUGE_H
