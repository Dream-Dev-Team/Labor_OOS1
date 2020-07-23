// Dozent.hpp
#pragma once

#include "Person.h"

// Klasse Dozent als Spezialisierung von Person
class Dozent : public Person {
	// Prüfernummer des Dozenten
	int prfrNr;
public:
	// Standardkosntruktor
	Dozent(string name, int prfrNr);
	// Dozenten auf der Konsole ausgeben
	void print() const;
};

