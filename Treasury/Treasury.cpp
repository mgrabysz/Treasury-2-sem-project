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
	//usuwa n-ty z kolei kontrakt z listu kontrakow n-tej osoby
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
		{
			auto person = *i;
			
			for (auto j = person->getContracts().begin(); j != person->getContracts().end(); ++j)
			{
				contrId--;
				if (contrId == 0)
				{ 
					(*i)->delContract(j);
					return;
				}	
			}
			throw std::invalid_argument("There is no contract with that id");
		}
	}
	throw std::invalid_argument("There is no person with that id");
}

void Treasury::editPerson(int id, Contract* newContr)
{
	//dodaje nowy kontrakt do n-tej osoby
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		id--;
		if (id == 0)
		{
			(*i)->addContract(newContr);
			return;
		}
	}
	throw std::invalid_argument("There is no person with that id");
}

void Treasury::resetPerson(Person* person) noexcept
{
	person->setAllIncomesSettled(0);
	person->setAllPayments(0);
	person->details.retirement = 0;
	person->details.pension = 0;
	person->details.health = 0;
	person->details.illness = 0;
	person->details.tax = 0;
}

void Treasury::addPayment(Payment* payment)
{
	calculator.addPayment(payment);
}

TwoWayList<Info> Treasury::showPeople()
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
	data.details = person->details;
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

void Treasury::getDataFromJson(std::string path)
{
	std::ifstream reader("people.json");
	nlohmann::json j = nlohmann::json::parse(reader);
	reader.close();
	int i = 0;
	for (auto& person : j) {
		std::string name = person["name"];
		std::string surname = person["surname"];
		int age = person["age"];
		Person pers(name, surname, age);
		for (auto& contract : person["contracts"])
		{
			contrType type = contract["type"];
			int value = contract["value"];
			pers.addContract(new Contract(type, value));
		}
		addPerson(&pers);
	}
}



