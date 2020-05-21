#include "Fifo.h"

Fifo::Fifo() {
	this->maxSize = 20;
	this->number = 0;
	this->rPos = 0;
	this->wPos = 0;
	this->ptr = new char[20 + 1];
	this->ptr[0] = '/0';
}

Fifo::~Fifo() {
	delete[] this->ptr;
}

int Fifo::getRPos() {
	return this->getRPos;
}

int Fifo::getWPos() {
	return this->getWPos;
}

bool Fifo::isEmpty() {
	if (this->ptr[0] != '/0')
		return false;
	else
		return true;
}

bool Fifo::isFull() {
	if (this->ptr[20] != '/0')
		return false;
	else
		return true;
}

