#include "pch.h"
#include "CppUnitTest.h"
#include  "E:\Rep\Aig_lab№1\Aig_lab№1\BRTree.h"
#include "E:\Rep\Aig_lab№1\Aig_lab№1\List.h"
#include "E:\Rep\Aig_lab№1\Aig_lab№1\functionBRTree.h"
#include "E:\Rep\Aig_lab№1\Aig_lab№1\functionList.h"
#include "E:\Rep\Aig_lab№1\Aig_lab№1\functionStack.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(RBTree_Test1)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			List<int>* list;
			tree->insert(11, 1);
			tree->insert(2, 3);
			tree->insert(14, 5);
			tree->insert(15, 6);
			tree->insert(5, 4);
			tree->insert(3, 2);
			list = tree->get_keys();
			List<int>* list_test = new List<int>;
			list_test->push_back(11);
			list_test->push_back(3);
			list_test->push_back(2);
			list_test->push_back(5);
			list_test->push_back(14);
			list_test->push_back(15);
			for (int i = 0; i < list->get_size(); i++) {
				Assert::IsTrue(list->at(i) == list_test->at(i));
			}
		}
		TEST_METHOD(RBTree_Test2)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			List<int>* list;
			tree->insert(11, 1);
			tree->insert(2, 3);
			tree->insert(14, 5);
			tree->insert(15, 6);
			tree->insert(5, 4);
			tree->insert(3, 2);
			tree->remove(2);
			list = tree->get_keys();
			List<int>* list_test = new List<int>;
			list_test->push_back(11);
			list_test->push_back(3);
			list_test->push_back(5);
			list_test->push_back(14);
			list_test->push_back(15);
			for (int i = 0; i < list->get_size(); i++) {
				Assert::IsTrue(list->at(i) == list_test->at(i));
			}
		}
		TEST_METHOD(RBTree_Test3)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			Node<int, int>* key;
			tree->insert(11, 1);
			tree->insert(2, 3);
			tree->insert(14, 5);
			tree->insert(15, 6);
			tree->insert(5, 4);
			tree->insert(3, 2);
			key = tree->find(14);
			Assert::IsTrue(key->key == 14);
		}
		TEST_METHOD(RBTree_Test4)
		{
			try
			{
				RBTree<int, int>* tree = new RBTree<int, int>;
				tree->insert(11, 1);
				tree->insert(2, 3);
				tree->insert(14, 5);
				tree->insert(15, 6);
				tree->insert(5, 4);
				tree->insert(3, 2);
				tree->find(20);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "No such element exists");
			}
		}
		TEST_METHOD(RBTree_Test5)
		{
			try
			{
				RBTree<int, int>* tree = new RBTree<int, int>;
				tree->get_keys();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "There is no element");
			}
		}
		TEST_METHOD(RBTree_Test6)
		{
			try
			{
				RBTree<int, int>* tree = new RBTree<int, int>;
				tree->get_values();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "There is no element");
			}
		}
		TEST_METHOD(RBTree_Test7)
		{
			RBTree<int, int>* tree = new RBTree<int, int>;
			tree->insert(11, 1);
			tree->insert(2, 3);
			tree->insert(14, 5);
			tree->insert(15, 6);
			tree->insert(5, 4);
			tree->insert(3, 2);
			tree->clear();
			Assert::IsTrue(tree->Root == nullptr);
			Assert::IsTrue(tree->get_nil() == nullptr);
		}
	};
}
