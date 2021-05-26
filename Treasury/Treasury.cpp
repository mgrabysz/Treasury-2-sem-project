#include "Treasury.h"

void Treasury::addPerson(Person* person) noexcept
{
	people.append(person);
}

void Treasury::deletePerson(int id) noexcept
{
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
		{
			people.remove(i);
			return;
		}		
	}
	//mozna dac wyjatek ze nie ma osoby o takim id
}

void Treasury::editPerson(int id, int contrId) noexcept
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
					(*i)->delContr(j);
			}
		}
	}
}

void Treasury::editPerson(int id, Contract newContr) noexcept
{
	//dodaje nowy kontrakt do n-tej osoby
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
			(*i)->addContr(newContr);
	}
	
}

std::string Treasury::showPeople() const noexcept
{
	//wyswietlac w konsoli ludzi z ich id
	std::string strToShow = "";
	int id = 0;
	for (auto i = people.begin(); i != nullptr; ++i)
	{	
		id++;
		strToShow = strToShow + std::to_string(id) + ". " + (*i)->getName() + " " + (*i)->getSurname() + "\n";
	}
	return strToShow;
}

std::string Treasury::generateInfoPerson(Person* person) const noexcept
{
	std::string strToReturn = "Name: " + person->getName() + "\tSurname: " + person->getSurname();
	strToReturn = strToReturn + "\tAge: " + std::to_string(person->getAge()) + "\tAll Payments: " + std::to_string(person->getAllPayments());
	return strToReturn;
}

std::string Treasury::generateListPayment() const noexcept
{
	std::string strToReturn = "";
	for (auto i = people.begin(); i != nullptr; ++i)
	{
		Person* ptr = (*i);
		strToReturn += generateInfoPerson(ptr);
		strToReturn += "\n";
	}
	return strToReturn;
}
