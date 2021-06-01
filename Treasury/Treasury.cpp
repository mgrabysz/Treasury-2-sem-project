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
		TwoWayList<Contract*> contr;
		for (auto& contract : person["contracts"])
		{
			contrType type = contract["type"];
			int value = contract["value"];
			Contract contract(type, value);
			contr.push(&contract);
		}
		Person person(name, surname, age);
		person.setContracts(contr);
		addPerson(&person);
	}
}

//int main()
//{
////	//	std::ofstream reader("people.txt");
////	//	nlohmann::json j;
////	//	j["0"]["name"] = "Barbara";
////	//	j["0"]["surname"] = "Kowalska";
////	//	j["0"]["age"] = 45;
////	//	j["0"]["contracts"]["0"]["type"] = praca;
////	//	j["0"]["contracts"]["0"]["value"] = 1500;
////	//	j["1"]["name"] = "Tomasz";
////	//	j["1"]["surname"] = "Wisnia";
////	//	j["1"]["age"] = 30;
////	//	j["2"]["name"] = "Krystyna";
////	//	j["2"]["surname"] = "Malina";
////	//	j["2"]["age"] = 78;
////	//	j["2"]["contracts"]["0"]["type"] = dzielo;
////	//	j["2"]["contracts"]["0"]["value"] = 200;
////	//	j["2"]["contracts"]["1"]["type"] = praca;
////	//	j["2"]["contracts"]["1"]["value"] = 2050;
////	//	j["3"]["name"] = "Andrzej";
////	//	j["3"]["surname"] = "Truten";
////	//	j["3"]["age"] = 53;
////	//	j["3"]["contracts"]["0"]["type"] = praca;
////	//	j["3"]["contracts"]["0"]["value"] = 2300;
////	//	j["3"]["contracts"]["1"]["type"] = zlecenie;
////	//	j["3"]["contracts"]["1"]["value"] = 500;
////	//	reader << j.dump(4);
////	//	reader.close();
//	std::ifstream reader("people.json");
//	nlohmann::json j = nlohmann::json::parse(reader);
//	reader.close();
//	int i = 0;
//	for (auto& person : j) {
//		std::string name = person["name"];
//		std::string surname = person["surname"];
//		int age = person["age"];
//		TwoWayList<Contract> contr;
//		for (auto& contract : person["contracts"])
//		{
//			contrType type = contract["type"];
//			int value = contract["value"];
//			Contract contract(type, value);
//			contr.push(contract);
//		}
//		Person person(name, surname, age);
//		person.setContracts(contr);
//		addPerson(person);
//	}
//}

