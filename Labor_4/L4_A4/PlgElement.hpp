#pragma once
#include "Point.hpp"

class PlgElement
{
    Point point;
    PlgElement* next;

public:
    PlgElement(Point& p);

    // gibt den Punkt auf der Konsole aus
    void print(bool nl = true) const;

    // Gibt den Pointer auf das nächste Element zurück
    PlgElement* getNext() const;

    // Gibt den Pointer auf das nächste Element zurück
    const Point& getPoint() const;

    // Setzt den Pointer auf das nächste Element
    void setNext(PlgElement* p);

    // Verschiebt das Element
    void move(double dx, double dy);
};