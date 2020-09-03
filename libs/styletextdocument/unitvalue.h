#ifndef STYLE_UNITVALUE_H
#define STYLE_UNITVALUE_H

#include <QString>
#include <QMetaType>

namespace Style {

typedef float unitfloat;

class UnitValue
{
public:

	enum Unit{
		pt = 0x0, //point
		pc = 0x1, //pica
		mm = 0x2, //mm
		cm = 0x3, //cm
		in = 0x4, //inch
		invalid = 0x5 //invalid value
	};

	UnitValue(qreal val = 0, Unit unit = invalid);
	UnitValue(QString const& descr);
	UnitValue(UnitValue const& other);
	~UnitValue();

	UnitValue& operator=(UnitValue const& other);
	bool operator< (UnitValue const& other) const;
	bool operator== (UnitValue const& other) const;
	bool operator!= (UnitValue const& other) const;

	Unit getPreferedUnit() const;
	void setPreferedUnit(const Unit &preferedUnit);

	bool isValid() const;

	unitfloat getValue(Unit u) const;
	void setValue(unitfloat val);
	void setValue(unitfloat val, Unit u);

	QString getFormattedValue() const;
	void setFormattedValue(QString const& val);

protected:

	static unitfloat scaleFactor(Unit u);

	static QString unitName(Unit u);

	static Unit unitCode(QString s);

	qint32 _val;
	Unit _preferedUnit;

private:

	static const int registrationCode;

};

} // namespace Style

Q_DECLARE_METATYPE(Style::UnitValue);

#endif // STYLE_UNITVALUE_H
