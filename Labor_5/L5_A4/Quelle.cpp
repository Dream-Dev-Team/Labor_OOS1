#include <iostream>
#include "Polygonline.hpp"

using namespace std;
bool debugConstructor = false;
int main() {
	// Punkt erstellen und Infos ausgeben
	const Point p;
	cout << "maxId = " << ObjCounter::getMaxID() << endl;
	cout << "ID von p = " << p.id << endl;
	// ID von p unerlaubt �ndern
	*(((int*)(&p)) + 1) = ObjCounter::getMaxID() + 10;
	// Punkt ausgeben
	cout << "ID von p = " << p.id << endl;
	p.print();
	// Polygonline erstellen und ausgeben
	Polygonline pl;
	pl.addPoint(Point(1, 1));
	pl.addPoint(Point(2, 2));
	pl.addPoint(Point(3, 3));
	pl.addPoint(Point(4, 4));
	pl.print();
	// Polygonline unerlaubt �ndern
	PlgElement* first = (PlgElement*)(*((int*)(&pl) + 2));
	PlgElement* last = (PlgElement*)(*((int*)(&pl) + 3));
	last->setNext(first);
	pl.print();
	return 0;
}
