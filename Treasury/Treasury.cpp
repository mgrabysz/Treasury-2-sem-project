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

void Treasury::editPerson(int id, bool del) noexcept
{
	//narazie nwm jak podac kontrakt do usuniecia lub dodania bo skad uzytkownik ma wiedziec ktory kontrakt chce usunac,
	//moze pokazac mu liste kontraktow i zeby wybral sobie id
	//wtedy trzeba zmienic klase Person
}

void Treasury::showPeople() const noexcept
{
	//wyswietlac w konsoli ludzi z ich id
	std::string strToShow = "";
	int id = 0;
	for (auto i = people.begin(); i != people.end(); ++i)
	{
		strToShow = strToShow + std::to_string(id) + ".\t" + "\n";
		id++;
	}
	std::cout << strToShow;
}

std::string Treasury::generateInfoPerson(Person* person) const noexcept
{
	return "";
}

std::string Treasury::generateListPayment() const noexcept
{
	return "";
}
