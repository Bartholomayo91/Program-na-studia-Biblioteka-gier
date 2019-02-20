#include "stdafx.h"
#include "Cbiblioteka.h"

unsigned Cbiblioteka::n = 0;
Cbiblioteka::Cbiblioteka()
{
	f = new Cgames[N];
	n = 0;
}
Cbiblioteka::~Cbiblioteka()
{
	delete[] f;
}
void Cbiblioteka::Printall() const
{
	cout << "******************************************************************************************************" << endl;
	printf("|%5s|%30s|%30s|%30s|\n", "Kod", "Tytul", "Studio", "Rok wydania");
	cout << "******************************************************************************************************" << endl;
	for (unsigned i = 0; i < n; i++)
		f[i].Printgames();
	cout << "*******************************************************************************************************" << endl;
}
void Cbiblioteka::Sort(bool(*cmp)(Cgames&, Cgames&))
{
	Cgames tmp;
	int i, j, maxi;
	for (i = 0; i < n; ++i)
	{
		maxi = 1;
		for (j = i + 1; j < n; ++j)
			if ((*cmp)(f[j], f[maxi]))
				maxi = j;
			if (maxi != 1)
			{
				tmp = f[i];
				f[i] = f[maxi];
				f[maxi] = tmp;
			}
	}
}
void Cbiblioteka::Addgames()
{
	f[n].Inputgames();
	n++;
}
bool Cbiblioteka::Dell(int j)
{
	if (n == 0) { cout << "Usunieto wszystkie gry." << endl; return false; }
	else
	{ 
		if (j >= n) { cout << "Nieprawidlowy kod: " << endl; system("pause"); return false; }
		else
		{
			for (unsigned i = j; i < n; i++)
				f[i] = f[i + 1];
			n--;
			return true;
		}
	}
}
Cgames& Cbiblioteka::operator[](const unsigned &index)const
{
	return f[index];
}

