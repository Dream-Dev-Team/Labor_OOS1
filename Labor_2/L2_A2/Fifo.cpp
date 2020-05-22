#include "Fifo.h"

Fifo::Fifo() {
	this->maxSize = 20;
	this->number = 0;
	this->rPos = 0;
	this->wPos = 0;
	this->loops = 0;
	this->ptr = new char[this->maxSize + 1];
	this->ptr[0] = '\0';
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

bool Fifo::isEmpty() {
	if (this->ptr[0] != '\0')
		return false;
	else
		return true;
}

bool Fifo::isFull() {
	if (this->ptr[20] != '\0')
		return false;
	else
		return true;
}

int Fifo::push(char input) {
	if (this->wPos == this->maxSize) {
		this->wPos = 0;
		this->loops++;
	}

	if (this->ptr[wPos] == '\0') {
		this->ptr[wPos] = input;
		if (this->loops == 0) {
			this->ptr[wPos + 1] = '\0'; 
		}
		this->wPos++;
		return 1;
	}
	else
		return -1;
}

char Fifo::pop() {
	char returnVal;
	
	if (this->rPos == this->maxSize)
		this->rPos = 0;

	if (this->ptr[rPos] == '\0') {
		returnVal = '\0';
	}
	else {
		returnVal = this->ptr[rPos];
		this->ptr[rPos] = '\0';
	}

	rPos++;
	return returnVal;
}
