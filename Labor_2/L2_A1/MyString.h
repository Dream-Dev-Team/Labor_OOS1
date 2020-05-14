#pragma once
#include <string>
using namespace std;


class MyString
{
	char* strPtr;							//Pointer auf dynamisches char-Array
	unsigned int strSize;					//Größe, ohne abschließendes Null - Zeichen
	unsigned int strCapacity;				//Kapazität, ohne abschließendes Null - Zeichen

public:
	MyString();								//Standartkonstruktor
	~MyString();							//Destruktor
 
	MyString(string & str);					//Konvertierungskonstruktoren
	MyString(const char* str);
	MyString(const MyString& mStr);			//Kopierkonstruktor


	//Vergrößert den Speicherplatz des dynamischen Arrays auf den übergebenen Wert c.
	//Wenn die aktuelle Kapazität größer als der Wert c ist, wird nichts getan.
	void reserve(unsigned int c);
	//Hängt str an das thisObjekt hinten an.
	MyString& append(MyString& str);
	//Weist den String str dem this - Objekt zu. Ein evtl.vorher vorhandener String im this - Objekt wird überschrieben.
	MyString& assign(MyString& str);
	//Greift auf das i - te Zeichen eines Strings zurück und kann dieses auch verändern.
	//Sollte at(i) versuchen, außerhalb des Strings zuzugreifen, liefert at(i) das Nullzeichen
	char& at(unsigned int i);
	
	//Liefert einen Zeiger auf den im this - Objekt gespeicherten CString zurück.
	//Über den Zeiger kann keine Manipulation am String vorgenommen werden.
	const char* c_str();
	//Gibt die Größe des MyStrings zurück.
	unsigned int size();
	//Gibt die Kapazität des MyStrings zurück.
	unsigned int capacity();

	//Setzt den String auf einen leeren String.
	void clear();
	//Prüft, ob ein String leer ist.
	//Gibt true zurück, falls Strings leer ist.
	bool empty();
};

