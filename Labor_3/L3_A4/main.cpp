//////////////////////////////////////////////////////
//Dateiname: L3_A4
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: Point.h, Ciurcle.h, Polygonline.h, PolygonElement.h
//Entwicklungsbeginn: 11.06.2020		Entwicklungsende: 18.06.2020
//Zeitaufwand gesamt: to much
//Letzte Modifikationen: 18.06.2020
//////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "Circle.h"
#include "Polygonline.h"
using namespace std;

// Hauptprogramm
int main(void)
{
	Point p1(0, 0);
	const Point p2(2, 2);
	const Point p3(3, 3);
	Circle c(p1, 1.1);
	cout << "Circle c: " << c << endl;
	p1 = p1 + 0.5;
	p1 = 0.5 + p1;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	Point p4 = p1 + p2 - p3 + 4.0;
	cout << "p4: " << p4 << endl;
	p1 = -p4;
	cout << "p1: " << p1 << endl;
	cout << "p4: " << p4 << endl;
	Point p5 = p1++;
	cout << "p5: " << p5 << endl;
	cout << "p1: " << p1 << endl;
	p5 = ++++++++p1;
	cout << "p5: " << p5 << endl;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	cout << "p4: " << p4 << endl;
	Polygonline l1;
	cout << "l1: " << l1 << endl;
	(l1 + p1) + p2;
	cout << "l1: " << l1 << endl;
	const Polygonline l2(p4);
	l1 + l2;
	cout << "l1: " << l1 << endl;
	cout << "l2: " << l2 << endl;
	return 0;
}