#pragma once
class ObjCounter
{
private:
	static int maxID;
	static int number;
public:
	int id;

	int getID();
	static int getMaxID();
	static int getNumber();
protected:
	ObjCounter();
	~ObjCounter();

};

