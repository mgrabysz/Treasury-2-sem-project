#include "../Treasury/Calculator.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest
{
	TEST_CLASS(CalculatorTest)
	{
	public:
		
		TEST_METHOD(OneContract)
		{
			Person* halpert = new Person("Jim", "Halpert", 30);
			Contract con1(praca, 5000000);
			
			halpert->addContr(con1);

			Calculator calculator;

			calculator.callAllPayments(halpert);

			Details details = halpert->getDetailsPtr();
			Assert::AreEqual(488000, details.retirement);
			Assert::AreEqual(75000, details.pension);
			Assert::AreEqual(450000, details.health);
			Assert::AreEqual(122500, details.illness);
			Assert::AreEqual(850000, details.tax);
			Assert::AreEqual(1985500, halpert->getAllPayments());
			Assert::AreEqual(5000000, halpert->getAllIncomesSettled());
		}

		TEST_METHOD(TwoContracts)
		{
			Person* halpert = new Person("Jim", "Halpert", 30);
			Contract con1(praca, 5000000);
			Contract con2(zlecenie, 2000000);

			halpert->addContr(con1);
			halpert->addContr(con2);

			Calculator calculator;

			calculator.callAllPayments(halpert);

			Details details = halpert->getDetailsPtr();
			Assert::AreEqual(488000, details.retirement);
			Assert::AreEqual(75000, details.pension);
			Assert::AreEqual(630000, details.health);
			Assert::AreEqual(122500, details.illness);
			Assert::AreEqual(1190000, details.tax);
			Assert::AreEqual(2505500, halpert->getAllPayments());
			Assert::AreEqual(7000000, halpert->getAllIncomesSettled());
		}
	};
}
