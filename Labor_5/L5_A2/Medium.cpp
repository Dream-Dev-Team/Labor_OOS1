#include "Medium.h"
#include <iostream>

Medium::Medium(string t, string v, int j) : titel(t), verlag(v), jahr(j) {}

string Medium::getTitel() const {
	return this->titel;
}

Person* Medium::getAusleiher() const {
	return this->ausleiher;
}

void Medium::ausleihen(Person& p, Datum von, Datum bis) {
	this->ausleiher = &p;
	this->von = von;
	this->bis = bis;
}

void Medium::print() const {
	cout << "-----------------------------------------" << endl;
	//cout << this->typ << endl;
	cout << "Titel: " << this->titel << endl;
	cout << "Verlag: " << this->verlag << endl;
	cout << "Jahr: " << this->jahr << endl;
	if (this->ausleiher != nullptr) {
		this->ausleiher->print();
		cout << " von: " << this->von << " bis: " << this->bis << endl;
	}
	else
		cout << "Ausleiher: kein" << endl;
}
