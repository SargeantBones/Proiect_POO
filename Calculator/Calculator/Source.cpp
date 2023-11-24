#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include "Ecuatie.h"

using namespace std;

int main()
{
	cout << "Va multumim pentru ca a-ti ales sa folosit Calc-Scrip ver 0.1.";
	cout << endl<< "Introduceti ecuatia pe care o doriti sa o calculati.Daca dorit sa iesiti din program, tastati 'Exit' "<<endl;
	Ecuatie ecuatie("Ecuatie Nedefinita");

	cout << "Ecuatie: ";
	cin >> ecuatie;

	cout << "Rezultat: ";
	cout << ecuatie;

	while (ecuatie != "Exit")
	{
		//functii
		
		cout << endl << "Ecuatie: ";
		cin >> ecuatie;

		if (ecuatie == "Exit") cout << "Multumim de vizita!";
		else
		{
			cout << "Rezultat: ";
			cout << ecuatie;

		}
	}
	return 0;
}