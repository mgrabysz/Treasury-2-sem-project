#include "Person.h"

void Person::addContract(Contract contr)
{
	allPayments += contr.value;
	contracts.append(contr);
}

void Person::delContract(Contract contr)
{
	auto iter = contracts.begin();
	while (iter != nullptr)
	{
		if (*iter == contr)
		{
			allPayments -= contr.value;
			allIncomesSettled += contr.value;
			contracts.remove(iter);
		}
		iter++;
	}
}

void Person::addContr(Contract contr)
{
	addContract(contr);
}

void Person::delContr(Contract contr)
{
	delContract(contr);
}

Person::Person(std::string nam, std::string surnam, int ag)
{
	name = nam;
	surname = surnam;
	age = ag;
}