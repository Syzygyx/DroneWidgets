#include "QcPixmapItem.h"

//-----------------------------------------------------------------------------

QcPixmapItem::QcPixmapItem(const QPixmap &rPix, int iSize, QObject *pParent) :
	QcItem(pParent), m_pixOrig(rPix), m_pix()
{
	m_iRelSize = iSize;
	m_fAngle = 0.0f;
}

//-----------------------------------------------------------------------------

void QcPixmapItem::draw(QPainter* pP)
{
	QRectF rectOrig = resetRect();
	QRectF tmpRect = adjustRect(position());

	QPointF ptCenter = getPoint(m_fAngle, tmpRect);
	int iW = (int)round(m_iRelSize*rectOrig.width()/100);
	int iH = (int)round(m_iRelSize*rectOrig.height()/100);

	// create pixmap for painting only if it is necessary!
	if (iW != m_pix.width() || iH != m_pix.height())
		m_pix = m_pixOrig.scaled(iW, iH, Qt::KeepAspectRatio, Qt::SmoothTransformation);

	// align pixmap center with actual center for given position
	pP->drawPixmap(
				ptCenter.x() - m_pix.width()/2,
				ptCenter.y() - m_pix.height()/2,
				m_pix
				);
}

//-----------------------------------------------------------------------------

void QcPixmapItem::setAngle(float fA)
{
	m_fAngle = fA;
	update();
}

//-----------------------------------------------------------------------------


