#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include "Listy.h"
#include "Menu.h"


using namespace std;


int main()
{
	Listy* nowe = new Listy;
	Menu menu;

	int wyb = 1;
	while (wyb)
	{
		menu.wyswietl();
		wyb = menu.wybor();
		system("cls");
		menu.wybrana(wyb, nowe);
	}
	delete nowe;
	return 0;
}