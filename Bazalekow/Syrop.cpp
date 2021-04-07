#include <iostream>
#include <vector>
#include "Syrop.h"


	Syrop::Syrop()
	{
		typ = "s";
	}
	Syrop::Syrop(std::string n, double c, std::vector<std::string> prz, std::string sub, int poz, int poj, int ref, bool rec)
	{
		nazwa = n;
		cena = c;
		przeciwskazania = prz;
		substancja = sub;
		pozostalo = poz;
		pojemnosc = poj;
		typ = "s";
		refundacja = ref;
		recepta = rec;

	}
	
	 std::ostream& operator <<(std::ostream& s, const Syrop leki)
	{
		s << "\ntyp: " << leki.typ << "\nnazwa: " << leki.nazwa << "\ncena: " << leki.cena << "\nprzeciwskazania:";
		for (int i = 0; i < leki.przeciwskazania.size(); i++)
		{
			s << "\n" <<  leki.przeciwskazania[i];

		}
		s << "\npozostalo: " << leki.pozostalo << "\nsubstancja: " << leki.substancja << "\npojemnosc: " << leki.pojemnosc << "\nrefundacja: " << leki.refundacja;
		if (leki.recepta == 0)
		{
			s << "\nLek bez recepty" << std::endl;
		}
		else
			s << "\nLek na recepte" << std::endl;

		return s;
	}
	 std::ostream& operator <<(std::ostream& s, const Syrop* leki)
	{
		s << "\ntyp: " << leki->typ << "\nnazwa: " << leki->nazwa << "\ncena: " << leki->cena << "\nprzeciwskazania:";
		for (int i = 0; i < leki->przeciwskazania.size(); i++)
		{
			s << "\n" << leki->przeciwskazania[i];

		}
		s << "\npozostalo: " << leki->pozostalo << "\nsubstancja: " << leki->substancja << "\npojemnosc: " << leki->pojemnosc << "\nrefundacja: " << leki->refundacja;
		if (leki->recepta == 0)
		{
			s << "\nLek bez recepty" << std::endl;
		}
		else
			s << "\nLek na recepte" << std::endl;
		return s;
	}
	 std::istream& operator >>(std::istream& s, Syrop& leki)
	{
		std::string temp;
		int ilel;
		s >> ilel >> temp >> leki.typ;
		s >> temp >> leki.nazwa >> temp;
		s >> leki.cena >> temp;
		getline(s, temp);
		for (int i = 0; i < ilel; i++)
		{
			getline(s, temp);
			//s >> temp;
			leki.przeciwskazania.push_back(temp);
		}
		s >> temp >> leki.pozostalo;
		s >> temp >> leki.substancja;
		s >> temp >> leki.pojemnosc;
		s >> temp >> leki.refundacja;
		s >> temp >> temp >> temp;
		//jezeli napis to "Lek bez recepty"
		if (temp[temp.length()-1] == 'y')
			leki.recepta = 0;
		else
			leki.recepta = 1;
		return s;
	}
	bool Syrop::operator ==(const Syrop& syr)
	{
		if (nazwa == syr.nazwa && substancja == syr.substancja && pojemnosc == syr.pojemnosc && przeciwskazania == syr.przeciwskazania)
			return true;
		return false;
	}
	bool Syrop::operator !=(const Syrop& syr)
	{
		if (nazwa != syr.nazwa && substancja != syr.substancja && pojemnosc != syr.pojemnosc && przeciwskazania != syr.przeciwskazania)
			return true;
		return false;
	}
