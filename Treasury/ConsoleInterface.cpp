#include "ConsoleInterface.h"

void ConsoleInterface::showPeopleList() noexcept
{
	std::cout << "List of People\n==============================\n";
	TwoWayList<Info> data = treasury.showPeople();
	for (auto i = data.begin(); i != data.end(); ++i)
	{
		std::cout << (*i).id << ". " << (*i).name << " " << (*i).surname << " " << (*i).age << "\n";
	}
}

void ConsoleInterface::insertPeopleFromJson(std::string path)
{
	treasury.getDataFromJson(path);
}

void ConsoleInterface::exportGeneratedSettlementPerson()
{
	while (true)
	{
		std::cout << "Please choose id of person from list below\n(Or 0 if you want to exit)\n";
		showPeopleList();
		int id;
		std::cin >> id;
		if (id == 0)
			break;
		try
		{
			Info data = treasury.generateInfoPerson(id);
			//tu bartek musisz zrobic export tych danych do jsona dla tej osoby konkretnej
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "There is no person with that id!\n";
		}
	}
}

void ConsoleInterface::addNewPerson() noexcept
{
	//praca -> zlecenie -> dzielo ---uwazam ze dodawanie kontraktow powinno byc poprzez editPerson, a pilnowanie kolejnosci wtedy w klasie Person przy dodawaniu kontraktu
	std::cout << "Name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Surname: ";
	std::string surname;
	std::cin >> surname;
	int age = 0;
	while (age <= 0)
	{
		std::cout << "Age: ";
		std::cin >> age;
	}
	treasury.addPerson(new Person(name, surname, age));
}

void ConsoleInterface::deletePerson()
{
	while (true)
	{
		std::cout << "Please choose id of person from list below\n(Or 0 if you want to exit)\n";
		showPeopleList();
		int id;
		std::cin >> id;
		if (id == 0)
			break;
		try
		{
			treasury.deletePerson(id);
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "There is no person with that id!\n";
		}
	}
}

void ConsoleInterface::editPerson()
{
	while (true)
	{
		std::cout << "Please choose id of person from list below\n(Or 0 if you want to exit)\n";
		showPeopleList();
		int id;
		std::cin >> id;
		if (id == 0)
			break;
		try
		{
			while (true)
			{
				std::cout << "Please choose option\n1. Delete contract\n2. Add new contract\n";
				int ch;
				std::cin >> ch;
				if (ch == 1)
				{
					std::cout << "Please input id of coontract to delete\n";
					int idC;
					std::cin >> idC;
					try
					{
						treasury.editPerson(id, idC);
						break;
					}
					catch (std::invalid_argument)
					{
						std::cout << "Invalid contract id!\n";
					}
				}
				else if (ch == 2)
				{
					std::cout << "What type of contract you want to add:\n0.praca\n1.zlecenie\n2.dzielo\n";
					int cType;
					std::cin >> cType;
					if (cType < 0 || cType > 2)
					{
						std::cout << "Wrong type of contract";
						continue;
					}
					contrType type = static_cast<contrType>(cType);
					std::cout << "What was the income for this contract?\n";
					int income;
					std::cin >> income;
					if (income < 0)
					{
						std::cout << "Wrong income";
						continue;
					}
					treasury.editPerson(id, new Contract(type, income));
					break;
				}
			}
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "There is no person with that id!\n";
		}
	}
}

void ConsoleInterface::exportListSettlementToJson()
{
	TwoWayList<Info> data = treasury.generateListPayment();
	//bartek na podstawie data do jsona 
}
