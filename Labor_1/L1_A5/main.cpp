#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: Labor_1_Aufgabe_5
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: -
//Entwicklungsbeginn: 07.05.20		Entwicklungsende: 07.05.20 
//Zeitaufwand gesamt: 80 min
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

float trapezFlaeche(float a, float b = 0, float gamma = 90, float c = 0) {
	float flaeche;
	if (b == 0) {
		b = a;
		c = a;
	}
	else if (c == 0) {
		c = a;
	}
	gamma *= PI;
	gamma /= 180;
	flaeche = 0.5 * (a + c) * b * sin(gamma);
	return flaeche;
}

float input();
void output(float);


int main()
{
	output(input());

}

float input() {
	char modus;
	float a;
	float b;
	float c;
	float gamma;
	float flaeche=0;

	cout << "Geben Sie an, ob sie den Fl\x84 \bcheninhalt f\x81 \br ein (Q)uadrat, (R)echteck, (P)arallelogramm oder ein (T)rapez berechnen wollen. " << endl;
	cin >> modus;
	switch (modus) {
	case 'q':
	case 'Q':
		cout << "Geben Sie die Seitenl\x84 \bnge an: \n";
		cin >> a;
		flaeche = trapezFlaeche(a);
		break;
	case 'r':
	case  'R':
		cout << "Geben Sie die Seitenl\x84 \bnge 'a' an: \n";
		cin >> a;
		cout << "Geben Sie die Seitenl\x84 \bnge 'b' an: \n";
		cin >> b;
		flaeche = trapezFlaeche(a, b);
		break;
	case 'p':
	case  'P':
		cout << "Geben Sie die Seitenl\x84 \bnge 'a' an: \n";
		cin >> a;
		cout << "Geben Sie die Seitenl\x84 \bnge 'b' an: \n";
		cin >> b;
		cout << "Geben Sie den Winkel 'gamma' an: \n";
		cin >> gamma;
		flaeche = trapezFlaeche(a, b, gamma);
		break;
	case 't':
	case  'T':
		cout << "Geben Sie die Seitenl\x84 \bnge 'a' an: \n";
		cin >> a;
		cout << "Geben Sie die Seitenl\x84 \bnge 'b' an: \n";
		cin >> b;
		cout << "Geben Sie den Winkel 'gamma' an: \n";
		cin >> gamma;
		cout << "Geben Sie die Seitenl\x84 \bnge 'c' an: \n";
		cin >> c;
		flaeche = trapezFlaeche(a, b, gamma, c);
		break;
	default : 
		cerr << "\n#####\n"<<"Fehler bei der Eingabe! Geben Sie nur einen der Buchstaben Q (Quadrat), R (Rechteck), P (Parallelogramm) oder T (Trapez) ein !\n"<<"#####\n\n";
		input();
	}
	return flaeche;
}



void output(float f) {
	cout << "Der Fl\x84 \bcheninhalt des Trapez ist: " << f;
	return;
}