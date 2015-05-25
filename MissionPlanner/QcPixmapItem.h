#ifndef QCPIXMAPITEM_H
#define QCPIXMAPITEM_H

#include <QPixmap>

#include "../Qt-custom-gauge-widget/source/qcgaugewidget.h"

//! This class implements a pixmap gauge item
class QCGAUGE_DECL QcPixmapItem : public QcItem
{
	Q_OBJECT

public:
	//! Constructor
	QcPixmapItem(const QPixmap& rPix, int iSize, QObject* pParent = 0);
	//! Draw method
	void draw(QPainter* pP);
	//! Sets the angle
	void setAngle(float);

private:
	//! Original pixmap object
	QPixmap m_pixOrig;
	//! Pixmap actually being painted
	QPixmap m_pix;
	//! Angle where pixmap is drawn
	float m_fAngle;
	//! Relative pixmap size (in %)
	int m_iRelSize;
};



#endif // QCPIXMAPITEM_H
