#include <iostream>
#include <cmath>
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: xx.xx.xx		Entwicklungsende: xx.xx.xx
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

float trapezFlaeche(float a, float b,  float gamma, float c);
void input();
int main()
{
	input();

}

void input() {
	char modus;
	cout << "Geben Sie an, ob sie den Fl\x84 \bcheninhalt f\x81 \br ein (Q)uadrat, (R)echteck, (P)arallelogramm oder ein (T)rapez berechnen wollen. " << endl;
	cin >> modus;
	switch (modus)
		case 'q':
		case 'Q':

}