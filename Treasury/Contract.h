#pragma once

#include <string>

enum contrType {
	praca,
	zlecenie,
	dzielo
};

struct Contract
{
	contrType type;
	int value;
	Contract(contrType typ, int val)
		:type(typ), value(val)
	{

	};
	bool operator==(Contract contr)
	{
		return (type == contr.type && value == contr.value);
	}
};



