#ifndef SYROP_H
#define SYROP_H
#include <iostream>
#include <vector>
#include <string>
#include "Lek.h"


class Syrop : public Lek
{
private:
	int pojemnosc = 0;
public:
	Syrop();
	Syrop(std::string n, double c, std::vector<std::string> prz, std::string sub, int poz, int poj, int ref, bool rec);
	
	friend std::ostream& operator <<(std::ostream& s, const Syrop leki);
	friend std::ostream& operator <<(std::ostream& s, const Syrop* leki);
	friend std::istream& operator >>(std::istream& s, Syrop& leki);
	//leki sa takie same, kiedy maja te sama nazwe, substancje czynna, przeciwskazania i pojemnosc
	bool operator ==(const Syrop& syr);
	bool operator !=(const Syrop& syr);
};
#endif
