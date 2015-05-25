#ifndef QUANTITYSCROLLBAR_H
#define QUANTITYSCROLLBAR_H

#include <QScrollBar>
#include <QLabel>

/** This class implements basic QScrollBar with a dedicated
 *  label, which shows the value explicitely
 */
class QuantityScrollBar : public QWidget
{
	Q_OBJECT

public:
	//! Constructor
	QuantityScrollBar(double dDiv = 1.0, QWidget* pParent = 0);
	//! Destructor
	~QuantityScrollBar();
	//! Sets the range
	void SetRange(double dMin, double dMax);
	//! Returns the value
	double GetValue() const
	{	return m_psb->value()*m_dDiv; }

signals:
	//! Emitted when value has changed
	void SignalValueChanged();

private:
	//! Builds the widget GUI
	void BuildGUI();

private slots:
	//! Updates the label value
	void UpdateLabel();

private:
	//! Pointer to the scroll bar
	QScrollBar* m_psb;
	//! Label displaying the value
	QLabel* m_plbValue;
	//! Number, by which the scroll bar value is divided
	double m_dDiv;
};

#endif // QUANTITYSCROLLBAR_H
