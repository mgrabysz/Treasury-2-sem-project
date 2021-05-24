#include "Calculator.h"

void Calculator::callAllPayments(Person& person) noexcept
{
	
	for (auto j = person.getContracts().begin(); j != person.getContracts().end(); ++j)
	{
		for (auto i = payments.begin(); i != payments.end(); ++i)
		{
			Contract con = *j;
			(*i)->calculate(person, con);
		}
	}
}

void Calculator::addPayment(Payment&  newPay) noexcept 
{
//payments.append(newPay);
}
