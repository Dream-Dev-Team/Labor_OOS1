#pragma once
#include "Point.hpp"
#include "DrawingObject.h"

class PlgElement :DrawingObject
{
    Point point;
    PlgElement* next;

public:
    PlgElement(Point& p);
    ~PlgElement();

    // gibt den Punkt auf der Konsole aus
    void print(bool nl = true) const;

    // Gibt den Pointer auf das n�chste Element zur�ck
    PlgElement* getNext() const;

    // Gibt den Pointer auf das n�chste Element zur�ck
    const Point& getPoint() const;

    // Setzt den Pointer auf das n�chste Element
    void setNext(PlgElement* p);

    // Verschiebt das Element
    void move(double dx, double dy);
};