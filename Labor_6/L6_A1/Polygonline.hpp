#pragma once
#include "PlgElement.hpp"
#include "OneDimObject.h"

class Polygonline :public OneDimObject
{


public:
	PlgElement* start;
	PlgElement* end;

	// Konstruktor
	Polygonline();

	// Konvertierkonstruktor
	Polygonline(Point& p);

	// Konvertierkonstruktor
	Polygonline(string s);

	// Destruktor
	~Polygonline();

	// gibt die Elemente des Polygons auf der Konsole aus
	void print(bool nl = true) const;

	// H�ngt einen Punkt hinten an
	Polygonline& addPoint(Point p);

	// H�ngt einen zus�tzlichen Polygon hinten an
	void appendPolygonline(const Polygonline& pl);

	// Verschiebt den gesamten Polygon
	void move(double dx, double dy);

	std::string toString() const;

	friend istream& operator>>(istream& is, Polygonline& c);

	friend ostream& operator<<(ostream& os, const Polygonline& c);

	Polygonline& operator+(const Point& p);

	Polygonline& operator+(const Polygonline& pl);

	class LoopInLine :public GraphException {
	public:
		LoopInLine(int id): GraphException(id){}
		const char* what() const throw () {
			return "Exception: Loop in Line!";
		}
	};

};