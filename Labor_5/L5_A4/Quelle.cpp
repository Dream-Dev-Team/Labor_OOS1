#include <iostream>
#include "Circle.hpp"
#include "Rectangle.h"
#include "Polygonline.hpp"
using namespace std;
bool debugConstructor = false;
int main()
{
	DrawingObject* objects[20];
	int anzahl = 0;
	string input;
	cout << "Wieviele Objekte wollen Sie einlesen?" << endl;
	cout << "Anzahl: ";
	cin >> anzahl;
	// Objekte einlesen
	cout << "Geben Sie nacheinander alle Objekte ein: \n";
		for (int i = 0; i < anzahl; i++)
		{
			// einzelnes Objekt einlesen
			cin >> input;
			switch (input[0]) {
			case '(':
				objects[i] = new Point(input);
				break;
			case'<':
				objects[i] = new Circle(input);
				break;
			case '[':
				objects[i] = new Rectangle(input);
				break;
			case '|':
				objects[i] = new Polygonline(input);
				break;
			}
				
		}
	// Objekte ausgeben
	for (int i = 0; i < anzahl; i++)
	{
		// einzelnes Objekt ausgeben
		cout << "Object " << i+1 << "(ID)" << objects[i]->getID() << "\t";
		objects[i]->print(true);
	}
	return 0;
}
