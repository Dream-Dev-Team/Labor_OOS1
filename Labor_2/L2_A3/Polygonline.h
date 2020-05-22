#pragma once
#include "Point.h"
#include "PlgElement.h"

class Polygonline
{
	PlgElement* ptr;
	PlgElement* anker;
public:
	Polygonline& addPoint(Point newPoint);
	void appendPolygonline(Polygonline pl);
	void move(double dx, double dy);
	void print();
	Polygonline();
	Polygonline(Point newPoint);
	Polygonline(Polygonline& pl);
	~Polygonline();
};

