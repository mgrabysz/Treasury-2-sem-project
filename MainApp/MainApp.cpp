#include "../Treasury/ConsoleInterface.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	ConsoleInterface cInterface;
	std::cout << "Welcome in Treasury!\nInput path to file with data to import: \n";
	std::string path;
	bool startedReady = false;
	while (!startedReady)
	{
		std::cin >> path;
		try
		{
			cInterface.insertPeopleFromJson(path);
			std::cout << "Inserting data completed!";
			startedReady = true;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Incorrect path to json file!\nTry again!\n";
		}
	}
	
	bool end = false;
	char opt = '0';

	while (!end)
	{
		std::cout << "What do you want to do?\n1. Generale list of settlements\n2. Generate settlement for one person\n3. Add person\n4. Delete person\n5. Edit person\n6. Exit\n";
		std::cin >> opt;
		if (!isdigit(opt))
			opt = '0';
		system("CLS");
		switch (opt)
		{
		case '0':
			std::cout << "Wrong input!\nTry again\n";
			break;
		case '1':
			cInterface.exportListSettlementToJson();
			std::cout << "Export completed!\n";
			break;
		case '2':
			cInterface.exportGeneratedSettlementPerson();
			std::cout << "Export completed!\n";
			break;
		case '3':
			cInterface.addNewPerson();
			std::cout << "Operation completed\n";
			break;
		case '4':
			cInterface.deletePerson();
			std::cout << "Deleted succesfully\n";
			break;
		case '5':
			cInterface.editPerson();
			std::cout << "Operation completed\n";
			break;
		case '6':
			std::cout << "Thank you for using our services.\n";
			end = true;
			continue;
		}

	}
}

