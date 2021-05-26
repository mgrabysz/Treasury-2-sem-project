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
			std::string exp = "1. Lukasz Kuli\n";
			Assert::AreEqual(exp, treasury.showPeople());
		}
	};
}
