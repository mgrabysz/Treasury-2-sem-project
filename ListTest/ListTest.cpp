#include "CppUnitTest.h"
#include "../Treasury/TwoWayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTest
{
	TEST_CLASS(ListTest)
	{
	public:
		
		TEST_METHOD(collection_constructor)
		{
			TwoWayList<int> collection;
			collection.push(5);

			TwoWayList<int>::Iterator i = collection.begin();
			auto my_number = *i;
			Assert::AreEqual(5, my_number);
		}
		TEST_METHOD(collection_iterator)
		{
			TwoWayList<int> collection;
			collection.push(10);
			collection.push(11);
			collection.push(12);

			TwoWayList<int>::Iterator i = collection.begin();
			int number_0 = *i;
			++i;
			int number_1 = *i;
			++i;
			int number_2 = *i;
			Assert::AreEqual(10, number_0);
			Assert::AreEqual(11, number_1);
			Assert::AreEqual(12, number_2);
		}
		TEST_METHOD(collection_iterator_backward)
		{
			TwoWayList<int> collection;
			collection.push(20);
			collection.push(21);
			collection.push(22);

			TwoWayList<int>::Iterator i = collection.end();
			--i;
			int number_2 = *i;
			--i;
			int number_1 = *i;
			--i;
			int number_0 = *i;
			Assert::AreEqual(20, number_0);
			Assert::AreEqual(21, number_1);
			Assert::AreEqual(22, number_2);
		}
		TEST_METHOD(iterator_range_error_right)
		{
			auto func = [] {
				TwoWayList<int> collection;
				collection.push(2);
				collection.push(4);
				TwoWayList<int>::Iterator i = collection.end();
				++i;
			};
			Assert::ExpectException<std::range_error>(func);
		}
		TEST_METHOD(iterator_range_error_left)
		{
			auto func = [] {
				TwoWayList<int> collection;
				collection.push(5);
				collection.push(2);
				TwoWayList<int>::Iterator i = collection.begin();
				--i;
			};
			Assert::ExpectException<std::range_error>(func);
		}
		TEST_METHOD(collection_add_middle)
		{
			TwoWayList<int> collection;
			collection.push(30);
			collection.push(31);
			collection.push(32);

			TwoWayList<int>::Iterator i = collection.begin();
			++i;	// i is pointing to 31

			collection.add(100, i);
			collection.add(200, i);

			// expected order in collection: 30, 200, 100, 31, 32

			TwoWayList<int>::Iterator iter = collection.begin();
			Assert::AreEqual(30, *iter);
			++iter;
			Assert::AreEqual(200, *iter);
			++iter;
			Assert::AreEqual(100, *iter);
			++iter;
			Assert::AreEqual(31, *iter);
			++iter;
			Assert::AreEqual(32, *iter);
		}
		TEST_METHOD(add_begin)
		{
			TwoWayList<int> collection;
			collection.push(40);
			collection.push(41);

			TwoWayList<int>::Iterator i = collection.begin();

			collection.add(100, i);
			collection.add(200, i);

			// expected order in collection: 200, 100, 40, 41

			TwoWayList<int>::Iterator iter = collection.begin();
			Assert::AreEqual(200, *iter);
			++iter;
			Assert::AreEqual(100, *iter);
			++iter;
			Assert::AreEqual(40, *iter);
			++iter;
			Assert::AreEqual(41, *iter);
		}
		TEST_METHOD(add_end)
		{
			TwoWayList<int> collection;
			collection.push(50);
			collection.push(51);

			TwoWayList<int>::Iterator i = collection.end();

			collection.add(100, i);
			collection.add(200, i);

			// expected order in collection: 50, 51, 100, 200

			TwoWayList<int>::Iterator iter = collection.begin();
			Assert::AreEqual(50, *iter);
			++iter;
			Assert::AreEqual(51, *iter);
			++iter;
			Assert::AreEqual(100, *iter);
			++iter;
			Assert::AreEqual(200, *iter);
		}
		TEST_METHOD(del_middle)
		{
			TwoWayList<int> collection;
			collection.push(60);
			collection.push(61);
			collection.push(62);
			collection.push(63);

			TwoWayList<int>::Iterator i = collection.begin();
			++i;	// i is pointing to 61
			collection.del(i);
			collection.del(i);

			// expected order in collection: 60, 63
			TwoWayList<int>::Iterator iter = collection.begin();
			Assert::AreEqual(60, *iter);
			++iter;
			Assert::AreEqual(63, *iter);
		}
		TEST_METHOD(del_begin)
		{
			TwoWayList<int> collection;
			collection.push(70);
			collection.push(71);
			collection.push(72);
			collection.push(73);

			TwoWayList<int>::Iterator i = collection.begin();
			collection.del(i);
			collection.del(i);

			// expected order in collection: 72, 73
			TwoWayList<int>::Iterator iter = collection.begin();
			Assert::AreEqual(72, *iter);
			++iter;
			Assert::AreEqual(73, *iter);
		}
		TEST_METHOD(del_last)
		{
			TwoWayList<int> collection;
			collection.push(80);
			collection.push(81);
			collection.push(82);
			collection.push(83);

			TwoWayList<int>::Iterator i = collection.end();
			--i;	// i is pointing to 83
			collection.del(i);
			--i;
			collection.del(i);

			// expected order in collection: 80, 81
			TwoWayList<int>::Iterator iter = collection.begin();
			Assert::AreEqual(80, *iter);
			++iter;
			Assert::AreEqual(81, *iter);
		}
		TEST_METHOD(del_end)
		{
			auto func = [] {
				TwoWayList<int> collection;
				collection.push(5);
				collection.push(2);
				TwoWayList<int>::Iterator i = collection.end();
				collection.del(i);
			};
			Assert::ExpectException<std::range_error>(func);
		}
	};
}
