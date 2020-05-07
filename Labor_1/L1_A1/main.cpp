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
		cout << dec << k << " ";
		cout << oct << k << " ";
		cout << "0x" << uppercase << hex << k;
		cout << setfill('*') << string(k % 5 + 1, '*') << " ";
		cout << setprecision(3) << fixed << d << " ";
		cout << uppercase << scientific << d;
		d = d * -2;
		cout << endl;
	}
	return 0;
}