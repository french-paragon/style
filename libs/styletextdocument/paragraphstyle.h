#ifndef ABSTRACTPARAGRAPHSTYLE_H
#define ABSTRACTPARAGRAPHSTYLE_H

#include "./styletextdocument_global.h"
#include "./unitvalue.h"

#include "./abstractstyle.h"

#include "./overloadableproperty.h"

#include <QVariant>

namespace Style {

class SpanStyle;

class STYLE_TEXTDOCUMENT_EXPORT ParagraphStyle : public AbstractStyle
{
	Q_OBJECT

public:

	enum ScaleMode {
		AlignLeft,
		AlignCenter,
		AlignRight,
		Jusitfy,
		CompleteJustify
	};

	ParagraphStyle(QObject* parent = nullptr);
	ParagraphStyle(ParagraphStyle* parent);

	AbstractStyle::Styletype styletype() const;

	SpanStyle* spanStyle() const;

	virtual AbstractStyle* styleParent() const;
	ParagraphStyle* paragraphStyleParent() const;
	void setParentStyle(ParagraphStyle* parentStyle);

	SpanStyle *defaultSpanStyle() const;
	void setDefaultSpanStyle(SpanStyle *defaultSpanStyle);

	quint32 gluedFirstLines() const;
	void setGluedFirstLines(const quint32 &gluedFirstLines);
	void clearGlueadFirstLines();
	bool gluedFirstLinesSet() const;

	quint32 gluedLastLines() const;
	void setGluedLastLines(const quint32 &gluedLastLines);
	void clearGlueadLastLines();
	bool gluedLastLinesSet() const;

	bool doNotSplit() const;
	void setDoNotSplit(bool doNotSplit);
	void clearDoNotSplit();
	bool doNotSplitSet() const;

	UnitValue spaceAbove() const;
	void setSpaceAbove(const UnitValue &spaceAbove);
	void clearSpaceAbove();
	bool spaceAboveSet() const;

	UnitValue spaceBelow() const;
	void setSpaceBelow(const UnitValue &spaceBelow);
	void clearSpaceBelow();
	bool spaceBelowSet() const;

	UnitValue lineSpace() const;
	void setLineSpace(const UnitValue &lineSpace);
	void clearLineSpace();
	bool lineSpaceSet() const;

	UnitValue indentMargin() const;
	void setIndentMargin(const UnitValue &indentMargin);
	void clearIndentMargin();
	bool indentMarginSet() const;

	UnitValue leftMargin() const;
	void setLeftMargin(const UnitValue &leftMargin);
	void clearLeftMargin();
	bool leftMarginSet() const;

	UnitValue rightMargin() const;
	void setRightMargin(const UnitValue &rightMargin);
	void clearRightMargin();
	bool rightMarginSet();

Q_SIGNALS:

	void parentStyleChanged(ParagraphStyle* parent);
	void defaultSpanStyleChanged(SpanStyle *defaultSpanStyle);

	void spaceAboveChanged(UnitValue space);
	void spaceAboveSetStatusChanged(bool setStatus);
	void spaceBelowChanged(UnitValue space);
	void spaceBelowSetStatusChanged(bool setStatus);
	void lineSpaceChanged(UnitValue space);
	void lineSpaceSetStatusChanged(bool setStatus);

	void indentMarginChanged(UnitValue margin);
	void indentMarginSetStatusChanged(bool setStatus);
	void leftMarginChanged(UnitValue margin);
	void leftMarginSetStatusChanged(bool setStatus);
	void rightMarginChanged(UnitValue margin);
	void rightMarginSetStatusChanged(bool setStatus);

	void doNotSplitChanged(bool doNotSplit);
	void doNotSplitSetStatusChanged(bool setStatus);

	void gluedFirstLinesChanged(quint32 n);
	void gluedFirstLinesSetStatusChanged(bool setStatus);

	void gluedLastLinesChanged(quint32 n);
	void gluedLastLinesSetStatusChanged(bool setStatus);

private:

	ParagraphStyle* _parentStyle;
	SpanStyle* _defaultSpanStyle;

	OverloadableProperty<UnitValue, AbstractStyle::ParagraphStyletype> _spaceAbove;
	OverloadableProperty<UnitValue, AbstractStyle::ParagraphStyletype> _spaceBelow;
	OverloadableProperty<UnitValue, AbstractStyle::ParagraphStyletype> _lineSpace;

	OverloadableProperty<UnitValue, AbstractStyle::ParagraphStyletype> _indentMargin;
	OverloadableProperty<UnitValue, AbstractStyle::ParagraphStyletype> _leftMargin;
	OverloadableProperty<UnitValue, AbstractStyle::ParagraphStyletype> _rightMargin;

	OverloadableProperty<bool, AbstractStyle::ParagraphStyletype> _doNotSplit;
	OverloadableProperty<quint32, AbstractStyle::ParagraphStyletype> _glueNbFirstLines;
	OverloadableProperty<quint32, AbstractStyle::ParagraphStyletype> _glueNbLastLines;
};

} // namespace Style

#endif // ABSTRACTPARAGRAPHSTYLE_H
