#pragma once
#include "Calculator.h"
#include "TwoWayList.h"
#include "Person.h"

struct Info
{
	int id;
	std::string name;
	std::string surname;
	int age;
	int allPayments;
};

class Treasury
{
private:
	TwoWayList<Person*> people;
	Calculator calculator = Calculator();
	void resetPerson(Person* person) noexcept;
public:
	Treasury() = default;
	void addPerson(Person* person) noexcept;
	void deletePerson(int id) noexcept;
	void editPerson(int id, int contrId) noexcept;
	void editPerson(int id, Contract newContr) noexcept;
	void getDataFromJson(std::string path);
	TwoWayList<Info> showPeople() const noexcept;
	Info generateInfoPerson(Person* person) noexcept;
	TwoWayList<Info> generateListPayment() noexcept;
};
