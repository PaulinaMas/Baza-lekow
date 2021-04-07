#include <regex>
#include <fstream>
#include "Walidator.h"


	bool Walidator::sprawdzliczby(std::string sprawdz)
	{
		std::regex wzorzec("[^\\d]$");
		std::smatch wynik;
		if (regex_search(sprawdz, wynik, wzorzec))
			return false;
		else
			return true;

		
	}
	bool Walidator::sprawdzwybor(std::string sprawdz)
	{
		//dokladnie jedna liczba
		std::regex wzorzec("^\\d{1}$");
		std::smatch wynik;
		if (regex_search(sprawdz, wynik, wzorzec))
			return true;
		else
			return false;


	}
	bool Walidator::sprawdzcene(std::string sprawdz)
	{
		//jedna lub wiecej cyfr przed kropka, jedna lub dwie po kropce
		std::regex wzorzec("^\\d+.\\d{1,2}?$");
		std::smatch wynik;
		if (regex_search(sprawdz, wynik, wzorzec))
			return true;
		else
			return false;
	}
	bool Walidator::sprawdzrefundacje(std::string sprawdz)
	{
		std::regex wzorzec("\\d*");
		std::smatch wynik;
		if (regex_search(sprawdz, wynik, wzorzec))
		{
			int a = stoi(sprawdz);
			if (a < 0 || a>100)
				return false;
			return true;
		}
		else
			return false;
	}
	bool Walidator::pustyplik(std::ifstream& plik)
	{
		return plik.peek() == std::ifstream::traits_type::eof();
	}

