#include <iostream>
#include <conio.h> // für _getch()
// Achtung: _getch() ist nicht im Standard und 
//          daher abhängig vom Compiler
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: Labor_1_Aufgabe_3
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: -
//Entwicklungsbeginn: 07.05.20		Entwicklungsende: 07.05.20
//Zeitaufwand gesamt: 30 min
//Letzte Modifikationen: 
//////////////////////////////////////////////////////


// Größe des Labyrinths
const int kZeilen = 11;
const int kSpalten = 11;

// Zeichen, die im Labyrinth vorkommen können,
// NL = new line, EOS = end of string
enum Symbole {
	MAUER = '#', WEG = ' ', MUENZE = ':', NL = '\n',
	EOS = '\0', ICH = 'X', GEIST = 'G'
};

// Das Labyrinth als char-Array
// Die vorletzte Spalte speichert ein Zeilenendezeichen \n
// und die letzte ein \0-Zeichen, damit die Ausgabe leichter wird.
char labyrinth[kZeilen][kSpalten + 2];

// Labyrinth mit # füllen
void initialisieren() {
	
	
	for (int i = 0; i < kZeilen; ++i) {												//Erstelllen des Labyrinths
		for (int j = 0; j < kSpalten+2; ++j) {
			if (j == 11) {
				labyrinth[i][j] = '\n';
			}
			else if (j == 12) {
				labyrinth[i][j] = '\0';
			}
			else {
				labyrinth[i][j] = '#';
			}
		}
	}
}

// Labyrinth auf dem Bildschirm ausgeben
void drucken() {
	// Console frei machen
	system("cls");																	//Zeilenweise Ausgabe
	// Labyrinth ausgeben
	for (int i = 0; i < kZeilen;++i) {
		cout << labyrinth[i];
	}
}

// Hilfsfunktion max
int max(int x, int y) {
	return (x <= y) ? y : x;
}

// Hilfsfunktion min
int min(int x, int y) {
	return (x <= y) ? x : y;
}

// Durch Herumlaufen werden Wege im Labyrinth erzeugt
// ASCII-Wert der Tasten: oben 72, links 75, rechts 77, unten 80
void erzeugen() {
	char c = 'x';
	int posx = kSpalten / 2;
	int posy = kZeilen / 2;
	labyrinth[posy][posx] = ICH;
	drucken();
	while (c != 'q') {
		drucken();
		cout << "Laufen mit Pfeiltasten. Beenden mit q." << endl;
		labyrinth[posy][posx] = WEG;
		c = _getch();
		switch (int(c)) {
			// oben
		case 72: posy = max(1, posy - 1); break;
			// links
		case 75: posx = max(1, posx - 1); break;
			// rechts
		case 77: posx = min(kSpalten - 2, posx + 1); break;
			// unten
		case 80: posy = min(kZeilen - 2, posy + 1); break;
			// q = quit
		case 113: break;
		}
		labyrinth[posy][posx] = ICH;
	}
}

int main() {
	initialisieren();
	drucken();
	erzeugen();
}