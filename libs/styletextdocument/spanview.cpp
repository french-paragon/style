#include "spanview.h"

#include "abstracttextparagraph.h"

namespace Style {

SpanView::SpanView(AbstractTextParagraph* paragraph,
				   int startPos,
				   int len,
				   SpanStyle* style) :
	_paragraph(paragraph),
	_style(style),
	_startPos(startPos),
	_len(len)
{

}
SpanView::SpanView(SpanView const& other) :
	SpanView(other._paragraph, other._startPos, other.len(), other.style())
{

}

QString SpanView::text() const {

	QString txt = _paragraph->text();
	return txt.mid(_startPos, _len);

}
SpanStyle* SpanView::style() const {
	return _style;
}

bool SpanView::intersect(SpanView const& other) const {

	if (other._paragraph != _paragraph) {
		return false;
	}

    return !((_startPos + _len) < other.startPos() || (other.startPos() + other.len()) < _startPos);

}

bool SpanView::contain(SpanView const& other) const {

    if (other._paragraph != _paragraph) {
        return false;
    }

    return (_startPos + _len) >= (other.startPos() + other.len()) && _startPos <= other.startPos();

}

bool SpanView::matchPos(SpanView const& other) const {

    if (other._paragraph != _paragraph) {
        return false;
    }

    return (_startPos + _len) == (other.startPos() + other.len()) && _startPos == other.startPos();
}

bool SpanView::operator <(SpanView const& other) const {

	if (other._paragraph != _paragraph) {
		return false;
	}

    return _startPos < other._startPos;
}
bool SpanView::operator ==(SpanView const& other) const {

	if (other._paragraph != _paragraph) {
		return false;
	}

	if (other._startPos != _startPos) {
		return false;
	}

	if (other._len != _len) {
		return false;
	}

	if (other._style != _style) {
		return false;
	}

	return true;

}

int SpanView::startPos() const
{
	return _startPos;
}

int SpanView::endPos() const
{
	return startPos() + len();
}

int SpanView::len() const
{
	return _len;
}

} // namespace Style
