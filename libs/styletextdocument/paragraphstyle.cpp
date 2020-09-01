#include "paragraphstyle.h"

#include <math.h>

namespace Style {

ParagraphStyle::ParagraphStyle(QObject *parent) :
	QObject (parent),
	_parentStyle(nullptr)
{

}
ParagraphStyle::ParagraphStyle(ParagraphStyle* parent) :
	QObject (parent),
	_parentStyle(parent)
{

}

ParagraphStyle* ParagraphStyle::parentStyle() const {
	return _parentStyle;
}
void ParagraphStyle::setParentStyle(ParagraphStyle* parentStyle) {

	if (_parentStyle != parentStyle) {
		_parentStyle = parentStyle;
		Q_EMIT parentStyleChanged(_parentStyle);
	}

}

quint32 ParagraphStyle::gluedFirstLines() const
{
	return _glueNbFirstLines;
}

void ParagraphStyle::setGluedFirstLines(const quint32 &glueNbFirstLines)
{
	if (_glueNbFirstLines != glueNbFirstLines) {
		_glueNbFirstLines = glueNbFirstLines;
		Q_EMIT gluedFirstLinesChanged(_glueNbLastLines);
	}
}

quint32 ParagraphStyle::gluedLastLines() const
{
	return _glueNbLastLines;
}

void ParagraphStyle::setGluedLastLines(const quint32 &glueNbLastLines)
{
	if (_glueNbLastLines != glueNbLastLines) {
		_glueNbLastLines = glueNbLastLines;
		Q_EMIT gluedLastLinesChanged(_glueNbLastLines);
	}
}

qreal ParagraphStyle::indentMargin() const
{
	return static_cast<qreal>(_indentMargin)/100.;
}

void ParagraphStyle::setIndentMargin(const qreal &im)
{
	qint32 f = static_cast<qint32>(std::round(im*100));
	if (_indentMargin != f) {
		_indentMargin = f;
		Q_EMIT indentMarginChanged(indentMargin());
	}
}

qreal ParagraphStyle::leftMargin() const
{
	return static_cast<qreal>(_leftMargin)/100.;
}

void ParagraphStyle::setLeftMargin(const qreal &lm)
{
	qint32 f = static_cast<qint32>(std::round(lm*100));
	if (_leftMargin != f) {
		_leftMargin = f;
		Q_EMIT leftMarginChanged(leftMargin());
	}
}

qreal ParagraphStyle::rightMargin() const
{
	return static_cast<qreal>(_rightMargin)/100.;
}

void ParagraphStyle::setRightMargin(const qreal &rm)
{
	qint32 f = static_cast<qint32>(std::round(rm*100));
	if (_rightMargin != f) {
		_rightMargin = f;
		Q_EMIT rightMarginChanged(rightMargin());
	}
}

bool ParagraphStyle::doNotSplit() const
{
	return _doNotSplit;
}

void ParagraphStyle::setDoNotSplit(bool doNotSplit)
{
	if (_doNotSplit != doNotSplit) {
		_doNotSplit = doNotSplit;
		Q_EMIT doNotSplitChanged(_doNotSplit);
	}
}

qreal ParagraphStyle::spaceAbove() const
{
	return static_cast<qreal>(_spaceAbove)/100.;
}

void ParagraphStyle::setSpaceAbove(const qreal &sa)
{qint32 f = static_cast<qint32>(std::round(sa*100));
	if (_spaceAbove != f) {
		_spaceAbove = f;
		Q_EMIT spaceAboveChanged(spaceAbove());
	}
}

qreal ParagraphStyle::spaceBelow() const
{
	return static_cast<qreal>(_spaceBelow)/100.;
}

void ParagraphStyle::setSpaceBelow(const qreal &sb)
{
	qint32 f = static_cast<qint32>(std::round(sb*100));
	if (_spaceBelow != f) {
		_spaceBelow = f;
		Q_EMIT spaceBelowChanged(spaceBelow());
	}
}

qreal ParagraphStyle::lineSpace() const
{
	return static_cast<qreal>(_lineSpace)/100.;
}

void ParagraphStyle::setLineSpace(const qreal &ls)
{
	qint32 f = static_cast<qint32>(std::round(ls*100));
	if (_lineSpace != f) {
		_lineSpace = f;
		Q_EMIT lineSpaceChanged(lineSpace());
	}
}

SpanStyle *ParagraphStyle::defaultSpanStyle() const
{
	return _defaultSpanStyle;
}

void ParagraphStyle::setDefaultSpanStyle(SpanStyle *defaultSpanStyle)
{
	if (_defaultSpanStyle != defaultSpanStyle) {
		_defaultSpanStyle = defaultSpanStyle;
		Q_EMIT defaultSpanStyleChanged(_defaultSpanStyle);
	}
}

} // namespace Style
