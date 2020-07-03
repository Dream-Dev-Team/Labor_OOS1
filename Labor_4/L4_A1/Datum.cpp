#include "Datum.h"
#include <sstream>

Datum::Datum(int t, int m, int j) : tag(t), monat(m), jahr(j){}

Datum::Datum(const string& d) {
	char trash;
	istringstream stream(d);
	stream >> this->tag >> trash >> this->monat >> trash >> this->jahr;
}

Datum::Datum(const char* d) {
	char trash;
	istringstream stream(d);
	stream >> this->tag >> trash >> this->monat >> trash >> this->jahr;
}

Datum Datum::operator+(int tage) {
	Datum d(*this);
	d.tag += tage;
	while (d.tag > 30 || d.monat > 12) {
		if (d.tag > 30) {
			d.monat++;
			d.tag -= 30;
		}
		if (d.monat > 12) {
			d.jahr++;
			d.monat -= 12;
		}
	}
	return d;
}

ostream& operator<<(ostream& os, const Datum& d) {
	os << d.tag << "." << d.monat << "." << d.jahr;
	return os;
}