#pragma once
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class Cgames
{
	char *title;
	char *studio;
	int code;
	int year;
public:
	Cgames();
	Cgames(int ncode, int nyear, char *ntitle, char *nstudio);
	Cgames(const Cgames &gamesRef);
	const Cgames & operator = (const Cgames &gamesRef);
	void Printgames(void);
	void Inputgames(void);

	~Cgames();

	void Setcode(int code)
	{
		this->code = code;
	};
	int Getcode() const

	{
		return code;
	};
	void Setyear(int year)
	{
		this->year = year;
	};
	int Getyear() const
	{
		return year;
	};
	void Setstudio(char *studio);
	char* Getstudio() const
	{
		return this->studio;
	};
	void Settitle(char *title);
	char* Gettitle() const
	{
		return this->title;
	};
};

