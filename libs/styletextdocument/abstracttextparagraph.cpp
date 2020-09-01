#include "abstracttextparagraph.h"

#include "abstracttextdocument.h"
#include "paragraphstyle.h"

namespace Style {

AbstractTextParagraph::AbstractTextParagraph(AbstractTextDocument *parent) : QObject(parent)
{

}

ParagraphStyle *AbstractTextParagraph::style() const
{
	return _style;
}

void AbstractTextParagraph::setStyle(ParagraphStyle *style)
{
	_style = style;
}

QString AbstractTextParagraph::text() const
{
	return _text;
}

void AbstractTextParagraph::setText(const QString &text)
{
	_text = text;
	_spanmarks.clear();

	Q_EMIT spanLayoutChanged();
	Q_EMIT textChanged();
	Q_EMIT paragraphChanged();
}
void AbstractTextParagraph::insert(int position, const QString &str)
{
	replace(position, 0, str);
}

void AbstractTextParagraph::replace(int position, uint32_t l, const QString &str) {

	bool spanChanged = false;

	int len = static_cast<int>(l);

	int spanRemoved = -1;
	int id = 0;
	for (SpanView & s : _spanmarks) {

		if (s.startPos() > position + len) { // insert before span
			s._startPos += str.length() - len;
			spanChanged = true;
		} else if (s.startPos() > position && s.startPos() <= position + len) {//start before start of span and end after start of span
			if (s.endPos() > position + len) { //insert over span begin
				s._len -= position + len - s._startPos;
				s._startPos = position + str.length();
			} else { //insert over span
				spanRemoved = id;
				spanChanged = true;
			}
			spanChanged = true;
		} else if (s.startPos() > position && s.startPos() >= position + len) { //start within span
			if (s.endPos() >= position + len) { //insert into span
				s._len += str.length() - len; //extend the span marks.
			} else { //insert over span end
				int delta = s.len() - (position - s.startPos());
				s._len += str.length() - delta; //extend the span marks.
			}
			spanChanged = true;
		}
		//Do not account for insert after span (s.endPos() < position)

		id++;
	}

	if(spanRemoved > 0) {
		_spanmarks.removeAt(spanRemoved);
	}

	_text.remove(position, len);
	_text.insert(position, str);

	Q_EMIT textChanged();
	if (spanChanged) {
		Q_EMIT spanLayoutChanged();
	}
	Q_EMIT paragraphChanged();
}

void AbstractTextParagraph::setSpanStyle(int position, int len, SpanStyle * style) {

    if (position >= _text.length()) {
        return;
    }

    SpanView v(this, position, std::min(len, _text.length() - position), style);

    int previous_id = -1;
    int next_id = -1;

    if (_spanmarks.empty()) {
        _spanmarks.push_back(v);
        goto emit_changed;
    }

    for (int i = 0; i < _spanmarks.size(); i++) {

        if (_spanmarks[i] < v) {
            previous_id = i;
        } else if (next_id < 0 && v < _spanmarks[i]) {
            next_id = i;
            break;
        } else if (v.startPos() == _spanmarks[i].startPos()) {

            if (v.len() == _spanmarks[i].len()) {
                _spanmarks[i]._style = style;
                goto emit_changed;
            } else {
                next_id = i;
                break;
            }
        }

    }

    Q_ASSERT(previous_id < 0 && next_id < 0);

    if (previous_id >= 0) {

        if (_spanmarks[previous_id].intersect(v)) {
            _spanmarks[previous_id]._len = position - _spanmarks[previous_id].startPos();
        }

    }

    if (next_id >= 0) {

        if (v.contain(_spanmarks[next_id])) {
            _spanmarks[next_id] = v;
            goto emit_changed;
        } else if (_spanmarks[next_id].intersect(v)) {
            _spanmarks[next_id]._len = _spanmarks[next_id].len() - v.len() + (_spanmarks[next_id].startPos() - v.startPos());
            _spanmarks[next_id]._startPos = v.startPos() + v.len();
        }

        _spanmarks.insert(next_id, v);

    } else {
        _spanmarks.push_back(v);
    }

    //TODO: unit test this function

    emit_changed :

    Q_EMIT spanLayoutChanged();
    Q_EMIT paragraphChanged();

}

} // namespace Style
