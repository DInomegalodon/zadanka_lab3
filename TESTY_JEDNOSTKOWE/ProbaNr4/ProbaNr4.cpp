#include "pch.h"
#include "CppUnitTest.h"
#include "../Proba4/funkcja.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProbaNr4
{
	TEST_CLASS(ProbaNr4)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int oczekiwany = 12;
			int wynik = zad_1(2,3);

			Assert::AreEqual(oczekiwany, wynik);

		}
		TEST_METHOD(TestMethod2)
		{
			int oczekiwany = 18;
			int wynik = zad_1(3, 3);

			Assert::AreEqual(oczekiwany, wynik);

		}
	};
}
