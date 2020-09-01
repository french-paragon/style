#ifndef ABSTRACTPARAGRAPHSTYLE_H
#define ABSTRACTPARAGRAPHSTYLE_H

#include "styletextdocument_global.h"

#include <QObject>
#include <QVariant>

namespace Style {

class SpanStyle;

class STYLE_TEXTDOCUMENT_EXPORT ParagraphStyle : public QObject
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

	SpanStyle* spanStyle() const;

	ParagraphStyle* parentStyle() const;
	void setParentStyle(ParagraphStyle* parentStyle);

	quint32 gluedFirstLines() const;
	void setGluedFirstLines(const quint32 &gluedFirstLines);

	quint32 gluedLastLines() const;
	void setGluedLastLines(const quint32 &gluedLastLines);

	qreal indentMargin() const;
	void setIndentMargin(const qreal &indentMargin);

	qreal leftMargin() const;
	void setLeftMargin(const qreal &leftMargin);

	qreal rightMargin() const;
	void setRightMargin(const qreal &rightMargin);

	bool doNotSplit() const;
	void setDoNotSplit(bool doNotSplit);

	qreal spaceAbove() const;
	void setSpaceAbove(const qreal &spaceAbove);

	qreal spaceBelow() const;
	void setSpaceBelow(const qreal &spaceBelow);

	qreal lineSpace() const;
	void setLineSpace(const qreal &lineSpace);

	SpanStyle *defaultSpanStyle() const;
	void setDefaultSpanStyle(SpanStyle *defaultSpanStyle);

Q_SIGNALS:

	void parentStyleChanged(ParagraphStyle* parent);
	void defaultSpanStyleChanged(SpanStyle *defaultSpanStyle);

	void spaceAboveChanged(qreal space);
	void spaceBelowChanged(qreal space);
	void lineSpaceChanged(qreal space);

	void indentMarginChanged(qreal margin);
	void leftMarginChanged(qreal margin);
	void rightMarginChanged(qreal margin);

	void doNotSplitChanged(bool doNotSplit);
	void gluedFirstLinesChanged(quint32 n);
	void gluedLastLinesChanged(quint32 n);

private:

	ParagraphStyle* _parentStyle;
	SpanStyle* _defaultSpanStyle;

	qint32 _spaceAbove;
	qint32 _spaceBelow;
	qint32 _lineSpace;

	qint32 _indentMargin;
	qint32 _leftMargin;
	qint32 _rightMargin;

	bool _doNotSplit;
	quint32 _glueNbFirstLines;
	quint32 _glueNbLastLines;
};

} // namespace Style

#endif // ABSTRACTPARAGRAPHSTYLE_H
