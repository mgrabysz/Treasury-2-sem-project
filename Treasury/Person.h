#pragma once

#include <string.h>
#include "Contract.h"
#include "TwoWayList.h"

class Person
{
private:
	std::string name;
	std::string surname;
	char age;
	int allPayments = 0;
	int allIncomesSettled = 0;
	TwoWayList<Contract> contracts;
	void addContract(Contract contr);
	void delContract(Contract contr);
public:
	std::string getName() const noexcept
	{
		return name;
	}

	std::string getSurname() const noexcept
	{
		return surname;
	}
	
	char getAge() const noexcept
	{
		return age;
	}

	int getAllPayments() const noexcept
	{
		return allPayments;
	}

	int getAllIncomesSettled() const noexcept
	{
		return allIncomesSettled;
	}

	TwoWayList<Contract> getContracts() const noexcept
	{
		return contracts;
	}

	void setName(std::string nam)
	{
		name = nam;
	}

	void setSurname(std::string surnam)
	{
		surname = surnam;
	}

	void setAge(char ag)
	{
		age = ag;
	}

	void setAllPayments(int number)
	{
		allPayments = number;
	}

	void setAllIncomesSettled(int number)
	{
		allIncomesSettled = number;
	}

	void setContracts(TwoWayList<Contract> contr)
	{
		contracts = contr;
	}

	void addContr(Contract contr); // for testing
	void delContr(Contract contr); // for testing
	Person(std::string nam, std::string surnam, int ag);
};
