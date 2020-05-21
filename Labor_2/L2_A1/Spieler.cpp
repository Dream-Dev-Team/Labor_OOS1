#include "Spieler.h"
#include "Labyrinth.h"
#include "Position.h"


Spieler::Spieler(char* name) {
	this->name=name;
}

Spieler::Spieler(MyString name) {
	this->name = name;
}


Position Spieler::getPos(){
	return this->pos;
}

void Spieler::setPos(Position& pos) {
	this->pos = pos;
}

void Spieler::setRichtung(Richtung r) {
	this->pos.r = r;
}

int Spieler::getMuenzen() {
	return this->muenzen;
}

void Spieler::plusMuenze() {
	this->muenzen++;
}

Spieler & Spieler::schritt(Labyrinth & lab) {
	this->pos.schritt(lab);
	return *this;
}

// Schrittrichtung automatisch wählen lassen
void Spieler::orientieren(Labyrinth & lab) {
	Position postmp = pos;
	// Eine von 4 Richtungen auswählen
	int rint = rand() % 4;
	postmp.r = Richtung(rint);
	while ((lab.getZeichenAnPos(postmp)) == '#') {
		rint = rand() % 4;
		postmp.r = Richtung(rint);
	}
	pos.r = Richtung(rint);
}
