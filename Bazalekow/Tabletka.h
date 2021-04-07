#ifndef TABLETKA_H
#define TABLETKA_H
#include <iostream>
#include <vector>
#include "Lek.h"

class Tabletka : public Lek
{
	int ilosc = 0;

public:
	Tabletka();
	Tabletka(std::string n, double c, std::vector<std::string> prz, std::string sub, int poz, int ilo, int ref, bool rec);
	friend std::ostream& operator <<(std::ostream& s, Tabletka leki);
	friend std::ostream& operator <<(std::ostream& s, Tabletka* leki);
	friend std::istream& operator >>(std::istream& s, Tabletka& leki);
	bool operator ==(const Tabletka& tab);
	bool operator !=(const Tabletka& tab);
};

#endif