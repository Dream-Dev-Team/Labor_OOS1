#pragma once
#include "MyVectorData.h"


class MyListElement
{
public:
	const MyVectorData* data = nullptr;
	MyListElement* next=nullptr;
	~MyListElement();
};

