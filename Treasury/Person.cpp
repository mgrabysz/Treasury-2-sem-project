#include "Person.h"

void Person::add_contract(Contract contr)
{
	all_payments += contr.value;
	contracts.append(contr);
}

void Person::del_contract(Contract contr)
{
	auto iter = contracts.begin();
	while (iter != nullptr)
	{
		if (*iter == contr)
		{
			all_payments -= contr.value;
			all_incomes_settled += contr.value;
			contracts.remove(iter);
		}
		iter++;
	}
}

void Person::add_contr(Contract contr)
{
	add_contract(contr);
}

void Person::del_contr(Contract contr)
{
	del_contract(contr);
}

Person::Person(std::string nam, std::string surnam, int ag)
{
	name = nam;
	surname = surnam;
	age = ag;
}