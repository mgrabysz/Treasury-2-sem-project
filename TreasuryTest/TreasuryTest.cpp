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
			
		}
	};
}
