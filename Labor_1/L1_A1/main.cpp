#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: Labor1_Aufgabe1 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: 07.05.2020		Entwicklungsende: 07.05.2020
//Zeitaufwand gesamt: 20min  
//Letzte Modifikationen: 
//////////////////////////////////////////////////////


int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed  Scientific " << endl;
	for (int k = 1; k < 11; k++) {
		cout << setw(3) << dec << k << " ";
		cout << setw(3) << oct << k << " ";
		cout << setw(3) << "0x" << uppercase << hex << k << " ";						//hex liefert ausgabe ohne den 0x Teil aus der Aufgabenstellung
		cout << setfill('+') << setw(7) << string(k % 5 + 1, '*') << " ";
		cout << setfill(' ') << showpos << setw(8) << setprecision(3) << fixed << d << " ";		//setfill zurücksetzen auf space
		cout << noshowpos << setw(10) << uppercase << scientific << d;
		d = d * -2;
		cout << endl;
	}
	return 0;
}