#ifndef DURATIONGAUGE_H
#define DURATIONGAUGE_H

#include <QWidget>

//! This class is used to present maximum duration of the flight
class DurationGauge : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	DurationGauge(QWidget* pParent = 0);
	//! Destructor
	~DurationGauge();

	//! Sets the maximum duration
	void SetMaxDuration(double dMax);

	//! Sets the big scale step
	void SetStep(double dStep);

public slots:
	//! Sets the current duration
	void SetCurrentDuration(double dDuration);

protected:
	//! Paints the widget
	void paintEvent(QPaintEvent* pPE);

private:
	//! Holds the maximal duration
	double m_dMax;
	//! Holds the step
	double m_dStep;
	//! Holds the current duration
	double m_dDuration;

};

#endif // DURATIONGAUGE_H
