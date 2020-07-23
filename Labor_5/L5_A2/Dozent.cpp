#include "Dozent.h"
#include <iostream>

Dozent::Dozent(string name, int prfrNr) : Person(name, 3 * 30), prfrNr(prfrNr) {}

void Dozent::print() const {
	this->Person::print();
	cout << this->prfrNr << endl;
}