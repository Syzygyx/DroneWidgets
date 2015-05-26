#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSlider>

#include "VehicleWidget.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

	//! Adds a temperature gauge to vehicle widget
	void AddTemperatureGauge(int iS);

private:
	//! Pointer to vehicle widget
	VehicleWidget* m_pVehicle;
	//! Pointer to the slider object
	QSlider** m_pSlider;
};

#endif // MAINWIDGET_H
