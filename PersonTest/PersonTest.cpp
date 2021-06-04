#include "../Treasury/Person.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PersonTest
{
	TEST_CLASS(PersonTest)
	{
	public:
		
		TEST_METHOD(Test_create_person)
		{
			Person janusz("Janusz", "Kowalski", 29);
			Assert::IsTrue("Janusz" == janusz.getName());
			Assert::IsTrue("Kowalski" == janusz.getSurname());
			Assert::IsTrue(29 == janusz.getAge());
			Assert::IsTrue(0 == janusz.getAllIncomesSettled());
			Assert::IsTrue(0 == janusz.getAllPayments());
		}

		TEST_METHOD(Test_person_add_contract)
		{
			Person janusz("Janusz", "Kowalski", 29);
			Contract contr1 = Contract(zlecenie, 3500);
			Contract contr2 = Contract(praca, 3900);
			Contract contr3 = Contract(dzielo, 250);
			janusz.addContr(contr1);
			janusz.addContr(contr2);
			janusz.addContr(contr3);
			auto iter = janusz.getContracts().begin();
			Assert::IsTrue((*iter).value == 3900);
			++iter;
			Assert::IsTrue((*iter).value == 3500);
			++iter;
			Assert::IsTrue((*iter).value == 250);
		}

		TEST_METHOD(Test_person_add_contract_segregation)
		{
			Person janusz("Janusz", "Kowalski", 29);
			Contract contr1 = Contract(zlecenie, 1);
			Contract contr2 = Contract(praca, 2);
			Contract contr3 = Contract(dzielo, 3);
			Contract contr4 = Contract(zlecenie, 4);
			Contract contr5 = Contract(praca, 5);
			Contract contr6 = Contract(dzielo, 6);
			janusz.addContr(contr1);
			janusz.addContr(contr2);
			janusz.addContr(contr3);
			janusz.addContr(contr4);
			janusz.addContr(contr5);
			janusz.addContr(contr6);
			auto iter = janusz.getContracts().begin();
			Assert::IsTrue((*iter).type == praca);
			++iter;
			Assert::IsTrue((*iter).type == praca);
			++iter;
			Assert::IsTrue((*iter).type == zlecenie);
			++iter;
			Assert::IsTrue((*iter).type == zlecenie);
			++iter;
			Assert::IsTrue((*iter).type == dzielo);
			++iter;
			Assert::IsTrue((*iter).type == dzielo);
			++iter;
		}

		TEST_METHOD(Test_person_remove_contract)
		{
			Person janusz("Janusz", "Kowalski", 29);
			janusz.addContr(Contract(zlecenie, 3500));
			janusz.addContr(Contract(praca, 3000));
			Assert::IsTrue(0 == janusz.getAllIncomesSettled());
			janusz.delContr(janusz.getContracts().begin());
		}

		TEST_METHOD(test_person_setters)
		{
			Person janusz("Janusz", "Kowalski", 29);
			janusz.setName("Antonio");
			Assert::IsTrue("Antonio" == janusz.getName());
			janusz.setSurname("Fernandez");
			Assert::IsTrue("Fernandez" == janusz.getSurname());
			janusz.setAge(12);
			Assert::IsTrue(12 == janusz.getAge());
			janusz.setAllPayments(1002);
			Assert::IsTrue(1002 == janusz.getAllPayments());
			janusz.setAllIncomesSettled(200);
			Assert::IsTrue(200 == janusz.getAllIncomesSettled());
		}
	};
}
