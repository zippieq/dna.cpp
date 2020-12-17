
    
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Array.h"
#include "LinkedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{​​​​​​​        
    TEST_CLASS(TestArray)
    {​​​​​​​
    public:
        
        TEST_METHOD(TestMethod1)
        {​​​​​​​
            Array<int, 5> arr;
            Assert::IsTrue(arr.isEmpty());
        }​​​​​​​
        TEST_METHOD(TestMethod2)
        {​​​​​​​
            Array<int, 5> arr;
            arr.append(1);
            arr.append(2);
            arr.append(3);
            arr.append(4);
            arr.append(5);
            arr.append(6);
            Assert::AreEqual(10, arr.capacity());
        }​​​​​​​
        TEST_METHOD(TestMethod3)
        {​​​​​​​
            Array<int, 5> arr;
            arr.append(1);
            arr.append(2);
            arr.append(3);
            arr.append(4);
            arr.append(5);
            arr.append(6);
            arr.pop();
            arr.pop();
            arr.pop();
            arr.pop();
            arr.pop();
            Assert::AreEqual(2, arr.capacity());
        }​​​​​​​
        TEST_METHOD(TestMethod4)
        {​​​​​​​
            auto func = [] {​​​​​​​Array<int, 5> arr; int a = arr.itemAt(1); }​​​​​​​;
            Assert::ExpectException<std::out_of_range>(func);
        }​​​​​​​
        TEST_METHOD(TestMethod5)
        {​​​​​​​
            Array<int, 5> arr;
            arr.append(1);
            arr.append(2);
            arr.append(3);
            arr.append(4);
            arr.append(5);
            arr.append(6);
            arr.removeAt(3);
            Assert::AreEqual(5, arr.itemAt(3));
        }​​​​​​​
    }​​​​​​​;
    TEST_CLASS(TestLinkedList)
    {​​​​​​​
    public:


        TEST_METHOD(TestMethod1)
        {​​​​​​​
            LinkedList<int> link;
            Assert::IsTrue(link.isEmpty());
        }​​​​​​​
        TEST_METHOD(TestMethod2)
        {​​​​​​​
            LinkedList<int> link;
            link.pushFront(1);
            link.pushFront(2);
            link.pushFront(3);
            link.pushFront(4);
            link.pushFront(5);
            link.pushFront(6);
            Assert::AreEqual(6, link.size());
            Assert::AreEqual(6, link.front());
        }​​​​​​​
        TEST_METHOD(TestMethod3)
        {​​​​​​​
            LinkedList<int> link;
            link.pushFront(1);
            Assert::AreEqual(1, link.front());
            Assert::AreEqual(1, link.back());
            Assert::AreEqual(1, link.valueAt(0));
            link.pushFront(2);
            Assert::AreEqual(1, link.back());
            Assert::AreEqual(2, link.size());


            Assert::AreEqual(2, link.front());
            link.pushFront(3);
            link.pushFront(4);
            link.pushFront(5);
            link.pushFront(6);
            Assert::AreEqual(4, link.valueAt(2));
            link.popFront();
            link.popFront();
            link.popFront();
            link.popFront();
            Assert::AreEqual(1, link.back());
            Assert::AreEqual(2, link.size());


            Assert::AreEqual(2, link.front());
        }​​​​​​​


        TEST_METHOD(TestMethod4)
        {​​​​​​​
            LinkedList<int> link;
            link.pushBack(1);
            link.pushBack(2);
            link.pushBack(3);
            link.pushBack(4);
            link.pushBack(5);
            link.pushBack(6);
            Assert::AreEqual(6, link.back());
            Assert::AreEqual(3, link.valueAt(2));
            link.popBack();
            link.popBack();
            link.popBack();
            link.popBack();
            link.popBack();
            link.popBack();
            Assert::AreEqual(0, link.size());
        }​​​​​​​


        TEST_METHOD(TestMethod5)
        {​​​​​​​
            LinkedList<int> link;
            link.pushBack(1);
            link.pushBack(2);
            link.pushBack(3);
            link.pushBack(4);
            link.pushBack(5);
            link.pushBack(6);
            link.popBack();
            link.popBack();
            link.popBack();
            link.popBack();
            link.popBack();
            link.popBack();
            Assert::AreEqual(0, link.size());
        }​​​​​​​


        TEST_METHOD(TestRemove)
        {​​​​​​​
            LinkedList<int> link;
            link.pushBack(1);
            link.pushBack(2);
            link.pushBack(3);
            link.pushBack(4);
            link.pushBack(5);
            link.pushBack(6);
            link.remove(2);
            Assert::AreEqual(4, link.valueAt(2));
            Assert::AreEqual(5, link.size());
        }​​​​​​​
        TEST_METHOD(TestInsert)
        {​​​​​​​
            LinkedList<int> link;
            link.pushBack(1);
            link.pushBack(2);
            link.pushBack(3);
            link.pushBack(4);
            link.pushBack(5);
            link.pushBack(6);
            link.insert(2, 2);
            //Assert::AreEqual(2, link.valueAt(2));
            Assert::AreEqual(7, link.size());
        }​​​​​​​
    }​​​​​​​;
}​​​​​​​










