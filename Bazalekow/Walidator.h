#ifndef WALIDATOR_H
#define WALIDATOR_H

class Walidator
{
public:
	/**Sprawdza czy podany napis jest liczba*/
	bool sprawdzliczby(std::string sprawdz);
	/**Sprawdza format ceny*/
	bool sprawdzcene(std::string sprawdz);
	/**Sprawdza czy refundacja jest z zakresu 0-100*/
	bool sprawdzrefundacje(std::string sprawdz);
	bool pustyplik(std::ifstream& plik);
	/**Sprawdza, czy wybor jest pojedyncza liczba*/
	bool sprawdzwybor(std::string sprawdz);
};
#endif
