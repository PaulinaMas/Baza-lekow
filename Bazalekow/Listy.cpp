#include <iostream>
#include "Listy.h"



	 std::ostream& operator <<(std::ostream& s, Listy*& head)
	{
		 if (head->sss->liczliste(head->sss) == 0 && head->ttt->liczliste(head->ttt) == 0 && head->mmm->liczliste(head->mmm) == 0)
			 s << "Baza pusta" << std::endl;
		 else
		 {
			 s << head->sss << std::endl;
			 s << head->ttt << std::endl;
			 s << head->mmm << std::endl;
		 }
		return s;
	}
	Listy::~Listy()
	{
		delete sss;
		delete ttt;
		delete mmm;
	}

