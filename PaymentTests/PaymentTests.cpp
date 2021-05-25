#include "../Treasury/Payments.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PaymentTests
{
	TEST_CLASS(PaymentTests)
	{
	public:
		// testy dotycz¹:
		// employment -> umowa o prace
		// civil -> zlecenie
		// comission -> dzie³o
		
		TEST_METHOD(RetirementEmployment)
		{  
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(25600);
			scott.setAllIncomesSettled(760000);
			
			Contract contract(praca, 800000);
			Retirement retirementCalc;
			
			int payment = retirementCalc.calculate(scott, contract);
			
			Assert::AreEqual(78080, payment);
			Assert::AreEqual(1560000, scott.getAllIncomesSettled());
			Assert::AreEqual(103680, scott.getAllPayments());
		}
		TEST_METHOD(RetirementCivilLowerThanMinAnnual)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(25600);
			scott.setAllIncomesSettled(760000);

			Contract contract(zlecenie, 800000);
			Retirement retirementCalc;

			int payment = retirementCalc.calculate(scott, contract);

			Assert::AreEqual(78080, payment);
			Assert::AreEqual(1560000, scott.getAllIncomesSettled());
			Assert::AreEqual(103680, scott.getAllPayments());
		}
		TEST_METHOD(RetirementCivilGreaterThanMinAnnual)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(25600);
			scott.setAllIncomesSettled(5078000);

			Contract contract(zlecenie, 800000);
			Retirement retirementCalc;

			int payment = retirementCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(5878000, scott.getAllIncomesSettled());
			Assert::AreEqual(25600, scott.getAllPayments());
		}
		TEST_METHOD(RetirementCivilUnderAge)
		{
			Person scott("Michael", "Scott", 22);
			scott.setAllPayments(25600);
			scott.setAllIncomesSettled(5078000);

			Contract contract(zlecenie, 800000);
			Retirement retirementCalc;

			int payment = retirementCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(5878000, scott.getAllIncomesSettled());
			Assert::AreEqual(25600, scott.getAllPayments());
		}
		TEST_METHOD(RetirementComission)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(25600);
			scott.setAllIncomesSettled(760000);

			Contract contract(dzielo, 800000);
			Retirement retirementCalc;

			int payment = retirementCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(1560000, scott.getAllIncomesSettled());
			Assert::AreEqual(25600, scott.getAllPayments());
		}

		TEST_METHOD(PensionEmployment)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(345600);
			scott.setAllIncomesSettled(7891000);

			Contract contract(praca, 6000000);
			Pension pensionCalc;

			int payment = pensionCalc.calculate(scott, contract);

			Assert::AreEqual(90000, payment);
			Assert::AreEqual(13891000, scott.getAllIncomesSettled());
			Assert::AreEqual(435600, scott.getAllPayments());
		}
		TEST_METHOD(PensionCivilLowerThanMinAnnual)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(345600);
			scott.setAllIncomesSettled(2233300);

			Contract contract(zlecenie, 6000000);
			Pension pensionCalc;

			int payment = pensionCalc.calculate(scott, contract);

			Assert::AreEqual(90000, payment);
			Assert::AreEqual(8233300, scott.getAllIncomesSettled());
			Assert::AreEqual(435600, scott.getAllPayments());
		}
		TEST_METHOD(PensionCivilGreaterThanMinAnnual)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(345600);
			scott.setAllIncomesSettled(7891000);

			Contract contract(zlecenie, 6000000);
			Pension pensionCalc;

			int payment = pensionCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(13891000, scott.getAllIncomesSettled());
			Assert::AreEqual(345600, scott.getAllPayments());
		}
		TEST_METHOD(PensionCivilUnderAge)
		{
			Person scott("Michael", "Scott", 21);
			scott.setAllPayments(345600);
			scott.setAllIncomesSettled(2233300);

			Contract contract(zlecenie, 6000000);
			Pension pensionCalc;

			int payment = pensionCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(8233300, scott.getAllIncomesSettled());
			Assert::AreEqual(345600, scott.getAllPayments());
		}
		TEST_METHOD(PensionComission)
		{
			Person scott("Michael", "Scott", 21);
			scott.setAllPayments(345600);
			scott.setAllIncomesSettled(2233300);

			Contract contract(dzielo, 6000000);
			Pension pensionCalc;

			int payment = pensionCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(8233300, scott.getAllIncomesSettled());
			Assert::AreEqual(345600, scott.getAllPayments());
		}

		TEST_METHOD(HealthEmployment)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(123400);
			scott.setAllIncomesSettled(5678900);

			Contract contract(praca, 6000000);
			Health healthCalc;

			int payment = healthCalc.calculate(scott, contract);

			Assert::AreEqual(540000, payment);
			Assert::AreEqual(11678900, scott.getAllIncomesSettled());
			Assert::AreEqual(663400, scott.getAllPayments());
		}
		TEST_METHOD(HealthCivil)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(123400);
			scott.setAllIncomesSettled(5678900);

			Contract contract(zlecenie, 6000000);
			Health healthCalc;

			int payment = healthCalc.calculate(scott, contract);

			Assert::AreEqual(540000, payment);
			Assert::AreEqual(11678900, scott.getAllIncomesSettled());
			Assert::AreEqual(663400, scott.getAllPayments());
		}
		TEST_METHOD(HealthCivilUnderAge)
		{
			Person scott("Michael", "Scott", 17);
			scott.setAllPayments(123400);
			scott.setAllIncomesSettled(5678900);

			Contract contract(zlecenie, 6000000);
			Health healthCalc;

			int payment = healthCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(11678900, scott.getAllIncomesSettled());
			Assert::AreEqual(123400, scott.getAllPayments());
		}
		TEST_METHOD(HealthComission)
		{
			Person scott("Michael", "Scott", 45);
			scott.setAllPayments(123400);
			scott.setAllIncomesSettled(5678900);

			Contract contract(dzielo, 6000000);
			Health healthCalc;

			int payment = healthCalc.calculate(scott, contract);

			Assert::AreEqual(0, payment);
			Assert::AreEqual(11678900, scott.getAllIncomesSettled());
			Assert::AreEqual(123400, scott.getAllPayments());
		}
	};
}
