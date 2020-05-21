#pragma once
class Point
{
	double x;
	double y;

public:

	Point();
	
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();

	void move(double dx, double dy);
	void print(bool endline = true);
};

