#include "TwoWayList.h"
#include "Contract.h"
#include "Person.h"
#include <iostream>

int main()
{
	Contract cont("trala", 2445);
	Contract cont2("lala2", 2445);
	Person janusz("Jan", "Szczygiel", 76);
	janusz.add_contr(cont);
	janusz.del_contr(cont2);
}