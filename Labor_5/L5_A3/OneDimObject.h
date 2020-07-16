#pragma once
#include "DrawingObject.h"
#include <iostream>
#include "MyVectorData.h"

using namespace::std;

extern bool debugConstructor;
class OneDimObject :
    public DrawingObject
{
protected:
    OneDimObject() {
        if (debugConstructor) {
            cout << "Konstruktor der Klasse OneDimObject, Objekt:" << this->getID() << endl;
        }
    }
    ~OneDimObject() {
        if (debugConstructor) {
            cout << "Destruktor der Klasse OneDimObject, Objekt:" << this->getID() << endl;
        }
    }
public:
    virtual void print(bool = true) const = 0;
    virtual MyVectorData* clone() const = 0;
};

