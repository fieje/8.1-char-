#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1(char)/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestCountFunction)
		{
			char str1[] = "++-++-+--+";
			Assert::AreEqual(4, Count(str1));

			char str2[] = "+-+-+-+";
			Assert::AreEqual(3, Count(str2));

			char str3[] = "+++";
			Assert::AreEqual(0, Count(str3));

			char str4[] = "";
			Assert::AreEqual(0, Count(str4));
		}

		TEST_METHOD(TestChangeFunction)
		{
			char str1[] = "++-++-+--+.+";
			Assert::AreEqual("++++****++*..", Change(str1));

			char str2[] = "+-+-+-+...+";
			Assert::AreEqual("++++****++...*", Change(str2));

			char str3[] = "+++";
			Assert::AreEqual("+++", Change(str3));

			char str4[] = "";
			Assert::AreEqual("", Change(str4));
		}
	};
}
