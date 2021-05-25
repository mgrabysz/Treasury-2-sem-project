#include "Payments.h"
#define MIN_ANNUAL 3360000 // 33600.00 PLN

int Retirement::calculate(Person& person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	switch (contract.type) {
	case praca:
		payment = earnings * 0.0976;
		break;
	case zlecenie:
		if (person.getAllIncomesSettled() < MIN_ANNUAL && person.getAge() > 26)
			payment = earnings * 0.0976;
		break;
	}

	person.incrementAllIncomesSettled(earnings);
	person.incrementAllPayments(payment);

	return payment;
}

int Pension::calculate(Person& person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	switch (contract.type) {
	case praca:
		payment = earnings * 0.015;
		break;
	case zlecenie:
		if (person.getAllIncomesSettled() < MIN_ANNUAL && person.getAge() > 26)
			payment = earnings * 0.015;
		break;
	}

	person.incrementAllIncomesSettled(earnings);
	person.incrementAllPayments(payment);

	return payment;
}

int Health::calculate(Person& person, Contract& contract)
{
	int payment = 0;
	int earnings = contract.value;

	switch (contract.type) {
	case praca:
		payment = earnings * 0.09;
		break;
	case zlecenie:
		if (person.getAge() > 26)
			payment = earnings * 0.09;
		break;
	}

	person.incrementAllIncomesSettled(earnings);
	person.incrementAllPayments(payment);

	return payment;
}