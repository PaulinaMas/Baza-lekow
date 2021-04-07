#include <iostream>
#include "Komunikacja.h"

void Komunikacja::komunikuj(int x)
{
	switch (x)
	{
	case 1:
		std::cout << "Podaj nazwe" << std::endl;
		break;
	case 2:
		std::cout << "Po jakim parametrze chcesz wyszukac?(n-nazwa,c-cena,z-substancja(zamiennik))" << std::endl;
		break;
	case 3:
		std::cout << "Nie znaleziono" << std::endl;
		break;
	case 4:
		std::cout << "Podaj substancje" << std::endl;
		break;
	case 5:
		std::cout << "Podaj typ leku  (s-syrop, t-tabletka, m-masc)" << std::endl;
		break;
	case 6:
		std::cout << "Nie ma takiego typu!" << std::endl;
		break;
	case 7:
		std::cout << "Podaj ile zostalo: " << std::endl;
		break;
	case 8:
		std::cout << "Podaj poprawna liczbe!" << std::endl;
		break;
	case 9:
		std::cout << "Podaj cene: " << std::endl;
		break;
	case 10:
		std::cout << "Podaj poprawna cene!" << std::endl;
		break;
	case 11:
		std::cout << "Podaj cene minimalna" << std::endl;
		break;
	case 12:
		std::cout << "Podaj cene maksymalna" << std::endl;
		break;
	case 13:
		std::cout << "Cena minimalna nie moze byc wieksza od maksymalnej!" << std::endl;
		break;
	case 14:
		std::cout << "Podaj refundacje" << std::endl;
		break;
	case 15:
		std::cout << "Wpisz poprawna litere!" << std::endl;
		break;
	case 16:
		std::cout << "Podaj przeciwskazania(koniec - wcisnij '0': " << std::endl;
		break;
	case 17:
		std::cout << "Podaj ilosc leku jaki chcesz zarezerwowac" << std::endl;
		break;
	case 18:
		std::cout << "Nie udalo sie zarezerwowac" << std::endl;
		break;
	case 19:
		std::cout << "Taki lek juz istnieje" << std::endl;
		break;
	case 20:
		std::cout << "Podaj gramature opakowania: " << std::endl;
		break;
	case 21:
		std::cout << "Podaj ilosc w opakowaniu: " << std::endl;
		break;
	case 22:
		std::cout << "Podaj pojemnosc: " << std::endl;
		break;
	case 23:
		std::cout << "Podaj czy lek jest na recepte (1 jezeli tak, 0 jezeli nie)" << std::endl;
		break;
	case 24:
		std::cout << "Podaj liczbe o jaka edytowac stan leku (ujemna jezeli chcesz zmniejszyc ilosc)" << std::endl;
		break;
	case 25:
		std::cout << "Pusty plik!" << std::endl;
		break;
	case 26:
		std::cout << "Zapis udany" << std::endl;
		break;
	}
}