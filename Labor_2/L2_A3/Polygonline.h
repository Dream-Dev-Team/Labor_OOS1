#pragma once
#include "Point.h"

class Polygonline
{
	PlgElement* ptr;
	PlgElement* anker;
public:
	void addPoint(Point newPoint);
	Polygonline();
};

