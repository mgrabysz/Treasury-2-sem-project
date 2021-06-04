#include "Person.h"

void Person::addContract(Contract contr)
{
	if (contracts.empty())
	{
		contracts.push(contr);
	}
	else
	{
		contrType type = contr.type;
		for (auto i = contracts.begin(); i != contracts.end(); ++i)
		{
			contrType actual = (*i).type;
			if (actual > type)
			{
				contracts.add(contr, i);
				break;
			}
			++i;
			contrType next = (*i).type;
			--i;
			if (next != actual && next > type)
			{
				contracts.add(contr, i);
				break;
			}
		}
	}
}

void Person::delContract(TwoWayList<Contract>::Iterator iter)
{
	//allIncomesSettled += (*iter).value;
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