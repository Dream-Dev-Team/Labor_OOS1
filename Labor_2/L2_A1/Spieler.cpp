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

//gibt Position zur�ck
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

//gibt M�nzen zur�ck
int Spieler::getMuenzen() {
	return this->muenzen;
}

//addiert 1 M�nze
void Spieler::plusMuenze() {
	this->muenzen++;
}

//ruft (Position)schritt auf + gibt neue Position zur�ck
Spieler & Spieler::schritt(Labyrinth & lab) {
	this->pos.schritt(lab);
	return *this;
}

// Schrittrichtung automatisch w�hlen lassen>>Geister
void Spieler::orientieren(Labyrinth & lab) {
	Position postmp = pos;
	// Eine von 4 Richtungen ausw�hlen
	int rint = rand() % 4;
	postmp.r = Richtung(rint);
	while ((lab.getZeichenAnPos(postmp)) == '#') {
		rint = rand() % 4;
		postmp.r = Richtung(rint);
	}
	pos.r = Richtung(rint);
}
