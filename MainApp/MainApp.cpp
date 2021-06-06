#include "../Treasury/ConsoleInterface.h"
#include <iostream>

int main()
{
	ConsoleInterface cInterface;
	std::cout << "Welcome in Treasury!\nImporting data from json...\n";
	std::string path = "people.json";
	try
	{
		cInterface.insertPeopleFromJson(path);
		std::cout << "Done!";
	}
	catch (std::invalid_argument)
	{
		std::cout << "Incorrect path to json file!\n";
	}
	bool end = false;
	int opt = 0;
	
	while (!end)
	{
		std::cout << "What do you want to do?\n1. Generale list of settlements\n2. Generate settlement for one person\n3. Add person\n4. Delete person\n5. Edit person\n6. Exit\n";
		std::cin >> opt;
		switch (opt)
		{
		case 1:
			cInterface.exportListSettlementToJson();
			std::cout << "Export completed!\n";
			break;
		case 2:
			cInterface.exportGeneratedSettlementPerson();
			std::cout << "Export completed!\n";
			break;
		case 3:
			cInterface.addNewPerson();
			std::cout << "Operation completed\n";
			break;
		case 4:
			cInterface.deletePerson();
			std::cout << "Deleted succesfully\n";
			break;
		case 5:
			cInterface.editPerson();
			std::cout << "Operation completed\n";
			break;
		case 6:
			std::cout << "Thank you for using our services.\n";
			end = true;
			continue;
		default:
			std::cout << "Wrong input!\nTry again\n";
		}
		
	}
}

