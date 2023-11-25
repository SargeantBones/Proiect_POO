#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include "Ecuatie.h"
#include "Separator.h"

using namespace std;

int main()
{
	cout << "Va multumim pentru ca a-ti ales sa folosit Calc-Scrip ver 0.1.";
	cout << endl<< "Introduceti ecuatia pe care o doriti sa o calculati.Daca dorit sa iesiti din program, tastati 'Exit' "<<endl;
	Ecuatie ecuatie("Ecuatie Nedefinita");
	Separator ecuatieSeparata;
	string copie;

	while (ecuatie != "Exit")
	{
		//functii
		
		cout << endl << "Ecuatie: ";
		cin >> ecuatie;

		if (ecuatie == "Exit") cout << "Multumim de vizita!";
		else
		{
			copie = ecuatie.getEcuatie();
			ecuatieSeparata.setEcuatie(copie);

			ecuatieSeparata.setNumere();
			//ecuatieSeparata.getNumere();
		}
	}

	return 0;
}