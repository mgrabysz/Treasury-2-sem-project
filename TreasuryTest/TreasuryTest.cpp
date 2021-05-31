#include "CppUnitTest.h"
#include "../Treasury/Treasury.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreasuryTest
{
	TEST_CLASS(TreasuryTest)
	{
	public:
		
		TEST_METHOD(TreasuryAddPerson)
		{
			Treasury treasury;
			treasury.addPerson(new Person("Lukasz", "Kuli", 20));
			Info exp;
			exp.id = 1;
			exp.name = "Lukasz";
			exp.surname = "Kuli";
			exp.age = 20;
			Assert::IsTrue(exp==treasury.generateInfoPerson(1));
		}

		TEST_METHOD(TreasuryDeletePerson)
		{
			Treasury treasury;
			treasury.addPerson(new Person("Lukasz", "Kuli", 20));
			Info exp;
			exp.id = 1;
			exp.name = "Lukasz";
			exp.surname = "Kuli";
			exp.age = 20;
			Assert::IsTrue(exp == treasury.generateInfoPerson(1));
			treasury.deletePerson(1);
			Assert::ExpectException<std::invalid_argument>([&] {treasury.generateInfoPerson(1); });
		}

		TEST_METHOD(TreasuryEditPersonDelete)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			ptr->addContr(new Contract(praca, 2000));
			treasury.addPerson(ptr);
			Assert::IsFalse((ptr->getContracts()).empty());
			treasury.editPerson(1, 1);
			Assert::IsTrue((ptr->getContracts()).empty());
		}

		TEST_METHOD(TreasuryEditPersonAdd)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			Assert::IsTrue((ptr->getContracts()).empty());
			treasury.editPerson(1, new Contract(praca, 1000));
			Assert::IsFalse((ptr->getContracts()).empty());
		}

		TEST_METHOD(TreasuryEditPersonAddInvalid)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			Assert::IsTrue((ptr->getContracts()).empty());
			Assert::ExpectException<std::invalid_argument>([&] {treasury.editPerson(2, new Contract(praca, 1000)); });
		}

		TEST_METHOD(TreasuryEditPersonDeleteInvalid)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			treasury.editPerson(1, new Contract(praca, 1000));
			Assert::IsFalse((ptr->getContracts()).empty());
			Assert::ExpectException<std::invalid_argument>([&] {treasury.editPerson(2, 1); });
		}

		TEST_METHOD(TreasuryEditPersonDeleteInvalid2)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			Assert::IsTrue((ptr->getContracts()).empty());
			Assert::ExpectException<std::invalid_argument>([&] {treasury.editPerson(1, 1); });
		}

		TEST_METHOD(TreasuryGenerateInfoIter)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			Info exp;
			exp.id = 1;
			exp.name = "Lukasz";
			exp.surname = "Kuli";
			exp.age = 20;
			exp.allPayments = 0;
			Assert::IsTrue(exp == treasury.generateInfoPerson(ptr));
		}

		TEST_METHOD(TreasuryShowPeople)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			Person* ptr2 = new Person("Marcin", "Kuli", 20);
			treasury.addPerson(ptr2);
			Info exp;
			exp.id = 2;
			exp.name = "Marcin";
			exp.surname = "Kuli";
			exp.age = 20;
			TwoWayList<Info> data = treasury.showPeople();
			auto i = data.begin();
			++i;
			Assert::IsTrue(exp == (*i));
		}

		TEST_METHOD(TreasuryGenerateList)
		{
			Treasury treasury;
			Person* ptr = new Person("Lukasz", "Kuli", 20);
			treasury.addPerson(ptr);
			Person* ptr2 = new Person("Marcin", "Kuli", 20);
			treasury.addPerson(ptr2);
			Info exp;
			exp.id = 2;
			exp.name = "Marcin";
			exp.surname = "Kuli";
			exp.age = 20;
			TwoWayList<Info> data = treasury.generateListPayment();
			auto i = data.begin();
			++i;
			Assert::IsTrue(exp == (*i));
		}

	};
}
