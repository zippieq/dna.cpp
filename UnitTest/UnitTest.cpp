#include "CppUnitTest.h"
#include "Array.h"
#include "LinkedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace UnitTest1
{
    TEST_CLASS(TestArray)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Array<int, 5> arr;
            Assert::IsTrue(arr.isEmpty());
        }
        TEST_METHOD(TestMethod2)
        {
            Array<int, 5> arr;
            arr.append(1);
            arr.append(2);
            arr.append(3);
            arr.append(4);
            arr.append(5);
            arr.append(6);
            Assert::AreEqual(10, arr.capacity());
        }
        TEST_METHOD(TestMethod3)
        {
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
        }
        TEST_METHOD(TestMethod4)
        {
            auto func = [] {Array<int, 5> arr; int a = arr.itemAt(1); };
            Assert::ExpectException<std::out_of_range>(func);
        }
        TEST_METHOD(TestMethod5)
        {
            Array<int, 5> arr;
            arr.append(1);
            arr.append(2);
            arr.append(3);
            arr.append(4);
            arr.append(5);
            arr.append(6);
            arr.removeAt(3);
            Assert::AreEqual(5, arr.itemAt(3));
        }
    };

}