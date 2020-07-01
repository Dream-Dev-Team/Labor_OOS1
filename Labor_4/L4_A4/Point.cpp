#include "Point.hpp"
#include <iostream>

using namespace std;

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
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

Point::Point(std::string str) : Point()
{
	istringstream ss(str);
	ss >> *this;
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