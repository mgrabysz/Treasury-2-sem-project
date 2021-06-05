#include "Calculator.h"

Calculator::Calculator() noexcept
{
	payments.push(new Retirement());
	payments.push(new Pension());
	payments.push(new Health());
	payments.push(new Illness());
	payments.push(new Tax());
}

void Calculator::callAllPayments(Person* person) noexcept
{
	
	for (auto j = person->getContracts().begin(); j != person->getContracts().end(); ++j)
	{
		Contract con = *j;

		for (auto i = payments.begin(); i != payments.end(); ++i)
		{
			(*i)->calculate(person, con);
		}

		int value = con.value;
		person->incrementAllIncomesSettled(value);
	}
}

void Calculator::addPayment(Payment* newPay) noexcept 
{

	payments.push(newPay);
}
