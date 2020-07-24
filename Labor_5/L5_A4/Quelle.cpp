#include <iostream>
#include <sstream>
#include "Circle.hpp"
#include "Polygonline.hpp"
#include "Rectangle.h"
using namespace std;
bool debugConstructor = false;

//////////////////////////////////////////////////////
//Dateiname: L5_A4
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: 23.07.2020		Entwicklungsende: 24.07.2020
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////


int main(void)
{
	DrawingObject* objects[20];
	int anzahl = 0;
	cout << "Wieviele Objekte wollen Sie einlesen?" << endl;	//Anzahl Einage
	cout << "Anzahl: ";
	cin >> anzahl;

	for (int i = 0; i < anzahl; i++)
	{
		cout << ">>> ";
		string in;
		cin.clear();
		getline(cin, in);
		cin >> in;
		DrawingObject* d = nullptr;
		switch (in.c_str()[0])				//Obj Eingabe
		{
		case '(': {
			d = new Point(in);
			break;
		}

		case '<': {
			d = new Circle(in);
			break;
		}

		case '|': {
			d = new Polygonline(in);
			break;
		}

		case '[': {
			d = new Rectangle(in);
			break;
		}

		default:
			cout << "Error 418:	I’m a teapot - '" << in << "'" << endl;
		}
		objects[i] = d;
	}

	//Ausgabe	
	for (int i = 0; i < anzahl; i++)
	{
		if (objects[i])
			objects[i]->print(true); // einzelnes Objekt ausgeben

	}

	return 0;
}
