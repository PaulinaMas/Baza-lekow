#ifndef SZUKAJ_H
#define SZUKAJ_H
#include <iostream>
#include <vector>
#include "Listy.h"

class Szukaj
{
public:
	virtual std::vector<Lek*> szuk(Listy* head, std::string nazwa);
};

class Szukpocenie : public Szukaj
{
public:
	std::vector <Lek*> szuk(Listy* head, double cenamin, double cenamax);
};
class Szukzamiennik : public Szukaj
{
public:
	std::vector<Lek*> szuk(Listy* head, std::string substancja);
};

class Szukporef : public Szukaj
{
public:
	std::vector<Lek*> szuk(Listy* head, int ref);
};

#endif