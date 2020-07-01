// Student.hpp
#pragma once

#include "Person.h"

// Klasse Student als Spezialisierung von Person
class Student : public Person{
	// Matrikelnummer des Studenten/der Studentin
	int matNr;
public:
	// Standardkonstruktor
	Student(string name, int matNr);
	// Student auf der Konsole ausgeben
	void print() const;
};

