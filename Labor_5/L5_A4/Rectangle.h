#pragma once
#include "OneDimObject.h"
#include "Point.hpp"
#include <iostream>


class Rectangle : public OneDimObject
{
	Point p1;
	Point p2;
public:
	Rectangle();
	Rectangle(Point, Point);
	Rectangle(string);

	void print(bool b=true) const;
	
};

