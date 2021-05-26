#include "../Treasury/TwoWayList.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TwoWayListUnitTest)
	{
	public:
		TEST_METHOD(twowaylist_create_empty)
		{
			TwoWayList<int> my_list;
			Assert::IsTrue(my_list.size() == 0);
		}

		TEST_METHOD(twowaylist_create_one_elem)
		{
			TwoWayList<int> my_list(0);
			Assert::IsTrue(my_list.size() == 1);
			Assert::IsTrue(my_list.getNode(0)->getVal() == 0);
			Assert::IsTrue(my_list.getNode(0)->getNext() == nullptr);
			Assert::IsTrue(my_list.getNode(0)->getPrev() == nullptr);
		}

		TEST_METHOD(twowaylist_create_decent_size)
		{
			TwoWayList<int> my_list({ 3, 2, 1, 5, 7, 8 });
			Assert::IsTrue(my_list.size() == 6);
			Assert::IsTrue(my_list.getNode(0)->getVal() == 3);
			Assert::IsTrue(my_list.getNode(0)->getNext()->getVal() == 2);
			Assert::IsTrue(my_list.getNode(5)->getPrev()->getVal() == 7);
		}

		TEST_METHOD(twowaylist_append_to_empty)
		{
			TwoWayList<int> my_list;
			Assert::IsTrue(my_list.size() == 0);
			my_list.appendToEmpty(1);
			Assert::IsTrue(my_list.size() == 1);
			Assert::IsTrue(my_list.getNode(0)->getVal() == 1);
		}

		TEST_METHOD(twowaylist_add_to_begin)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getNode(0)->getVal() == 5);
			my_list.addToBegin(1);
			Assert::IsTrue(my_list.size() == 5);
			Assert::IsTrue(my_list.getNode(0)->getVal() == 1);
		}

		TEST_METHOD(twowaylist_append)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getNode(3)->getVal() == 8);
			my_list.append(1);
			Assert::IsTrue(my_list.size() == 5);
			Assert::IsTrue(my_list.getNode(4)->getVal() == 1);
		}

		TEST_METHOD(twowaylist_insert)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getNode(2)->getVal() == 7);
			TwoWayList<int>::Iterator iter = my_list.begin();
			iter += 2;
			my_list.insert(iter, 1);
			Assert::IsTrue(my_list.size() == 5);
			Assert::IsTrue(my_list.getNode(2)->getVal() == 1);
		}

		TEST_METHOD(twowaylist_getval_bad)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getVal(-1) == 0);
		}

		TEST_METHOD(twowaylist_destroy)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			my_list.destroy();
			Assert::IsTrue(my_list.size() == 0);
		}

		TEST_METHOD(twowaylist_removeFirst)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getVal(0) == 5);
			my_list.removeFirst();
			Assert::IsTrue(my_list.size() == 3);
			Assert::IsTrue(my_list.getVal(0) == 6);
		}

		TEST_METHOD(twowaylist_remove_last)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getVal(3) == 8);
			my_list.removeLast();
			Assert::IsTrue(my_list.size() == 3);
			Assert::IsTrue(my_list.getVal(2) == 7);
		}

		TEST_METHOD(twowaylist_remove)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			Assert::IsTrue(my_list.size() == 4);
			Assert::IsTrue(my_list.getVal(3) == 8);
			TwoWayList<int>::Iterator iter = my_list.begin();
			iter++;
			my_list.remove(iter);
			Assert::IsTrue(my_list.size() == 3);
			Assert::IsTrue(my_list.getVal(1) == 7);
		}

		//TEST_METHOD(twowaylist_pop)
		//{
		//	TwoWayList<int> my_list({ 5, 6, 7, 8 });
		//	Assert::IsTrue(my_list.size() == 4);
		//	Assert::IsTrue(my_list.getVal(3) == 8);
		//	Node<int>* my_nod = my_list.pop();
		//	Assert::IsTrue(my_list.size() == 3);
		//	Assert::IsTrue(my_list.getVal(2) == 7);
		//	Assert::IsTrue(my_nod->getVal() == 8);
		//}

		TEST_METHOD(twowaylist_iterator_increment)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			TwoWayList<int>::Iterator iter = my_list.begin();
			Assert::IsTrue(*iter == 5);
			Assert::IsTrue(*(iter++) == 5);
			Assert::IsTrue(*iter == 6);
			Assert::IsTrue(*(++iter) == 7);
		}

		TEST_METHOD(twowaylist_iterator_decrement)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			TwoWayList<int>::Iterator iter = my_list.end();
			Assert::IsTrue(*iter == 8);
			Assert::IsTrue(*(iter--) == 8);
			Assert::IsTrue(*iter == 7);
			Assert::IsTrue(*(--iter) == 6);
		}

		TEST_METHOD(twowaylist_iterator_increment_by_int)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			TwoWayList<int>::Iterator iter = my_list.begin();
			Assert::IsTrue(*iter == 5);
			iter += 2;
			Assert::IsTrue(*iter == 7);
		}

		TEST_METHOD(twowaylist_iterator_decrement_by_int)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			TwoWayList<int>::Iterator iter = my_list.end();
			Assert::IsTrue(*iter == 8);
			iter -= 2;
			Assert::IsTrue(*iter == 6);
		}

		TEST_METHOD(twowaylist_iterator_equal)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			TwoWayList<int>::Iterator iter1 = my_list.begin();
			TwoWayList<int>::Iterator iter2 = my_list.end();
			Assert::IsTrue(iter1 != iter2);
			iter2 -= 3;
			Assert::IsTrue(iter1 == iter2);

		}

		TEST_METHOD(twowaylist_iterator_reverse)
		{
			TwoWayList<int> my_list({ 5, 6, 7, 8 });
			TwoWayList<int>::Iterator iter = my_list.begin();
			iter += 2;
			Assert::IsTrue(*iter == 7);
			Assert::IsTrue(*(--iter) == 6);
			iter.reverse();
			iter -= 1;
			Assert::IsTrue(*iter == 7);
			Assert::IsTrue(*(++iter) == 6);
		}

	};
}
