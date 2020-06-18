#pragma once
#include "Point.h"
#include <string>

class Circle
{
	Point centre;
	double radius;

public:

	Circle();
	Circle(Point point);
	Circle(std::string);

	void setCentre(Point point);
	void setRadius(double radius);
	Point getCentre() const;
	double getRadius() const;

	void move(double dx, double dy);
	void print(bool endline = true) const;

	std::string toString() const;
};


