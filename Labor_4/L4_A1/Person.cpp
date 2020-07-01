#include "Person.h"
#include <iostream>

Person::Person(string name, int dauer) {
	this->name = name;
	this->ausleihdauer = dauer;
}

string Person::getName() const {
	return this->name;
}

int Person::getAusleihdauer() const {
	return this->ausleihdauer;
}

void Person::print() const {
	cout << "Ausleiher: " << this->name;
}
