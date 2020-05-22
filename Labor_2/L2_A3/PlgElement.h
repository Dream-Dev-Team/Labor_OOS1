#pragma once
#include "Point.h"

class PlgElement
{
	Point point;

public:
	PlgElement* next;

	PlgElement(Point newPoint) {
		this->point.setX(newPoint.getX());
		this->point.setY(newPoint.getY());
		this->next = nullptr;
	}
	PlgElement() {
		this->point.setX(0);
		this->point.setY(0);
		this->next = nullptr;
	}
	Point getPoint() {
		return this->point;
	}
	void setPoint(double x, double y) {
		this->point.setX(x);
		this->point.setY(y);
	}
};

