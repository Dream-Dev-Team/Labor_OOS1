#include "PlgElement.hpp"
extern bool debugConstruktor;

PlgElement::PlgElement(Point& p)
{
	point = p;
	next = nullptr;
	if (debugConstructor) {
		cout << "Konstruktor der Klasse PlgElement, Objekt:" << this->getID() << endl;
	}
}
PlgElement::~PlgElement() {
	if (debugConstructor) {
		cout << "Destruktor der Klasse PlgElement, Objekt:" << this->getID() << endl;
	}

}


void PlgElement::print(bool nl) const
{
	point.print(nl);
}

PlgElement* PlgElement::getNext() const
{
	return next;
}

const Point& PlgElement::getPoint() const
{
	return point;
}

void PlgElement::setNext(PlgElement* p)
{
	next = p;
}

void PlgElement::move(double dx, double dy)
{
	point.move(dx, dy);
}