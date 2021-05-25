#include "../Treasury/Payments.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PaymentTests
{
	TEST_CLASS(PaymentTests)
	{
	public:
		
		TEST_METHOD(Retirement_employment)
			// umowa o prace
		{  
			Person scott("Michael", "Scott", 45);
			Contract contract(praca, 800000);
			Retirement retirementCalc;
			int payment;
			
			payment = retirementCalc.calculate(scott, contract);

			Assert::AreEqual(78080, payment);
		}
	};
}
