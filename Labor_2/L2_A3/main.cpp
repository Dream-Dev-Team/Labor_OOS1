#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Point.h"
#include "Circle.h"
#include "Polygonline.h"
//////////////////////////////////////////////////////
//Dateiname: 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: xx.xx.xx		Entwicklungsende: xx.xx.xx
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

int main(void)
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.setX(1.1);
	p.setY(2.2);
	c.setCentre(p);
	c.setRadius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.getX() << ", " << p.getY() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();


	cout << endl << endl << endl;

	Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
	Polygonline l1;
	Polygonline l2(p3);
	cout << "Ausgabe 1:" << endl;
	l1.print();
	l2.print();
	l1.addPoint(p1).addPoint(p2);
	l2.addPoint(p4).addPoint(p5);
	cout << "Ausgabe 2:" << endl;
	l1.print();
	l2.print();
	p2.move(0.5, 0.5);
	cout << "Ausgabe 3:" << endl;
	p2.print();
	l1.print();
	l2.print();
	l1.appendPolygonline(l2);
	cout << "Ausgabe 4:" << endl;
	l1.print();
	l2.print();
	l1.move(0, 0.5);
	cout << "Ausgabe 5:" << endl;
	l1.print();
	l2.print();

	cout << "\nAufgabe 3" << endl;
	string arg = " (1.1, 2.2) ist ein Punkt.";
	istringstream is(arg);
	is >> p;
	cout << "Punkt nach istringstream input: " << p.toString()<<endl;
	Point cop("1.3, 2.5");
	cout << "Neuer Punkt mit string initialisiert: " << cop.toString() << endl;
	arg = "<(50.5, 6.06), 100.1>";
	Circle coc(arg);
	cout << "Neuer Circle mit string initialisiert: " << coc.toString() << endl;
	arg="|(1.1,1.2) - (2.1, 2.2) -(3.1,3.2) |";
	Polygonline loc(arg);
	cout << "Neue Poligonline mit string initialisiert: " << loc.toString() << endl;

	return 0;
}