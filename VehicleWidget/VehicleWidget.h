#ifndef VEHICLEWIDGET_H
#define VEHICLEWIDGET_H

#include <QWidget>
#include <QSvgRenderer>

//! This widget shows a top down view of the vehicle
class VehicleWidget : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	VehicleWidget(QWidget* pParent = 0);
	//! Destructor
	~VehicleWidget();

protected:
	//! Paints the widget
	void paintEvent(QPaintEvent* pPE);

protected:
	//! Object, which renders the vehicle widget from SVG
	QSvgRenderer* m_pSvgRender;
};

#endif // VEHICLEWIDGET_H
