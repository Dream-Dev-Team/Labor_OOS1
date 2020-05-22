#include "PacMan.h"
#include "Labyrinth.h"
//////////////////////////////////////////////////////
//Dateiname: Labor2_Aufgabe1
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: Labyrinth.h, MyString.h, PacMan.h, Position.h, Spieler.h
//Entwicklungsbeginn: 21.05.20		Entwicklungsende: 22.05.20
//Zeitaufwand gesamt: 3h
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

const bool kErzeugen = false;

int main() {
	Labyrinth lab;
	if (kErzeugen) {
		lab.erzeugen();
		lab.exportDatei("lab.txt");
	}
	else {
		lab.importDatei("lab.txt");
		lab.legeMuenzen();
		Spieler s("Demo");
		Spieler g[kAnzGeister] = { Spieler("Geist 1"),
								   Spieler("Geist 2"),
								   Spieler("Geist 3") };
		PacMan pm(lab, s, g, kAnzGeister);
		pm.spielen();
	}
}


