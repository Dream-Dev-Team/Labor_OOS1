#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
//////////////////////////////////////////////////////
//Dateiname: Labor1_Aufgabe4 
//Autoren: Maxim Becht (mabeit10@hs-esslingen.de), Aaron Müller (aamuit00@hs-esslingen.de)
//Enthaltene Module: 
//Entwicklungsbeginn: 07.05.2020		Entwicklungsende: 07.05.2020
//Zeitaufwand gesamt: 30min
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
	cout << "Name des Spielers: ";
	cin >> str;
	return str;
}

// Den Computer zufällig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
objectType randomChoice()
{
	srand(time(NULL));
	int randomNumber = rand() % 3;
	return objectType(randomNumber);
}

// Die Wahl von STEIN etc. als String zurückgeben lassen
const char* object2str(objectType o)
{
	const char * objectName = "none";
	switch (o)
	{
	case STEIN:
		objectName = "Stein";
		break;
	case SCHERE:
		objectName = "Schere";
		break;
	case PAPIER:
		objectName = "Papier";
		break;
	}
	return objectName;
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{
	cout << p.name << " hat das Objekt " << object2str(p.choice) << " ausgew\x84 \bhlt." << endl;
}

// Die Wahl des Spielers abfragen
objectType enterChoice()
{
	int playerChoiceIndex = 0;
	cout << "Bitte Objektwahl eingeben(1 = Stein, 2 = Schere, 3 = Papier) : ";
	cin >> playerChoiceIndex;
	return objectType(--playerChoiceIndex); //Index 0-2 => Eingabe 1-3 => Index = Eingabe - 1
}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{
	int winConditionIndex = obj1 - obj2;
	if (winConditionIndex == 1 || winConditionIndex == -2)
		return obj2;
	if (winConditionIndex == -1 || winConditionIndex == 2)
		return obj1;
	return obj1; //bei unentschieden wird einach das obj des Computers zurückgegeben
}	

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{
	objectType winningObj = winningObject(p1.choice, p2.choice);
	if (winningObj == p1.choice && winningObj == p2.choice)	//Unentschieden
		cout << "unentschieden!";
	else if (winningObj == p1.choice)
		cout << p1.name << " hat gewonnen!";
	else if (winningObj == p2.choice)
		cout << p2.name << " hat gewonnen!";
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