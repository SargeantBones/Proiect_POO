#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include <cmath>
#include<iomanip>
#include "Ecuatie.h"
#include "Separator.h"
#include "Calculator.h"
#include "Verificator.h"
#include "Verifica.h"
#include "Fisier.h"
#include "Rezultat.h"
#include<fstream>

using namespace std;

int main()
{

	//test//
	cout << "VA MULTUMIM PENTRU CA A-TI ALES SA FOLOSIT CALC-SCRIPT VER 0.1.";
	cout << endl<< "INTRODUCETI ECUATIA PE CARE O DORITI SA O CALCULATI.DACA DORIT SA IESITI DIN PROGRAM, TASTATI 'EXIT' "<<endl;
	
	Ecuatie ecuatie("Ecuatie Nedefinita");
	Separator ecuatieSeparata;
	Calculator* calc;
	Fisier fis;
	Rezultat rez;

	string copie, copie2, iesire, fisier;
	double* numere = nullptr;
	char* semne = nullptr;
	int n, m, verificare, dorinta = 0, dorintaBin = 0;
	double rezultat;

	Verificator* v1 = nullptr;
	Verifica v2;

	while (ecuatie != "EXIT")
	{
		dorinta = 0;
		cout << endl << "DORITI SA FOLOSITI O ECUATIE DE LA TASTATURA(1) SAU DINTR-UN FISIER(2): ";
		while (dorinta != 1 && dorinta != 2)
		{
			cin >> dorinta;
			if (dorinta != 1 && dorinta != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
		}

		// DACA UTILIZATORUL DORIESTE SA CITEASCA DE LA TASTATURA //
		if (dorinta == 1)
		{
			dorintaBin = 0;
			cout << endl << "DORITI SA VA FOLOSITI DE UN REZULTAT ANTERIOR ? TASTATI 1 PENTRU DA, SI 2 PENTRU NU: ";

			while (dorintaBin != 1 && dorintaBin != 2)
			{
				cin >> dorintaBin;
				if (dorintaBin != 1 && dorintaBin != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
			}
			// DACA UTILIZATORUL DORESTE SA SE FOLOSEASCA DE UN REZULTAT TRECUT //
			if (dorintaBin == 1)
			{
				rezultat = fis.citireBin();

				copie2 = to_string(rezultat);
			}
		
			if (dorintaBin == 1)
			{
				cout << endl << "ECUATIE: ";
				cout << rezultat;
			}
		}
		
		
		if (dorinta == 1)
		{
			if(dorintaBin != 1)cout << endl << "ECUATIE: ";
			cin >> ecuatie;
		}

		if (ecuatie == "EXIT") cout << "MULTUMIM DE VIZITA!";
		else
		{
			// COPIE PRIMESTE VALOAREA ECUATIEI CARE ESTE TRANSFERATA IN ECUATIE SEPARATA //

			if(dorinta == 1)copie = ecuatie.getEcuatie();
			else
			{
				copie = fis.citireText();

				cout << endl << "ECUATIE: " << copie;
				ecuatie.setCopie(copie);
				ecuatie.setEcuatie();

				copie = ecuatie.getEcuatie();
			}
			if (dorintaBin == 1) copie = copie2 + copie;

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

				calc = new Calculator();
				calc->setNumere(numere, n);
				calc->setSemne(semne);

				// SE VERIFICA VALIDITATEA ECUATIEI //

				v2.setNumere(numere, n);
				v2.setSemne(semne);

				v1 = &v2;

				verificare = v1->verif();
				if (verificare == 0)cout << "ECUATIE INCORECTA INCERCATI DIN NOU";
				else
				{
					// UTILIZATORUL ALEGE DACA VREA CA REZULTATUL SA FIE AFISAT DIRECT SAU PRIN INTERMEDIUL UNUI FISIER TEXT //

					dorinta = 0;

					rez.setNumere(numere, n);
					rez.setSemne(semne);

					rez.setRezultat();
					
					calc = &rez;

					fis.setRezultat(calc->getRezultat());
					cout << endl << "DORITI CA REZULTATUL SA FIE AFISAT INTR-UN FISIER TEXT (1), SAU IN CONSOLA (2): ";
						while (dorinta != 1 && dorinta != 2)
						{
							cin >> dorinta;
							if (dorinta != 1 && dorinta != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
						}
						if (dorinta == 2) {
							cout << "REZULTAT: ";
							calc->printareRezultat();
						}
						else fis.scriereText();

						dorinta = 0;

						// SALVAM REZULTATELE IN FISIER BINAR DUPA DORINTA UTIILIZATORULUI //

						cout << endl << "DORITI SA SALVATI REZULATUL ECUATIEI INTR-UN FISIER BINAR PENTRU A FI UTILIZAT MAI TARZIU ? TASTATI 1 PENTRU DA, SI 2 PENTRU NU: ";
							while (dorinta != 1 && dorinta != 2)
							{
								cin >> dorinta;
								if (dorinta != 1 && dorinta != 2) cout << endl << "NU EXISTA ACEASTA OPTIUNE INCERCATI DIN NOU: ";
							}
							if (dorinta == 1)fis.scriereBin();

						dorinta = 0;
				}

				delete[] semne;
				delete[] numere;
			}
		}
	}

	return 0;
}