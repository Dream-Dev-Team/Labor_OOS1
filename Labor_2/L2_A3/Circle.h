#pragma once
#include "Point.h"
class Circle
{
	Point centre;
	double radius;

public:

	Circle();
	Circle(Point point);

	void setCentre(Point point);
	void setRadius(double radius);
	Point getCentre() const;
	double getRadius() const;

	void move(double dx, double dy);
	void print(bool endline = true) const;

	//Fix
	stringstream& toString(stringstream& stream) const;
};


