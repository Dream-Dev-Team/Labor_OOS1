#include "MyList.h"
#include "MyListElement.h"
#include "MyVectorData.h"
MyList::MyList(){
	
}

MyList::MyList(const MyList& l1) {
	*this = l1;
}

void MyList::push_back(const MyVectorData& obj)
{
	if (this->empty()) {
		this->first = new MyListElement;
		this->first->data = &obj;
		this->last = this->first;
		return;
	}
	this->last->next = new MyListElement;
	this->last = this->last->next;
	this->last->data = &obj;
	return;
}

void MyList::pop_back() {
	MyListElement* ptr = this->first;
	while (ptr->next != this->last)
		ptr = ptr->next;
	ptr->next = nullptr;
	delete this->last;
	this->last = ptr;

}

MyListElement* MyList::front() {
	return this->first;
}

MyListElement* MyList::back() {
	return this->last;
}

void MyList::clear() {
	MyListElement* ptr = this->first;
	while (ptr != nullptr) {
		//delete ptr->data;
		ptr->data = nullptr;
		ptr = ptr->next;
	}
	this->last = nullptr;
}

bool MyList::empty() {
	if (this->first == nullptr)
		return true;
	if ( this->first->data == nullptr)
		return true;
	return false;
}

int MyList::size() {
	int size = 0;
	for (MyListElement* ptr=this->first; ptr != nullptr; ptr = ptr->next)
		if(ptr->data!=nullptr)
			size++;
	return size;
}

MyList& MyList::operator=(const MyList& l1){
	MyList l2;
	l2.first = new MyListElement;
	MyListElement* ptr2 = l2.first;
	for (MyListElement* ptr1 = l1.first; ptr1 != l1.last; ptr1 = ptr1->next) {
		ptr2->data = ptr1->data->clone();
		ptr2->next = new MyListElement;
		ptr2 = ptr2->next;
	}
	ptr2->data = l1.last->data->clone();
	ptr2->next = nullptr;
	l2.last = ptr2;
	return l2;
}


MyList MyList::operator+(const MyList& list) {
	MyList l2 = *this; 
	MyList l3 = list;
	if (l2.last == nullptr)
		l2.last = l3.first;
	else{
		l2.last->next = l3.first;
		l2.last = l3.first;
	}
	return l2;
}

void MyList::print()const {

	for (MyListElement* ptr = this->first; ptr != nullptr; ptr = ptr->next) {
		if(ptr->data!=nullptr)
			ptr->data->print();
	}
}