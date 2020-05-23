#include "MyString.h"
#pragma once
class Fahrzeug
{
private:
	MyString kz;
	int vin; 
	double km;

public:
	Fahrzeug(const char*);
	void fahren(double);
	friend ostream& operator<<(ostream& stream, const Fahrzeug& veh);

};

