// Datum.hpp
#pragma once

#include <string>
using namespace std;

// Klasse Datum, �hnlich zu der in der �bung der Vorlesung
class Datum {
	// Elemente eines Datums
	int tag, monat, jahr;

public:
	// Standardkonstruktor
	Datum(int t = 0, int m = 0, int j = 0);
	// Konvertierkonstruktor f�r String
	Datum(const string&);
	// Konvertierkonstruktor f�r C-String
	Datum(const char*);
	// Operator + addiert eine Anzahl von Tagen zum Datum hinzu
	Datum operator+(int tage);
	// Ausgabeoperator <<, Ausgabe in dem Format tt.mm.jjjj
	friend ostream& operator<<(ostream&, const Datum&);
};

