#include "Point.h"
#include <iostream>
#include <sstream>

using namespace std;

Point::Point() {
	this->x = 0;
	this->y = 0;
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

stringstream& Point::toString(stringstream& stream) const{
	stream << "(" << this->getX() << ", " << this->getY() << ")";
	return stream;
}