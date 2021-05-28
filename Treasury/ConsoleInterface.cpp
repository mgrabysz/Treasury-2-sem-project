#include "ConsoleInterface.h"

void ConsoleInterface::showPeopleList() noexcept
{
	std::cout << "List of People\n==============================\n";
	TwoWayList<Info> data = treasury.showPeople();
	for (auto i = data.begin(); i != nullptr; ++i)
	{
		std::cout << (*i).id << ". " << (*i).name << " " << (*i).surname << " " << (*i).age << "\n";
	}
}

void ConsoleInterface::insertPeopleFromJson(std::string path)
{
	treasury.getDataFromJson(path);
}

void ConsoleInterface::showGeneratedInfoPerson()
{
	while (true)
	{
		std::cout << "Please choose id of person from list below\n";
		showPeopleList();
		int id;
		std::cin >> id;
		try
		{
			Info data = treasury.generateInfoPerson(id);
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "There is no person with that id!\n";
		}
	}
}

void ConsoleInterface::showGeneratedListPayments()
{
	TwoWayList<Info> data = treasury.generateListPayment();
	std::cout << "Payments Raport\n==============================\n";
	for (auto i = data.begin(); i != nullptr; ++i)
	{
		std::cout << (*i).id << ". " << (*i).name << " " << (*i).surname << " Age: " << (*i).age << " All payments: "<<(*i).allPayments << "\n";
	}
}

void ConsoleInterface::exportListPaymentsToTxt()
{
	TwoWayList<Info> data = treasury.generateListPayment();
	std::ofstream myfile;
	myfile.open("raport.txt");
	for (auto i = data.begin(); i != nullptr; ++i)
	{
		myfile << (*i).id << ". " << (*i).name << " " << (*i).surname << " Age: " << (*i).age << " All payments: " << (*i).allPayments << "\n";
	}
	myfile.close();
	std::cout << "Raport generated to raport.txt file.";
}

void ConsoleInterface::addNewPerson() noexcept
{

}

void ConsoleInterface::deletePerson()
{

}

void ConsoleInterface::editPerson()
{

}
