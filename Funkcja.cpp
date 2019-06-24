#include "pch.h"
#include "Funkcja.h"


	int Funkcja::Obliczanie_funkcji_przystosowania(int x)
	{
		return ((a*pow(x, 3)) + (b*pow(x, 2)) + (c*x) + d)+minusowa_funkcja;
	}

	int Funkcja::Maksimum_funkcji()
	{
		int wynik = Obliczanie_funkcji_przystosowania(0);
		int wynik_funkcji = wynik;
		for (int i = 0; i <= 31; i++)
		{
			wynik_funkcji = Obliczanie_funkcji_przystosowania(i);
			if (wynik < wynik_funkcji)
			{
				wynik = wynik_funkcji;
			}
		}
		return wynik;


	}

	Funkcja::Funkcja()
	{
		std::cout << "Podaj wspolczynniki a, b, c oraz d: ";
		std::cin >> a >> b >> c >> d;
		std::cout << "Podaj wspolczynnik krzyzowania: ";
		std::cin >> Pk;
		std::cout << "Podaj wspolczynnik mutacji: ";
		std::cin >> Pm;
		minusowa_funkcja = Mnimum_funkcji() * (-1);
		max_funkcji = Maksimum_funkcji();
	}
	Funkcja::~Funkcja()
	{

	}


	int Funkcja::Mnimum_funkcji()
	{
		int wynik = Obliczanie_funkcji_przystosowania(0);
		int wynik_funkcji = wynik;
		for (int i = 0; i <= 31; i++)
		{
			wynik_funkcji = Obliczanie_funkcji_przystosowania(i);
			if (wynik > wynik_funkcji)
			{
				wynik = wynik_funkcji;
			}
		}

		if (wynik > 0)
			return 0;
		else
			return wynik;
	}