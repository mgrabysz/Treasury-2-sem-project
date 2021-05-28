#pragma once

#include "Person.h"

class Payment
	// virtual base class for all payments
{
public:
	virtual int calculate(Person* person, Contract& contract) = 0;
	/* This function modifies person attributes: allIncomesSettled and allPayments
	Contract remains unchanged
	Function returns value of the payment added to person.allPayments (not necessary,
	but may be helpful) */
};

class Retirement :public Payment
	// pension contribution (pol.: sk³adka emerytalna)
{
public:
	Retirement() = default;
	virtual int calculate(Person* person, Contract& contract);
};
class Pension :public Payment
	// disablement pension (pol.: sk³adka rentowa)
{
public:
	virtual int calculate(Person* person, Contract& contract);
};

class Health :public Payment
	// Health insurance (pol.: sk³adka zdrowotna)
{
public:
	virtual int calculate(Person* person, Contract& contract);
};

class Illness :public Payment
	// Another health insurance (pol.: sk³adka chorobowa, nawet nie wiem jak to przet³umaczyæ)
{
public:
	virtual int calculate(Person* person, Contract& contract);
};

class Tax :public Payment
	// income tax (pol.: podatek dochodowy)
{
public:
	virtual int calculate(Person* person, Contract& contract);
	int taxWithTreshold(int const earnings);
};
