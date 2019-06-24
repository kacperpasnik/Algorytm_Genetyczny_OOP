#include "pch.h"
#include "Chromosom.h"


void Chromosom::Zwycieska_pula()
{
	pula_najlepsza = chromosom;
	fenotyp_najlepszy = fenotyp;
}


void Chromosom::Obliczanie_fenotypu()
{
	fenotyp = 0;
	int zastepcza = 0;
	double potega_dwojki = 0;
	for (int i = 4; i >= 0; i--, potega_dwojki++)
	{
		if (chromosom[i] == '0')
			zastepcza = 0;
		else if (chromosom[i] == '1')
			zastepcza = 1;
		fenotyp = fenotyp + (zastepcza*pow(2, potega_dwojki));

	}

}

void Chromosom::Mutacja(float Pm)
{
	int z = 0;
	float y = 0;
	//srand(time(NULL));
	z = (rand() % 100 + 1);
	y = (float)z / 100;

	if (y < Pm)
	{
		//srand(time(NULL));
		z = rand() % 5;

		if (chromosom[z] == '0')
			chromosom[z] = '1';
		else if (chromosom[z] == '1')
			chromosom[z] = '0';
	}

}

void Chromosom::Nowy_chromosom(float kolo_ruletki[], std::string chromosomy_zastepcze[])
{
	int i = 0, z = 0;
	float losowana_liczba = 0;
	z = (rand() % 101);
	losowana_liczba = (float)z / 100;

	for (i; i < 8; i++)
	{
		losowana_liczba = losowana_liczba - kolo_ruletki[i];
		if (losowana_liczba <= 0)
		{

			chromosom = chromosomy_zastepcze[i];
		}
		else
			continue;

	}

}
Chromosom::Chromosom()
{

	chromosom = Wylosowanie_chromosomu();
	chromosom_poczatkowy = chromosom;
	Obliczanie_fenotypu();
	fenotyp_poczatkowy = fenotyp;


}
Chromosom::~Chromosom()
{

}

std::string Chromosom::Wylosowanie_chromosomu()
{
	std::string x = "aaaaa";
	int losowana_liczba = 0;
	for (int i = 0; i < 5; i++)
	{
		//srand(time(NULL));
		losowana_liczba = rand() % 2;
		if (losowana_liczba == 0)
			x[i] = '0';
		else if (losowana_liczba == 1)
			x[i] = '1';
	}

	return x;
}

