#ifndef LISTY_H
#define LISTY_H

#include "Syrop.h"
#include "Tabletka.h"
#include "Masc.h"



/**Szablon listy dla list Tabletek, Syropow i Masci*/
template <class T>
class Lista
{
public:
	T lek;
	Lista* pNast = nullptr;

	Lista()
	{
		ilewliscie++;
	}
	Lista(T lek1, Lista* nast)
	{
		lek = lek1;
		pNast = nast;
	}

	bool sprawdzczyrowne(Lista* head, const T b)
	{
		while (head)
		{
			if (head->lek == b)
			{
				return true;
			}
			head = head->pNast;
		}
		return false;
	}
	//Zlicza elementy w liscie
	int liczliste(Lista* head)
	{
		if (!head)
			return 0;
		else
			return(1 + liczliste(head->pNast));
	}

	void dodaj(Lista*& head, T lek1)
	{
		head = new Lista(lek1, head);
	}
	

	friend std::ostream& operator <<(std::ostream& s, Lista* head)
	{
		Lista* pomoc = head;
		while (pomoc)
		{
			s << pomoc->lek;
			s << std::endl;
			pomoc = pomoc->pNast;
		}
		return s;
	}
	~Lista()
	{
		if (pNast)
		{
			delete pNast;
		}
	}
};
struct Listy
{
	Lista<Syrop>* sss = nullptr;
	Lista<Tabletka>* ttt = nullptr;
	Lista <Masc>* mmm = nullptr;

	friend std::ostream& operator <<(std::ostream& s, Listy*& head);

	~Listy();
};


#endif
