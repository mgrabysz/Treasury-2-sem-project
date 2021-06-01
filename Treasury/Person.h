#pragma once

#include <string.h>
#include "Contract.h"
#include "TwoWayList.h"

struct Details
{
	int retirement = 0;
	int pension = 0;
	int health = 0;
	int illness = 0;
	int tax = 0;
};


class Person
{
	friend class Treasury;
private:
	std::string name;
	std::string surname;
	char age;
	int allPayments = 0;
	int allIncomesSettled = 0;
	TwoWayList<Contract*> contracts;
	void addContract(Contract* contr);
	void delContract(TwoWayList<Contract*>::Iterator iter);
	Details details;
public:
	Person(std::string nam, std::string surnam, int ag);
	
	std::string getName() const noexcept;
	std::string getSurname() const noexcept;	
	int getAge() const noexcept;
	int getAllPayments() const noexcept;
	int getAllIncomesSettled() const noexcept;
	TwoWayList<Contract*>& getContracts() noexcept;

	void setName(std::string nam);
	void setSurname(std::string surnam);
	void setAge(char ag);
	void setAllPayments(int number);
	void incrementAllPayments(int number);
	void setAllIncomesSettled(int number);
	void incrementAllIncomesSettled(int number);
	void setContracts(TwoWayList<Contract*> contr);

	void addContr(Contract* contr); // for testing
	void delContr(TwoWayList<Contract*>::Iterator iter); // for testing
	Person(std::string nam, std::string surnam, int ag);

	Details& getDetailsPtr();
};
