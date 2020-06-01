#include <iostream>
#include "MyString.h"

using namespace std;
//////////////////////////////////////////////////////
//Dateiname: 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: xx.xx.xx		Entwicklungsende: xx.xx.xx
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

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