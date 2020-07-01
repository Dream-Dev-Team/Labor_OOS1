#pragma once
#include "DrawingObject.h"
#include <iostream>
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

};

