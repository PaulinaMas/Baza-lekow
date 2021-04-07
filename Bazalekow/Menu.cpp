#include <iostream>
#include <vector>
#include <fstream>
#include "Menu.h"




	int Menu::wybor()
	{
		std::string a;
		Walidator w;
		
		std::cin >> a;
		if (!(w.sprawdzwybor(a)))
			 return 9;
		else
		{
			int z;
			z= stoi(a);
			return z;
		}
	}
	
	bool Menu::opcja1szukaj(Listy*& head)
	{
		Komunikacja k;
		std::string n, s, pomoc;
		double c, cmax;
		int ref;
		std::string wyb;
		k.komunikuj(2);
		std::cin >> wyb;
		if (wyb == "n")
		{
			Szukaj szuk;
			k.komunikuj(1);
			std::cin >> n;
			std::vector <Lek*> znalezione = szuk.szuk(head, n);
			if (znalezione.size() == 0)
			{
				k.komunikuj(3);
				return true;
			}
			else
			{

				for (int i = 0; i < znalezione.size(); i++)
				{
					std::string a = znalezione[i]->gettyp();
					
					if(a=="t")
						std::cout << (Tabletka*)znalezione[i];
						if (a == "s")
						std::cout << (Syrop*)znalezione[i];
						if (a == "m")
						std::cout << (Masc*)znalezione[i];
					

				}
				return true;
			}

		}
		else if (wyb == "z")
		{
			Szukzamiennik szuk;
			k.komunikuj(4);
			std::cin >> s;
			std::vector <Lek*> znalezione = szuk.szuk(head, s);
			if (znalezione.size() == 0)
			{
				k.komunikuj(3);
				return false;
			}
			else
			{
				for (int i = 0; i < znalezione.size(); i++)
				{
					std::string a = znalezione[i]->gettyp();
					//konwersja z Lek* na odpowiedni typ
					if(a=="t")
						std::cout << (Tabletka*)znalezione[i];
					if (a == "s")
						std::cout << (Syrop*)znalezione[i];
					if (a == "m")
						std::cout << (Masc*)znalezione[i];
					
				}
			}


		}
		else if (wyb == "c")
		{
			Szukpocenie szuk;
			Walidator w;
			k.komunikuj(11);
			std::cin >> pomoc;
			if (w.sprawdzcene(pomoc))
				c = stod(pomoc);
			else
			{
				k.komunikuj(10);
				return 0;
			}
			k.komunikuj(12);
			std::cin >> pomoc;
			if (w.sprawdzcene(pomoc))
				cmax = stod(pomoc);
			else
			{
				k.komunikuj(10);
				return 0;
			}
			if (cmax < c)
			{
				k.komunikuj(13);
				return 0;
			}
	
			std::vector <Lek*> aaa = szuk.szuk(head, c, cmax);
			if (aaa.size() == 0)
			{
				k.komunikuj(3);
				return false;
			}
			else
			{
				for (int i = 0; i < aaa.size(); i++)
				{
					std::string a = (aaa[i]->gettyp());
					
					if (a == "t")
						std::cout << (Tabletka*)aaa[i];
					if (a == "s")
						std::cout << (Syrop*)aaa[i];
					if (a == "m")
						std::cout << (Masc*)aaa[i];
					
				}
			}


		}
		else if (wyb == "r")
		{
		Szukporef szuk;
		k.komunikuj(14);
		std::cin >> ref;
		std::vector <Lek*> znalezione = szuk.szuk(head, ref);
		if (znalezione.size() == 0)
		{
			k.komunikuj(3);
			return false;
		}
		else
		{
			for (int i = 0; i < znalezione.size(); i++)
			{
				std::string a = (znalezione[i]->gettyp());
				
				if(a=="t")
					std::cout << (Tabletka*)znalezione[i];
			
					if (a == "s")
					std::cout << (Syrop*)znalezione[i];
				
					if (a == "m")
					std::cout << (Masc*)znalezione[i];
				
				
			}
		}
		}
		else
		{
		k.komunikuj(15);
			return 0;
		}
	}

	bool Menu::opcja2dodaj(Listy*& head)
	{
		std::string n, s, p, pomoc;
		Komunikacja k;
		double c, cmax;
		int z, il, ref, poj;
		std::vector <std::string> prz;
		Walidator w;
		std::string typ;
		k.komunikuj(5);
		std::cin >> typ;
		if (typ != "s" && typ != "m" && typ != "t")
		{
			k.komunikuj(6);
			return false;
		}
		k.komunikuj(1);
		std::cin >> n;
		k.komunikuj(4);
		std::cin >> s;
		k.komunikuj(7);
		std::cin >> pomoc;
		if (!w.sprawdzliczby(pomoc))
		{
			k.komunikuj(8);
			return false;
		}
		else
			z = atoi(pomoc.c_str());


		k.komunikuj(16);
		while (getline(std::cin,p) && p != "0")
			prz.push_back(p);
		k.komunikuj(9);
		std::cin >> pomoc;
		if (!w.sprawdzcene(pomoc))
		{
			k.komunikuj(10);
			return false;
		}
		else
			c = std::stod(pomoc.c_str());
		k.komunikuj(23);
		std::cin >> pomoc;
		if (!w.sprawdzliczby(pomoc))
		{
			k.komunikuj(8);
			return false;
		}
		
			int rec = atoi(pomoc.c_str());
		if(rec!=1 && rec!=0)
		{
			k.komunikuj(8);
			return false;
		}
		if(rec==0)
		{
			ref = 0;
		}
		else if (rec == 1)
		{
			k.komunikuj(14);
			std::cin >> pomoc;
			if (!w.sprawdzrefundacje(pomoc))
			{
				k.komunikuj(8);
				return false;
			}
			else
				ref = std::stod(pomoc.c_str());
		}
		
		
		if (typ == "s")
		{
			k.komunikuj(22);
			std::cin >> pomoc;
			if (!w.sprawdzliczby(pomoc))
			{
				k.komunikuj(8);
				return false;
			}
			else
				poj = atoi(pomoc.c_str());
			Syrop aaa(n, c, prz, s, z, poj, ref,rec);
			if (head->sss->sprawdzczyrowne(head->sss, aaa))
			{
				k.komunikuj(19);
				return false;
			}
			head->sss->dodaj(head->sss, aaa);
		}
		else if (typ == "t")
		{
			k.komunikuj(21);
			std::cin >> pomoc;
			if (!w.sprawdzliczby(pomoc))
			{
				k.komunikuj(8);
				return false;
			}
			else
				il = atoi(pomoc.c_str());
			Tabletka aaa(n, c, prz, s, z, il, ref,rec);
			if (head->ttt->sprawdzczyrowne(head->ttt, aaa))
			{
				k.komunikuj(19);
				return false;
			}
			head->ttt->dodaj(head->ttt, aaa);
		}
		else if (typ == "m")
		{
			k.komunikuj(20);
			std::cin >> pomoc;
			if (!w.sprawdzliczby(pomoc))
			{
				k.komunikuj(8);
				return false;
			}
			else
				il = atoi(pomoc.c_str());

			Masc aaa(n, c, prz, s, z, il, ref , rec);
			if (head->mmm->sprawdzczyrowne(head->mmm, aaa))
			{
				k.komunikuj(19);
				return false;
			}
			head->mmm->dodaj(head->mmm, aaa);
		}
	}

	bool Menu::opcja3rezerwuj(Listy*& head)
	{
		Komunikacja k;
		Walidator w;
		std::string typ;
		std::string n, s, pomoc;
		k.komunikuj(5);
		std::cin >> typ;
		if (typ != "s" && typ != "m" && typ != "t")
		{
			k.komunikuj(6);
			return false;
		}
		k.komunikuj(1);
		std::cin >> n;
		k.komunikuj(4);
		std::cin >> s;
		int ile;
		k.komunikuj(17);
		std::cin >> pomoc;
		if (!w.sprawdzliczby(pomoc))
		{
			k.komunikuj(8);
			return false;
		}
		else
			ile = atoi(pomoc.c_str());
		Szukaj szuk;
		Szukzamiennik szukz;
		std::vector<Lek*> szukn = szuk.szuk(head, n);
		std::vector<Lek*> szuks = szukz.szuk(head, s);
		if (szukn.size() == 0 || szuks.size() == 0)
		{
			k.komunikuj(3);
			return false;
		}
		for (int i = 0; i < szukn.size(); i++)
		{
			for (int j = 0; j < szuks.size(); j++)
			{
				if (szukn[i] == szuks[j])
				{
					if (!szukn[i]->rezerwuj(ile))
					{
						k.komunikuj(18);
						return false;
					}

					std::string a = (szukn[i]->gettyp());
					
					if(a=="t")

						std::cout << (Tabletka*)szukn[i];
						if (a == "s")
						std::cout << (Syrop*)szukn[i];
						if (a == "m")
						std::cout << (Masc*)szukn[i];
					
					return true;
				}
				else
				{
					k.komunikuj(3);
					return false;
				}


			}
		}
	}

	bool Menu::opcja4zmienstan(Listy*& head)
	{
		std::string typ, pomoc;
		std::string n, s;
		Walidator w;
		Komunikacja k;
		k.komunikuj(5);
		std::cin >> typ;
		if (typ != "s" && typ != "m" && typ != "t")
		{
			k.komunikuj(6);
			return false;
		}
		k.komunikuj(1);
		std::cin >> n;
		k.komunikuj(4);
		std::cin >> s;
		int ile;
		k.komunikuj(24);
		std::cin >> pomoc;
		if (!w.sprawdzliczby(pomoc))
		{
			k.komunikuj(8);
			return false;
		}
		else
			ile = atoi(pomoc.c_str());

		Szukaj szuk;
		Szukzamiennik szukz;
		std::vector<Lek*> szukn = szuk.szuk(head, n);
		std::vector<Lek*> szuks = szukz.szuk(head, s);
		if (szukn.size() == 0 || szuks.size() == 0)
		{
			k.komunikuj(3);
			return false;
		}
		for (int i = 0; i < szukn.size(); i++)
		{
			for (int j = 0; j < szuks.size(); j++)
			{
				if (szukn[i] == szuks[j])
				{
					if (!szukn[i]->edytujstan(ile))
						k.komunikuj(18);
					std::string a = (szukn[i]->gettyp());
					
					if(a=="t")

						std::cout << (Tabletka*)szukn[i];
						if (a == "s")
						std::cout << (Syrop*)szukn[i];
						if (a == "m")
						std::cout << (Masc*)szukn[i];
					
				}
			}
		}



	}
	bool Menu::opcja5odczyt(Listy*& head)
	{
		Walidator w;
		Komunikacja k;
		if (head)
		{
			std::ifstream plik;
			plik.open("baza.clv");
			if (plik.good())
			{
				if (w.pustyplik(plik))
				{
					k.komunikuj(25);
					plik.close();
					return false;
				}
				int tab[3];
				plik >> tab[0] >> tab[1] >> tab[2];

				for (int i = 0; i < tab[0]; i++)
				{
					Syrop nowysyr;
					plik >> nowysyr;
					if (head->sss->sprawdzczyrowne(head->sss, nowysyr))
						return false;
					
					head->sss->dodaj(head->sss, nowysyr);
					

				}
				for (int i = 0; i < tab[1]; i++)
				{
					Tabletka nowatab;
					plik >> nowatab;
					if (head->ttt->sprawdzczyrowne(head->ttt, nowatab))
						return false;

					head->ttt->dodaj(head->ttt, nowatab);
					
				}
				for (int i = 0; i < tab[2]; i++)
				{
					Masc nowamasc;
					plik >> nowamasc;
					if (head->mmm->sprawdzczyrowne(head->mmm, nowamasc))
						return false;
					head->mmm->dodaj(head->mmm, nowamasc);
					
				}

			}
			plik.close();
			return true;


		}
	}
	void Menu::opcja6zapis(Listy*& head)
	{
		Komunikacja k;
		if (head)
		{
			std::ofstream plik;
			plik.open("baza.clv");
			if (plik.good())
			{
				if (head->sss)
					plik << "\n" << head->sss->liczliste(head->sss);
				else
					plik << "\n0";
				if (head->ttt)
					plik << "\n" << head->ttt->liczliste(head->ttt);
				else
					plik << "\n0";
				if (head->mmm)
					plik << "\n" << head->mmm->liczliste(head->mmm);
				else
					plik << "\n0";
				Lista<Syrop>* pomocs = head->sss;
				Lista<Tabletka>* pomoct = head->ttt;
				Lista<Masc>* pomocm = head->mmm;
				while (pomocs)
				{
					//zapis do pliku liczby przeciwskazan danego leku
					plik << "\n" << pomocs->lek.getwielkoscwek();
					plik << pomocs->lek;
					plik << std::endl;
					pomocs = pomocs->pNast;
				}
				while (pomoct)
				{
					plik << "\n" << pomoct->lek.getwielkoscwek();
					plik << pomoct->lek;
					plik << std::endl;
					pomoct = pomoct->pNast;
				}
				while (pomocm)
				{
					plik << "\n" << pomocm->lek.getwielkoscwek();
					plik << pomocm->lek;
					plik << std::endl;
					pomocm = pomocm->pNast;
				}
			}
			plik.close();
			k.komunikuj(26);


		}
	}
	void Menu::opcja7pokaz(Listy*& head)
	{
		std::cout << head << std::endl;
	}

	void Menu::wyswietl()
	{
		std::cout << "\n0.Koniec\n1.Wyszukaj lek\n2.Dodaj lek\n3.Zarezerwuj lek\n4.Edytuj stan leku w magazynie\n"
			<< "5.Wczytaj z pliku\n6.Zapisz do pliku\n7.Wyswietl cala baze\n";
	}

	bool Menu::wybrana(int wybor, Listy*& head)
	{

		if (wybor == 0)
			return false;
		else if (wybor == 1)
		{
			if (!opcja1szukaj(head))
				return false;
		}
		else if (wybor == 2)
		{
			if (!opcja2dodaj(head))
				return false;
		}
		else if (wybor == 3)
		{
			opcja3rezerwuj(head);
		}

		else if (wybor == 4)
		{
			opcja4zmienstan(head);
		}

		else if (wybor == 5)
		{
			opcja5odczyt(head);
		}

		else if (wybor == 6)
		{
			opcja6zapis(head);

		}
		else if (wybor == 7)
		{
			opcja7pokaz(head);

		}

		else if (wybor == 9)
		{
			return 0;
		}
	}

