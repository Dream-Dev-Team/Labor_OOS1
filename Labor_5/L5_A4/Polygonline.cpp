#include "Polygonline.hpp"
#include <iostream>

using namespace std;

Polygonline::Polygonline()
{
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Polygonline(default), Objekt:" << this->getID() << endl;
	}
	start = end = nullptr;

}

Polygonline::Polygonline(Point& p)
{
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Polygonline(convert), Objekt:" << this->getID() << endl;
	}
	start = end = new PlgElement(p);

}

Polygonline::Polygonline(string str) : Polygonline()
{
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Polygonline(convert), Objekt:" << this->getID() << endl;
	}
	istringstream ss(str);
	ss >> *this;

}

Polygonline::~Polygonline()
{
	if (debugConstructor) {
		cout << "Destruktor der Klasse Polygonline, Objekt:" << this->getID() << endl;
	}
	PlgElement* p = start;
	PlgElement* toDelete;

	while (p != nullptr)
	{
		toDelete = p;
		p = p->getNext();
		delete toDelete;
	}

}

void Polygonline::appendPolygonline(const Polygonline& pl)
{
	for (PlgElement* p = pl.start; p; p = p->getNext())
	{
		addPoint(p->getPoint());
	}
}

void Polygonline::print(bool nl) const
{
	cout << "|";

	// loop over pointer list
	for (PlgElement* p = start; p; p = p->getNext())
	{
		p->print(false);

		if (p != end)
		{
			cout << " - ";
		}
	}

	cout << "|";

	if (nl)
	{
		cout << endl;
	}
}

Polygonline& Polygonline::addPoint(Point p)
{
	PlgElement* ptr = new PlgElement(p);

	if (end != nullptr)
	{
		end->setNext(ptr);
	}
	else
	{
		start = end = ptr;
	}

	end = ptr;
	return *this;
}

void Polygonline::move(double dx, double dy)
{
	for (PlgElement* p = start; p; p = p->getNext())
	{
		p->move(dx, dy);
	}
}

string Polygonline::toString() const
{
	stringstream ss;
	ss << "|";

	for (PlgElement* p = start; p; p = p->getNext())
	{
		ss << p->getPoint().toString();
		if (p != end)
		{
			ss << " - ";
		}
	}

	ss << "|";

	return ss.str();
}

istream& operator>>(istream& is, Polygonline& pl)
{
	// | (1.1, 1.2) - (2.1, 2.2) - (3.1, 3.2) |
	char c;
	Point p;
	is >> c >> p;			// | (1.1, 1.2)
	pl.addPoint(p);

	is >> c;				// - 
	while (c == '-')
	{
		is >> p >> c;		// "(2.1, 2.2) -" und dannn "(3.1, 3.2) |"
		pl.addPoint(p);
	}
	return is;
}

ostream& operator<<(ostream& os, const Polygonline& pl)
{
	os << pl.toString();
	return os;
}

Polygonline& Polygonline::operator+(const Point& p)
{
	addPoint(p);
	return *this;
}

Polygonline& Polygonline::operator+(const Polygonline& pl)
{
	appendPolygonline(pl);
	return *this;
}