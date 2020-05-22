#include "Polygonline.h"
#include "PlgElement.h"

Polygonline::Polygonline() {
	this->anker = nullptr;
	this->ptr = nullptr;
}

void Polygonline::addPoint(Point newPoint) {
	if (this->anker == nullptr) {
		this->anker = new Polygonline[];
	}
	else {
		this->ptr = new Polygonline[];
	}

}
