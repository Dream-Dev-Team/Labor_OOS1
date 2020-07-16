#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "MyVector.h"
#include "MyVectorData.h"

MyVector::MyVector()
{
	size = 0;
	capacity = 10;
	mainPtr = new MyVectorData*[capacity + 1];
	for (int i = 0; i <= capacity; ++i) {
		mainPtr[i] = nullptr;
	}
}

MyVector::MyVector(const MyVector& v)
{
	size = v.size;
	capacity = v.capacity;
	mainPtr = new MyVectorData*[capacity + 1];
	for (int i = 0; i <= capacity; ++i) {
		mainPtr[i] = v.mainPtr[i];
	}
}

// Destruktor
MyVector::~MyVector()
{
	delete[] mainPtr;
}

// Speicherplatz für String erweitern
void MyVector::reserve(unsigned int s)
{
	if (s > capacity)
	{
		MyVectorData** oldPtr = mainPtr;
		unsigned int oldCapacity = this->capacity;
		capacity = s;
		mainPtr = new MyVectorData*[capacity + 1];
		for (int i = 0; i <= s; ++i) {
			if (i <= oldCapacity)
				mainPtr[i] = oldPtr[i];
			else
				mainPtr[i] = nullptr;
		}
		delete[] oldPtr;
	}
}

// Länge des Strings zurückgeben
unsigned int MyVector::getSize() const
{
	return size;
}

// Kapazität des Strings zurückgeben
unsigned int MyVector::getCapacity() const
{
	return capacity;
}

// MyVector anhängen
MyVector& MyVector::append(const MyVector& v)
{
	int vIndex = 0;
	reserve(size + v.size);
	for (int i = 0; i <= size + v.size; ++i) {
		if (this->mainPtr[i] == nullptr && v.mainPtr[vIndex] != nullptr) {
			mainPtr[i] = v.mainPtr[vIndex];
			vIndex++;
		}
	} 
	size += v.size;
	
	return *this;
}

// MyString zuweisen
MyVector& MyVector::assign(const MyVector& v)
{
	reserve(v.size);
	for (int i = 0; i < v.size; ++i) {
		mainPtr[i] = v.mainPtr[i];
	}
	size = v.size;
	return *this;
}


// MyString leeren
void MyVector::clear()
{
	size = 0;
	for(int i = 0; i < this->size; i++)
		this->mainPtr[i] = nullptr;
}

// prüfen, ob der String leer ist
bool MyVector::empty() const
{
	return (size == 0);
}

// Zugriff auf die einzelne Zeichen des Strings
MyVectorData& MyVector::at(unsigned int i) const
{
	if (this->mainPtr[i] == nullptr || this->size < i)
		return *mainPtr[0];
	return *mainPtr[i];
}
//Kopiert Objekt an Ende der List
void MyVector::push_back(const MyVectorData& vd) {
	MyVectorData* obj = vd.clone();
	MyVector* vec = new MyVector();
	vec->size += 1;
	vec->mainPtr[0] = obj;
	this->append(*vec);
}

//PrintMethode
void MyVector::printAll()const {
	for (int i = 0; i < this->size; ++i) {
		if (this->mainPtr[i] != nullptr) {
			const MyVectorData* obj = this->mainPtr[i];
			obj->print();
		}
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