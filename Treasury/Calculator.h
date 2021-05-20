#pragma once
#include "TwoWayList.h"
#include "Person.h"

class Calculator
{
	friend class Person;
private:
	TwoWayList<std::string> payments; //beda tu wskazania na obiekty typu Payment*
public:
	void callAllPayments(Person& person) noexcept;
};
