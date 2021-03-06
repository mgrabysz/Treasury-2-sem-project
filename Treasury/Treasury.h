#pragma once
#include "Calculator.h"
#include "TwoWayList.h"
#include "Person.h"
#include <iostream>

#include "json.h"
#include <fstream>

struct Info
{
	int id;
	std::string name;
	std::string surname;
	int age;
	int allPayments = 0;
	Details details;
};

bool operator==(Info lhs, Info rhs);

class Treasury
{
private:
	TwoWayList<Person*> people;
	Calculator calculator;
	void resetPerson(Person* person) noexcept;
public:
	Treasury() = default;
	void addPerson(Person* person) noexcept;
	void deletePerson(int id);
	void editPerson(int id, int contrId);
	void editPerson(int id, Contract newContr);
	void addPayment(Payment* payment);
	void getDataFromJson(std::string path);
	TwoWayList<Info> showPeople();
	Info generateInfoPerson(Person* person) noexcept;
	Info generateInfoPerson(int id);
	TwoWayList<Info> generateListPayment() noexcept;

};
