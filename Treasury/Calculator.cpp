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
		for (auto i = payments.begin(); i != payments.end(); ++i)
		{
			Contract con = **j;
			(*i)->calculate(person, con);
		}
	}
}

void Calculator::addPayment(Payment*  newPay) noexcept 
{

	payments.push(newPay);
}
