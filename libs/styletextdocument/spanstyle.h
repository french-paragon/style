#ifndef SPANSTYLE_H
#define SPANSTYLE_H

#include "./styletextdocument_global.h"
#include "./unitvalue.h"

#include "./abstractstyle.h"

#include "./overloadableproperty.h"

#include <QString>
#include <QColor>

namespace Style {

class STYLE_TEXTDOCUMENT_EXPORT SpanStyle : public AbstractStyle
{
	Q_OBJECT
public:
	enum FontStyle {
		Normal = 0x0,
		Oblique = 0x1,
		Italic = 0x2
	};

	enum FontDecorations {
		NoDecoration = 0x0,
		Underlined = 0x1,
		Stricked = 0x2
	};
	Q_DECLARE_FLAGS(FontDecoration, FontDecorations)
	Q_FLAG(FontDecorations)

	explicit SpanStyle(QObject *parent = nullptr);
	explicit SpanStyle(SpanStyle* parent);

	AbstractStyle::Styletype styletype() const;

	virtual AbstractStyle* styleParent() const;
	SpanStyle* spanStyleParent() const;
	void setParentStyle(SpanStyle *parentStyle);

	QString fontName() const;
	void setFontName(const QString &fontName);
	void clearFontName();
	bool isFontNameSet();

	UnitValue fontSize() const;
	void setFontSize(const UnitValue &fontSize);
	void clearFontSize();
	bool isFontSizeSet() const;

	FontStyle fontStyle() const;
	void setFontStyle(const FontStyle &fontStyle);
	void clearFontStyle();
	bool isFontStyleSet() const;

	int fontWeight() const;
	void setFontWeight(const int &fontWeight);
	void clearFontWeight();
	bool isFontWeightSet() const;

	FontDecoration fontDecoration() const;
	void setFontDecoration(const FontDecorations &fontDecoration);
	void clearFontDecoration();
	bool isFontDecorationSet() const;

	QColor fontColor() const;
	void setFontColor(const QColor &fontColor);
	void clearFontColor();
	bool isFontColorSet() const;

Q_SIGNALS:

	void parentStyleChanged(SpanStyle* parentStyle);

	void fontNameChanged(QString);
	void fontNameSetStatusChanged(bool);

	void fontSizeChanged(UnitValue);
	void fontSizeSetStatusChanged(bool);

	void fontStyleChanged(FontStyle);
	void fontStyleSetStatusChanged(bool);

	void fontWeightChanged(int);
	void fontWeightSetStatusChanged(bool);

	void fontDecorationChanged(FontDecoration);
	void fontDecorationSetStatusChanged(bool);

	void fontColorChanged(QColor);
	void fontColorSetStatusChanged(bool);

public Q_SLOTS:

protected:

	SpanStyle* _parentStyle;

	OverloadableProperty<QString, AbstractStyle::SpanStyletype> _fontName;
	OverloadableProperty<UnitValue, AbstractStyle::SpanStyletype> _fontSize;
	OverloadableProperty<FontStyle, AbstractStyle::SpanStyletype> _fontStyle;
	OverloadableProperty<int, AbstractStyle::SpanStyletype> _fontWeight;
	OverloadableProperty<FontDecoration, AbstractStyle::SpanStyletype> _fontDecoration;

	OverloadableProperty<QColor, AbstractStyle::SpanStyletype> _fontColor;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(SpanStyle::FontDecoration)

} // namespace Style

#endif // SPANSTYLE_H
