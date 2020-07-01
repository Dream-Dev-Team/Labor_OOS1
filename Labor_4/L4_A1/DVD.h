// DVD.hpp
#pragma once

#include "Medium.h"

// Klasse für die DVDs als Spezialisierung von Medium
class DVD {
	// Abspieldauer der DVD
	const int dauer;
public:
	// Standardkonstruktor
	DVD(string t = "", string v = "", int j = 0, int d = 0);
	// die DVD auf der Konsole ausgeben
	void print() const;
};

