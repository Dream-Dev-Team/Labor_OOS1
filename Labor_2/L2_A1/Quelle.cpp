// Main für Hausaufgabe 2
#include <iostream>
#include <iomanip>
#include "Labyrinth.h"
#include "MyString.h"

using namespace std;
#pragma once 

int main() {
	const MyString cs("Ein konstanter String");
	MyString s(cs);
	s.assign(cs);
	s.append(cs);
	cout << cs.c_str() << endl;
	cout << cs.size() << endl;
	cout << cs.capacity() << endl;
	cout << boolalpha << cs.empty() << endl;
	s = cs + cs;
	cout << (cs == cs) << endl;
	s = cs;
	cout << cs << endl;
	s.at(1) = 'X';				//Es muss noch at()/[] angepasst werden das const MyString an diesen Stellen nicht geändert werden kann.
	s[2] = 'Y';					//
	cout << s << endl;
	return 0;
}
		
	//...

	/*
	Labyrinth lab;
	lab.drucken();
	lab.erzeugen();
	lab.drucken();
	lab.exportDatei("lab.txt");						
	Labyrinth lab2;
	lab2.importDatei("lab.txt");
	lab2.drucken();
	lab2.legeMuenzen();
	lab2.drucken();
	//lab2.erzeugen();									//2zeilen test
	//lab2.drucken();

	*/
