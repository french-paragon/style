#ifndef SPANVIEW_H
#define SPANVIEW_H

#include "styletextdocument_global.h"

#include <QtGlobal>
#include <QStringView>

namespace Style {

class AbstractTextParagraph;
class SpanStyle;

class STYLE_TEXTDOCUMENT_EXPORT SpanView
{
    friend class Style::AbstractTextParagraph;

public:

	SpanView(AbstractTextParagraph* paragraph, int startPos, int len, SpanStyle* style);
	SpanView(SpanView const& other);

	QString text() const;
	SpanStyle* style() const;

    bool intersect(SpanView const& other) const;
    bool contain(SpanView const& other) const;
    bool matchPos(SpanView const& other) const;
	bool operator <(SpanView const& other) const;
	bool operator ==(SpanView const& other) const;

	int startPos() const;
	int endPos() const;
	int len() const;

private:

	AbstractTextParagraph* _paragraph;

	SpanStyle* _style;
	int _startPos;
	int _len;

};

} // namespace Style

#endif // SPANVIEW_H
