#include "Fahrzeug.h"
#include <iostream>

int vinnr = 1;

double Fahrzeug::summeKm = 0;


//Konstruktor
Fahrzeug::Fahrzeug(const char* carr) {
	this->kz = carr;
	this->vin = vinnr;
	vinnr++;
	this->km = 0;
}
Fahrzeug::~Fahrzeug() {
	summeKm += this->km;
}

//fahren
void Fahrzeug::fahren(double km) {
	this->km += km;
}

//Stream-Integration
ostream& operator<<(ostream& stream, const Fahrzeug& veh){
	stream << "Kennzeichen: " << veh.kz << "| VIN: " << veh.vin << "| km: " << veh.km << endl;
	return stream;
}

double Fahrzeug::getSummeKm() {
	return summeKm;
}
