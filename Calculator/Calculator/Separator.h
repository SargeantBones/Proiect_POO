#pragma once
#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>


using namespace std;

class Separator
{
	int* numere = nullptr;
	char* ecuatie = nullptr;
	char* semne = nullptr;
	int noNumber = 0;
public:

	static char* copiereChar(const char* ecuatie)
	{
		if (ecuatie == nullptr) return nullptr;
		else
		{
			char* copie = new char[strlen(ecuatie) + 1];
			strcpy_s(copie, strlen(ecuatie) + 1, ecuatie);
			return copie;
		}
	}

	void setEcuatie(string copie)
	{
		delete this->ecuatie;
		this->ecuatie = copiereChar(copie.c_str());
	}
	string getEcuatie()
	{
		return string(this->ecuatie);
	}

	char* eliminareCaractere()
	{
		int k = 0;

		char* copie = new char[strlen(this->ecuatie) + 1];
		strcpy_s(copie, strlen(this->ecuatie) + 1, this->ecuatie);

		for (int i = 0; i < strlen(copie); i++)
		{
			if (strchr("0123456789 ", copie[i]) == 0 && strchr("0123456789", copie[i - 1] == ' '))
			{
				copie[i] = ' ';
				i--;
			}
			else
			if (strchr("0123456789 ", copie[i])==0)
			{
				for (int j = i; j < strlen(copie); j++)
				{
					copie[j] = copie[j + 1];
				}
				i--;
			}
		}
		for (int i = 0; i < strlen(copie); i++)
		{
			if (copie[i] == ' ' && copie[i + 1] == ' ')
			{
				for (int j = i + 1; j < strlen(copie); j++)
				{
					copie[j] = copie[j + 1];
				}
				i--;
			}
		}

		while (copie[0] == ' ')
		{
			for (int j = 0; j < strlen(copie); j++)
			{
				copie[j] = copie[j + 1];
			}
		}
		int j = strlen(copie) - 1;
		while (copie[j] == ' ')
		{
			if (copie[j - 1] != ' ') copie[j] = '\0';
			j--;
		}
		for (int i = 0; i < strlen(copie); i++)
		{
	
			if (copie[i] == ' ')k++;
		}


		this->noNumber = k + 1;
		return copie;
	}

	void setNumere()
	{
		char* copie;
		copie = new char[strlen(this->eliminareCaractere()) + 1];
		copie = this->eliminareCaractere();

		delete[] this->numere;
		this->numere = new int[this->noNumber];

		int k = 0, p =-1 ,q, n;
		char* aux;

		for (int i = 0; i < strlen(copie); i++)
		{
			if (copie[i] != ' ' && p == -1)p = i;
			else if(copie[i] == ' ')
			{
				q = i;
				n = 0;
				for (int j = p; j < q; j++)
				{
					n = n * 10 + (int)copie[j] - 48;
				}
				this -> numere[k] = n;
				k++;
				p = -1;
			}
		}
		n = 0;
		for (int i = p; i < strlen(copie); i++)
		{
			n=n*10 + (int)copie[i] - 48;
		}
		this->numere[this->noNumber - 1] = n;
	}
	int* getNumere()
	{
		
		int* copie;
		copie = new int[this->noNumber];
		copie = this->numere;
		return copie;
	}
	
	~Separator()
	{
		delete[] this->numere;
		this->numere = nullptr;

		delete[] this->semne;
		this->semne = nullptr;

		delete this->ecuatie;
		this->ecuatie = nullptr;
	}
};