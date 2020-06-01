#include "MyString.h"
#pragma once
class Fahrzeug
{
private:
	MyString kz;
	int vin; 
	double km;

public:
	static double summeKm;

	Fahrzeug(const char*);
	~Fahrzeug();
	void fahren(double);
	friend ostream& operator<<(ostream& stream, const Fahrzeug& veh);
	static double getSummeKm();
};

