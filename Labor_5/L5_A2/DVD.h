// DVD.hpp
#pragma once

#include "Medium.h"

// Klasse f�r die DVDs als Spezialisierung von Medium
class DVD : public Medium {
	// Abspieldauer der DVD
	const int dauer;
public:
	// Standardkonstruktor
	DVD(string t = "", string v = "", int j = 0, int d = 0);
	// die DVD auf der Konsole ausgeben
	void print() const;
	// DVD klonen
	DVD* const clone() const override;
};

