//////////////////////////////////////////////////////
//Dateiname: L3_A1
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: MyString.h, Fahrzeug.h
//Entwicklungsbeginn: 11.06.2020		Entwicklungsende: 18.06.2020
//Zeitaufwand gesamt: to much
//Letzte Modifikationen: 18.06.2020
//////////////////////////////////////////////////////

#include "Fahrzeug.h"
#include <iostream>
using namespace std;


int main() {

	{
		Fahrzeug f1("ES - H 123");
		cout << f1 << endl;
		f1.fahren(101.5);
		cout << f1 << endl;
		Fahrzeug f2("ES - M 4711");
		f2.fahren(10.57);
		cout << f2 << endl;
	}

	cout << Fahrzeug::getSummeKm();

	return 0;
}
