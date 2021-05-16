#pragma once

#include <string>

struct Contract
{
	std::string type;
	int value;
	Contract(std::string typ, int val)
		:type(typ), value(val)
	{

	};
	bool operator==(Contract contr)
	{
		return (type == contr.type && value == contr.value);
	}
};