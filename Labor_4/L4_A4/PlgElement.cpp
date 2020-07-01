#include "PlgElement.hpp"

PlgElement::PlgElement(Point& p)
{
	point = p;
	next = nullptr;
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