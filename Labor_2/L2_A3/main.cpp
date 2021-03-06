//////////////////////////////////////////////////////
//Dateiname: L3_A3
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: Point.h, Ciurcle.h, Polygonline.h, PolygonElement.h
//Entwicklungsbeginn: 11.06.2020		Entwicklungsende: 18.06.2020
//Zeitaufwand gesamt: to much
//Letzte Modifikationen: 18.06.2020
//////////////////////////////////////////////////////

using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include "Point.h"
#include "Circle.h"
#include "Polygonline.h"

void* UserInput(bool);

int main(void)
{
	string str1 ("(1.1,2.1)"); 
	string str2 ("<(5.5, 6.6), 10.1>"); 
	string str3 ("|(1.1,1.2) - (2.1, 2.2) -(3.1,3.2) |"); 
	Point p (str1); 
	Circle c (str2); 
	Polygonline l (str3);

	cout << p.toString() << endl;
	cout << c.toString() << endl; 
	c.move(1.0, 2.0); 
	cout << c.toString() << endl; 
	cout << l.toString() << endl; 

	UserInput(true);
	return 0;
}

void* UserInput(bool print = false) {
	string input;
	char modus;
	cin >> input;

	modus = input[0];
	switch (modus)
	{
	case 'P':
	case 'p': {Point* returnVal = new Point(input);
		if (print)
			returnVal->print();
		return returnVal; }
		break;
	case 'C':
	case 'c': {Circle* returnVal = new Circle(input);
		if (print)
			returnVal->print();
		return returnVal;
		break; }
	case 'L':
	case 'l': {Polygonline* returnVal = new Polygonline(input);
		if (print)
			returnVal->print();
		return returnVal;
		break; }
	default:
		cout << "Error 404: Mode not found!" << endl;
		return nullptr;
		break; 
	}
}