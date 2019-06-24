#pragma once
#include <string>
class Chromosom
{
public:
	std::string chromosom = "00000";
	int fenotyp = 0;
	std::string chromosom_poczatkowy = "00000";
	std::string pula_najlepsza = "00000";
	int fenotyp_poczatkowy = 0;
	int fenotyp_najlepszy = 0;
	float funkcja_przystosowania = 0;

	void Zwycieska_pula();
	void Obliczanie_fenotypu();
	void Mutacja(float Pm);
	void Nowy_chromosom(float kolo_ruletki[], std::string chromosomy_zastepcze[]);
	Chromosom();
	~Chromosom();

private:
	std::string Wylosowanie_chromosomu();
};

