#include <iostream>
#include "Circle.hpp"
#include "Polygonline.hpp"
using namespace std;
bool debugConstructor = false;
// Hauptprogramm
int main(void)
{
	cout << "Anzahl der Objekte: " << DrawingObject::getNumber();
	cout << endl;
	Point p1;
	cout << "p1 ObjectId: " << p1.getID() << " " << p1 << endl;
	Point p2(1, 1);
	cout << "p2 ObjectId: " << p2.getID() << " " << p2 << endl;
	Circle c1(p1, 3);
	cout << "c1 ObjectId: " << c1.getID() << " " << c1 << endl;
	Polygonline l1(p1);
	cout << "l1 ObjectId: " << l1.getID() << " " << l1 << endl;
	cout << "Anzahl der Objekte: " << c1.getNumber() << endl;
}
