#ifndef MENU_H
#define MENU_H
#include "Listy.h"
#include "Szukaj.h"
#include "Walidator.h"
#include "Komunikacja.h"


class Menu
{
public:

	int wybor();
	bool opcja1szukaj(Listy*& head);
	bool opcja2dodaj(Listy*& head);
	bool opcja3rezerwuj(Listy*& head);
	bool opcja4zmienstan(Listy*& head);
	bool opcja5odczyt(Listy*& head);
	void opcja6zapis(Listy*& head);
	/**wyswietla baze*/
	void opcja7pokaz(Listy*& head);
	/**wyswietla menu*/
	void wyswietl();
	/**wywoluje funkcje z menu*/
	bool wybrana(int wybor, Listy*& head);
};

#endif
