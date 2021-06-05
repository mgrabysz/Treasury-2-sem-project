#include "Person.h"

void Person::addContract(Contract contr)
{
	auto i = contracts.begin();
	switch (contr.type) {
	case praca:
		contracts.add(contr, i);
		break;
	case dzielo:
		contracts.push(contr);
		break;
	case zlecenie:
		for (i; i != contracts.end(); ++i)
		{
			if ((*i).type != praca)
				break;
		}
		contracts.add(contr, i);
	}
}

void Person::delContract(TwoWayList<Contract>::Iterator iter)
{
	contracts.del(iter);
}

void Person::addContr(Contract contr)
{
	addContract(contr);
}

void Person::delContr(TwoWayList<Contract>::Iterator iter)
{
	delContract(iter);
}

Person::Person(std::string nam, std::string surnam, int ag)
{
	name = nam;
	surname = surnam;
	age = ag;
}

std::string Person::getName() const noexcept
{
	return name;
}

std::string Person::getSurname() const noexcept
{
	return surname;
}

int Person::getAge() const noexcept
{
	return static_cast<int> (age);
}

int Person::getAllPayments() const noexcept
{
	return allPayments;
}

int Person::getAllIncomesSettled() const noexcept
{
	return allIncomesSettled;
}

TwoWayList<Contract>& Person::getContracts() noexcept
{
	return contracts;
}

void Person::setName(std::string nam)
{
	name = nam;
}

void Person::setSurname(std::string surnam)
{
	surname = surnam;
}

void Person::setAge(char ag)
{
	age = ag;
}

void Person::setAllPayments(int number)
{
	allPayments = number;
}

void Person::incrementAllPayments(int number)
{
	allPayments += number;
}

void Person::setAllIncomesSettled(int number)
{
	allIncomesSettled = number;
}

void Person::incrementAllIncomesSettled(int number)
{
	allIncomesSettled += number;
}

void Person::setContracts(TwoWayList<Contract> contr)
{
	contracts = contr;
}

Details& Person::getDetailsPtr()
{
	return details;
}