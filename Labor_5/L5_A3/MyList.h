#pragma once
#include "MyListElement.h"

class MyList
{
	MyListElement* first = nullptr;
	MyListElement* last = nullptr;
public:
	MyList();
	MyList(const MyList&);
	void push_back(const MyVectorData& obj);
	void pop_back();
	MyListElement* front();
	MyListElement* back();
	void clear();
	bool empty();
	int size();
	MyList& operator=(const MyList&);
	MyList operator+(const MyList&);
	void print()const;
};

