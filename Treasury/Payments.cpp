#include "Payments.h"
#define MIN_ANNUAL 33600

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
	}

	person.incrementAllIncomesSettled(earnings);
	person.incrementAllPayments(payment);
	return payment;
}