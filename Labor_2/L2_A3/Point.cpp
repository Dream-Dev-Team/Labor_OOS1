#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {
	this->x = 0;
	this->y = 0;
}

void Point::setX(double x){
	this->x = x;
}
void Point::setY(double y) {
	this->y = y;
}
double Point::getX() {
	return this->x;
}
double Point::getY() {
	return this->y;
}

void Point::move(double dx, double dy) {
	this->x += dx;
	this->y += dy;
}

void Point::print(bool endline) {
	if (endline)
		cout << "(" << this->getX() << ", " << this->getY() << ")" << endl;
	else
		cout << "(" << this->getX() << ", " << this->getY() << ")";

}
