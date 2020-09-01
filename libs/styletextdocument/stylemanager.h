#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QObject>

#include "styletextdocument/paragraphstyle.h"
#include "styletextdocument/spanstyle.h"

namespace Style {

class StyleManager : public QObject
{
	Q_OBJECT
public:
	explicit StyleManager(QObject *parent = nullptr);

	ParagraphStyle* getParagraphStyleByName(QString name) const;
	void insertParagraphStyle(ParagraphStyle* style, bool takeOwnership = true);

Q_SIGNALS:

public Q_SLOTS:
};

} // namespace Style

#endif // STYLEMANAGER_H
