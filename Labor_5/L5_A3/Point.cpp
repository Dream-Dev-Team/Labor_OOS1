#include "Point.h"
#include "MyVectorData.h"
#include <iostream>

using namespace std;
extern bool debugConstructor;

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Point(param), Objekt:" << this->getID() << endl;
	}
}

Point::Point(std::string str) : Point()
{
	istringstream ss(str);
	ss >> *this;
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Point(convert), Objekt:" << this->getID() << endl;
	}
}

Point::~Point() {
	if (debugConstructor) {
		cout << "Destruktor der Klasse Point, Objekt:" << this->getID() << endl;
	}
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

void Point::setX(double v)
{
	x = v;
}

void Point::setY(double v)
{
	y = v;
}

void Point::move(double dx, double dy)
{
	x += dx;
	y += dy;
}

void Point::print(bool nl) const
{
	cout << "(";
	cout << x << ", " << y << ")";

	if (nl)
		cout << endl;
}

std::string Point::toString() const
{
	stringstream ss;
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}

istream& operator >> (istream& is, Point& p)
{
	char c;
	is >> c >> p.x >> c >> p.y >> c;
	return is;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << p.toString();
	return os;
}

Point Point::operator+(const Point& rhs) const
{
	return Point(x + rhs.x, y + rhs.y);
}
Point Point::operator-(const Point& rhs) const
{
	return Point(x - rhs.x, y - rhs.y);
}

Point Point::operator-() const
{
	return Point(-x, -y);
}

Point Point::operator+(double d) const
{
	return Point(x + d, y + d);
}

Point operator+(double d, const Point& p)
{
	return p + d;
}

// pre increment
Point& Point::operator++()
{
	x++;
	y++;
	return *this;
}

// post increment
Point Point::operator++(int i)
{
	Point p = *this;
	++(*this);
	return p;
}

MyVectorData* Point::clone() const {
	Point pt(this->x, this->y);
	return &pt;
}