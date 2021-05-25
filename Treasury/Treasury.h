#pragma once
#include "Calculator.h"
#include "TwoWayList.h"
#include "Person.h"


class Treasury
{
private:
	TwoWayList<Person*> people;
public:
	Treasury() = default;
	void addPerson(Person* person) noexcept;
	void deletePerson(int id) noexcept;
	void editPerson(int id, int contrId) noexcept;
	void editPerson(int id, Contract newContr) noexcept;
	void showPeople() const noexcept;
	std::string generateInfoPerson(Person* person) const noexcept;
	std::string generateListPayment() const noexcept;
};
