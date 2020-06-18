#include "Circle.h"
#include "Point.h"
#include <iostream>
#include <sstream>
using namespace std;

Circle::Circle() {
	this->centre;
	this->radius = 0;
}

Circle::Circle(Point point) {
	this->centre.setX(point.getX());
	this->centre.setY(point.getY());
	this->radius = 0;
}

Circle::Circle(string s) {
	this->radius = stod(s.substr(s.find_last_of(",") + 1, s.length() - s.find_last_of(",") - 1));
	Point buffer(s);
	centre = buffer;
}

void Circle::setCentre(Point point) {
	this->centre = point;
}
void Circle::setRadius(double radius) {
	this->radius = radius;
}
Point Circle::getCentre() const {
	return this->centre;
}
double Circle::getRadius() const {
	return this->radius;
}

void Circle::move(double dx, double dy) {
	this->centre.move(dx, dy);
	// this->centre.setY(centre.getY() + dy);
}

void Circle::print(bool endline) const {
	if (endline)
		cout << "<(" << this->centre.getX() << ", " << this->centre.getY() << "), " << this->getRadius() << ">" << endl;
	else
		cout << "<(" << this->centre.getX() << ", " << this->centre.getY() << "), " << this->getRadius() << ">";

}


string Circle::toString() const {
	ostringstream stream;
	stream << "<(" << this->centre.getX() << ", " << this->centre.getY() << "), " << this->getRadius() << ">";
	return stream.str();
}
