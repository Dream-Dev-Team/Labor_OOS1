#include "DrawingObject.h"
using namespace std;

void DrawingObject::check() const {
    try {
        if(this->id>ObjCounter::getMaxID())
        throw IDtooHigh(this->id);
    }
    catch (IDtooHigh& e) {
        cout << "\n!!!\nException caught:" << endl;
        cout << e.what() << endl;
    }

}

int DrawingObject::getID() {
    this->check();
    return this->id;
}

DrawingObject::GraphException::GraphException(int id) :id(id){
   
}