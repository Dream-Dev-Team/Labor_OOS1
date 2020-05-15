#pragma once
#include "Position.h"

class Labyrinth
{
private:
	static const unsigned int kZeilen=11;							//
	static const unsigned int kSpalten=11;
	const unsigned int kAnzGeister = 3;

	unsigned int LabZeilen;
	unsigned int LabSpalten;
	unsigned int LabAnzGeister;
	unsigned int muenzen;
	char lab[kZeilen][kSpalten+2];

public:
	Labyrinth();
	void initialisieren();
	void drucken();
	void erzeugen();
	unsigned int getZeilen();
	unsigned int getSpalten();
	unsigned int getAnzGeister();
	unsigned int getMuenzen();
	void legeMuenzen();
	void zeichneChar(char, Position);
	void zeichneChar(char, Position, Position);
	char getZeichenAnPos(Position);
	bool istMuenzeAnPos(Position);
	void exportDatei(const char*);
	void importDatei(const char*);
};

