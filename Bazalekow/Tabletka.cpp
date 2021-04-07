#include <iostream>
#include <vector>

#include "Tabletka.h"


	Tabletka::Tabletka()
	{
		typ = "t";
	}
	Tabletka::Tabletka(std::string n, double c, std::vector<std::string> prz, std::string sub, int poz, int ilo, int ref, bool rec)
	{
		nazwa = n;
		cena = c;
		przeciwskazania = prz;
		substancja = sub;
		pozostalo = poz;
		ilosc = ilo;
		typ = "t";
		refundacja = ref;
		recepta = rec;
	}
	 std::ostream& operator <<(std::ostream& s, Tabletka leki)
	{
		s << "\ntyp: " << leki.typ << "\nnazwa: " << leki.nazwa << "\ncena: " << leki.cena << "\nprzeciwskazania:";
		for (int i = 0; i < leki.przeciwskazania.size(); i++)
		{
			s << "\n" << leki.przeciwskazania[i];

		}
		s << "\npozostalo: " << leki.pozostalo << "\nsubstancja: " << leki.substancja << "\nilosc: " << leki.ilosc << "\nrefundacja: " << leki.refundacja;
		if (leki.recepta == 0)
		{
			s << "\nLek bez recepty" << std::endl;
		}
		else
			s << "\nLek na recepte" << std::endl;
		return s;
	}
	 std::ostream& operator <<(std::ostream& s, Tabletka* leki)
	{
		s << "\ntyp: " << leki->typ << "\nnazwa: " << leki->nazwa << "\ncena: " << leki->cena << "\nprzeciwskazania:";
		for (int i = 0; i < leki->przeciwskazania.size(); i++)
		{
			s << "\n" << leki->przeciwskazania[i] ;

		}
		s << "\npozostalo: " << leki->pozostalo << "\nsubstancja: " << leki->substancja << "\npojemnosc: " << leki->ilosc << "\nrefundacja: " << leki->refundacja;
		if (leki->recepta == 0)
		{
			s << "\nLek bez recepty" << std::endl;
		}
		else
			s << "\nLek na recepte" << std::endl;
		return s;
	}
	 std::istream& operator >>(std::istream& s, Tabletka& leki)
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
		s >> temp >> leki.ilosc;
		s >> temp >> leki.refundacja;
		s >> temp >> temp >> temp;
		if (temp[temp.length()-1] == 'y')
			leki.recepta = 0;
		else
			leki.recepta = 1;
		return s;
	}
	 bool Tabletka::operator ==(const Tabletka& tab)
	 {
		 if (this->nazwa == tab.nazwa && this->substancja == tab.substancja && this->ilosc == tab.ilosc)
			 return true;
		 return false;
	 }
	
		bool Tabletka::operator !=(const Tabletka & tab)
		{
			if (this->nazwa != tab.nazwa && this->substancja != tab.substancja && this->ilosc != tab.ilosc)
				return true;
			return false;
		}
