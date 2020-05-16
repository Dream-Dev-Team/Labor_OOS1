// Main für Hausaufgabe 2
#include <iostream>
#include <iomanip>
#include "Labyrinth.h"
#include "MyString.h"

using namespace std;
#pragma once 

int main() {
	MyString a("Hello ");
	MyString b("World!");
	
	
	MyString c = a + b;
	
	c += b;

	int size = a;
	string str = a;

	if(a[3] == b[3])
		cout << c << a << b;

	if(a > b)

	if(a != b)

	if(a <= b)
	
		
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
}
