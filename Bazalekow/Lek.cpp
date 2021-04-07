#include <vector>
#include "Lek.h"

	Lek::Lek()
	{

	}

	std::string Lek::getnazwa()
	{
		return nazwa;
	}
	double Lek::getcena()
	{
		return cena;
	}
	std::string Lek::getsub()
	{
		return substancja;
	}
	int Lek::getref()
	{
		return refundacja;
	}
	std::string Lek::gettyp()
	{
		return typ;
	}
	int Lek::getwielkoscwek()
	{
		return przeciwskazania.size();
	}
	bool Lek::rezerwuj(int ile)
	{
		if (ile > 0)
		{
			if (pozostalo - ile > 0 || pozostalo - ile == 0)
			{
				this->pozostalo -= ile;
				return true;
			}
			else return false;
		}
		else return false;

	}
	bool Lek::edytujstan(int ile)
	{
		
		if (pozostalo + ile > 0 || pozostalo + ile == 0)
		{
			this->pozostalo += ile;
			return true;
		}
		else return false;
	}


