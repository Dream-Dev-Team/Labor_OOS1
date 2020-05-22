#include "Spieler.h"
#include "Labyrinth.h"
#include "Position.h"

//name aus chararray
Spieler::Spieler(char* name) {
	this->name=name;
}

//name aus MyString
Spieler::Spieler(MyString name) {
	this->name = name;
}

//gibt Position zurück
Position Spieler::getPos(){
	return this->pos;
}

//setzt neue Position
void Spieler::setPos(Position& pos) {
	this->pos = pos;
}

//setzt neue Richtung
void Spieler::setRichtung(Richtung r) {
	this->pos.r = r;
}

//gibt Münzen zurück
int Spieler::getMuenzen() {
	return this->muenzen;
}

//addiert 1 Münze
void Spieler::plusMuenze() {
	this->muenzen++;
}

//ruft (Position)schritt auf + gibt neue Position zurück
Spieler & Spieler::schritt(Labyrinth & lab) {
	this->pos.schritt(lab);
	return *this;
}

// Schrittrichtung automatisch wählen lassen>>Geister
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
