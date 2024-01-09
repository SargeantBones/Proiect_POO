#pragma once
#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cmath>
#include"Calculator.h"

using namespace std;

class Rezultat : public Calculator
{
	double rezultat;

public:

	void setRezultat()
	{
		rezultat = this->Calcul();
	}

	double getRezultat()
	{
		return this->rezultat;
	}

	void printareRezultat()
	{
		cout << setprecision(15) << this->rezultat;
	}


};
