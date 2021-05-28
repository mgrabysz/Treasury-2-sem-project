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



	};
}
