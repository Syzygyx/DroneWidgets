#include <math.h>

#include <QHBoxLayout>
#include <QFontMetrics>

#include "QuantityScrollBar.h"

//-----------------------------------------------------------------------------

QuantityScrollBar::QuantityScrollBar(double dDiv, QWidget* pParent) : QWidget(pParent)
{
	m_dDiv = dDiv;
	BuildGUI();
	// make sure that value in the label is updated when user moves the scrollbar
	connect(m_psb, SIGNAL(valueChanged(int)), this, SLOT(UpdateLabel()));
	// make sure other interested widgets know about the change too
	connect(m_psb, SIGNAL(valueChanged(int)), this, SLOT(ReportValue()));
	SetRange(0.0, 10.0);

	UpdateLabel();
}

//-----------------------------------------------------------------------------

QuantityScrollBar::~QuantityScrollBar()
{
	// nothing to do here
}

//-----------------------------------------------------------------------------

void QuantityScrollBar::SetRange(double dMin, double dMax)
{
	m_psb->setRange((int)round(dMin/m_dDiv), (int)round(dMax/m_dDiv));
	// calculate the minimum label width
	QFontMetrics fm(m_plbValue->font());
	int iNum = fm.width(QString::number(round(dMax), 'f', 0) + ".00") + 10;
	m_plbValue->setMinimumWidth(iNum);
}

//-----------------------------------------------------------------------------

void QuantityScrollBar::BuildGUI()
{
	// widget's layout
	QHBoxLayout* pLayout = new QHBoxLayout(this);
	pLayout->setMargin(0);

	m_psb = new QScrollBar(Qt::Horizontal);
	m_psb->setMinimumWidth(100);
	m_psb->setPageStep(1);

	m_plbValue = new QLabel;
	m_plbValue->setStyleSheet("color: rgb(0, 255, 0);");
	m_plbValue->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	pLayout->addWidget(m_psb);
	pLayout->addWidget(m_plbValue);
	pLayout->setStretch(0, 1);
	pLayout->setStretch(1, 0);
}

//-----------------------------------------------------------------------------

void QuantityScrollBar::UpdateLabel()
{
	// take the value from scroll bar, convert it to QString and set it as
	// label's text
	m_plbValue->setText(QString::number(m_psb->value()*m_dDiv, 'f', 2));
}

//-----------------------------------------------------------------------------

void QuantityScrollBar::ReportValue()
{
	emit SignalValueChanged(GetValue());
}

//-----------------------------------------------------------------------------

