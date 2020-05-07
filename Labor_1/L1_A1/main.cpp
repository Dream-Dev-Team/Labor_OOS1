#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: xx.xx.xx		Entwicklungsende: xx.xx.xx
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////


int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed  Scientific " << endl;
	for (int k = 1; k < 11; k++) {
		cout << setw(3) << dec << k << " ";
		cout << setw(3) << oct << k << " ";
		cout << setw(3) << "0x" << uppercase << hex << k << " ";
		cout << setfill('+') << setw(7) << string(k % 5 + 1, '*') << " ";
		cout << setfill(' ') << showpos << setw(8) << setprecision(3) << fixed << d << " ";
		cout << noshowpos << setw(10) << uppercase << scientific << d;
		d = d * -2;
		cout << endl;
	}
	return 0;
}