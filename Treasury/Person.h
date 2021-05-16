#pragma once

#include <string.h>
#include "Contract.h"
#include "TwoWayList.h"
#include "Calculator.h"

class Person
{
private:
	std::string name;
	std::string surname;
	int age;
	int all_payments = 0;
	int all_incomes_settled = 0;
	TwoWayList<Contract> contracts;
	void add_contract(Contract contr);
	void del_contract(Contract contr);
public:
	void add_contr(Contract contr); // for testing
	void del_contr(Contract contr); // for testing
	Person(std::string nam, std::string surnam, int ag);
};
