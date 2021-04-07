#ifndef LEK_H
#define LEK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

/**Klasa, z ktorej dziedzicza klasy Syrop, Tabletka oraz Masc*/
class Lek
{
protected:
	std::string nazwa = "brak";
	double cena = 0.00;
	std::vector <std::string>  przeciwskazania = {};
	std::string substancja = "brak";
	int pozostalo = 0; 
	std::string typ = "0"; //s, t lub m
	int refundacja = 0; //w %
	bool recepta = 0; //1 jezeli lek jest na recepte

public:
	Lek();
	std::string getnazwa();
	double getcena();
	std::string getsub();
	int getref();
	std::string gettyp();
	/**zwraca ilosc przeciwskazan*/
	int getwielkoscwek();
	/**zmniejsza ilosc leku w bazie*/
	bool rezerwuj(int ile);
	/**zmniejsza lub zwieksza ilosc leku w bazie*/
	bool edytujstan(int ile);
};


#endif
