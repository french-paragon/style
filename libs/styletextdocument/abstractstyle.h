#ifndef STYLE_ABSTRACTSTYLE_H
#define STYLE_ABSTRACTSTYLE_H

#include <QObject>

namespace Style {

class AbstractStyle : public QObject
{
	Q_OBJECT
public:
    enum Styletype {
        SpanStyletype,
        ParagraphStyletype
    };

    explicit AbstractStyle(QObject *parent = nullptr);

    virtual Styletype styletype() const = 0;
    virtual AbstractStyle* styleParent() const = 0;

Q_SIGNALS:

};

} // namespace Style

#endif // STYLE_ABSTRACTSTYLE_H
