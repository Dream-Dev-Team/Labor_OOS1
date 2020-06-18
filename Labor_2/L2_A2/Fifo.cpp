#include "Fifo.h"

Fifo::Fifo(int size = 20) {
	this->maxSize = size;
	this->number = 0; 
	this->rPos = 0;
	this->wPos = 0;
	this->ptr = new char[this->maxSize + 1];

	for (int i = 0; i < size; i++) {
		this->ptr[i] = '\0';
	}
}

Fifo::~Fifo() {
	delete[] this->ptr;
}

int Fifo::getRPos() {
	return this->rPos;
}

int Fifo::getWPos() {
	return this->wPos;
}

int Fifo::getNumber() {
	return this->number;
}

bool Fifo::isEmpty() {
	if (this->ptr[0] != '\0')
		return false;
	else
		return true;
}

bool Fifo::isFull() {
	if (this->ptr[this->maxSize] != '\0')
		return false;
	else
		return true;
}

int Fifo::push(char input) {
	this->wPos = wPos % this->maxSize;

	if (this->ptr[wPos] == '\0') {
		this->ptr[wPos] = input;
		this->wPos++;
		this->number++;
		return this->wPos - 1;
	}
	else
		return -1;
}

char Fifo::pop() {
	char returnVal;
	this->rPos = rPos % this->maxSize;

	if (this->ptr[rPos] == '\0') {
		returnVal = '\0';
	}
	else {
		returnVal = this->ptr[rPos];
		this->ptr[rPos] = '\0';
	}

	rPos++;
	if(this->number > 0)
		this->number--;

	return returnVal;
}
