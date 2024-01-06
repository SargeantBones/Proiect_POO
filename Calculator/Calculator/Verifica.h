#pragma once

#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cmath>
#include "Verificator.h"

using namespace std;

class Verifica : public Verificator
{
	public:
		int verif()
		{
			int verif = 1;
			int ct = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0;
			for (int i = 0; i < noSemne; i++)
			{
				if (strchr("+-*/#^", this->semne[i]) != 0)ct++;
				if (strchr("+-/*^#()[]", this->semne[i]) == 0)ct5++;
				if (semne[i] == '(')ct1++;
				else if (semne[i] == ')')ct2++;
				else if (semne[i] == '[')ct3++;
				else if (semne[i] == ']')ct4++;
			}

			if (ct != noNumber - 1)verif = 0;
			if (ct1 != ct2 || ct3 != ct4) verif = 0;
			if (ct5 != 0)verif = 0;
			return verif;
		}

};