#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include <cmath>
#include<iomanip>
#include "Ecuatie.h"
#include "Separator.h"
#include "Calculator.h"

using namespace std;

int main()
{
	cout << "Va multumim pentru ca a-ti ales sa folosit Calc-Scrip ver 0.1.";
	cout << endl<< "Introduceti ecuatia pe care o doriti sa o calculati.Daca dorit sa iesiti din program, tastati 'Exit' "<<endl;
	Ecuatie ecuatie("Ecuatie Nedefinita");
	Separator ecuatieSeparata;
	Calculator calc;
	string copie;
	string iesire;
	Calculator copi;
	double* numere = nullptr;
	char* semne = nullptr;
	int n, m;
	int verificare;


	while (ecuatie != "Exit")
	{
		cout << endl << "Ecuatie: ";
		cin >> ecuatie;

		if (ecuatie == "Exit") cout << "Multumim de vizita!";
		else
		{
			copie = ecuatie.getEcuatie();
			ecuatieSeparata.setEcuatie(copie);

			ecuatieSeparata.setNumere();
			n = ecuatieSeparata.getNoNumber();

			numere = new double[n];
			numere = ecuatieSeparata.getNumere();

			ecuatieSeparata.setNoSemne();

			m = ecuatieSeparata.getNoSemne();
			semne = new char[m + 1];

			ecuatieSeparata.setSemne();
			semne = ecuatieSeparata.getSemne();


			calc.setNumere(numere, n);
			calc.setSemne(semne);

			verificare = calc.verificare();
			if (verificare == 0)cout << "ECUATIE INCORECTA INCERCATI DIN NOU";
			else
			{
				cout << "REZULTAT: " << setprecision(20) << calc.Calcul();
			}
			
			delete semne;
			delete[] numere;
		}
	}

	return 0;
}