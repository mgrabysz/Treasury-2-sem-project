#include "Calculator.h"

Calculator::Calculator() noexcept
{
	payments.append(new Retirement());
	payments.append(new Pension());
	payments.append(new Health());
	payments.append(new Illness());
	payments.append(new Tax());
}

void Calculator::callAllPayments(Person* person) noexcept
{
	
	for (auto j = person->getContracts().begin(); j != person->getContracts().end(); ++j)
	{
		for (auto i = payments.begin(); i != payments.end(); ++i)
		{
			Contract con = *j;
			(*i)->calculate(person, con);
		}
	}
}

void Calculator::addPayment(Payment*  newPay) noexcept 
{

	payments.append(newPay);
}
