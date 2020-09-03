#include "spanstyle.h"

#include <QColor>

namespace Style {

SpanStyle::SpanStyle(QObject *parent) :
	AbstractStyle(parent),
	_parentStyle(nullptr),
	_fontName(this,
			  &SpanStyle::fontName,
			  &SpanStyle::fontNameChanged,
			  &SpanStyle::fontNameSetStatusChanged,
			  "serif"),
	_fontSize(this,
			  &SpanStyle::fontSize,
			  &SpanStyle::fontSizeChanged,
			  &SpanStyle::fontSizeSetStatusChanged,
			  UnitValue(10, UnitValue::pt)),
	_fontStyle(this,
			  &SpanStyle::fontStyle,
			  &SpanStyle::fontStyleChanged,
			  &SpanStyle::fontStyleSetStatusChanged,
			  Normal),
	_fontWeight(this,
			  &SpanStyle::fontWeight,
			  &SpanStyle::fontWeightChanged,
			  &SpanStyle::fontWeightSetStatusChanged,
			  400),
	_fontDecoration(this,
			  &SpanStyle::fontDecoration,
			  &SpanStyle::fontDecorationChanged,
			  &SpanStyle::fontDecorationSetStatusChanged,
			  NoDecoration),
	_fontColor(this,
			  &SpanStyle::fontColor,
			  &SpanStyle::fontColorChanged,
			  &SpanStyle::fontColorSetStatusChanged,
			  QColor(0, 0, 0))
{

}
SpanStyle::SpanStyle(SpanStyle* parent) :
	SpanStyle (static_cast<QObject*>(parent))
{
	setParentStyle(parent);
}

AbstractStyle::Styletype SpanStyle::styletype() const {
	return AbstractStyle::SpanStyletype;
}

AbstractStyle* SpanStyle::styleParent() const {
	return spanStyleParent();
}

SpanStyle* SpanStyle::spanStyleParent() const {
	return _parentStyle;
}

void SpanStyle::setParentStyle(SpanStyle* parentStyle) {

	if (parentStyle != _parentStyle) {
		_parentStyle = parentStyle;
		Q_EMIT parentStyleChanged(_parentStyle);
	}

}


QString SpanStyle::fontName() const {
	return _fontName.getValue();
}
void SpanStyle::setFontName(const QString &fn) {
	_fontName.setValue(fn);
}
void SpanStyle::clearFontName() {
	_fontName.clearValue();
}
bool SpanStyle::isFontNameSet() {
	return _fontName.isSet();
}

UnitValue SpanStyle::fontSize() const {
	return _fontSize.getValue();
}
void SpanStyle::setFontSize(const UnitValue &fs) {
	if (fs.isValid()) {
		_fontSize.setValue(fs);
	} else {
		clearFontSize();
	}
}
void SpanStyle::clearFontSize() {
	_fontSize.clearValue();
}
bool SpanStyle::isFontSizeSet() const {
	return _fontSize.isSet();
}

SpanStyle::FontStyle SpanStyle::fontStyle() const {
	return _fontStyle.getValue();
}
void SpanStyle::setFontStyle(const FontStyle &fs) {
	_fontStyle.setValue(fs);
}
void SpanStyle::clearFontStyle() {
	_fontStyle.clearValue();
}
bool SpanStyle::isFontStyleSet() const {
	return _fontStyle.isSet();
}

int SpanStyle::fontWeight() const {
	return _fontWeight.getValue();
}
void SpanStyle::setFontWeight(const int &fw) {
	_fontWeight.setValue(fw);
}
void SpanStyle::clearFontWeight() {
	_fontWeight.clearValue();
}
bool SpanStyle::isFontWeightSet() const {
	return _fontWeight.isSet();
}

SpanStyle::FontDecoration SpanStyle::fontDecoration() const {
	return _fontDecoration.getValue();
}
void SpanStyle::setFontDecoration(const FontDecorations &fd) {
	_fontDecoration.setValue(fd);
}
void SpanStyle::clearFontDecoration() {
	_fontDecoration.clearValue();
}
bool SpanStyle::isFontDecorationSet() const {
	return _fontDecoration.isSet();
}

QColor SpanStyle::fontColor() const {
	return _fontColor.getValue();
}
void SpanStyle::setFontColor(const QColor &fc) {
	if (fc.isValid()) {
		_fontColor.setValue(fc);
	} else {
		clearFontColor();
	}
}
void SpanStyle::clearFontColor() {
	_fontColor.clearValue();
}
bool SpanStyle::isFontColorSet() const {
	return _fontColor.isSet();
}

} // namespace Style
