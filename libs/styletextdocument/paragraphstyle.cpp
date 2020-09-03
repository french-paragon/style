#include "paragraphstyle.h"

#include <math.h>

namespace Style {

ParagraphStyle::ParagraphStyle(QObject *parent) :
	AbstractStyle (parent),
	_parentStyle(nullptr),
	_spaceAbove(this,
				&ParagraphStyle::spaceAbove,
				&ParagraphStyle::spaceAboveChanged,
				&ParagraphStyle::spaceAboveSetStatusChanged,
				UnitValue(0, UnitValue::pt)),
	_spaceBelow(this,
				&ParagraphStyle::spaceBelow,
				&ParagraphStyle::spaceBelowChanged,
				&ParagraphStyle::spaceBelowSetStatusChanged,
				UnitValue(0, UnitValue::pt)),
	_lineSpace(this,
				&ParagraphStyle::lineSpace,
				&ParagraphStyle::lineSpaceChanged,
				&ParagraphStyle::lineSpaceSetStatusChanged,
				UnitValue(12, UnitValue::pt)),
	_indentMargin(this,
				&ParagraphStyle::indentMargin,
				&ParagraphStyle::indentMarginChanged,
				&ParagraphStyle::indentMarginSetStatusChanged,
				UnitValue(0, UnitValue::pt)),
	_leftMargin(this,
				&ParagraphStyle::leftMargin,
				&ParagraphStyle::leftMarginChanged,
				&ParagraphStyle::leftMarginSetStatusChanged,
				UnitValue(0, UnitValue::pt)),
	_rightMargin(this,
				&ParagraphStyle::rightMargin,
				&ParagraphStyle::rightMarginChanged,
				&ParagraphStyle::rightMarginSetStatusChanged,
				UnitValue(0, UnitValue::pt)),
	_doNotSplit(this,
				&ParagraphStyle::doNotSplit,
				&ParagraphStyle::doNotSplitChanged,
				&ParagraphStyle::doNotSplitSetStatusChanged,
				false),
	_glueNbFirstLines(this,
					  &ParagraphStyle::gluedFirstLines,
					  &ParagraphStyle::gluedFirstLinesChanged,
					  &ParagraphStyle::gluedFirstLinesSetStatusChanged,
					  0),
	_glueNbLastLines(this,
					 &ParagraphStyle::gluedLastLines,
					 &ParagraphStyle::gluedFirstLinesChanged,
					 &ParagraphStyle::gluedLastLinesSetStatusChanged,
					 0)
{

}
ParagraphStyle::ParagraphStyle(ParagraphStyle* parent) :
	ParagraphStyle (static_cast<QObject*>(parent))
{
	setParentStyle(parent);
}

AbstractStyle::Styletype ParagraphStyle::styletype() const {
	return AbstractStyle::ParagraphStyletype;
}

AbstractStyle* ParagraphStyle::styleParent() const {
	return paragraphStyleParent();
}

ParagraphStyle* ParagraphStyle::paragraphStyleParent() const {
	return _parentStyle;
}
void ParagraphStyle::setParentStyle(ParagraphStyle* parentStyle) {

	if (_parentStyle != parentStyle) {
		_parentStyle = parentStyle;
		Q_EMIT parentStyleChanged(_parentStyle);
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

quint32 ParagraphStyle::gluedFirstLines() const
{
	return _glueNbFirstLines.getValue();
}

void ParagraphStyle::setGluedFirstLines(const quint32 &glueNbFirstLines)
{
	_glueNbFirstLines.setValue(glueNbFirstLines);
}
void ParagraphStyle::clearGlueadFirstLines() {
	_glueNbFirstLines.clearValue();
}
bool ParagraphStyle::gluedFirstLinesSet() const {
	return _glueNbFirstLines.isSet();
}

quint32 ParagraphStyle::gluedLastLines() const
{
	return _glueNbLastLines.getValue();
}

void ParagraphStyle::setGluedLastLines(const quint32 &glueNbLastLines)
{
	_glueNbLastLines.setValue(glueNbLastLines);
}
void ParagraphStyle::clearGlueadLastLines() {
	_glueNbLastLines.clearValue();
}
bool ParagraphStyle::gluedLastLinesSet() const {
	return _glueNbLastLines.isSet();
}

bool ParagraphStyle::doNotSplit() const
{
	return _doNotSplit.getValue();
}

void ParagraphStyle::setDoNotSplit(bool dns)
{
	_doNotSplit.setValue(dns);
}

void ParagraphStyle::clearDoNotSplit() {
	_doNotSplit.clearValue();
}
bool ParagraphStyle::doNotSplitSet() const {
	return _doNotSplit.isSet();
}

UnitValue ParagraphStyle::spaceAbove() const{
	return _spaceAbove.getValue();
}

void ParagraphStyle::setSpaceAbove(const UnitValue &sa)
{
	if (sa.isValid()) {
		_spaceAbove.setValue(sa);
	} else {
		clearSpaceAbove();
	}
}
void ParagraphStyle::clearSpaceAbove() {
	_spaceAbove.clearValue();
}
bool ParagraphStyle::spaceAboveSet() const {
	return _spaceAbove.isSet();
}

UnitValue ParagraphStyle::spaceBelow() const{
	return _spaceBelow.getValue();
}

void ParagraphStyle::setSpaceBelow(const UnitValue &sb)
{
	if(sb.isValid()) {
		_spaceBelow.setValue(sb);
	} else {
		_spaceBelow.clearValue();
	}
}
void ParagraphStyle::clearSpaceBelow() {
	_spaceBelow.clearValue();
}
bool ParagraphStyle::spaceBelowSet() const {
	return _spaceBelow.isSet();
}

UnitValue ParagraphStyle::lineSpace() const{
	return _lineSpace.getValue();
}

void ParagraphStyle::setLineSpace(const UnitValue &ls)
{
	if (ls.isValid()) {
		_lineSpace.setValue(ls);
	} else {
		clearLineSpace();
	}
}
void ParagraphStyle::clearLineSpace() {
	_lineSpace.clearValue();
}
bool ParagraphStyle::lineSpaceSet() const {
	return _lineSpace.isSet();
}

UnitValue ParagraphStyle::indentMargin() const{
	return _indentMargin.getValue();
}

void ParagraphStyle::setIndentMargin(const UnitValue &im)
{
	if (im.isValid()) {
		_indentMargin.setValue(im);
	} else {
		clearIndentMargin();
	}
}
void ParagraphStyle::clearIndentMargin() {
	_indentMargin.clearValue();
}
bool ParagraphStyle::indentMarginSet() const {
	return _indentMargin.isSet();
}

UnitValue ParagraphStyle::leftMargin() const{
	return _leftMargin.getValue();
}

void ParagraphStyle::setLeftMargin(const UnitValue &lm)
{
	if (!lm.isValid()) {
		clearLeftMargin();
	} else {
		_leftMargin.setValue(lm);
	}
}
void ParagraphStyle::clearLeftMargin() {
	_leftMargin.clearValue();
}
bool ParagraphStyle::leftMarginSet() const {
	return _leftMargin.isSet();
}

UnitValue ParagraphStyle::rightMargin() const
{
	return _rightMargin.getValue();
}

void ParagraphStyle::setRightMargin(const UnitValue &rm)
{
	if (!rm.isValid()) {
		clearRightMargin();
	} else {
		_rightMargin.setValue(rm);
	}
}
void ParagraphStyle::clearRightMargin() {
	_rightMargin.clearValue();
}
bool ParagraphStyle::rightMarginSet() {
	return _rightMargin.isSet();
}

} // namespace Style
