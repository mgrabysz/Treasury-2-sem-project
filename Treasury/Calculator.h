#pragma once
#include "TwoWayList.h"
#include "Person.h"
#include "Payments.h"

class Calculator
{
	friend class Person;
private:
	TwoWayList<Payment*> payments;
public:
	void addPayment(Payment& newPay) noexcept;
	void callAllPayments(Person& person) noexcept;
};
