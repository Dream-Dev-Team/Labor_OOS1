//////////////////////////////////////////////////////
//Dateiname: L3_A2
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: MyString.h
//Entwicklungsbeginn: 11.06.2020		Entwicklungsende: 18.06.2020
//Zeitaufwand gesamt: to much
//Letzte Modifikationen: 18.06.2020
//////////////////////////////////////////////////////

using namespace std;
#include <iostream>
#include "MyString.h"

using namespace std;


int main()
{
	const MyString cs("Ein konstanter String");
	MyString s(cs);
	s.assign(cs);
	s.append(cs);
	cout << cs.c_str() << endl;
	cout << cs.size() << endl;
	cout << cs.capacity() << endl;
	cout << boolalpha << cs.empty() << endl;
	s = cs + cs;
	cout << (cs == cs) << endl;
	s = cs;
	cout << cs << endl;
	s.at(1) = 'X';
	s[2] = 'Y';
	cout << s << endl;
	return 0;
}