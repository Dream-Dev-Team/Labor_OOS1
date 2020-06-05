#pragma once
class Fifo
{
	int maxSize;		//max Datenelemente in Speicher
	int number;			//momentan gespeicherte Elemente
	char* ptr;			//Zeiger auf Array
	int wPos;			//Position des nächsten Schreibens
	int rPos;			//Position des nächsten Lesens

public:
	Fifo(int);
	~Fifo();

	int getWPos();
	int getRPos();
	int getNumber();
	bool isEmpty();
	bool isFull();

	int push(char input);
	char pop();
};

