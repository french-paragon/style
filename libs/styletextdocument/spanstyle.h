#ifndef SPANSTYLE_H
#define SPANSTYLE_H

#include "styletextdocument_global.h"

#include <QObject>
#include <QVariant>

namespace Style {

class STYLE_TEXTDOCUMENT_EXPORT SpanStyle : public QObject
{
	Q_OBJECT
public:
	enum FontDecoration {
		NoDecoration = 0x0,
		Underlined = 0x1,
		Stricked = 0x2
	};
	Q_DECLARE_FLAGS(FontDecorations, FontDecoration)
	Q_FLAG(FontDecorations)

	explicit SpanStyle(QObject *parent = nullptr);
	explicit SpanStyle(SpanStyle* parent);

	SpanStyle* parentStyle() const;
	void setParentStyle(SpanStyle *parentStyle);

	QVariant fontName() const;
	void setFontName(const QString &fontName);
	void clearFontName();

	QVariant fontSize() const;
	void setFontSize(const int &fontSize);
	void clearFontSize();

	QVariant fontStyle() const;
	void setFontStyle(const int &fontStyle);
	void clearFontStyle();

	QVariant fontWeight() const;
	void setFontWeight(const int &fontWeight);
	void clearFontWeight();

	QVariant fontDecoration() const;
	void setFontDecoration(const FontDecorations &fontDecoration);
	void clearFontDecoration();

	QVariant fontColor() const;
	void setFontColor(const QColor &fontColor);
	void clearFontColor();

Q_SIGNALS:

	void parentStyleChanged(SpanStyle* parentStyle);

public Q_SLOTS:

protected:

	SpanStyle* _parentStyle;

	QVariant _fontName;
	QVariant _fontSize;
	QVariant _fontStyle;
	QVariant _fontWeight;
	QVariant _fontDecoration;

	QVariant _fontColor;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(SpanStyle::FontDecorations)

} // namespace Style

#endif // SPANSTYLE_H
