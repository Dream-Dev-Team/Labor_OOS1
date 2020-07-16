#pragma once
class MyVectorData
{
public:
	virtual ~MyVectorData() {};
	virtual MyVectorData* clone() const = 0;
	virtual void print(bool = true) const = 0;
	virtual MyVectorData& operator=(const MyVectorData&) { return  *this; };
};

