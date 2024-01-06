#pragma once

#define CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cmath>
#include "Calculator.h"

using namespace std;

class Verificator : public Calculator
{
	public:
	virtual int verif() = 0;
};

