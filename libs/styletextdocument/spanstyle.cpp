#include "spanstyle.h"

#include <QColor>

namespace Style {

SpanStyle::SpanStyle(QObject *parent) :
	QObject(parent),
	_parentStyle(nullptr)
{

}
SpanStyle::SpanStyle(SpanStyle* parent) :
	QObject (parent),
	_parentStyle(parent)
{

}

SpanStyle* SpanStyle::parentStyle() const {
	return _parentStyle;
}

void SpanStyle::setParentStyle(SpanStyle* parentStyle) {

	if (parentStyle != _parentStyle) {
		_parentStyle = parentStyle;
		Q_EMIT parentStyleChanged(_parentStyle);
	}

}

QVariant SpanStyle::fontName() const
{
	return _fontName;
}

void SpanStyle::setFontName(const QString &fontName)
{
	_fontName = fontName;
}
void SpanStyle::clearFontName() {
	_fontName = QVariant();
}


QVariant SpanStyle::fontSize() const
{
	return _fontSize;
}

void SpanStyle::setFontSize(const int &fontSize)
{
	_fontSize = fontSize;
}
void SpanStyle::clearFontSize() {
	_fontSize = QVariant();
}

QVariant SpanStyle::fontStyle() const
{
	return _fontStyle;
}

void SpanStyle::setFontStyle(const int &fontStyle)
{
	_fontStyle = fontStyle;
}
void SpanStyle::clearFontStyle() {
	_fontStyle = QVariant();
}

QVariant SpanStyle::fontWeight() const
{
	return _fontWeight;
}

void SpanStyle::setFontWeight(const int &fontWeight)
{
	_fontWeight = fontWeight;
}
void SpanStyle::clearFontWeight() {
	_fontWeight = QVariant();
}

QVariant SpanStyle::fontDecoration() const
{
	return _fontDecoration;
}

void SpanStyle::setFontDecoration(const FontDecorations &fontDecoration)
{
	_fontDecoration = QVariant::fromValue(fontDecoration);
}
void SpanStyle::clearFontDecoration() {
	_fontDecoration = QVariant();
}

QVariant SpanStyle::fontColor() const
{
	return _fontColor;
}

void SpanStyle::setFontColor(const QColor &fontColor)
{
	_fontColor = QVariant::fromValue(fontColor);
}
void SpanStyle::clearFontColor() {
	_fontColor = QVariant();
}

} // namespace Style
