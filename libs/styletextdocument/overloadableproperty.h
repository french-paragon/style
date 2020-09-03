#ifndef STYLE_OVERLOADABLEPROPERTY_H
#define STYLE_OVERLOADABLEPROPERTY_H

#include "./abstractstyle.h"

namespace Style {

class ParagraphStyle;
class SpanStyle;

template<typename T, AbstractStyle::Styletype S>
class OverloadableProperty
{
public:

	typedef typename std::conditional<S==AbstractStyle::ParagraphStyletype,ParagraphStyle,SpanStyle>::type StyleType;

	OverloadableProperty(StyleType* style,
						 T (StyleType::*getter)() const,
						 void (StyleType::*changeSignal)(T),
						 void (StyleType::*setChangeSignal)(bool),
						 T const& defval = T(),
						 bool isSet = false,
						 T const& val = T() ) :
		_style(style),
		_value(val),
		_default(defval),
		_isSet(isSet),
		_getter(getter),
		_changeSignal(changeSignal),
		_setChangeSignal(setChangeSignal) {

	}

	inline T getValue() const {
		if (_isSet) {
			return _value;
		}

		if (_style->styleParent() != nullptr) {
			StyleType* p = static_cast<StyleType*>(_style->styleParent());
			return (p->*_getter)();
		}

		return _default;
	}

	inline void setValue(T const& v) {

		if (_isSet and _value != v) {
			_value = v;
			(_style->*_changeSignal)(v);
		} else if (!_isSet) {
			bool changed = (v != getValue());
			_value = v;
			(_style->*_setChangeSignal)(true);
			if (changed) {
				(_style->*_changeSignal)(v);
			}
		}

	}

	inline void clearValue() {
		if (_isSet) {
			_isSet = false;
			(_style->*_setChangeSignal)(false);
			T nV = getValue();
			if (_value != nV) {
				(_style->*_changeSignal)(nV);
			}
		}
	}

	inline bool isSet() const {
		return _isSet;
	}

protected:
	StyleType* _style;
	T _value;
	T _default;
	bool _isSet;
	T (StyleType::*_getter)() const;
	void (StyleType::*_changeSignal)(T);
	void (StyleType::*_setChangeSignal)(bool);

};

} // namespace Style

#endif // STYLE_OVERLOADABLEPROPERTY_H
