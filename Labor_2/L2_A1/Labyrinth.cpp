#include "Labyrinth.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

extern int max(int, int);
extern int min(int, int);

Labyrinth::Labyrinth() {														//Std Construktor
	this->muenzen = 0;
	this->LabZeilen = kZeilen;
	this->LabSpalten = kSpalten;
	this->LabAnzGeister = kAnzGeister;
	Labyrinth::initialisieren();
}; 

void Labyrinth::initialisieren() {
	for (auto& zeile : this->lab) {												//Erstelllen des Labyrinths
		for (int i = 0; i < kSpalten + 2; ++i) {
			if (i == 11) {
				zeile[i] = '\n';
			}
			else if (i == 12) {
				zeile[i] = '\0';
			}
			else {
				zeile[i] = '#';
			}
		}
	}
};
void Labyrinth::drucken() {
	// Console frei machen
	system("cls");																	//Zeilenweise Ausgabe
	// Labyrinth ausgeben
	for (auto& i : this->lab) {
		cout << i;
	}
};
void Labyrinth::erzeugen() {

	char c = 'x';																	//Spieler an Mittelpunkt des Labyrinths
	int posx = kSpalten / 2;
	int posy = kZeilen / 2;
	this->lab[posy][posx] = 'X';
	drucken();
	while (c != 'q') {
		drucken();
		cout << "Laufen mit WASD. Beenden mit q." << endl;
		this->lab[posy][posx] = ' ';
		c = _getch();
		switch (int(c)) {
			// oben
		case 'w': posy = max(1, posy - 1); break;
			// links
		case 'a': posx = max(1, posx - 1); break;
			// rechts
		case 'd': posx = min(kSpalten - 2, posx + 1); break;								
			// unten
		case 's': posy = min(kZeilen - 2, posy + 1); break;
			// q = quit
		case 113: break;
		}
		this->lab[posy][posx] = 'X';
	}
};
unsigned int Labyrinth::getZeilen() {
	return this->LabZeilen;
};
unsigned int Labyrinth::getSpalten() {
	return this->LabSpalten;
};
unsigned int Labyrinth::getAnzGeister() {
	return this->LabAnzGeister;
};
unsigned int Labyrinth::getMuenzen() {
	return this->muenzen;
};
void Labyrinth::legeMuenzen() {
	for (int i = 0; i < kZeilen;++i) {
		for (int j = 0; j < kSpalten + 2;++j) {
			if (this->lab[i][j]==' ') {
				this->lab[i][j] =':';
				this->muenzen += 1;
			}
		}
	}
};

void Labyrinth::zeichneChar(char c, Position pos) {														//Neue Zeichen setzen
	this->lab[pos.posy][pos.posx] = c;
};

void Labyrinth::zeichneChar(char c, Position posalt, Position posneu) {									//Zeichen 'bewegen'
	this->zeichneChar(c, posneu);
	this->lab[posalt.posy][posalt.posx] = ' ';
};

char Labyrinth::getZeichenAnPos(Position pos) {
	return this->lab[pos.posy][pos.posx];
};

bool Labyrinth::istMuenzeAnPos(Position pos) {
	if (getZeichenAnPos(pos) == ':')
		return true;
};

void Labyrinth::exportDatei(const char* dateiname) {
	ofstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	} 
	for (int i = 0; i < kZeilen; i++) {
		datei << lab[i];
	}
	datei.close();
}
// Labyrinth als Textdatei einlesen
void Labyrinth::importDatei(const char* dateiname) {
	ifstream datei(dateiname);
	if (!datei) {
		cerr << "Kann Datei nicht oeffnen" << endl;
	}
	for (int i = 0; i < kZeilen; i++) {
		datei.getline(lab[i], kSpalten + 2);
		lab[i][kSpalten] = '\n';
		lab[i][kSpalten + 1] = '\0';
	}
	datei.close();
}