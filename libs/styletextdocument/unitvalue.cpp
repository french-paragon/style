#include "unitvalue.h"

#include <math.h>

#include <QRegularExpression>

namespace Style {

const int UnitValue::registrationCode = qRegisterMetaType<Style::UnitValue>();

UnitValue::UnitValue(qreal val, Unit unit) :
	_val(0),
	_preferedUnit(unit)
{
	setValue(val, unit);
}

UnitValue::UnitValue(QString const& descr) {
	setFormattedValue(descr);
}
UnitValue::UnitValue(UnitValue const& other) :
	_val(other._val),
	_preferedUnit(other._preferedUnit)
{

}
UnitValue::~UnitValue() {

}

UnitValue& UnitValue::operator=(UnitValue const& other) {
	_val = other._val;
	_preferedUnit = other._preferedUnit;

	return *this;
}
bool UnitValue::operator< (UnitValue const& other) const {
	if (!isValid()) {
		return false;
	}
	return _val < other._val;
}
bool UnitValue::operator== (UnitValue const& other) const {
	if (!isValid() and !other.isValid()) {
		return true;
	}
	if (!isValid() or !other.isValid()) {
		return false;
	}
	return _val == other._val;
}
bool UnitValue::operator!= (UnitValue const& other) const {
	return !(*this == other);
}

UnitValue::Unit UnitValue::getPreferedUnit() const
{
	return _preferedUnit;
}

void UnitValue::setPreferedUnit(const Unit &preferedUnit)
{
	_preferedUnit = preferedUnit;
}

bool UnitValue::isValid() const {
	return _preferedUnit != invalid;
}

unitfloat UnitValue::getValue(Unit u) const {
	return static_cast<unitfloat>(_val)/scaleFactor(u);
}

void UnitValue::setValue(unitfloat val) {
	setValue(val, _preferedUnit);
}
void UnitValue::setValue(unitfloat val, Unit u) {
	_val = static_cast<qint32>(std::roundf(val*scaleFactor(u)));
	_preferedUnit = (std::isnan(val) || std::isinf(val)) ? invalid : _preferedUnit;
}

QString UnitValue::getFormattedValue() const {
	if (!isValid()) {
		return "invalid";
	}
	unitfloat val = std::roundf(getValue(_preferedUnit)*100);
	return QString::number(val, 'f', 2) + unitName(_preferedUnit);
}
void UnitValue::setFormattedValue(QString const& val) {

	QRegularExpression rx("^(\\d(?:\\d+)(?:.\\d*)?)(?:\\s*)([a-zA-Z]+)?$");

	auto m = rx.match(val);
	if (m.hasMatch()) {
		QString fVal = m.captured(1);

		if (m.lastCapturedIndex() == 2) {
			QString unit = m.captured(2);
			_preferedUnit = unitCode(unit);
		}

		setValue(QVariant(fVal).toFloat(nullptr), _preferedUnit);
	} else {
		_preferedUnit = invalid;
	}
}

unitfloat UnitValue::scaleFactor(Unit u) {

	switch (u) {
	case pt:
		return 100.;
	case pc:
		return 1200.;
	case mm:
		return 283.46457;
	case cm:
		return 28346.457;
	case in:
		return 7200.;
	case invalid:
		return std::nan("");
	}

}

QString UnitValue::unitName(Unit u) {

	switch (u) {
	case pt:
		return "pt";
	case pc:
		return "pc";
	case mm:
		return "mm";
	case cm:
		return "cm";
	case in:
		return "in";
	case invalid:
		return "";
	}
}

UnitValue::Unit UnitValue::unitCode(QString s) {

	for(int u = 0; u < invalid; u++) {
		if (s.toLower() == unitName(static_cast<Unit>(u))) {
			return static_cast<Unit>(u);
		}
	}

	return invalid;
}


} // namespace Style
