#include <iostream>
#include "Fifo.h"
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: xx.xx.xx		Entwicklungsende: xx.xx.xx
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

int main()
{
	Fifo fif(5);

	fif.push('A');
	fif.push('B');
	fif.push(' ');
	fif.push('D');
	fif.push('E');

	fif.push('F');
	cout << "Number of Elements: " << fif.getNumber() << endl;
	fif.push('G');
	fif.push('H');
	fif.push('I');
	fif.push('J');

	fif.push('K');
	cout << "Number of Elements: " << fif.getNumber() << endl;
	fif.push('L');
	fif.push('M');
	fif.push('N');
	fif.push('O');

	fif.push('S');
	fif.push('T');
	fif.push('P');
	fif.push('Q');
	fif.push('R');

	fif.push('#');
	fif.push('#');

	for (int i = 0; i < 10; i++) {
		cout << fif.getRPos() << " : " << fif.pop() << endl;
	}
	fif.push('U');
	fif.push('V');
	cout << "Number of Elements: " << fif.getNumber() << endl;
	for (int i = 0; i < 10; i++) {
		cout << fif.getRPos() << " : " << fif.pop() << endl;
	}
}