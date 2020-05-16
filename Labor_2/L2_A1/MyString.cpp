#include "MyString.h"
#include <string.h>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;


//Konstruktoren/Destruktoren:

MyString::MyString() {
	this->strPtr = new char[1];
	this->strPtr[0] = '\0';
	this->strSize = 0;
	this->strCapacity = 0;
}

MyString::~MyString() {
	if(this->strPtr != nullptr)
		delete[] this->strPtr;
}

MyString::MyString(string & str) {
	this->strPtr = new char[str.capacity()];
	strcpy(this->strPtr, str.c_str());
	this->strPtr[str.size()] = '\0';
	this->strSize = str.size();
	this->strCapacity = str.capacity();
}

MyString::MyString(const char* str) {
	this->strPtr = new char[strlen(str) + 1];
	strcpy(this->strPtr, str);
	this->strPtr[strlen(str)] = '\0';
	this->strSize = strlen(str);
	this->strCapacity = strlen(str);
}

MyString::MyString(const MyString& mStr) {
	this->strPtr = new char[mStr.strSize + 1];
	strcpy(this->strPtr, mStr.strPtr);
	this->strPtr[mStr.strSize] = '\0';
	this->strSize = mStr.strSize;
	this->strCapacity = mStr.strCapacity;
}



//Operators:

MyString MyString::operator+(const MyString& mStr2) {
	MyString mStr1(*this);
	mStr1.append(mStr2);
	return mStr1;
}

MyString MyString::operator+(const MyString& mStr2) const{
	MyString mStr1(*this);
	mStr1.append(mStr2);
	return mStr1;
}

const MyString& MyString::operator+=(const MyString& mStr2) {
	return this->append(mStr2);
}

ostream& operator<<(ostream& stream, const MyString& mStr) {
	stream << mStr.strPtr;
	return stream;
}

const MyString& MyString::operator=(const MyString& mStr){
	if (this != &mStr) {
		this->assign(mStr);
	}
	return *this;
}

const MyString MyString::operator=(const MyString& mStr) const{
	MyString mStrNew(*this);
	if (this != &mStr) {
		mStrNew = mStr; 
	}
	return mStrNew;
}

bool operator==(MyString& mStr1, const MyString& mStr2) {
	return mStr1.equal(mStr2);
}

bool operator!=(MyString& mStr1, const MyString& mStr2) { 
	return !mStr1.equal(mStr2);
} 

char& MyString::operator[](std::size_t i) {
	return this->strPtr[i];
}

MyString::operator string() const const {
	return this->strPtr;
}

MyString::operator int() const const {
	return this->strSize;
}



//Methoden:

void MyString::reserve(unsigned int c) {
	if (this->strCapacity < c) {
		char* copy = new char[c + 1];								//kopiere alten Inhalt in ein neues dynamisches array

		for (int i = 0; i < (int) this->strCapacity; i++) {
			copy[i] = this->strPtr[i];
		}
		delete [] this->strPtr;
		this->strPtr = copy;										//zeige nach löschen des alten speichers auf den neuen (copy speicher), mit dem alten Inhalt
		if (this->strSize != 0)										//setzte end-Zeichen in char[] am ende der beschriebenen Zeichenkette (des Inhalts), wenn this->strPtr kein leeres dyn. Array 
			this->strPtr[this->size()] = '\0';
		else														//setzte end-Zeichen an der letzten speicheradresse des dyn. Arrays
			this->strPtr[c] = '\0';								
		this->strCapacity = c;
	}
}

MyString& MyString::append(const MyString& str) {
	this->reserve(this->strCapacity + str.strCapacity);				//reserviere genügend speicher (mehr)
	strcpy(this->strPtr, strcat(this->strPtr, str.strPtr));
	this->strSize = this->strSize + str.strSize;
	return *this;
}

MyString& MyString::assign(const MyString& str) {
	this->reserve(str.strCapacity);
	strcpy(this->strPtr, str.strPtr);
	this->strSize = str.strSize;
	this->strCapacity = str.strCapacity;

	return *this;
}

const char* MyString::c_str() {
	return this->strPtr;
}

const char* MyString::c_str() const{
	return this->strPtr;
}

unsigned int MyString::size() {
	return this->strSize;
}

unsigned int MyString::size() const{
	return this->strSize;
}

unsigned int MyString::capacity() {
	return this->strCapacity;
}

unsigned int MyString::capacity() const{
	return this->strCapacity;
}

//nicht schreiben wenn at() '\0' returned -> '\0' von string wird zerstört
char& MyString::at(unsigned int i) {
	if (this->strCapacity < i)
		return strPtr[this->strCapacity];
	return this->strPtr[i - 1];
}

void MyString::clear() {
	strcpy(this->strPtr, "");
	this->strSize = 0;
	this->strPtr[this->size()] = '\0';
}

bool MyString::empty() {
	if (this->size() == 0)
		return true;
	else
		return false;
}

bool MyString::empty() const{
	if (this->size() == 0)
		return true;
	else
		return false;
}

bool MyString::equal(const MyString& str) {
	if (this->strSize == str.strSize) {
		if (strcmp(this->strPtr, str.strPtr) == 0) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}



