#include "ObjCounter.h"
#include <iostream>
using namespace::std;

//ObjectCounter-Variablen initialisieren
int ObjCounter::maxID = 0;
int ObjCounter::number = 0;
extern bool debugConstructor;


ObjCounter::ObjCounter() {
	maxID++;
	id = maxID;
	number++;
	if (debugConstructor) {
		cout << "Konstruktor der Klasse ObjCounter, Objekt:" << this->getID() << endl;
	}

}

ObjCounter::~ObjCounter() {
	maxID--;
	number--;
	if (debugConstructor) {
		cout << "Destruktor der Klasse ObjCounter, Objekt:" << this->getID() << endl;
	}
}

int ObjCounter::getID() {
	return this->id;
}

int ObjCounter::getMaxID() {
	return maxID;
}

int ObjCounter::getNumber() {
	return number;
}