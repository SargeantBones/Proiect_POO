#pragma once

#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Fisier
{
	double rezultat;

public:

	void setRezultat(double rez)
	{
		this->rezultat = rez;
	}
	double getRezultat()
	{
		return this->rezultat;
	}

	string citireText()
	{
		string fisier, numar;

		ifstream f;

		cout << "SCRIETI NUMELE FISIERULUI DE UNDE DORITI SA EXTRAGETI ECUATIA: ";

		if (cin.peek() == '\n')cin.ignore();
		getline(cin, fisier);

		f.open(fisier, ios::in | ios::_Nocreate);

		while (!f.is_open())
		{
			cout << "FISIERUL PRECIZAT NU EXISTA, INCERCATI DIN NOU: ";

			if (cin.peek() == '\n')cin.ignore();
			getline(cin, fisier);

			f.open(fisier, ios::in | ios::_Nocreate);
		}

		getline(f, numar);

		f.close();

		return numar;
	}

	void scriereText()
	{
		string fisier;

		ofstream f;

		cout << endl << "NUMITI FISIERUL UNDE DORITI SA FIE AFISAT REZULTATUL ECUATIEI: ";
		if (cin.peek() == '\n')cin.ignore();
		getline(cin, fisier);

		f.open(fisier, ios::out | ios::trunc);

		f << this->rezultat;

		f.close();
		
	}

	double citireBin()
	{
		double rezultat;
		string fisier;

		cout << "INTRODUCETI NUMELE FISIERULUI DE UNDE DORITI SA OBTINETI REZULTATUL: ";

		if (cin.peek() == '\n')cin.ignore();
		getline(cin, fisier);

		ifstream g(fisier, ios::in | ios::binary | ios::_Nocreate);
		while (!g.is_open())
		{
			cout << "FISIERUL PRECIZAT NU EXISTA, INCERCATI DIN NOU: ";

			if (cin.peek() == '\n')cin.ignore();
			getline(cin, fisier);

			ifstream g(fisier, ios::in | ios::binary | ios::_Nocreate);
		}
		g.read((char*)&rezultat, sizeof(rezultat));

		g.close();

		return rezultat;

	}

	void scriereBin()
	{
		string fisier;

		cout << endl << "NUMITI FISIERUL UNDE DORITI SA FIE SALVAT REZULTATUL ECUATIEI: ";
		if (cin.peek() == '\n')cin.ignore();
		getline(cin, fisier);

		ofstream g(fisier, ios::out | ios::binary);
		g.write((char*)&this->rezultat, sizeof(this->rezultat));

		g.close();
	}
};