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
public:
    int getID();
    virtual void print(bool b = false) const = 0;
    void check() const;


    class GraphException {
        int id;
    public:
        GraphException(int);

    };
    class IDtooHigh:GraphException
    {
    public:
        IDtooHigh(int id) :GraphException(id){}
        const char* what() const throw () {
            return "Exception: ID too high!";
        }

    };


};

