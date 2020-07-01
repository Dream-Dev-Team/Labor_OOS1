#pragma once
#include "ObjCounter.h"
#include <iostream>
using namespace::std;
extern bool debugConstructor;
class DrawingObject :
    public ObjCounter
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
};

