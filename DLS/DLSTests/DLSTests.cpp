#include "pch.h"
#include "CppUnitTest.h"
#include "../DLS/DLS.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DLSTests
{
	TEST_CLASS(DLSTests)
	{
	public:
		
		TEST_METHOD(TestDLSCreation)
		{
			const auto result = new DLS();
			Assert::IsNotNull(result);
		}
		TEST_METHOD(TestDLSParamCreation)
		{
			const size_t expected = 5;
			DLS result = { 1, 2, 3, 4, 5 };
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1, 2, 3, 4, 5");
		}
		TEST_METHOD(TestAddHead)
		{
			const size_t expected = 6;
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementHead(0);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "0, 1, 2, 3, 4, 5");
		}
		TEST_METHOD(TestAddHeadEmpty)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElementHead(0);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "0");
		}
		TEST_METHOD(TestAddTail)
		{
			const size_t expected = 6;
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementTail(6);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1, 2, 3, 4, 5, 6");
		}
		TEST_METHOD(TestAddTailEmpty)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElementTail(1);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1");
		}
		TEST_METHOD(TestAddElementEmpty)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElement(1, 42);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "42");
		}
		TEST_METHOD(TestAddElementException)
		{
			DLS result;
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.AddElement(-1, 255);
			});
		}
		TEST_METHOD(TestAddElement)
		{
			const size_t expected = 6;
			DLS result = { 1, 2, 3, 5, 6 };
			result.AddElement(3, 4);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1, 2, 3, 4, 5, 6");
		}
		TEST_METHOD(TestAddElementPosGrLen)
		{
			const size_t expected = 3;
			DLS result = { 1, 2 };
			result.AddElement(20, 5);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1, 2, 5");
		}
		TEST_METHOD(TestRemoveElementTailHead)
		{
			const size_t expected = 0;
			DLS result = { 1 };
			result.RemoveElement(1);
			Assert::IsTrue(result.IsEmpty() && expected == result.GetSize() && result.ToString() == "");
		}
		TEST_METHOD(TestRemoveElementHead)
		{
			const size_t expected = 4;
			DLS result = { 1, 2, 3, 4, 5};
			result.RemoveElement(1);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "2, 3, 4, 5");
		}
		TEST_METHOD(TestRemoveElementTail)
		{
			const size_t expected = 4;
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(5);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1, 2, 3, 4");
		}
		TEST_METHOD(TestRemoveElementPos)
		{
			const size_t expected = 4;
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(3);
			Assert::IsTrue(!result.IsEmpty() && expected == result.GetSize() && result.ToString() == "1, 2, 4, 5");
		}
		TEST_METHOD(TestRemoveElementException1)
		{
			DLS result = { 1, 2, 3 };
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.RemoveElement(-99);
			});
		}
		TEST_METHOD(TestRemoveElementException2)
		{
			DLS result;
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.RemoveElement(1);
			});
		}
		TEST_METHOD(TestGetSize)
		{
			const size_t expected = 3;
			DLS result = { 1, 2, 3 };
			Assert::AreEqual(expected, result.GetSize());
		}
		TEST_METHOD(TestGetElement)
		{
			const int expected = 2;
			DLS result = { 1, 2, 3 };
			Assert::AreEqual(expected, result.GetElement(2));
		}
		TEST_METHOD(TestGetElementException1)
		{
			DLS result = {1, 2, 3};
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.GetElement(-24);
			});
		}
		TEST_METHOD(TestGetElementException2)
		{
			DLS result = { 1, 2, 3 };
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.GetElement(4);
			});
		}
		TEST_METHOD(TestTo_stringEmpty)
		{
			DLS result;
			const std::string expected = "";
			Assert::AreEqual(expected, result.ToString());
		}
		TEST_METHOD(TestTo_string)
		{
			DLS result = {24, 56, 68};
			const std::string expected = "24, 56, 68";
			Assert::AreEqual(expected, result.ToString());
		}
		TEST_METHOD(TestIsEmpty)
		{
			DLS result;
			Assert::IsTrue(result.IsEmpty());
		}
		TEST_METHOD(TestIsEmptyFull)
		{
			DLS result = {4, 2};
			Assert::IsFalse(result.IsEmpty());
		}
	};
}
