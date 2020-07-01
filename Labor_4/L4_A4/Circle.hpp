#pragma once

#include "Point.hpp"
#include <iostream>

using namespace std;

class Circle
{
	Point centre;
	double radius;

public:
	// Konstruktor
	Circle(Point p = Point(0.0, 0.0), double r = 1.0);
	
	Circle(string s);

	// liefert den Kreismittelpunkt zurück
	const Point& getCentre() const;
	
	// Gibt Radius zurück
	double getRadius() const;

	// setzt den Kreismittelpunkt
	void setCentre(Point p);

	// setzt den Radius
	void setRadius(double r);
	
	// Verschiebt den Kreismittelpunkt um vorgegebene Koordinaten
	void move(double dx, double dy);

	// Kreisdaten auf der Konsole ausgeben
	void print(bool nl = true) const;

	string toString() const;

	friend istream& operator>>(istream& is, Circle& c);

	friend ostream& operator<<(ostream& is, Circle& c);
};