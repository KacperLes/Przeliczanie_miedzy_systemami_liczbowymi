#include <iostream>
#include <string>
#include <cmath>
#include "funkcje.h"
#include "Sprawdzanie_Inputu.h"

void funkcje::Program() {
	Pytania(); // Pytania o parametry
	
	if (system_z_ktorego_przeliczamy != 10) // Przeliczanie
		Przeliczanie_na_system_10();
	if (system_do_ktorego_przeliczamy != 10) // Przeliczanie
		Przeliczanie_na_system_docelowy();
	
	Wyswietlanie_wyniku(); // Wyniki
}
void funkcje::Pytania() {
	std::cout << "Podaj z jakiego system przeliczamy liczbe <2,16>: ";
	std::cin >> system_z_kp_string;
		system_z_ktorego_przeliczamy = Podaj_system_ponownie(system_z_kp_string); // Sprawdzanie czy podany system jest poprawny
	
	std::cout << "Podaj w jakim systemie chcesz otrzymac liczbe <2,16>: ";
	std::cin >> system_do_kp_string;
		system_do_ktorego_przeliczamy = Podaj_system_ponownie(system_do_kp_string); // Sprawdzanie czy podany system jest poprawny
	
	std::cout << "Podaj liczbe do przeliczenia z systemu ("<<system_z_ktorego_przeliczamy<<") na (" << system_do_ktorego_przeliczamy << "): ";
	std::cin >> liczba_podana_przez_uzytkownika;
		liczba_podana_przez_uzytkownika = Podaj_liczbe_ponownie(liczba_podana_przez_uzytkownika); // Sprawdzanie czy podana liczba jest poprawna
	
};
int funkcje::Podaj_system_ponownie(std::string system) {

	int liczba = Sprawdzanie_systemu(system);
	while (!(liczba >= 2 && liczba <= 16))
	{
		std::cout << "Blad! Podaj liczbe ponownie: ";
		std::cin >> system;
		liczba = Sprawdzanie_systemu(system);
	}
	return liczba;
};
std::string funkcje::Podaj_liczbe_ponownie(std::string liczba) {
	bool czy_poprawna;
	czy_poprawna = Sprawdzanie_czy_liczba_poprawna(liczba, system_z_ktorego_przeliczamy);
	while (czy_poprawna == false) 
	{
		std::cout << "Blad! Podaj liczbe ponownie: ";
		std::cin >> liczba;
		czy_poprawna = Sprawdzanie_czy_liczba_poprawna(liczba, system_z_ktorego_przeliczamy);
	}
	return liczba;
};
void funkcje::Przeliczanie_na_system_10() {
	int dlugosc = liczba_podana_przez_uzytkownika.length() - 1;
	int wynik = 0, liczba_pom;
	for (int i = 0; i <= dlugosc; i++) // przeliczanie liczby z uzyciem tablicy ascii
	{
		if (int(std::toupper(liczba_podana_przez_uzytkownika[dlugosc - i])) - 48 <= 9)
			liczba_pom = int(std::toupper(liczba_podana_przez_uzytkownika[dlugosc - i])) - 48;
		else
			liczba_pom = int(std::toupper(liczba_podana_przez_uzytkownika[dlugosc - i])) - 55;
		
		wynik += liczba_pom * pow(system_z_ktorego_przeliczamy, i);
	}
	liczba_podana_przez_uzytkownika = std::to_string(wynik);
};
void funkcje::Przeliczanie_na_system_docelowy() {
	int dlugosc = liczba_podana_przez_uzytkownika.length() - 1;
	int liczba_pom = 0;
	for (int i = 0; i <= dlugosc; i++) // tworzenie liczby - int
	{
		liczba_pom += pow(10, i) * int(liczba_podana_przez_uzytkownika[dlugosc - i] - 48);
	}
	
	liczba_podana_przez_uzytkownika = ""; //tworzenie liczby - string
	liczba_podana_przez_uzytkownika.append(Przeliczanie_pojedynczych_liczb(liczba_pom));
	do
	{
		liczba_pom /= system_do_ktorego_przeliczamy;
		liczba_podana_przez_uzytkownika.append(Przeliczanie_pojedynczych_liczb(liczba_pom));	
	} while (liczba_pom > system_do_ktorego_przeliczamy);
	liczba_pom /= system_do_ktorego_przeliczamy;
	liczba_podana_przez_uzytkownika.append(Przeliczanie_pojedynczych_liczb(liczba_pom));
	
	std::string slowo_pom = liczba_podana_przez_uzytkownika; // Odwracanie liczby
	dlugosc = liczba_podana_przez_uzytkownika.length() - 1;
	for (int i = 0; i <= dlugosc; i++)
	{
		liczba_podana_przez_uzytkownika[i] = slowo_pom[dlugosc - i];
	}
	
	if (liczba_podana_przez_uzytkownika[0] == '0') //usuwanie niepotrzebnego zera 
		liczba_podana_przez_uzytkownika = liczba_podana_przez_uzytkownika.substr(1);

};
void funkcje::Wyswietlanie_wyniku(){
	std::cout << "Otrzymana liczba to: " << liczba_podana_przez_uzytkownika << " w systemie (" << system_do_ktorego_przeliczamy << ") \n";
};
std::string funkcje::Przeliczanie_pojedynczych_liczb(int pom) {
	
	if(pom % system_do_ktorego_przeliczamy <= 9) // zmiana liczby <int> na liczbe <string>
		return std::to_string(pom % system_do_ktorego_przeliczamy);
	else
	{
		std::string znak(1, char(pom % system_do_ktorego_przeliczamy + 55)); // zmiana na string
		return znak;
	}
}