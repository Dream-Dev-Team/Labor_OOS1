#include <iostream>
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: Labor_1_Aufgabe_2
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: -
//Entwicklungsbeginn: 07.05.20		Entwicklungsende: 07.05.20
//Zeitaufwand gesamt: 35  min
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

void eingabe(int[], int);
void ausgabe(int[], int);
int main()
{
	int length;
	cout << "Wie viele Zahlen m\x94 \bchten Sie einlesen?" << endl;
	cin >> length;
	int * array = new int[length];
	if (array == NULL){
		cerr << "Fehler beim Erstellen eines Arrays";
		return 1;
	}
	eingabe(array, length);
	ausgabe(array, length);
}

void eingabe(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << "Geben Sie das " << i + 1 << ". Element ein: ";
		cin >> array[i];
	}
}

void ausgabe(int array[] , int length) {
	float avg = 0;
	for (int i = 0; i < length; ++i) {
		avg += array[i];
		cout << i + 1 << ". Element des Arrays: " << array[i] << endl;
	}
	avg /= length;
	cout << "Durchschnitt aller Elemente des Arrays: " << avg;
}