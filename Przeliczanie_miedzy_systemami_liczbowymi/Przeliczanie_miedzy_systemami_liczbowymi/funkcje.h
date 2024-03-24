#include <iostream>


class funkcje{
	public:

	int system_z_ktorego_przeliczamy; // System liczbowy <2,16>
	std::string system_z_kp_string; // Sprawdzanie inputu do powy¿szego inta
	int system_do_ktorego_przeliczamy; // System liczbowy <2,16>
	std::string system_do_kp_string; // Sprawdzanie inputu do powy¿szego inta
	std::string liczba_podana_przez_uzytkownika; // Liczba 1-9,A-F

	void Program(); // Uruchamia program
	void Pytania(); // Pytanie o system pocz¹tkowy, koñcowy oraz liczbe do przeliczenia
	int Podaj_system_ponownie(std::string a); // Ponowne pytania w przypadku podania nieprawid³owych
	std::string Podaj_liczbe_ponownie(std::string a); // Sprawdza czy podana liczba sk³ada siê z odpowiednich znaków
	void Przeliczanie_na_system_10(); // Przelicza podan¹ liczbê na system 10
	void Przeliczanie_na_system_docelowy(); // Przyelicza na system docelowy
	void Wyswietlanie_wyniku(); // Wyœwietlanie wyniku
	std::string Przeliczanie_pojedynczych_liczb(int a); // Zwracanie liczb 1-9,A-F
};