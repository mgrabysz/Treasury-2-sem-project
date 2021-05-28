#include "Treasury.h"

bool operator==(Info lhs, Info rhs)
{
	return (lhs.name == rhs.name && lhs.surname == rhs.surname && lhs.age == rhs.age && lhs.allPayments == rhs.allPayments);
}

void Treasury::addPerson(Person* person) noexcept
{
	people.push(person);
}

void Treasury::deletePerson(int id)
{
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
		{
			people.del(i);
			return;
		}		
	}
	throw std::invalid_argument("There is no person with that id");
}

void Treasury::editPerson(int id, int contrId)
{
	//usuwa n-ty z kolei kontrakt z listu kontraktów n-tej osoby
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
		{
			for (auto j = (*i)->getContracts().begin(); j != (*i)->getContracts().end(); ++j)
			{
				contrId--;
				if (contrId == 0)
				{ 
					(*i)->delContr(j);
					return;
				}	
			}
			throw std::invalid_argument("There is no contract with that id");
		}
	}
	throw std::invalid_argument("There is no person with that id");
}

void Treasury::editPerson(int id, Contract newContr)
{
	//dodaje nowy kontrakt do n-tej osoby
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
		{
			(*i)->addContr(newContr);
			return;
		}
	}
	throw std::invalid_argument("There is no person with that id");
}

void Treasury::resetPerson(Person* person) noexcept
{
	person->setAllIncomesSettled(0);
	person->setAllPayments(0);
}

TwoWayList<Info> Treasury::showPeople() noexcept
{
	TwoWayList<Info> data;
	int id = 0;
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id++;
		Info inf;
		inf.id = id;
		inf.name = (*i)->getName();
		inf.surname = (*i)->getSurname();
		inf.age = (*i)->getAge();
		data.push(inf);
	}
	return data;
}

Info Treasury::generateInfoPerson(Person* person) noexcept
{
	resetPerson(person);
	calculator.callAllPayments(person);
	Info data;
	data.name = person->getName();
	data.surname = person->getSurname();
	data.age = person->getAge();
	data.allPayments = person->getAllPayments();
	return data;
}

Info Treasury::generateInfoPerson(int id)
{
	int newId = 0;
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		newId++;
		if (newId == id)
		{
			return generateInfoPerson((*i));
		}
	}
	throw std::invalid_argument("There is no person with that id");
}

TwoWayList<Info> Treasury::generateListPayment() noexcept
{
	TwoWayList<Info> data;
	int id = 0;
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		data.push(generateInfoPerson((*i)));
	}
	return data;
}

