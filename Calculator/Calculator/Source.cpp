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

	float* numere = nullptr;
	char* semne = nullptr;
	int n, m;



	while (ecuatie != "Exit")
	{
		//functii
		
		cout << endl << "Ecuatie: ";
		cin >> ecuatie;

		if (ecuatie == "Exit") cout << "Multumim de vizita!";
		else
		{
			// NUMERE PRIMESTE VECTORU DE NUMERE DIN ECUATIE //
			copie = ecuatie.getEcuatie();
			ecuatieSeparata.setEcuatie(copie);

			ecuatieSeparata.setNumere();
			n = ecuatieSeparata.getNoNumber();

			numere = new float[n];
			numere = ecuatieSeparata.getNumere();

			// SEMNE PRIMESTE SIRUL DE CARACTERE CE CONTIN SEMNELE ARITMETICE //
			ecuatieSeparata.setNoSemne();

			m = ecuatieSeparata.getNoSemne();
			semne = new char[m + 1];

			ecuatieSeparata.setSemne();
			semne = ecuatieSeparata.getSemne();
			
			cout << ecuatieSeparata;
			delete semne;
			delete[] numere;
		}
	}

	return 0;
}