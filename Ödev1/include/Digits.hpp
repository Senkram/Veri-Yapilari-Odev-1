#ifndef DIGITS_HPP
#define DIGITS_HPP

#include <iostream>
using namespace std;

struct Digits
{
	int Digit;
	Digits *next;
	
	Digits(const int& Digit, Digits *next = NULL)
	{
		this->Digit = Digit;
		this->next = next;
	}
};

#endif