#ifndef ABSTRACTTEXTDOCUMENT_H
#define ABSTRACTTEXTDOCUMENT_H

#include "styletextdocument_global.h"

#include <QObject>

namespace Style {

class AbstractTextParagraph;

class STYLE_TEXTDOCUMENT_EXPORT AbstractTextDocument : public QObject
{
	Q_OBJECT
public:

	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)

	explicit AbstractTextDocument(QObject *parent = nullptr);

	int countParagraphs() const;

	AbstractTextParagraph* paragraphAt(int index);
	const AbstractTextParagraph* paragraphAt(int index) const;

	int insertParagraph(int index, AbstractTextParagraph* p);
	int clearParagraph(int index);
	int moveParagraph(int start, int dest);

	QString title() const;
	void setTitle(const QString &title);

	QString author() const;
	void setAuthor(const QString &author);

Q_SIGNALS:

	void paragraphsAboutToBeInserted(int index, int n = 1);
	void paragraphsAboutToBeRemoved(int index, int n = 1);
	void paragraphsAboutToBeMoved(int start, int dest, int n = 1);
	void paragraphsInserted(int index, int n = 1);
	void paragraphsRemoved(int index, int n = 1);
	void paragraphsMoved(int start, int dest, int n = 1);

	void paragraphDataChanged(int index);

	void titleChanged(QString title);
	void authorChanged(QString author);

public Q_SLOTS:

protected :

	QString _title;
	QString _author;
	QList<AbstractTextParagraph*> _paragraphs;

};

} // namespace Style

#endif // ABSTRACTTEXTDOCUMENT_H
