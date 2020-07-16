#pragma once

#include <iostream>
#include "MyVectorData.h"

class MyVector
{
private:
	MyVectorData** strPtr;
	unsigned int strSize = 0;
	unsigned int strCapacity = 0;

public:
	// Standardkonstruktor
	MyVector();
	// Kopierkonstruktor (tiefe Kopie)
	MyVector(const MyVector&);
	// Destruktor
	~MyVector();
	// Speicherplatz für String erweitern
	void reserve(unsigned int);
	// MyString zuweisen
	MyVector& assign(const MyVector&);
	// MyString anhängen	
	MyVector& append(const MyVector&);
	// MyString zuweisen
	
	unsigned int size() const;
	// Kapazität des Strings zurückgeben
	unsigned int capacity() const;
	// MyString leeren, d.h. auf leeren String setzen
	void clear();
	// prüfen, ob der String leer ist
	bool empty() const;
	// Zugriff auf die einzelne Zeichen des Strings
	MyVectorData& at(unsigned int) const;
	//Objekt an Ende der Liste kopieren
	void push_back(const MyVectorData& d);
	//Objekt clonen
	MyVectorData* clone() const;
	void printAll()const;
	
	/*// HA3:
	// MyStrings anhängen
	MyVector operator+ (const MyVector& rhs) const;

	// MyString vergleichen
	bool operator==(const MyVector& rhs) const;

	// Ausgabeoperator, MyString ins cout ausgeben
	friend std::ostream& operator<< (std::ostream& os, const MyVector& rhs);

	// Zuweisungsoperator
	MyVector& operator= (const MyVector& rhs);

	// Zugriffsoperator
	char& operator[](int val) const;*/
};