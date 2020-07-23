#include "Buch.h"
#include <iostream>

Buch::Buch(string t, string a, string v, int jahr) : Medium(t, v, jahr), autor(a) {
}

void Buch::print() const {
	this->Medium::print();
	cout << "Autor: " << this->autor << endl;
}

Buch* const Buch::clone() const {
	return new Buch(*this);
}