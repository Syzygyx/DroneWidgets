#ifndef VEHICLEWIDGET_H
#define VEHICLEWIDGET_H

#include <QWidget>
#include <QSvgRenderer>

#include "../Qt-custom-gauge-widget/source/qcgaugewidget.h"

#define GAUGE_COUNT					7

//! This widget shows a top down view of the vehicle
class VehicleWidget : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	VehicleWidget(QWidget* pParent = 0);
	//! Destructor
	~VehicleWidget();
	/** Sets i-th gauge to the widget, calculates the correct position and size of gauge.
	 *  VehicleWidget will take ownership of the gauge widget, so do not delete it
	 *  outside of this class!
	 */
	void SetGauge(int i, QcGaugeWidget* pGauge);

protected:
	//! Returns the center of i-th engine
	QPoint GetCenter(int i) const;
	//! Returns the size of i-th engine
	int GetSize(int i) const;

	//! Paints the widget
	void paintEvent(QPaintEvent* pPE);
	//! This is intended to find locations for gauges
	void mousePressEvent(QMouseEvent* pME);
	//! Handles the resize events by moving the gauges as well
	void resizeEvent(QResizeEvent*);


protected:
	//! Object, which renders the vehicle widget from SVG
	QSvgRenderer* m_pSvgRender;
	//! Array of pointers to gauges
	QcGaugeWidget* m_apGauges[GAUGE_COUNT];
};

#endif // VEHICLEWIDGET_H
