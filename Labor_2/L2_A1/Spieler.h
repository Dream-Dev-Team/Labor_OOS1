#pragma once
#include "MyString.h"
#include "Position.h"

class Spieler{
private:
	MyString name;
	Position pos;
	int muenzen;
public:	
	Spieler(MyString);
	Spieler(char*);
	Position getPos();
	void setPos(Position&);
	void setRichtung(Richtung);
	int getMuenzen();
	void plusMuenze();
	Spieler& schritt(Labyrinth&);
	void orientieren(Labyrinth&);


};

