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
	int allPayments = 0;
	int allIncomesSettled = 0;
	TwoWayList<Contract> contracts;
	void addContract(Contract contr);
	void delContract(Contract contr);
public:
	void addContr(Contract contr); // for testing
	void delContr(Contract contr); // for testing
	Person(std::string nam, std::string surnam, int ag);
};
