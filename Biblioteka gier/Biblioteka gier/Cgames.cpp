#include "stdafx.h"
#include "Cgames.h"
#include <iostream>
using namespace std;

Cgames::Cgames()
{
	code = 0;
	title = new char[strlen("Nieznany tutul") + 1];
	strcpy_s(title, strlen("Nieznany tytul") + 1, "Nieznany tytul");
	studio = new char[strlen("Nieznane studio") + 1];
	strcpy_s(studio, strlen("Nieznane studio") + 1, "Nieznane studio");
	year = 2000;
}

Cgames::Cgames(int ncode, int nyear, char *ntitle, char *nstudio)
{
	code = ncode;
	title = new char[strlen(ntitle) + 1];
	strcpy_s(title, strlen(ntitle) + 1, ntitle);
	studio = new char[strlen(nstudio) + 1];
	strcpy_s(studio, strlen(nstudio) + 1, nstudio);
	year = nyear;
}
Cgames::Cgames(const Cgames &gamesRef)
{
	code = gamesRef.code;
	title = new char[strlen(gamesRef.title) + 1];
	strcpy_s(title, strlen(gamesRef.title) + 1, gamesRef.title);
	studio = new char[strlen(gamesRef.studio) + 1];
	strcpy_s(studio, strlen(gamesRef.studio) + 1, gamesRef.studio);
	year = gamesRef.year;
}
const Cgames & Cgames::operator = (const Cgames &gamesRef)
{
	code = gamesRef.code;
	delete[] title;
	title = new char[strlen(gamesRef.title) + 1];
	strcpy_s(title, strlen(gamesRef.title) + 1, gamesRef.title);
	delete[] studio;
	studio = new char[strlen(gamesRef.studio) + 1];
	strcpy_s(studio, strlen(gamesRef.studio) + 1, gamesRef.studio);
	year = gamesRef.year;
	return *this;
}

Cgames::~Cgames(void)
{
	
	delete[] title;
	delete[] studio;
}
void Cgames::Inputgames(void)
{
	int ncode = 0, nyear = 0;
	char ntitle[100], nstudio[100];
	cout << endl;
	cout <<"Wprowadz kod indeksu: ";
	cin >> ncode;
	cout <<"Wprowadz tytul: ";
	cin >> ntitle;
	cout <<"Wprowadz studio wykonawcze: ";
	cin >> nstudio;
	cout << "Wprowadz rok wydania: ";
	cin >> nyear;
	
	delete[] this->title;
	this->title = new char[strlen(ntitle) + 1];
	strcpy_s(title, strlen(ntitle) + 1, ntitle);
	delete[] this->studio;
	this->studio = new char[strlen(nstudio) + 1];
	strcpy_s(studio, strlen(nstudio) + 1, nstudio);
	code = ncode;
	year = nyear;
}
void Cgames::Printgames(void)
{
	
	printf("|%5u|%30s|%30s|%30u|\n", code, title, studio, year);
}
void Cgames::Settitle(char* title)
{
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
};
void Cgames::Setstudio(char* studio)
{
	delete[] this->studio;
	this->studio = new char[strlen(studio) + 1];
	strcpy_s(this->studio, strlen(studio) + 1, studio);
};
