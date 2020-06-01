#include "Polygonline.h"
#include "PlgElement.h"
#include <iostream>
#include <sstream>
using namespace std;

Polygonline::Polygonline() {
	this->anker = nullptr;
	this->ptr = nullptr;
}

Polygonline::Polygonline(Point newPoint) {
	this->anker = nullptr;
	this->ptr = nullptr;
	this->addPoint(newPoint);
}

Polygonline::Polygonline(Polygonline& pl){
	this->anker = nullptr;
	this->ptr = nullptr;
	pl.ptr = pl.anker;

	while (pl.ptr != nullptr) {
		Point p;
		p.setX(pl.ptr->getPoint().getX());
		p.setY(pl.ptr->getPoint().getY());

		if (this->anker == nullptr) {
			this->anker = new PlgElement(p);
			this->ptr = anker;
		}
		else
		{
			this->ptr->next = new PlgElement(p);
			this->ptr = this->ptr->next;
		}
		pl.ptr = pl.ptr->next;
	}
}

Polygonline::~Polygonline(){
}


Polygonline& Polygonline::addPoint(Point newPoint) {
	if (this->anker == nullptr) {
		this->anker = new PlgElement(newPoint);
	}
	else {
		this->ptr = anker;
		while (this->ptr->next != nullptr) {
			ptr = ptr->next;
		}
		this->ptr->next = new PlgElement(newPoint);
	}
	return *this;
}

void Polygonline::appendPolygonline(Polygonline pl) {
	Polygonline newPolyL(pl);
	this->ptr = this->anker;
	while (this->ptr->next != nullptr) {
		this->ptr = this->ptr->next;
	}
	this->ptr->next = pl.anker;
}

void Polygonline::move(double dx, double dy) {
	this->ptr = anker;
	
	while (this->ptr != nullptr) {
		this->ptr->setPoint(this->ptr->getPoint().getX() + dx, this->ptr->getPoint().getY() + dy);
		this->ptr = this->ptr->next;
	}
}

void Polygonline::print() const {
	PlgElement * cPtr = nullptr;
	cPtr = this->anker;
	cout << "|";
	while (cPtr != nullptr) {
		cout << "(" << cPtr->getPoint().getX() << ", " << cPtr->getPoint().getY() << ")";
		if (cPtr->next != nullptr)
			cout << " - ";
		cPtr = cPtr->next;
	}
	cout << "|" << endl;
}

stringstream& Polygonline::toString(stringstream& stream) const {

	PlgElement* cPtr = nullptr;
	cPtr = this->anker;
	stream << "|";
	while (cPtr != nullptr) {
		stream << "(" << cPtr->getPoint().getX() << ", " << cPtr->getPoint().getY() << ")";
		if (cPtr->next != nullptr)
			stream << " - ";
		cPtr = cPtr->next;
	}
	stream << "|";
	return stream;
}