#include "Student.h"
#include <iostream>

Student::Student(string name, int matNr) : Person(name, 1*30), matNr(matNr){}

void Student::print() const {
	this->Person::print();
	cout << this->matNr << endl;
}
