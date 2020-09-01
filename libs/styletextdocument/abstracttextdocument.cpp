#include "abstracttextdocument.h"

#include "abstracttextparagraph.h"

namespace Style {

AbstractTextDocument::AbstractTextDocument(QObject *parent) : QObject(parent)
{

}

int AbstractTextDocument::countParagraphs() const {
	return _paragraphs.size();
}

AbstractTextParagraph* AbstractTextDocument::paragraphAt(int index) {
	return _paragraphs.at(index);
}
const AbstractTextParagraph* AbstractTextDocument::paragraphAt(int index) const {
	return _paragraphs.at(index);
}

int AbstractTextDocument::insertParagraph(int index, AbstractTextParagraph* p) {

	if (this != qobject_cast<AbstractTextDocument*>(p->parent())) {
		return 0;
	}

	if (_paragraphs.contains(p)) {
		return 0;
	}

	Q_EMIT paragraphsAboutToBeInserted(index);

	_paragraphs.insert(index, p);

	Q_EMIT paragraphsInserted(index);

	return 1;
}

int AbstractTextDocument::clearParagraph(int index) {

	Q_EMIT paragraphsAboutToBeRemoved(index);

	_paragraphs.removeAt(index);

	Q_EMIT paragraphsRemoved(index);

	return 1;

}

int AbstractTextDocument::moveParagraph(int start, int dest) {

	Q_EMIT paragraphsAboutToBeMoved(start, dest);

	_paragraphs.move(start, dest);

	Q_EMIT paragraphsMoved(start, dest);

	return 1;
}

QString AbstractTextDocument::title() const
{
	return _title;
}

void AbstractTextDocument::setTitle(const QString &title)
{
	if (_title != title) {
		_title = title;
		Q_EMIT titleChanged(title);
	}
}

QString AbstractTextDocument::author() const
{
	return _author;
}

void AbstractTextDocument::setAuthor(const QString &author)
{
	if (_author != author) {
		_author = author;
		Q_EMIT authorChanged(author);
	}
}

} // namespace Style
