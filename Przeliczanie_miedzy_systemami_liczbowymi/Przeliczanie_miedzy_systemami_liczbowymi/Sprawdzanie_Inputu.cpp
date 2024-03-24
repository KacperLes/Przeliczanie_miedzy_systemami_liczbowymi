#include <iostream>
#include <cmath>
#include "funkcje.h"

int Sprawdzanie_systemu(std::string liczba) {
	int liczba_int = 0;
	for (int i = liczba.length() - 1; i >= 0; i--)
	{
		char znak = std::toupper(liczba[i]);
		if (int(znak) - 48 >= 0 && int(znak) - 48 <= 9) {
			liczba_int += pow(10, liczba.length() - i - 1) * (int(znak) - 48);
		}
		else
		{
			return -1;
		}
		
	}
	return liczba_int;
};
bool Sprawdzanie_czy_liczba_poprawna(std::string liczba, int system_poczatkowy) {
	if (system_poczatkowy <= 10)
		for (int i = 0; i < liczba.length(); i++) {
			if (!(int(liczba[i]) - 48 < system_poczatkowy))
				return false;
		}
	else 
		for (int i = 0; i < liczba.length(); i++) {
			char znak = std::toupper(liczba[i]);
			if (!(int(liczba[i]) - 48 < system_poczatkowy || int(znak - 55) < system_poczatkowy))
				return false;
		}
	return true;
}