#pragma once

class Point
{
	double x;
	double y;

public:

	Point();
	Point(double x, double y);
	
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;

	void move(double dx, double dy);
	void print(bool endline = true) const;

	//Fix
	stringstream& toString(stringstream& stream) const;
};

