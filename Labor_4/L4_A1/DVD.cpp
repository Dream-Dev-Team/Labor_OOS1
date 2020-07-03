#include "DVD.h"
#include <iostream>

DVD::DVD(string t, string v, int j, int d) : Medium(t, v, j, "DVD"), dauer(d){}

void DVD::print() const {
	this->Medium::print();
	cout << "Dauer: " << this->dauer << endl;
}