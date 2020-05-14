#pragma once
#include <string>
using namespace std;


class MyString
{
	char* strPtr;							//Pointer auf dynamisches char-Array
	unsigned int strSize;					//Gr��e, ohne abschlie�endes Null - Zeichen
	unsigned int strCapacity;				//Kapazit�t, ohne abschlie�endes Null - Zeichen

public:
	MyString();								//Standartkonstruktor
	~MyString();							//Destruktor
 
	MyString(string & str);					//Konvertierungskonstruktoren
	MyString(const char* str);
	MyString(const MyString& mStr);			//Kopierkonstruktor


	//Vergr��ert den Speicherplatz des dynamischen Arrays auf den �bergebenen Wert c.
	//Wenn die aktuelle Kapazit�t gr��er als der Wert c ist, wird nichts getan.
	void reserve(unsigned int c);
	//H�ngt str an das thisObjekt hinten an.
	MyString& append(MyString& str);
	//Weist den String str dem this - Objekt zu. Ein evtl.vorher vorhandener String im this - Objekt wird �berschrieben.
	MyString& assign(MyString& str);
	//Greift auf das i - te Zeichen eines Strings zur�ck und kann dieses auch ver�ndern.
	//Sollte at(i) versuchen, au�erhalb des Strings zuzugreifen, liefert at(i) das Nullzeichen
	char& at(unsigned int i);
	
	//Liefert einen Zeiger auf den im this - Objekt gespeicherten CString zur�ck.
	//�ber den Zeiger kann keine Manipulation am String vorgenommen werden.
	const char* c_str();
	//Gibt die Gr��e des MyStrings zur�ck.
	unsigned int size();
	//Gibt die Kapazit�t des MyStrings zur�ck.
	unsigned int capacity();

	//Setzt den String auf einen leeren String.
	void clear();
	//Pr�ft, ob ein String leer ist.
	//Gibt true zur�ck, falls Strings leer ist.
	bool empty();
};

