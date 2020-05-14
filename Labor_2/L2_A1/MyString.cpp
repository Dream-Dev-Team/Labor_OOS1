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


//Methoden:

void MyString::reserve(unsigned int c) {
	if (this->strCapacity < c) {
		char* copy = new char[c + 1];

		for (int i = 0; i < (int) this->strCapacity; i++) {
			copy[i] = this->strPtr[i];
		}
		delete [] this->strPtr;
		this->strPtr = copy;
		if (this->strSize != 0)
			this->strPtr[this->size()] = '\0';
		else
			this->strPtr[c] = '\0';
		this->strCapacity = c;
	}
}

MyString& MyString::append(MyString& str) {
	this->reserve(this->capacity() + str.capacity()); //reserve genügend speicher (mehr)
	
	//for return:
	MyString* cpy = new MyString;
	cpy->strPtr = new char[this->capacity()];
	strcpy(cpy->strPtr, strcat(this->strPtr, str.strPtr));
	cpy->strSize = this->size() + str.size();
	cpy->strCapacity = this->capacity();

	//for this:
	strcpy(this->strPtr, cpy->strPtr);
	this->strSize = cpy->size();
	this->strCapacity = cpy->capacity();

	return *cpy;
}

MyString& MyString::assign(MyString& str) {
	//for return:
	MyString* cpy = new MyString;
	cpy->strPtr = new char[str.capacity() + 1];
	strcpy(cpy->strPtr, str.strPtr);
	cpy->strPtr[str.size()] = '\0';
	cpy->strSize = str.size();
	cpy->strCapacity = str.capacity();

	//for this:
	//delete [] this->strPtr;				//funktioniert hier nicht???
	this->strPtr = cpy->strPtr;
	this->strSize = cpy->size();
	this->strCapacity = cpy->capacity();

	return *cpy;
}

const char* MyString::c_str() {
	return this->strPtr;
}

unsigned int MyString::size() {
	return this->strSize;
}

unsigned int MyString::capacity() {
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
