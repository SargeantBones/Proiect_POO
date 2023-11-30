#pragma once
#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>


using namespace std;

class Calculator
{
	char* semne = nullptr;
	float* numere = nullptr;
	int noNumber = 0;
	int noSemne = 0;
public:

	void setNoNumber(int n)
	{
		this->noNumber = n;
	}
	int getNoNumber()
	{
		return this->noNumber;
	}

	void setNoSemne(int n)
	{
		this->noSemne = n;
	}
	int getNoSemne()
	{
		return this->noSemne;
	}

	void setNumere(float* nr, int m)
	{
		this->numere = nullptr;
		this->numere = new float[m];
		for (int i = 0; i < m; i++)
		{
			this->numere[i] = nr[i];
		}
		this->setNoNumber(m);
	}
	float* getNumere()
	{

		float* copie;
		copie = new float[this->noNumber];
		copie = this->numere;
		return copie;
	}

	void setSemne(char* semn)
	{
		this->semne = nullptr;
		this->semne = new char[strlen(semn)+1];
		this->semne = semn;
		this->setNoSemne(strlen(semn));
	}
	char* getSemne()
	{
		char* copie;
		copie = new char[this->noSemne + 1];
		copie = this->semne;
		return copie;
	}

	Calculator()
	{

	}

	Calculator(int nrNum, int nrSemn, float* num, char* semn):noNumber(nrNum), noSemne(nrSemn)
	{
		this->setNumere(num, nrNum);
		this->setSemne(semn);
	}
	
	~Calculator()
	{
		delete[] this->numere;
		this->numere = nullptr;

		delete this->semne;
		this->semne = nullptr;
	}

};

void operator << (ostream& consola, Calculator& c)
{
	float* copie;
	copie = new float[c.getNoNumber()];
	copie = c.getNumere();
	for (int i = 0; i < c.getNoNumber(); i++)
	{
		consola << copie[i] << " ";
	}
	consola << endl;

	char* copie2;
	copie2 = new char[c.getNoSemne() + 1];
	copie2 = c.getSemne();
	consola << copie2 << endl;
}