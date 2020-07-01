#pragma once
class ObjCounter
{
private:
	static int maxID;
	static int number;

	 int id;
public:
	int getID();
	static int getMaxID();
	static int getNumber();
protected:
	ObjCounter();
	~ObjCounter();

};

