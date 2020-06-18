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
	friend std::ostream& operator<<(std::ostream&, const Point&);
	Point& operator+(const Point& p2);
	friend Point& operator+(double d, const Point& p2);
	Point& operator+(double d);
	Point& operator-(const Point& p2);
	Point& operator-();
	Point& operator++(); //präfix
	Point& operator++(int); //postfix
};

