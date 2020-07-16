#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "MyVector.h"
#include "MyVectorData.h"

MyVector::MyVector()
{
	strSize = 0;
	strCapacity = 10;
	strPtr = new MyVectorData*[strCapacity + 1];
	for (int i = 0; i <= strCapacity; ++i) {
		strPtr[i] = nullptr;
	}
}

MyVector::MyVector(const MyVector& str)
{
	strSize = str.strSize;
	strCapacity = str.strCapacity;
	strPtr = new MyVectorData*[strCapacity + 1];
	for (int i = 0; i <= strCapacity; ++i) {
		strPtr[i] = str.strPtr[i];
	}
}

// Destruktor
MyVector::~MyVector()
{
	delete[] strPtr;
}

// Speicherplatz für String erweitern
void MyVector::reserve(unsigned int s)
{
	if (s > strCapacity)
	{
		MyVectorData** oldPtr = strPtr;
		unsigned int oldCapacity = this->strCapacity;
		strCapacity = s;
		strPtr = new MyVectorData*[strCapacity + 1];
		for (int i = 0; i <= s; ++i) {
			if (i <= oldCapacity)
				strPtr[i] = oldPtr[i];
			else
				strPtr[i] = nullptr;
		}
		delete[] oldPtr;
	}
}

// Länge des Strings zurückgeben
unsigned int MyVector::size() const
{
	return strSize;
}

// Kapazität des Strings zurückgeben
unsigned int MyVector::capacity() const
{
	return strCapacity;
}

// MyVector anhängen
MyVector& MyVector::append(const MyVector& str)
{
	reserve(strSize + str.strSize);
	for (int i = this->strSize; i < strSize + str.strSize; ++i) {
		strPtr[i] = str.strPtr[i];
	}
	strSize += str.strSize;
	
	return *this;
}

// MyString zuweisen
MyVector& MyVector::assign(const MyVector& str)
{
	reserve(str.strSize);
	for (int i = 0; i < str.strSize; ++i) {
		strPtr[i] = str.strPtr[i];
	}
	strSize = str.strSize;
	return *this;
}


// MyString leeren
void MyVector::clear()
{
	strSize = 0;
}

// prüfen, ob der String leer ist
bool MyVector::empty() const
{
	return (strSize == 0);
}

// Zugriff auf die einzelne Zeichen des Strings
MyVectorData& MyVector::at(unsigned int i) const
{
	if (i < strSize && i >= 0)
	{
		 MyVectorData *obj = strPtr[i];
		 return *obj;
	}
	return *strPtr[0];
}
//Kopiert Objekt an Ende der List
void MyVector::push_back(const MyVectorData& d) {
	MyVectorData* obj =d.clone();
	MyVector vec;
	vec.strSize += 1;
	vec.strPtr[0] = obj;
	this->append(vec);
}

//PrintMethode
void MyVector::printAll()const {
	for (int i = 0; i <= this->strSize; ++i) {
		const MyVectorData* obj = this->strPtr[i];
		obj->print();
	}
}

/*
MyVector MyVector::operator+ (const MyVector& rhs) const
{
	MyVector tmp(*this);
	tmp.append(rhs);
	return tmp;
}

MyVector& MyVector::operator= (const MyVector& rhs)
{
	if (this != &rhs)
	{
		assign(rhs);
	}
	return *this;
}

bool MyVector::operator== (const MyVector& rhs) const
{
	if (strSize != rhs.strSize)
	{
		return false;
	}

	return strncmp(strPtr, rhs.strPtr, strSize) == 0;
}

std::ostream& operator<< (std::ostream& os, const MyVector& rhs)
{
	os << rhs.strPtr;
	return os;
}

char& MyVector::operator[](int val) const
{
	return strPtr[val];
}
*/