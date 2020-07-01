#include "Circle.hpp"
extern bool debugConstructor;
Circle::Circle(Point p, double r)
{
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Circle(param), Objekt:" << this->getID() << endl;

	}
	centre = p;
	radius = r;

}

Circle::Circle(string str)
{
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Circle(convert), Objekt:" << this->getID() << endl;

	}
	radius = 0;
	istringstream ss(str);
	ss >> *this;

}

const Point& Circle::getCentre() const 
{
	return centre;
}

double Circle::getRadius() const
{
	return radius;
}

void Circle::setCentre(Point p)
{
	centre = p;
}

// setzt den Radius
void Circle::setRadius(double r)
{
	radius = r;
}

void Circle::move(double dx, double dy)
{
	centre.move(dx, dy);
}

void Circle::print(bool nl) const
{
	cout << "<";
	centre.print(false);
	cout << ", " << radius << ">";

	if (nl)
		cout << endl;
}

string Circle::toString() const
{
	stringstream ss;
	ss << "<" << centre.toString() << ", " << radius << ">";
	return ss.str();
}

istream& operator>>(istream& is, Circle& circ)
{
	char c;
	is >> c >> circ.centre >> c >> circ.radius >> c;
	return is;
}

ostream& operator<<(ostream& os, Circle& c)
{
	os << c.toString();
	return os;
}

Circle::~Circle() {


}