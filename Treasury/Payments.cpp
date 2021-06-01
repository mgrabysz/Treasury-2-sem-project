#include "Payments.h"
#define MIN_ANNUAL 3360000 // 33600.00 PLN
#define TAX_TRESHOLD 8552800 // 85528.00 PLN


int Retirement::calculate(Person* person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	switch (contract.type) {
	case praca:
		payment = earnings * 0.0976;
		break;
	case zlecenie:
		if (person->getAllIncomesSettled() < MIN_ANNUAL && person->getAge() > 26)
			payment = earnings * 0.0976;
		break;
	}

	person->incrementAllIncomesSettled(earnings);
	person->incrementAllPayments(payment);	
	person->getDetailsPtr().retirement += payment;

	return payment;
}

int Pension::calculate(Person* person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	switch (contract.type) {
	case praca:
		payment = earnings * 0.015;
		break;
	case zlecenie:
		if (person->getAllIncomesSettled() < MIN_ANNUAL && person->getAge() > 26)
			payment = earnings * 0.015;
		break;
	}

	person->incrementAllIncomesSettled(earnings);
	person->incrementAllPayments(payment);
	person->getDetailsPtr().pension += payment;

	return payment;
}

int Health::calculate(Person* person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	switch (contract.type) {
	case praca:
		payment = earnings * 0.09;
		break;
	case zlecenie:
		if (person->getAge() > 26)
			payment = earnings * 0.09;
		break;
	}

	person->incrementAllIncomesSettled(earnings);
	person->incrementAllPayments(payment);
	person->getDetailsPtr().health += payment;

	return payment;
}

int Illness::calculate(Person* person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	if (contract.type == praca) {
		payment = earnings * 0.0245;
	}

	person->incrementAllIncomesSettled(earnings);
	person->incrementAllPayments(payment);
	person->getDetailsPtr().illness += payment;

	return payment;
}

int Tax::calculate(Person* person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	if (person->getAge() > 26)
		payment = taxWithTreshold(earnings);
	else
	{
		if (contract.type == dzielo)
			payment = taxWithTreshold(earnings);
		else // praca || zlecenie
		{
			if (earnings > TAX_TRESHOLD)
			{
				int taxationBase = earnings - TAX_TRESHOLD;
				payment = taxationBase * 0.32; // robbery af 
			}
		}
	}

	person->incrementAllIncomesSettled(earnings);
	person->incrementAllPayments(payment);
	person->getDetailsPtr().tax += payment;

	return payment;
}

int Tax::taxWithTreshold(int const earnings)
// auxilary function to calculate tax in normal situation
{
	int tax;

	if (earnings > TAX_TRESHOLD)
	{
		int overTresholdBase = earnings - TAX_TRESHOLD;
		tax = TAX_TRESHOLD * 0.17 + overTresholdBase * 0.32;
	}
	else
	{
		tax = earnings * 0.17;
	}

	return tax;
}