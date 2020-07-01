#pragma once
#include <sstream>
#include "DrawingObject.h"

using namespace std;
class Point:public DrawingObject
{
	double x;
	double y;
public:

	Point(double x = 0.0, double y = 0.0);
	Point(string);
	~Point();
	double getX() const;
	double getY() const;

	void setX(double v);
	void setY(double v);

	// Verschiebt den Punkt um vorgegebene Koordinaten
	void move(double dx, double dy);

	// Kreisdaten auf der Konsole ausgeben
	void print(bool nl = true) const;

	string toString() const;

	friend istream& operator >> (istream& is, Point& p);
	friend ostream& operator<<(ostream& is, const Point& c);

	Point operator+(const Point& rhs) const;
	Point operator-(const Point& rhs) const;
	Point operator-() const;
	Point operator+(double d) const;
	friend Point operator+(double d, const Point& p);
	Point& operator++();
	Point operator++(int i);
};