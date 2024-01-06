#pragma once
#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string simbolRetinut = "";

class Calculator
{
protected:
	char* semne = nullptr;
	double* numere = nullptr;
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

	void setNumere(double* nr, int m)
	{
		this->numere = nullptr;
		this->numere = new double[m];
		for (int i = 0; i < m; i++)
		{
			this->numere[i] = nr[i];
		}
		this->setNoNumber(m);
	}
	double* getNumere()
	{

		double* copie;
		copie = new double[this->noNumber];
		copie = this->numere;
		return copie;
	}

	void setSemne(char* semn)
	{
		this->semne = nullptr;
		this->semne = new char[strlen(semn) + 1];
		strcpy_s(this->semne, strlen(semn) + 1, semn);
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

	Calculator(int nrNum, int nrSemn, double* num, char* semn) :noNumber(nrNum), noSemne(nrSemn)
	{
		this->setNumere(num, nrNum);
		this->setSemne(semn);
	}

	double subEcuatie(int& i, int& j, string& SimnbolStocat)
	{

		string test;
		double s = -1;
		double r = this->numere[i];
		i++;

		if (j != 0 && strchr("[(", this->semne[j - 1]) == 0) j++;
		else if (j == 0 && SimnbolStocat != " ")j++;
		else if (j == 0 || this->semne[j - 1] != '(' || this->semne[j - 1] != '[')
		{
			test = this->semne[j];
			if (test == SimnbolStocat)
			{
				if (strchr("*/^#", this->semne[j + 1]) != 0 && strchr("+-", this->semne[j]) != 0)j++;
				if (strchr("^#", this->semne[j + 1]) != 0 && strchr("*/", this->semne[j]) != 0)j++;
			}
		}

		if (this->semne[j] == ')' || this->semne[j] == ']')
		{
			j++;
			SimnbolStocat = this->semne[j];
			simbolRetinut = SimnbolStocat;
			return r;
		}
		else if (this->semne[j - 2] == ')' || this->semne[j - 2] == ']')
		{
			SimnbolStocat = this->semne[j];
			simbolRetinut = SimnbolStocat;
			return r;
		}

		if (this->semne[j] == '[' || this->semne[j] == '(')
		{
			i--;
			j++;
			if (this->semne[j] == '[')
			{
			
				s = parantezaPatrata(i, j);
			}
			else
			{
				s = parantezaRotunda(i, j);
			}
		}
		if (s != -1)
		{
			if (SimnbolStocat == "+") r = r + s;
			else if (SimnbolStocat == "-") r = r - s;
			else if (SimnbolStocat == "*") r = r * s;
			else if (SimnbolStocat == "/") r = r / s;
			else if (SimnbolStocat == "^") r = pow(r, s);
			else if (SimnbolStocat == "#") r = pow(r, 1.0 / s);
			return s;
		}

		if (this->semne[j] == '+' || this->semne[j] == '-')
		{

			while (strchr("*/^#([", this->semne[j + 1]) == 0 && this->semne[j] != ')' && this->semne[j] != ']')
			{
				if (this->semne[j] == '+') r = r + this->numere[i];
				else r = r - this->numere[i];
				i++;
				j++;
			}

			if (this->semne[j + 1] == '(' || this->semne[j + 1] == '[')
			{
				SimnbolStocat = this->semne[j];
				simbolRetinut = SimnbolStocat;
				j = j + 2;

				if (this->semne[j - 1] == '(')
				{
					if (SimnbolStocat == "+") r = r + parantezaRotunda(i, j);
					else if (SimnbolStocat == "-") r = r - parantezaRotunda(i, j);
				}
				else
				{
					if (SimnbolStocat == "*") r = r + parantezaPatrata(i, j);
					else if (SimnbolStocat == "-") r = r - parantezaPatrata(i, j);
				}
			}
		}
		else if (this->semne[j] == '*' || this->semne[j] == '/')
		{
			while (this->semne[j + 1] != '^' && this->semne[j + 1] != '#' && this->semne[j] != '+' && this->semne[j] != '-' && j < this->noSemne && this->semne[j + 1] != '(' && this->semne[j + 1] != '[' && this->semne[j] != ')' && this->semne[j] != ']')
			{
				if (this->semne[j] == '*') r = r * this->numere[i];
				else
				{
					if (this->numere[i] == 0)throw exception("EROARE");
					r = r / this->numere[i];
				}
				i++;
				j++;
			}

			if (this->semne[j + 1] == '(' || this->semne[j + 1] == '[')
			{
				SimnbolStocat = this->semne[j];
				j = j + 2;
				if (this->semne[j - 1] == '(')
				{
					if (SimnbolStocat == "*") r = r * parantezaRotunda(i, j);
					else if (SimnbolStocat == "/") r = r / parantezaRotunda(i, j);
					else if (SimnbolStocat == "+") r = r + parantezaRotunda(i, j);
					else if (SimnbolStocat == "-") r = r - parantezaRotunda(i, j);
					else if (SimnbolStocat == "^") r = pow(r, parantezaRotunda(i,j));
					else if (SimnbolStocat == "#") r = pow(r, 1.0 / parantezaRotunda(i, j));
				}
				else
				{
					if (SimnbolStocat == "*") r = r * parantezaPatrata(i, j);
					else if (SimnbolStocat == "/") r = r / parantezaPatrata(i, j);
					else if (SimnbolStocat == "+") r = r + parantezaPatrata(i, j);
					else if (SimnbolStocat == "-") r = r - parantezaPatrata(i, j);
					else if (SimnbolStocat == "^") r = pow(r, parantezaPatrata(i, j));
					else if (SimnbolStocat == "#") r = pow(r, 1.0 / parantezaPatrata(i, j));
				}
			}
		}
		else if (this->semne[j] == '#' || this->semne[j] == '^')
		{
			while (strchr("*/([", this->semne[j + 1]) == 0 && strchr("+-)]", this->semne[j + 1]) == 0)
			{
				if (this->semne[j] == '^') r = pow(r, this->numere[i]);
				else r = pow(r, 1 / this->numere[i]);
				i++;
				j++;
			}
			if (this->semne[j + 1] == '(' || this->semne[j + 1] == '[')
			{
				SimnbolStocat = this->semne[j];
				j = j + 2;
				if (this->semne[j - 1] == '(')
				{
					if (SimnbolStocat == "*") r = r * parantezaRotunda(i, j);
					else if (SimnbolStocat == "/") r = r / parantezaRotunda(i, j);
					else if (SimnbolStocat == "+") r = r + parantezaRotunda(i, j);
					else if (SimnbolStocat == "-") r = r - parantezaRotunda(i, j);
					else if (SimnbolStocat == "^") r = pow(r, parantezaRotunda(i, j));
					else if (SimnbolStocat == "#") r = pow(r, 1.0 / parantezaRotunda(i, j));
				}
				else
				{
					if (SimnbolStocat == "*") r = r * parantezaPatrata(i, j);
					else if (SimnbolStocat == "/") r = r / parantezaPatrata(i, j);
					else if (SimnbolStocat == "+") r = r + parantezaPatrata(i, j);
					else if (SimnbolStocat == "-") r = r - parantezaPatrata(i, j);
					else if (SimnbolStocat == "^") r = pow(r, parantezaPatrata(i, j));
					else if (SimnbolStocat == "#") r = pow(r, 1.0 / parantezaPatrata(i, j));
				}
			}
		}

		if (this->semne[j] == ')' || this->semne[j] == ']')j++;
		{
			SimnbolStocat = this->semne[j];
			simbolRetinut = SimnbolStocat;
		}

		return r;
	}

	double parantezaRotunda(int& i, int& j)
	{
		double r = 0;
		string simbol;
		r = r + subEcuatie(i, j, simbol);
		simbol = simbolRetinut;
		while (i < this->noNumber && this->semne[j - 1] != ')')
		{
			if (simbol == "+") r = r + subEcuatie(i, j, simbol);
			else if (simbol == "-") r = r - subEcuatie(i, j, simbol);
			else if (simbol == "*") r = r * subEcuatie(i, j, simbol);
			else if (simbol == "/") r = r / subEcuatie(i, j, simbol);
			else if (simbol == "^") r = pow(r, subEcuatie(i, j, simbol));
			else if (simbol == "#") r = pow(r, 1.0 / subEcuatie(i, j, simbol));
		}
		if (strchr("*^/#", this->semne[j]) != 0)
		{
			if (simbol == "*") r = r * subEcuatie(i, j, simbol);
			else if (simbol == "/") r = r / subEcuatie(i, j, simbol);
			else if (simbol == "^") r = pow(r, subEcuatie(i, j, simbol));
			else if (simbol == "#") r = pow(r, 1.0 / subEcuatie(i, j, simbol));
		}
		return r;
	}

	double parantezaPatrata(int& i, int& j)
	{
		double r = 0;
		string simbol;
		if (this->semne[j] == '(')
		{
			j++;
			r = r + parantezaRotunda(i, j);
		}
		else r = r + subEcuatie(i, j, simbol);
		simbol = simbolRetinut;
		while (i < this->noNumber && this->semne[j - 1] != ']')
		{
			if (simbol == "+") r = r + subEcuatie(i, j, simbol);
			else if (simbol == "-") r = r - subEcuatie(i, j, simbol);
			else if (simbol == "*") r = r * subEcuatie(i, j, simbol);
			else if (simbol == "/") r = r / subEcuatie(i, j, simbol);
			else if (simbol == "^") r = pow(r, subEcuatie(i, j, simbol));
			else if (simbol == "#") r = pow(r, 1.0 / subEcuatie(i, j, simbol));
		}
		return r;
	}

	double Calcul()
	{
		double r = 0;
		int i = 0, j = 0;
		string simbol = " ";
		if (this->semne[j] == '[')
		{
			j++;
			r = r + parantezaPatrata(i, j);
		}
		else if (this->semne[j] == '(')
		{
			j++;
			r = r + parantezaRotunda(i, j);
		}
		else r = r + subEcuatie(i, j, simbol);
		simbol = simbolRetinut;
		while (i < this->noNumber && j < this->noSemne)
		{
			if (simbol == "+") r = r + subEcuatie(i, j, simbol);
			else if (simbol == "-") r = r - subEcuatie(i, j, simbol);
			else if (simbol == "*") r = r * subEcuatie(i, j, simbol);
			else if (simbol == "/") r = r / subEcuatie(i, j, simbol);
			else if (simbol == "^") r = pow(r, subEcuatie(i, j, simbol));
			else if (simbol == "#") r = pow(r, 1.0 / subEcuatie(i, j, simbol));
		}
		return r;
	}

	~Calculator()
	{
		delete[] this->numere;
		this->numere = nullptr;

		delete this->semne;
		this->semne = nullptr;
	
	}

	void operator = (const Calculator& c)
	{
		if (this != &c)
		{
			this->noNumber = c.noNumber;
			this->noSemne = c.noSemne;
			this->numere = nullptr;
			this->numere = new double[this->noNumber];
			for (int i = 0; i < this->noNumber; i++)
			{
				this->numere[i] = c.numere[i];
			}

			this->semne = nullptr;
			this->semne = new char[this->noSemne + 1];
			strcpy_s(this->semne, this->noSemne + 1, c.semne);
		}
	}

	Calculator operator + (double nr)
	{
		for (int i = 0; i < this->noNumber; i++)
		{
			this->numere[i] += nr;
		}
		return *this;
	}


};



void operator << (ostream& consola, Calculator& c)
{
	double* copie;
	copie = new double[c.getNoNumber()];
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

void operator >> (istream& consola, Calculator& c)
{
	int noSemne;
	cout << "Numar de semne: ";
	consola >> noSemne;
	char* semne;
	semne = new char[noSemne + 1];
	cout << "Semne";
	consola >> semne;
	c.setSemne(semne);

	int noNr;
	cout << "Numar de numere: ";
	consola >> noNr;
	double* nr;
	nr = new double[noNr];
	for (int i = 0; i < noNr; i++)
	{
		cout << "Numarul " << i + 1 << " : ";
		consola >> nr[i];
	}
	c.setNumere(nr, noNr);

}