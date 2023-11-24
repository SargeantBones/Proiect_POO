#pragma once

#include<string>
#include<iostream>

using namespace std;

class Ecuatie
{
	char* ecuatie = nullptr;
	string copie = "";
	static const int DimensiuneMaximaEcuatie = 100;
public:
	static char* copiereChar(const char* ecuatie)
	{
		if (ecuatie == nullptr) return nullptr;
		else
		{
			char* copie = new char[strlen(ecuatie) + 1];
			strcpy_s(copie, strlen(ecuatie) + 1, ecuatie);
			return copie;
		}
	}
	void setEcuatie()
	{
			delete this->ecuatie;
			this->ecuatie = copiereChar(this->copie.c_str());
	}
	string getEcuatie()
	{
		return string(this->ecuatie);
	}

	void setCopie(const string cop)
	{
		if (cop.size() > DimensiuneMaximaEcuatie)
		{
			this->copie = "ECUATIE MAI MARI DE 100 DE CARACTERE NEPERMISA!";
		}
		else this->copie = cop;
	}
	
	string getCopie()
	{
		return this->copie;
	}

	Ecuatie()
	{

	}
	Ecuatie(string copie = "Ecuatie nedefinita") : copie(copie)
	{
		setEcuatie();
	}

};

int operator == (Ecuatie& ecuatie, string ecuatie2)
{
	if (ecuatie2 == ecuatie.getEcuatie()) return 1;
	else return 0;
}

int operator != (Ecuatie& ecuatie, string ecuatie2)
{
	if (ecuatie2 != ecuatie.getEcuatie()) return 1;
	else return 0;
}
void operator << (ostream& consola, Ecuatie& ecuatie)
{
	consola << ecuatie.getEcuatie();
	consola << endl;
}


void operator >> (istream& consola, Ecuatie& ecuatie)
{
	string copie;
	getline(consola, copie);
	ecuatie.setCopie(copie);

	ecuatie.setEcuatie();
}