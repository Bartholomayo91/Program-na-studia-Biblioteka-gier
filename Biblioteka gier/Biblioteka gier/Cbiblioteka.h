#pragma once
#include "Cgames.h"
#include <iostream>
class Cbiblioteka 
{
	static const unsigned N = 10;
	static unsigned n;
	Cgames *f;
public:
	unsigned GetN() const 
		{return n;	}
	void Printall() const;
	void Addgames();
	void Sort(bool(*cmp)(Cgames&, Cgames&));
	Cgames& operator[](const unsigned &index)const;
	bool Find() const;
	bool Dell(int);
	static bool Cmpcode(Cgames &a, Cgames &b)
	{
		return a.Getcode() < b.Getcode();
	}
	static bool Cmpyear(Cgames &a, Cgames &b)
	{
		return a.Getyear() < b.Getyear();
	}
	static bool Cmptitle(Cgames &a, Cgames &b)
	{
		return strcmp(a.Gettitle(), b.Gettitle()) < 0;
	}
	static bool Cmpstudio(Cgames &a, Cgames &b)
	{
		return strcmp(a.Getstudio(), b.Getstudio()) < 0;
	}
	Cbiblioteka();
	~Cbiblioteka();
};

