#include "pch.h"
#include "CppUnitTest.h"
#include "../LODOWKA/dodawanie_produktu.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LODOWKATEST
{
	TEST_CLASS(LODOWKATEST)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Produkt test(1, 1, "jasio");
			string utworzony = test.nazwa;
			vector<Produkt> wczytane = wczytajProduktyZPliku("produkty.txt");
			string wczytany = wczytane[0].nazwa;

			Assert::AreEqual(utworzony, wczytany);
		}
		TEST_METHOD(TestMethod2)
		{
			//wczytywanie z klawiatury

			string nazwa_klawiatura = Wczytaj_dane_produktu();
			Produkt test(1, 1, "maslo");
			string nazwa_testowa = "maslo";
			Assert::AreEqual(nazwa_testowa, nazwa_klawiatura);
		}
	};
}
