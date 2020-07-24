#include <iostream>
#include "Polygonline.hpp"

//////////////////////////////////////////////////////
//Dateiname: L6_A1
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: 23.07.2020		Entwicklungsende: 24.07.2020
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

using namespace std;
bool debugConstructor = false;
int main() {
	// Punkt erstellen und Infos ausgeben
	Point p;
	cout << "maxId = " << ObjCounter::getMaxID() << endl;
	cout << "ID von p = " << p.id << endl;
	cout << " ID von p unerlaubt ändern\n";
	//*(((int*)(&p)) + 1) = ObjCounter::getMaxID() + 10;
	p.id = ObjCounter::getMaxID() + 10;
	// Punkt ausgeben
	cout << "ID von p = " << p.id << endl;
	p.check();
	p.print();
	// Polygonline erstellen und ausgeben
	Polygonline pl;
	pl.addPoint(Point(1, 1));
	pl.addPoint(Point(2, 2));
	pl.addPoint(Point(3, 3));
	pl.addPoint(Point(4, 4));
	pl.print();
	cout << " Polygonline unerlaubt ändern\n";
	//PlgElement* first = (PlgElement*)(*((int*)(&pl) + 2));
	//PlgElement* last = (PlgElement*)(*((int*)(&pl) + 3));
	//last->setNext(first);
	pl.end->setNext(pl.start);

	pl.print();
	return 0;
}
