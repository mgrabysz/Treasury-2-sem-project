#pragma once

#include "Person.h"

class Payment
	// virtual base class for all payments
{
public:
	virtual int calculate(Person& person, Contract& const contract) = 0;
	/* This function modifies person attributes: allIncomesSettled and allPayments
	Contract remains unchanged
	Function returns value of the payment added to person.allPayments (not necessary,
	but may be helpful) */
};

class Retirement :public Payment
	// pension contribution (pol.: sk�adka emerytalna)
{
public:
	virtual int calculate(Person& person, Contract& const contract);
};

class Pension :public Payment
	// disablement pension (pol.: sk�adka rentowa)
{
public:
	virtual int calculate(Person& person, Contract& const contract);
};

class Tax :public Payment
	// income tax (pol.: podatek dochodowy)
{
public:
	virtual int calculate(Person& person, Contract& const contract);
};

class Health :public Payment
	// Health insurance (pol.: sk�adka zdrowotna)
{
public:
	virtual int calculate(Person& person, Contract& const contract);
};

class Illness :public Payment
	// Another health insurance (pol.: sk�adka chorobowa, nawet nie wiem jak to przet�umaczy�)
{
public:
	virtual int calculate(Person& person, Contract& const contract);
};