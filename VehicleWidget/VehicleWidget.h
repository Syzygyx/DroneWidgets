#ifndef VEHICLEWIDGET_H
#define VEHICLEWIDGET_H

#include <QWidget>
#include <QSvgRenderer>

#include "../Qt-custom-gauge-widget/source/qcgaugewidget.h"

//! This widget shows a top down view of the vehicle
class VehicleWidget : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	VehicleWidget(QWidget* pParent = 0);
	//! Destructor
	~VehicleWidget();
	/** Adds gauge to the widget, places it so that its center is at ptCenter. VehicleWidget
	 *  will take ownership of the gauge widget, so do not delete it outside of this class!
	 */
	void AddGauge(QPoint ptCenter, QcGaugeWidget* pGauge);

protected:
	//! Paints the widget
	void paintEvent(QPaintEvent* pPE);
	//! This is intended to find locations for gauges
	void mousePressEvent(QMouseEvent* pME);

protected:
	//! Object, which renders the vehicle widget from SVG
	QSvgRenderer* m_pSvgRender;
	//! List of gauges
	QList<QcGaugeWidget*> m_liGauges;
};

#endif // VEHICLEWIDGET_H
