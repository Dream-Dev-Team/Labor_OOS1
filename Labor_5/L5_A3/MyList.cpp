#include "MyList.h"
#include "MyListElement.h"
#include "MyVectorData.h"
#include <iostream>

MyList::MyList(){
	
}

MyList::MyList(const MyList& l1) {
	this->first = new MyListElement();
	this->first->data = l1.first->data->clone();

	MyListElement* ptr = l1.first;
	MyListElement* thisPtr = this->first;

	while (ptr->next != nullptr) {
		thisPtr->next = new MyListElement();
		thisPtr->next->data = ptr->data->clone();

		ptr = ptr->next;
		thisPtr = thisPtr->next;
	}
	this->last = thisPtr;
	this->last->data = ptr->data->clone();
}

void MyList::push_back(const MyVectorData& obj)
{
	if (this->empty()) {
		std::cout << "EMPTY";
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
	//delete this->last;
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
	this->first = nullptr;
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

MyList& MyList::operator=(const MyList& l2){
	if (this != &l2) {
		MyList* newList = new MyList(l2);
		MyListElement* ptr = newList->first;
		MyListElement* thisPtr = new MyListElement();
		thisPtr->data = newList->first->data->clone();
		this->first = thisPtr;

		while (ptr->next != nullptr) {
			thisPtr->next = new MyListElement();
			thisPtr->next->data = ptr->data->clone();

			ptr = ptr->next;
			thisPtr = thisPtr->next;
		}
		this->last = thisPtr;
		this->last->data = ptr->data->clone();
	}
	return *this;
}


MyList MyList::operator+(const MyList& list2) {
	MyList l1(*this); 
	MyList l2(list2);
	if (l1.empty()) {
		return l2;
	}
	else if (l2.empty()) {
		return l1;
	}
	else{
		l1.last->next = l2.first;
		l1.last = l2.last;
	}
	return l1;
}

void MyList::print()const {

	for (MyListElement* ptr = this->first; ptr != nullptr; ptr = ptr->next) {
		if(ptr->data!=nullptr)
			ptr->data->print();
	}
}