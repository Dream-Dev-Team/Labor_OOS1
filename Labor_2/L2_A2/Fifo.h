#pragma once
class Fifo
{
	int maxSize;
	int number;
	char* ptr;
	int wPos;
	int rPos;


public:
	Fifo();
	~Fifo();

	int getWPos();
	int getRPos();
	bool isEmpty();
	bool isFull();
};

