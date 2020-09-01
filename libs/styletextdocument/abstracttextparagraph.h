#ifndef ABSTRACTTEXTPARAGRAPH_H
#define ABSTRACTTEXTPARAGRAPH_H

#include "styletextdocument_global.h"

#include <QObject>

#include "spanview.h"

namespace Style {

class AbstractTextDocument;
class ParagraphStyle;

class STYLE_TEXTDOCUMENT_EXPORT AbstractTextParagraph : public QObject
{
	Q_OBJECT
public:
	explicit AbstractTextParagraph(AbstractTextDocument *parent = nullptr);

	ParagraphStyle *style() const;
	void setStyle(ParagraphStyle *style);

	virtual QString text() const;
	void setText(const QString &text);
	void insert(int position, const QString &str);
	void replace(int position, uint32_t len, const QString &str);
    void setSpanStyle(int position, int len, SpanStyle * style);

	virtual int countSpan() const;
	SpanView spanAt(int i) const;

Q_SIGNALS:

	void styleChanged(ParagraphStyle* style);

	void textChanged();
	void spanLayoutChanged();

	void paragraphChanged();

public Q_SLOTS:

protected:
	QString _text;
	QList<SpanView> _spanmarks;
	ParagraphStyle* _style;
};

} // namespace Style

#endif // ABSTRACTTEXTPARAGRAPH_H
