#include <iostream>
#include <vector>
#include "Masc.h"


	Masc::Masc()
	{
		typ = "m";
	}
	Masc::Masc(std::string n, double c, std::vector<std::string> prz, std::string sub, int poz, int ilo, int ref, bool rec)
	{
		nazwa = n;
		cena = c;
		przeciwskazania = prz;
		substancja = sub;
		pozostalo = poz;
		waga = ilo;
		typ = "m";
		refundacja = ref;
		recepta = rec;
	}
	 std::ostream& operator <<(std::ostream& s, Masc leki)
	{
		s << "\ntyp: " << leki.typ << "\nnazwa: " << leki.nazwa << "\ncena: " << leki.cena << "\nprzeciwskazania:";
		for (int i = 0; i < leki.przeciwskazania.size(); i++)
		{
			s << "\n" << leki.przeciwskazania[i];

		}
		s << "\npozostalo: " << leki.pozostalo << "\nsubstancja: " << leki.substancja << "\nwaga: " << leki.waga << "\nrefundacja: " << leki.refundacja;
		if (leki.recepta == 0)
		{
			s << "\nLek bez recepty" << std::endl;
		}
		else
			s << "\nLek na recepte" << std::endl;
		return s;
	}
	 std::ostream& operator <<(std::ostream& s, Masc* leki)
	{
		s << "\ntyp: " << leki->typ << "\nnazwa: " << leki->nazwa << "\ncena: " << leki->cena << "\nprzeciwskazania:";
		for (int i = 0; i < leki->przeciwskazania.size(); i++)
		{
			s << "\n" << leki->przeciwskazania[i] ;

		}
		s << "\npozostalo: " << leki->pozostalo << "\nsubstancja: " << leki->substancja << "\nwaga: " << leki->waga << "\nrefundacja: " << leki->refundacja;
		if (leki->recepta == 0)
		{
			s << "\nLek bez recepty" << std::endl;
		}
		else
			s << "\nLek na recepte" << std::endl;
		return s;
	}
	 std::istream& operator >>(std::istream& s, Masc& leki)
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
			leki.przeciwskazania.push_back(temp);
		}
		s >> temp >> leki.pozostalo;
		s >> temp >> leki.substancja;
		s >> temp >> leki.waga;
		s >> temp >> leki.refundacja;
		s >> temp >> temp >> temp;
		if (temp[temp.length()-1] == 'y')
			leki.recepta = 0;
		else
			leki.recepta = 1;
		return s;
	}
	bool Masc::operator ==(const Masc& masc)
	{
		if (this->nazwa == masc.nazwa && this->substancja == masc.substancja && this->waga == masc.waga)
			return true;
		return false;
	}
	bool Masc::operator !=(const Masc& masc)
	{
		if (this->nazwa != masc.nazwa && this->substancja != masc.substancja && this->waga != masc.waga)
			return true;
		return false;
	}
