#include "pch.h"
#include "CppUnitTest.h"
#include "../DLS/DLS.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DLSTests
{
	TEST_CLASS(DLSTests)
	{
	public:
		
		TEST_METHOD(DLS_Creation)
		{
			const auto result = new DLS();
			Assert::IsNotNull(result);
		}

		TEST_METHOD(DLS_ParamCreation_Size)
		{
			const size_t expected = 5;
			DLS result = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(DLS_ParamCreation_NotEmpty)
		{
			DLS result = { 1, 2, 3, 4, 5 };
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(DLS_ParamCreation_Order)
		{
			const std::string expected = "1, 2, 3, 4, 5";
			DLS result = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddHead_Size)
		{
			const size_t expected = 6;
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementHead(0);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddHead_NotEmpty)
		{
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementHead(0);
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(AddHead_Order)
		{
			const std::string expected = "0, 1, 2, 3, 4, 5";
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementHead(0);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddHeadEmpty_Size)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElementHead(0);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddHeadEmpty_NotEmpty)
		{
			DLS result;
			result.AddElementHead(0);
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(AddHeadEmpty_Order)
		{
			const std::string expected = "0";
			DLS result;
			result.AddElementHead(0);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddTail_Size)
		{
			const size_t expected = 6;
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementTail(6);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddTail_NotEmpty)
		{
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementTail(6);
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(AddTail_Order)
		{
			const std::string expected = "1, 2, 3, 4, 5, 6";
			DLS result = { 1, 2, 3, 4, 5 };
			result.AddElementTail(6);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddTailEmpty_Size)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElementTail(1);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddTailEmpty_NotEmpty)
		{
			DLS result;
			result.AddElementTail(1);
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(AddTailEmpty_Order)
		{
			const std::string expected = "1";
			DLS result;
			result.AddElementTail(1);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddElementEmpty_Size)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElement(1, 42);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddElementEmpty_NotEmpty)
		{
			const size_t expected = 1;
			DLS result;
			result.AddElement(1, 42);
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(AddElementEmpty_Order)
		{
			const std::string expected = "42";
			DLS result;
			result.AddElement(1, 42);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddElement_NegPos)
		{
			DLS result;
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.AddElement(-1, 255);
			});
		}

		TEST_METHOD(AddElement_Order)
		{
			const std::string expected = "1, 2, 3, 4, 5, 6";
			DLS result = { 1, 2, 3, 5, 6 };
			result.AddElement(3, 4);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(AddElement_Size)
		{
			const size_t expected = 6;
			DLS result = { 1, 2, 3, 5, 6 };
			result.AddElement(3, 4);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddElement_PosGrLen_Size)
		{
			const size_t expected = 3;
			DLS result = { 1, 2 };
			result.AddElement(20, 5);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(AddElement_PosGrLen_Order)
		{
			const std::string expected = "1, 2, 5";
			DLS result = { 1, 2 };
			result.AddElement(20, 5);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(RemoveElementTailHead_Size)
		{
			const size_t expected = 0;
			DLS result = { 1 };
			result.RemoveElement(1);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(RemoveElementTailHead_Empty)
		{
			DLS result = { 1 };
			result.RemoveElement(1);
			Assert::IsTrue(result.IsEmpty());
		}

		TEST_METHOD(RemoveElementHead_Size)
		{
			const size_t expected = 4;
			DLS result = { 1, 2, 3, 4, 5};
			result.RemoveElement(1);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(RemoveElementHead_NotEmpty)
		{
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(1);
			Assert::IsFalse(result.IsEmpty());
		}

		TEST_METHOD(RemoveElementHead_Order)
		{
			const std::string expected = "2, 3, 4, 5";
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(1);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(RemoveElementTail_Size)
		{
			const size_t expected = 4;
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(5);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(RemoveElementTail_Order)
		{
			const std::string expected = "1, 2, 3, 4";
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(5);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(RemoveElementPos_Size)
		{
			const size_t expected = 4;
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(3);
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(RemoveElementPos_Order)
		{
			const std::string expected = "1, 2, 4, 5";
			DLS result = { 1, 2, 3, 4, 5 };
			result.RemoveElement(3);
			Assert::AreEqual(result.ToString(), expected);
		}

		TEST_METHOD(RemoveElement_NegPos)
		{
			DLS result = { 1, 2, 3 };
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.RemoveElement(-99);
			});
		}

		TEST_METHOD(RemoveElement_Empty)
		{
			DLS result;
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.RemoveElement(1);
			});
		}

		TEST_METHOD(GetSize)
		{
			const size_t expected = 3;
			DLS result = { 1, 2, 3 };
			Assert::AreEqual(expected, result.GetSize());
		}

		TEST_METHOD(GetElement)
		{
			const int expected = 2;
			DLS result = { 1, 2, 3 };
			Assert::AreEqual(expected, result.GetElement(2));
		}

		TEST_METHOD(GetElement_NegPos)
		{
			DLS result = {1, 2, 3};
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.GetElement(-24);
			});
		}

		TEST_METHOD(GetElement_PosGrLen)
		{
			DLS result = { 1, 2, 3 };
			Assert::ExpectException<std::out_of_range>([&]
			{
				result.GetElement(4);
			});
		}

		TEST_METHOD(ToString_Empty)
		{
			DLS result;
			const std::string expected = "";
			Assert::AreEqual(expected, result.ToString());
		}

		TEST_METHOD(ToString)
		{
			DLS result = {24, 56, 68};
			const std::string expected = "24, 56, 68";
			Assert::AreEqual(expected, result.ToString());
		}

		TEST_METHOD(IsEmpty)
		{
			DLS result;
			Assert::IsTrue(result.IsEmpty());
		}

		TEST_METHOD(IsNotEmpty)
		{
			DLS result = {4, 2};
			Assert::IsFalse(result.IsEmpty());
		}
	};
}
