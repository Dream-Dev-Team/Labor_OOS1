#include "Circle.h"
#include <iostream>
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

void Circle::setCentre(Point point) {
	this->centre = point;
}
void Circle::setRadius(double radius) {
	this->radius = radius;
}
Point Circle::getCentre() {
	return this->centre;
}
double Circle::getRadius() {
	return this->radius;
}

void Circle::move(double dx, double dy) {
	this->centre.setX(centre.getX() + dx);
	this->centre.setY(centre.getY() + dy);
}

void Circle::print(bool endline) {
	if (endline)
		cout << "<(" << this->centre.getX() << ", " << this->centre.getY() << "), " << this->getRadius() << ">" << endl;
	else
		cout << "<(" << this->centre.getX() << ", " << this->centre.getY() << "), " << this->getRadius() << ">";
	
}