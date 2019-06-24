#pragma once
#include <iostream>
class Funkcja
{
public:
	//wspolczynniki funkcji
	int a = 0, b = 0, c = 0, d = 0;
	//wspolczynnik krzyzowania
	float Pk = 0;
	//wspolczynnik mutacji
	float Pm = 0;
	//zmienna potrzebna, gdy funkcja bedzie miala ujemne funckje przystosowania
	int minusowa_funkcja = 0;
	int max_funkcji = 0;

	int Obliczanie_funkcji_przystosowania(int x);
	int Maksimum_funkcji();
	Funkcja();
	~Funkcja();

private:
	int Mnimum_funkcji();
};

