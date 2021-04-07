#ifndef MASC_H
#define MASC_H
#include <iostream>
#include <vector>
#include "Lek.h"
class Masc : public Lek
{
	int waga = 0;

public:
	Masc();
	Masc(std::string n, double c, std::vector<std::string> prz, std::string sub, int poz, int ilo, int ref, bool rec);
	friend std::ostream& operator <<(std::ostream& s, Masc leki);
	friend std::ostream& operator <<(std::ostream& s, Masc* leki);
	friend std::istream& operator >>(std::istream& s, Masc& leki);
	
	bool operator ==(const Masc& masc);
	bool operator !=(const Masc& masc);
};

#endif
