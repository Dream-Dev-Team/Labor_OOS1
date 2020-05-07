#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: xx.xx.xx		Entwicklungsende: xx.xx.xx
//Zeitaufwand gesamt: 
//Letzte Modifikationen: 
//////////////////////////////////////////////////////

/*


Spiel Tsching, Tschang, Tschong

Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide können das gleiche Objekt wählen.
Der Spieler, der das mächtigere Objekt gewählt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist
mächtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist
mächtiger als STEIN. SCHERE zerschneidet PAPIER, d. h. SCHERE
ist maechtiger als PAPIER

*/


// Aufzählungstyp für Stein etc.
enum objectType { STEIN, SCHERE, PAPIER };

// Struktur für einen Spieler bestehend aus Name und Wahl 
// des Spielers
struct player {
	const char* name;
	objectType choice;
};

// Variable für den Namen des Spielers 
char name[15];

// Name des Spielers eingeben
char* enterName(char str[])
{
	cin >> str;



	return NULL;
}

// Den Computer zufällig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
objectType randomChoice()
{


	return  STEIN;

}

// Die Wahl von STEIN etc. als String zurückgeben lassen
char* object2str(objectType o)
{






	return NULL;


}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{



}

// Die Wahl des Spielers abfragen
objectType enterChoice()
{














	return STEIN;

}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{



	return STEIN;


}	

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{












}

int main()
{
	player player1, player2;
	player1.name = "Computer";
	player1.choice = randomChoice();
	cout << "Der Computer hat sein Wahl getroffen." << endl;
	player2.name = enterName(name);
	player2.choice = enterChoice();
	showPlayer(player1);
	showPlayer(player2);
	showWinner(player1, player2);
	return NULL;
}