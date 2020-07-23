#include "Rectangle.h"
extern bool debuConstructor;

Rectangle::Rectangle() {
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Rectangle(default), Objekt:" << this->getID() << endl;

	}
	this->p1 = *new Point(0, 0);
	this->p2 = *new Point(1, 1);
}

Rectangle::Rectangle(Point p1, Point p2) {
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Rectangle(param), Objekt:" << this->getID() << endl;

	}
	this->p1 = p1;
	this->p2 = p2;
}

Rectangle::Rectangle(string s) {
	if (debugConstructor) {
		cout << "Konstruktor der Klasse Rectangle(convert), Objekt:" << this->getID() << endl;

	}
	istringstream ss(s);
	char c;
	Point np1;
	Point np2;
	ss >> c >> np1 >> c >> np2;
	this->p1 = np1;
	this->p2 = np2;


}

void Rectangle::print(bool b) const {
	cout << "[ ";
	p1.print(false);
	cout << ", ";
	p2.print(false);
	cout << " ]";
	if (b)
		cout << endl;
}