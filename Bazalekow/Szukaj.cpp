#include <vector>
#include "Szukaj.h"


	 std::vector<Lek*> Szukaj::szuk(Listy* head, std::string nazwa)
	{

		Listy pomoc = *head;
		std::vector <Lek*> leki;
		while (pomoc.sss)
		{
			if (pomoc.sss->lek.getnazwa() == nazwa)
			{
				leki.push_back(&(pomoc.sss->lek));
			}

			pomoc.sss = pomoc.sss->pNast;


		}
		while (pomoc.ttt)
		{
			if (pomoc.ttt->lek.getnazwa() == nazwa)
			{
				leki.push_back(&(pomoc.ttt->lek));
			}

			pomoc.ttt = pomoc.ttt->pNast;

		}
		while (pomoc.mmm)
		{
			if (pomoc.mmm->lek.getnazwa() == nazwa)
			{
				leki.push_back(&(pomoc.mmm->lek));
			}

			pomoc.mmm = pomoc.mmm->pNast;


		}
		return leki;
	}

	std::vector <Lek*> Szukpocenie::szuk(Listy* head, double cenamin, double cenamax)
	{

		Listy pomoc = *head;
		std::vector <Lek*> leki;
		while (pomoc.sss)
		{
			if (pomoc.sss->lek.getcena() > cenamin&& pomoc.sss->lek.getcena() < cenamax)
			{
				leki.push_back(&(pomoc.sss->lek));

			}

			pomoc.sss = pomoc.sss->pNast;
		}
		while (pomoc.ttt)
		{
			if (pomoc.ttt->lek.getcena() > cenamin&& pomoc.ttt->lek.getcena() < cenamax)
			{
				leki.push_back(&(pomoc.ttt->lek));

			}

			pomoc.ttt = pomoc.ttt->pNast;


		}
		while (pomoc.mmm)
		{
			if (pomoc.mmm->lek.getcena() > cenamin&& pomoc.mmm->lek.getcena() < cenamax)
			{
				leki.push_back(&(pomoc.mmm->lek));


			}

			pomoc.mmm = pomoc.mmm->pNast;


		}
		return leki;



	}

	std::vector<Lek*> Szukzamiennik::szuk(Listy* head, std::string substancja)
	{
		Listy pomoc = *head;
		std::vector<Lek*> leki;
		while (pomoc.sss)
		{

			if (pomoc.sss->lek.getsub() == substancja)
			{
				leki.push_back(&(pomoc.sss->lek));
			}

			pomoc.sss = pomoc.sss->pNast;


		}
		while (pomoc.ttt)
		{
			if (pomoc.ttt->lek.getsub() == substancja)
			{
				leki.push_back(&(pomoc.ttt->lek));
			}

			pomoc.ttt = pomoc.ttt->pNast;

		}
		while (pomoc.mmm)
		{
			if (pomoc.mmm->lek.getsub() == substancja)
			{
				leki.push_back(&(pomoc.mmm->lek));
			}

			pomoc.mmm = pomoc.mmm->pNast;
		}
		return leki;



	}

	std::vector<Lek*> Szukporef::szuk(Listy* head, int ref)
	{
		Listy pomoc = *head;
		std::vector<Lek*> leki;
		while (pomoc.sss)
		{

			if (pomoc.sss->lek.getref() == ref)
			{
				leki.push_back(&(pomoc.sss->lek));
			}

			pomoc.sss = pomoc.sss->pNast;


		}
		while (pomoc.ttt)
		{
			if (pomoc.ttt->lek.getref() == ref)
			{
				leki.push_back(&(pomoc.ttt->lek));
			}

			pomoc.ttt = pomoc.ttt->pNast;

		}
		while (pomoc.mmm)
		{
			if (pomoc.mmm->lek.getref() == ref)
			{
				leki.push_back(&(pomoc.mmm->lek));
			}

			pomoc.mmm = pomoc.mmm->pNast;
		}
		return leki;



	}

