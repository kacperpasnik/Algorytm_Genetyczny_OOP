
#include "pch.h"
#include "Funkcja.h"
#include "Chromosom.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

int main()
{
	srand(time(NULL));

	Funkcja funkcja;
	Chromosom chromosomy[6];
	float kolo_ruletki[6];
	std::string chromosom_zastepczy[6];
	for (int i = 0; i < 6; i++)
		chromosom_zastepczy[i] = "00000";
	int najlepszy_chromosom = 0;
	//zmienna potrzebna do losowania
	int p = 0;
	float losowanie_krzyzowania = 0;
	float funkcja_przystosowania_max = 0;
	int max_fenotyp = 0;
	int max_suma = 0;
	float suma_przystosowania = 0;
	//ilosc iteracji algorytmu
	int iteracje = 0;

	int ilosc_iteracji = 0;
	std::cout << "Podaj ilosc iteracji: ";
	std::cin >> ilosc_iteracji;
	for (int j = 0; j < 6; j++)
	{
		chromosomy[j].funkcja_przystosowania = funkcja.Obliczanie_funkcji_przystosowania(chromosomy[j].fenotyp);
		suma_przystosowania = suma_przystosowania + chromosomy[j].funkcja_przystosowania;
	}
	for (iteracje; iteracje <= ilosc_iteracji; iteracje++)
	{



		//zliczenie sumy przystosowania
		for (int j = 0; j < 6; j++)
		{
			kolo_ruletki[j] = chromosomy[j].funkcja_przystosowania / suma_przystosowania;
			chromosom_zastepczy[j] = chromosomy[j].chromosom;

		}
		//selekcja i ruletka
		for (int j = 0; j < 6; j++)
			chromosomy[j].Nowy_chromosom(kolo_ruletki, chromosom_zastepczy);

		//krzyzowanie
		for (int j = 0; j < 6; j = j + 2)
		{

			p = rand() % 100 + 1;
			losowanie_krzyzowania = (float)p / 100;

			if (losowanie_krzyzowania < funkcja.Pk)
			{
				p = rand() % 4 + 1;

				for (int k = p; k <= 4; k++)
					std::swap(chromosomy[j].chromosom[k], chromosomy[j + 1].chromosom[k]);
			}
			else
			{

				continue;
			}
		}
		//mutacja
		for (int j = 0; j < 6; j++)
		{

			chromosomy[j].Mutacja(funkcja.Pm);
		}

		suma_przystosowania = 0;
		for (int j = 0; j < 6; j++)
		{
			chromosomy[j].Obliczanie_fenotypu();
			chromosomy[j].funkcja_przystosowania = funkcja.Obliczanie_funkcji_przystosowania(chromosomy[j].fenotyp);
			suma_przystosowania = suma_przystosowania + chromosomy[j].funkcja_przystosowania;

		}

		funkcja_przystosowania_max = chromosomy[0].funkcja_przystosowania;
		if (max_suma <= suma_przystosowania)
		{
			max_suma = suma_przystosowania;
			for (int j = 0; j < 6; j++)
			{
				chromosomy[j].Zwycieska_pula();

				if (funkcja_przystosowania_max <= chromosomy[j].funkcja_przystosowania)
				{
					funkcja_przystosowania_max = chromosomy[j].funkcja_przystosowania;
					max_fenotyp = chromosomy[j].fenotyp;
					najlepszy_chromosom = j;
				}
			}
		}


	}
	//wyniki
	std::cout << std::endl << "Wynik:\n\n"  << "Po " << iteracje-1 << " iteracjach otrzymalismy: \n"<< "\nPula poczatkowa: " << std::endl;
	for (int j = 0; j < 6; j++)
		std::cout << "Chromosom " << j + 1 << ": " << chromosomy[j].chromosom_poczatkowy << ", a jego fenotyp: " << chromosomy[j].fenotyp_poczatkowy << std::endl;
	std::cout << "Pula \"zwycieska\": " << std::endl;
	for (int j = 0; j < 6; j++)
		std::cout << "Chromosom " << j + 1 << ": " << chromosomy[j].pula_najlepsza << ", a jego fenotyp: " << chromosomy[j].fenotyp_najlepszy << std::endl;
	std::cout << "Maksymalna wartosc funkcji dla naszego przedzialu: " << funkcja.max_funkcji << std::endl;
	std::cout << "Wartosc 'x' dla maksymalnej wartosci dla naszego przedzialu: " << funkcja.Obliczanie_funkcji_przystosowania(max_fenotyp) << std::endl;
	std::cout << "Wybrany zostal chromosom o numerze: " << najlepszy_chromosom << " " << chromosomy[najlepszy_chromosom].pula_najlepsza << " " << chromosomy[najlepszy_chromosom].fenotyp_najlepszy << std::endl;

	return 0;
}


