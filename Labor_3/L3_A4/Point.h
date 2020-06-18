#pragma once
#include <string>

class Point
{
	double x;
	double y;

public:

	Point();
	Point(double x, double y);
	Point(std::string);

	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;

	void move(double dx, double dy);
	void print(bool endline = true) const;

	std::string toString() const;

	friend void operator>>(std::istringstream&, Point&);
};

