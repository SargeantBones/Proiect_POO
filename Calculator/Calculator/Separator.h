#pragma once
#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>


using namespace std;

class Separator
{
	float* numere = nullptr;
	char* ecuatie = nullptr;
	char* semne = nullptr;
	int noNumber = 0;
	int noSemne = 0;
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

	void setNoNumber(int n)
	{
		this->noNumber = n;
	}
	int getNoNumber()
	{
		return this->noNumber;
	}

	void setNoSemne()
	{
		int k = 0;
		for (int i = 0; i < strlen(this->ecuatie); i++)
		{
			if (strchr("0123456789 ", this->ecuatie[i]) == 0)k++;
		}
		this->noSemne = k;
	}
	int getNoSemne()
	{
		return this->noSemne;
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
		int p = -1, q = -1, r = -1;
		for (int i = 0; i < strlen(copie); i++)
		{
			if (copie[i] != ' ')
			{
				if (p == -1) p = i;
				else if (q == -1) q = i;
				else if (r == -1) 
				{
					r = i;

					if(copie[q] == '-')
					{
						if (strchr("0123456789", copie[r]) == 0) copie[q] = ' ';
						if (strchr("0123456789)]", copie[p]) != 0)copie[q] = ' ';
					}

					p = q;
					q = r;
					r = -1;
					
				}
			}
		}
		for (int i = 0; i < strlen(copie); i++)
		{
			if (strchr("0123456789.- ", copie[i]) == 0 && strchr("0123456789", copie[i - 1])!=0)
			{
				copie[i] = ' ';
				i--;
			}
			else
			if (strchr("0123456789.- ", copie[i])==0)
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
			if ((copie[i] == ' ' && copie[i + 1] == ' ') || (copie[i] == '.' && copie[i + 1] == '.'))
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
	
			if (copie[i] == ' ' && copie[i-1] != '-')k++;
		}
		this->noNumber = k + 1;
		return copie;
	}

	void setNumere()
	{
		char* copie = nullptr;
		copie = new char[strlen(this->eliminareCaractere()) + 1];
		copie = this->eliminareCaractere();

		this->numere = nullptr;
		this->numere = new float[this->noNumber];

		int k = 0, p =-1 ,q, s =-1;
		float l = 0, n = 0;
		char* aux;

		for (int i = 0; i < strlen(copie); i++)
		{
			if (copie[i] != ' ' && copie[i] != '-' && p == -1)p = i;
			else if (copie[i] == '.' && s == -1)s = i;
			else if(copie[i] == ' ' && copie[i-1] != '-')
			{
				q = i;
				n = 0;
				if (s != -1)
				{
					l = 10;
					for (int j = p; j < s; j++)
					{
						n = n * 10 + (float)copie[j] - 48;
					}

					for (int j = s + 1; j < q; j++)
					{
						n = n + ((float)copie[j] - 48) / l;
						l = l * 10;
					}
				}
				else
				{
					for (int j = p; j < q; j++)
					{
						n = n * 10 + (float)copie[j] - 48;
					}
				}
				if (copie[p - 2] == '-' || copie[p - 1] == '-') n = n * -1;
				this -> numere[k] = n;
				k++;
				s = -1;
				p = -1;
			}
		}
		n = 0;
		for (int i = p; i < strlen(copie); i++)
		{
			n=n*10 + (int)copie[i] - 48;
		}
		if (copie[p - 2] == '-' || copie[p - 1] == '-') n = n * -1;
		this->numere[this->noNumber - 1] = n;
	}
	float* getNumere()
	{
		
		float* copie;
		copie = new float[this->noNumber];
		copie = this->numere;
		return copie;
	}

	char* eliminareNumere()
	{
		int k = 0, j = 0;

		for (int i = 0; i < strlen(this->ecuatie); i++)
		{
			if (strchr("0123456789. ", this->ecuatie[i]) == 0)k++;
		}

		int p = 0;
		if (this->ecuatie[0] == '-') p = 1;

		for (int i = 0; i < strlen(this->ecuatie); i++)
		{
			if (this->ecuatie[i] == '-')
			{
				if ((strchr("-+*/#^([", this->ecuatie[i - 2]) != 0) || (strchr("0123456789", this->ecuatie[i + 2]) == 0))k--;
			}
		}

		char* copie = new char[k+1];
		for (int i = p; i < strlen(this->ecuatie); i++)
		{
			if (strchr("+*/#^()[]", this->ecuatie[i]) != 0)
			{
					copie[j] = this->ecuatie[i];
					j++;
			}

			if (this->ecuatie[i] == '-')
			{
				if (strchr("0123456789])", this->ecuatie[i - 2]) != 0 && (strchr("0123456789", this->ecuatie[i + 2]) != 0))
				{
					copie[j] = this->ecuatie[i];
					j++;
				}
			}
		}
		cout << k;
		copie[k] = '\0';
		return copie;

	}

	void setSemne()
	{
		this->setNoSemne();
		this->semne = nullptr;
		this->semne = new char[this->noSemne + 1];
		this->semne = this->eliminareNumere();
	}
	char* getSemne()
	{
		char* copie;
		copie = new char[this->noSemne + 1];
		copie = this->semne;
		return copie;
	}

	Separator()
	{

	}
	Separator(string ecuatie)
	{
		setEcuatie(ecuatie);
		setNumere();
		setSemne();
	}


	~Separator()
	{
		delete[] this->numere;
		this->numere = nullptr;

		delete this->semne;
		this->semne = nullptr;

		delete this->ecuatie;
		this->ecuatie = nullptr;
	}

	float& operator [](int index)
	{
		if (index<0 || index > this->noNumber)throw exception("index incorect");
		else return this->numere[index];
	}
	explicit operator int()
	{
		return this->noNumber;
	}

};

void operator >> (istream& consola, Separator& s)
{
	string copie;
	getline(consola, copie);
	s.setEcuatie(copie);
	s.setSemne();
	s.setNumere();
}

void operator << (ostream& consola, Separator& s)
{
	float* copie;
	copie = new float[s.getNoNumber()];
	copie = s.getNumere();
	for (int i = 0; i < s.getNoNumber(); i++)
	{
		consola << copie[i] << " ";
	}
	consola << endl;

	char* copie2;
	copie2 = new char[s.getNoSemne()+1];
	copie2 = s.getSemne();
	consola << copie2 << endl;
}