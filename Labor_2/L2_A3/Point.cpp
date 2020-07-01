#include "Point.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(string s) {
	istringstream is(s);
	is >> *this;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

void Point::setX(double x){
	this->x = x;
}
void Point::setY(double y) {
	this->y = y;
}
double Point::getX() const {
	return this->x;
}
double Point::getY() const {
	return this->y;
}

void Point::move(double dx, double dy) {
	this->x += dx;
	this->y += dy;
}

void Point::print(bool endline) const {
	if (endline)
		cout << "(" << this->getX() << ", " << this->getY() << ")" << endl;
	else
		cout << "(" << this->getX() << ", " << this->getY() << ")";

}


string Point::toString() const{
	ostringstream stream;
	stream << "(" << this->getX() << ", " << this->getY() << ")";
	return stream.str();
}


istringstream& operator>>(istringstream& stream, Point & p) {
	char dummy;

	stream >> dummy >> p.x >> dummy >> p.y >> dummy;

	/*
	string s;
	s = stream.str();
	s=s.substr(s.find("(")+1, s.find(")")-s.find("(")-1);
	p.setX(stod(s.substr(0, s.find(","))));
	s = s.substr(s.find(",") + 1, s.length() - s.find(","));
	p.setY(stod(s));*/

	return stream;
}

