#include "Calculator.h"

void Calculator::callAllPayments(Person& person) noexcept
{
	for (auto i = payments.begin(); i != payments.end(); ++i)
	{
		(*i); //powinno byc .funkcjaKtoraLiczyDanaSkladke chyba .calculate(person)
	}
}
