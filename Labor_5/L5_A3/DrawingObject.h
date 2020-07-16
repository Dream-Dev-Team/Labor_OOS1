#pragma once
#include "ObjCounter.h"
#include <iostream>
#include "MyVectorData.h"

using namespace::std;
extern bool debugConstructor;
class DrawingObject :
    public ObjCounter, public MyVectorData
{
protected:
    DrawingObject() {
        if (debugConstructor) {
            cout << "Konstruktor der Klasse DrawingObject, Objekt:" << this->getID() << endl;
        }
    }
    ~DrawingObject() {
        if (debugConstructor) {
            cout << "Destruktor der Klasse DrawingObject, Objekt:" << this->getID() << endl;
        }
    }
public:
    virtual void print(bool = true) const = 0;
    virtual MyVectorData* clone() const = 0;
};


