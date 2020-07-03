#include <iostream>
#include <string>
using namespace std;
// Name s und Wert val einer Instanzvariable ausgeben
void speicherzelle(string s, int val) {
	cout << "---------------------" << endl;
	cout << s << "= " << val << endl;
}
// Die Instanzvariablen raussuchen und ausgeben,
// die wegen virtuellen Basisklassen zusammenfallen
void suche(string s[], int* vptr[], int n) {
	// Zustand von cout zwischenspeichern
	ios::fmtflags cflags = cout.flags();
	// Hilfsvariablen initialisieren
	int i = 0;
	int k = 0;
	string str = "";
	// cout für Ausgabe der Instanzvariablen konfigurieren
	cout << hex << uppercase;
	// Schauen, ob Instanzvariable i (vptr[i])
	// evtl. mit Variable k (vptr[k]) zusammenfällt
	while (i < n) {
		// Wenn Variable i+k und i+k+1 identisch ...
		if ((i + k < n - 1) && (vptr[i + k] == vptr[i + k + 1])) {
			// erhöhe k
			k++;
		}
		else {
			// andernfalls gib die zusammengefallenen Variablen
			// auf einer Zeile aus
			// Text für Ausgabe zusammenstellen
			for (int m = i; m <= i + k; m++) {
				str += s[m] + " ";
			}
			// Text und Wert ausgeben
			speicherzelle(str, *vptr[i]);
			// Hilfsvariablen für nächste Prüfung zurücksetzen
			str = "";
			i += k + 1;
			k = 0;
		}
	}
	cout << "---------------------" << endl << endl;
	// Ursprünglicher Zustand von cout wieder herstellen
	cout.flags(cflags);
}

// Klassenhierarchie
class A {
public:
	int a;
	A(int a = 0xA) : a(a) {
		//cout << "a: " << a <<hex<< endl;
		
	}
};
class B : virtual public A {
public:
	int b;
	B(int a = 0xBA, int b = 0xD2B) : A(a), b(b) {
		//cout << "b: " << a <<hex<< endl;
		//cout << "b: " << b << hex << endl;
	}
};
/*class B2 : virtual public A {
public:
	int b;
	B2(int a = 0xBA, int b = 0xB) : A(a), b(b) {
		//cout << "b: " << a << hex << endl;
		//cout << "b: " << b << hex << endl;
	}
};*/
class C1 : virtual public B {
public:
	C1(int a = 0xC1A, int b = 0xC1B)
		: B(a, b) {
		//cout << "c1: " << a <<hex<< endl;
		//cout << "c1: " << b << hex << endl;
	}
};
class C2 : virtual public B {
public:
	C2(int a = 0xC2A, int b = 0xC2B)
		: B(a, b) {
		//cout << "c2: " << a <<hex<< endl;
		//cout << "c2: " << b << hex << endl;
	}
};
class C3 : virtual public A, public B {
public:
	C3(int a = 0xC2A, int b = 0xC2B)
		: B(a, b) {
		//cout <<"c3: "<< a <<hex<< endl;
		//cout << "c3: " << b << hex << endl;
	}
};
class D1 : public C1, public C2 {
public:
	D1(int C1_a = 0xD1A, int C2_a = 0xD1A,
		int C1_b = 0xB, int C2_b = 0xB)
		//: C1(C1_a, C1_b), C2(C2_a, C2_b) {
		:A(C1_a), B(C1_a, C1_b) {
		//cout << "C1_b: "<<C1_b<<hex<<endl;
	}
	void print() {
		cout << "D1::print() ..." << endl;
		string strArr[] =
		{ "C1::a", "C2::a", "C1::b", "C2::b" };
		int* intPtrArr[] = { &(C1::a), &(C2::a),
		&(C1::b), &(C2::b) };
		suche(strArr, intPtrArr, 4);
	}
};
class D2 : public D1, public C3 {
public:
	D2(int C1_a = 0xA, int C2_a = 0xA, int C3_a = 0xA,
		int C1_b = 0xD2B, int C2_b = 0xD2B, int C3_b = 0xD2C3B)
		: D1(C1_a, C2_a, C1_b, C2_b), C3(C1_a, C3_b) {}
	void print() {
		cout << "D2::print() ..." << endl;
		string strArr[] = { "C1::a", "C2::a", "C3::a",
		"C1::b", "C2::b", "C3::b" };
		int* intPtrArr[] = { &(C1::a), &(C2::a), &(C3::a),
		&(C1::b), &(C2::b), &(C3::b) };
		suche(strArr, intPtrArr, 6);
	}
};
int main() {
	D1 d1obj;
	D2 d2obj;
	d1obj.print();
	d2obj.print();
	return 0;
}