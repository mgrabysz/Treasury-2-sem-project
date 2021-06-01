#pragma once
#include "Treasury.h"
#include <iostream>
#include <fstream>

class ConsoleInterface
{
private:
	Treasury treasury;
public:
	ConsoleInterface() = default;
	void insertPeopleFromJson(std::string path);
	void showPeopleList() noexcept;
	void showGeneratedInfoPerson();
	void exportListPaymentsToJson();
	void addNewPerson() noexcept;
	void deletePerson();
	void editPerson();
};
