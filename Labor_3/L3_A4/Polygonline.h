#pragma once
#include "Point.h"
#include "PlgElement.h"
#include <string>


class Polygonline
{
	PlgElement* ptr;
	PlgElement* anker;
public:
	Polygonline& addPoint(Point newPoint);
	void appendPolygonline(Polygonline& pl);
	void move(double dx, double dy);
	void print() const;

	std::string toString() const;

	Polygonline();
	Polygonline(std::string);
	Polygonline(Point newPoint);
	Polygonline(Polygonline& pl);
	~Polygonline();
};
