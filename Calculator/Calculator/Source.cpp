#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include <cmath>
#include<iomanip>
#include "Ecuatie.h"
#include "Separator.h"
#include "Calculator.h"
#include<fstream>

using namespace std;

int main()
{
	//test//
	cout << "VA MULTUMIM PENTRU CA A-TI ALES SA FOLOSIT CALC-SCRIPT VER 0.1.";
	cout << endl<< "INTRODUCETI ECUATIA PE CARE O DORITI SA O CALCULATI.DACA DORIT SA IESITI DIN PROGRAM, TASTATI 'EXIT' "<<endl;
	Ecuatie ecuatie("Ecuatie Nedefinita");
	Separator ecuatieSeparata;
	Calculator calc;
	string copie, copie2;
	string iesire;
	double* numere = nullptr;
	char* semne = nullptr;
	int n, m, verificare, dorinta = 0;
	string fisier;
	double rezultat;

	while (ecuatie != "EXIT")
	{
		cout << endl << "DORITI SA VA FOLOSITI DE UN REZULTAT ANTERIOR ? TASTATI 1 PENTRU DA, SI 2 PENTRU NU: ";
			
			while (dorinta != 1 && dorinta != 2)
			{
				cin >> dorinta;
				if (dorinta != 1 && dorinta != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
			}

			

			if (dorinta == 1)
			{
				cout << "INTRODUCETI NUMELE FISIERULUI DE UNDE DORITI SA OBTINETI REZULTATUL: ";

				if (cin.peek() == '\n')cin.ignore();
				getline(cin, fisier);

				ifstream g(fisier, ios::in | ios::binary);

				g.read((char*)&rezultat, sizeof(rezultat));

				g.close();

				copie2 = to_string(rezultat);
			}
		cout << endl << "ECUATIE: ";

		if (dorinta == 1) cout << rezultat;

		cin >> ecuatie;

		if (ecuatie == "EXIT") cout << "MULTUMIM DE VIZITA!";
		else
		{
			// COPIE PRIMESTE VALOAREA ECUATIEI CARE ESTE TRANSFERATA IN ECUATIESEPARATA //

			copie = ecuatie.getEcuatie();
			if (dorinta == 1) copie = copie2 + copie;

			ecuatieSeparata.setEcuatie(copie);

			// SE VERIFICA CALITATEA ECUATIEI //

			verificare = ecuatieSeparata.verificare();
			if (verificare == 0)cout << "ECUATIE INCORECTA INCERCATI DIN NOU";
			else
			{

				// SUNT SEPARATE NUMERELE SI SEMNELE IN DOUA SIRURI DIFERITE //

				ecuatieSeparata.setNumere();
				n = ecuatieSeparata.getNoNumber();

				numere = new double[n];
				numere = ecuatieSeparata.getNumere();

				ecuatieSeparata.setNoSemne();

				m = ecuatieSeparata.getNoSemne();
				semne = new char[m + 1];

				ecuatieSeparata.setSemne();
				semne = ecuatieSeparata.getSemne();

				// SE CALCULEAZA REZULTATUL CU AJUTORUL CELOR DOUA SIRURI //

				calc.setNumere(numere, n);
				calc.setSemne(semne);

				// SE VERIFICA VALIDITATEA ECUATIEI //

				verificare = calc.verificare();
				if (verificare == 0)cout << "ECUATIE INCORECTA INCERCATI DIN NOU";
				else
				{
					// UTILIZATORUL ALEGE DACA VREA CA REZULTATUL SA FIE AFISAT DIRECT SAU PRIN INTERMEDIUL UNUI FISIER TEXT //

					dorinta = 0;

					rezultat = calc.Calcul();
					cout << endl << "DORITI CA REZULTATUL SA FIE AFISAT INTR-UN FISIER TEXT (1), SAU IN CONSOLA (2): ";
						while (dorinta != 1 && dorinta != 2)
						{
							cin >> dorinta;
							if (dorinta != 1 && dorinta != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
						}
						if (dorinta == 2) cout << "REZULTAT: " << setprecision(15) << rezultat;
						else 
						{
							ofstream f;

							cout << endl << "NUMITI FISIERUL UNDE DORITI SA FIE AFISAT REZULTATUL ECUATIEI: ";
							if (cin.peek() == '\n')cin.ignore();
							getline(cin, fisier);

							f.open(fisier, ios::out | ios::trunc);

							f << rezultat;

							f.close();
						}
						dorinta = 0;

						// SALVAM REZULTATELE IN FISIER BINAR DUPA DORINTA UTIILIZATORULUI //

						cout << endl << "DORITI SA SALVATI REZULATUL ECUATIEI INTR-UN FISIER BINAR PENTRU A FI UTILIZAT MAI TARZIU ? TASTATI 1 PENTRU DA, SI 2 PENTRU NU: ";
							while (dorinta != 1 && dorinta != 2)
							{
								cin >> dorinta;
								if (dorinta != 1 && dorinta != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
							}
							if (dorinta == 1)
							{
								cout << endl << "NUMITI FISIERUL UNDE DORITI SA FIE SALVAT REZULTATUL ECUATIEI: ";
								if (cin.peek() == '\n')cin.ignore();
								getline(cin, fisier);

								ofstream g(fisier, ios::out | ios::binary);
								g.write((char*)&rezultat, sizeof(rezultat));

								g.close();
								
							}

						dorinta = 0;
				}

				delete[] semne;
				delete[] numere;
			}
		}
	}

	return 0;
}