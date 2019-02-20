#include "stdafx.h"
#include "Menu.h"

Menu::~Menu()
{
}
Menu::Menu(Cbiblioteka &b)
{
	GeneralMenu(b);
}
void Menu::m()
{
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "- 0. Powrot." << endl;
	cout << "- 1. Kody indeksowe." << endl;
	cout << "- 2. Tytuly." << endl;
	cout << "- 3. Studia produkcyjne." << endl;
	cout << "- 4. Rok wydania." << endl;
	cout << "--------------------------------" << endl;
	cout << "Wprowadz nr polecenia: ";
}
void Menu::GeneralMenu(Cbiblioteka& b)
{
	int g = 1;
	while (g != 0)
	{
		system("cls");
		cout << "-------------------------------------------" << endl;
		cout << "WITAJ W MENU BIBLIOTEKI GIER KOMPUTEROWYCH!" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "- 0. Exit." << endl;
		cout << "- 1. Dodaj gre." << endl;
		cout << "- 2. Usun gre." << endl;
		cout << "- 3. Pokaz gry." << endl;
		cout << "- 4. Znajdz gre." << endl;
		cout << "- 5. Korekta pola." << endl;
		cout << "- 6. Sortuj." << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Wprowadz nr polecenia: ";
		cin >> g;
		switch (g)
		{
			case 1:
				{
				b.Addgames();
				break;
				};
			case 2:
			{
				cout << "Wybierz numer pozycji  od 0 do " << b.GetN()-1<<": ";
				int j;
				cin >> j;
				if (b.Dell(j))

				{
					cout << "Operacja wykonana poprawnie!" << endl;
					system("pause");
					
				}
				else
				{
					cout << "Blad operacji!" << endl;
					system("pause");
					
				}
				break;
			}
			case 3:
			{
				if (b.GetN() == 0)
				{
					cout << "Brak gier w bazie!" << endl;
					system("pause");
				}
				else
				{
					b.Printall();
					system("pause");
					
				}break;
			}
			case 4: {MenuFind(b); break; };
			case 5: {MenuCorect(b); break; };
			case 6: {MenuSort(b); break; };
		}


	}
}
void Menu::MenuCorect(Cbiblioteka &b)
{
	int g = 1, k = 0;
	int num = 0;
	char name[100];
	bool flag = true;
	while (g != 0)
	{
		m();
		cin >> g;
		switch (g)
		cin >> g;
		if (g == 0) break;
		cout << "Wprowadz kod indeksu gry od 0 do " << b.GetN() - 1 <<"."<< endl;
		cin >> k;
		if (k >= b.GetN())
		{
			cout << "Nieznany numer...";
			system("pause");
			break;
		}
		else
		{
			cout << "Wpisz nowa nazwe/liczbe: " << endl;
			switch (g)
			{
			case 1: cin >> num; b[k].Setcode(num);
			{
				b.Printall();
				system("pause");
				break;
			}
			case 2:cin >> name; b[k].Settitle(name);
			{
				b.Printall();
				system("pause");
				break;
			}
			case 3:cin >> name; b[k].Setstudio(name);
			{
				b.Printall();
				system("pause");
				break;
			}
			case 4:cin >> num; b[k].Setyear(num);
			{
				b.Printall();
				system("pause");
				break;
			}

			}

		}
	}
}
void Menu::MenuSort(Cbiblioteka &b)
{
	int g = 1;
	int num = 0;
	char name[100];
	bool flag = true;
	while (g != 0)
		{
		m();
		cin >> g;
		switch (g)
			cin >> g;
		switch (g)
			{
			case 1: b.Sort(Cbiblioteka::Cmpcode);
			{
				b.Printall();
				system("pause");
				break;
			}
			case 2:b.Sort(Cbiblioteka::Cmptitle);
			{
				b.Printall();
				system("pause");
				break;
			}
			case 3: b.Sort(Cbiblioteka::Cmpstudio);
			{
				b.Printall();
				system("pause");
				break;
			}
			case 4: b.Sort(Cbiblioteka::Cmpyear);
			{
				b.Printall();
				system("pause");
				break;
			}

			}

		}
}
void Menu::MenuFind(Cbiblioteka &b)
{
	int g = 1;
	int num = 0;
	char name[100];
	bool flag = true;
	while (g != 0)
	{
		m();
		cin >> g;
		switch (g)
			cin >> g;
		switch (g)
		{
		case 1: 
			cout << "Wprowadz kod: ";
			cin >> num;
			flag = true;
			for (unsigned i = 0; i < b.GetN(); i++)
				if(b[i].Getcode()==num)
				{
					b[i].Printgames(); 
					flag = false;
				}
			if (flag)
				cout << "Pola nie znaleziono." << endl;
			system("pause");
			break;

		
		case 2:
			cout << "Wprowadz tytul: ";
			cin >> name;
			flag = true;
			for (unsigned i = 0; i < b.GetN(); i++)
				if (strcmp(b[i].Gettitle(), name)==0)
				{
					b[i].Printgames();
					flag = false;
				}
			if (flag)
				cout << "Pola nie znaleziono." << endl;
			system("pause");
			break;
		case 3: 
			cout << "Wprowadz studio: ";
			cin >> name;
			flag = true;
			for (unsigned i = 0; i < b.GetN(); i++)
				if (strcmp(b[i].Getstudio(), name) == 0)
				{
					b[i].Printgames();
					flag = false;
				}
			if (flag)
				cout << "Pola nie znaleziono." << endl;
			system("pause");
			break;
		case 4: 
			cout << "Wprowadz rok wydania: ";
			cin >> num;
			flag = true;
			for (unsigned i = 0; i < b.GetN(); i++)
				if (b[i].Getyear() == num)
				{
					b[i].Printgames();
					flag = false;
				}
			if (flag)
				cout << "Pola nie znaleziono." << endl;
			system("pause");
			break;

		}

	}
}



