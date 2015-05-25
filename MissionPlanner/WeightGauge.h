#ifndef WEIGHTGAUGE_H
#define WEIGHTGAUGE_H

#include "../Qt-custom-gauge-widget/source/qcgaugewidget.h"

//! This class is used to show the weight gauge
class WeightGauge : public QcGaugeWidget
{
	Q_OBJECT

public:
	//! Constructor
	WeightGauge(double dMaxWeight, bool bLabels = true, QWidget* pParent = 0);
	//! Destructor
	~WeightGauge();

public slots:
	//! Sets the current weight
	void SetWeight(double dWeight);

private:
	//! Holds the maximum vehicle weight
	double m_dMaxWeight;
	//! Pointer to the needle item
	QcNeedleItem* m_pNeedle;
};

#endif // WEIGHTGAUGE_H
