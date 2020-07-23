#include "Bibliothek.h"
#include <iostream>

Bibliothek::Bibliothek(int maxAnz) : maxAnz(maxAnz) {
	this->medien = new (Medium * [maxAnz]);
}

void Bibliothek::mediumBeschaffen(Medium& m) {
	this->medien[anz] = m.clone();
	this->anz++;
}

void Bibliothek::print() const {
	int i = 0;
	cout << endl;
	cout << "Bibliothekskatalog: " << endl;
	while (i < anz) {
		this->medien[i++]->print();
	}
	cout << endl;
}

void Bibliothek::mediumAusleihen(int nr, Person& p, Datum d) {
	this->medien[nr]->ausleihen(p, d, d + p.getAusleihdauer());
}

void Bibliothek::mediumSuchen(string suchwort) {
	cout << "Suche nach " << suchwort << ". Ergebnis: " << endl << endl;

	int i = 0;
	while (i < anz) {
		if (this->medien[i]->getTitel().find(suchwort) != -1) {
			cout << "Medium " << i << ": " << endl;
			this->medien[i]->print();
			cout << endl;
		}
		i++;
	}
}
