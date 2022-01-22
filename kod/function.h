#include <string>
using namespace std;

#ifndef function_h
#define function_h

/** Funkcja przekazuaca argumenty wywolania do zmiennych.
 * @param mode odczytany przez funkcje tryb pracy
 * @param file odczytana przez funkcje nazwa pliku wejściowego
 * @param key_file odczytana przez funkcje nazwa pliku z kluczem szyfrującym
 * @param file_target odczytana przez funkcje nazwa pliku wyjściowego
 * @param number libcza wszystkich parametrów uruchomienia programu
 * @param argv tablica wskaźników na parametry uruchomienia programu
 */
void Arguments(string& mode, string& file, string& key_file, string& file_target, int number, char **argv);

/** Funckja zamieniajaca wszystkie litery na duze
 * @param key ciag znakow ktorym ma zostac zamieniony
*/
void Upperletter(string& key);

/** Funkcja dopasowujaca długosc klucza szyfrującego do wiadomosci
 * @param line ciag znakow z wiadomoscia do szyfrowania
 * @param key ciag znakow zawierajacy klucz szyfrujacy
 * @param keyMap ciag znakow z dopasowana dlugoscia klucza do wiadomosci
*/
void Mapping_Key(string line, string key, string& keyMap);

/**
Funkcja uzupełniająca tablice szyfrowania Vigenerate.
*/
void createTable();

/** Funkcja szyfrująca podany tekst według określonego klucza.
 * @param line ciąg znaków zawierający wiadomość do szyfrowania
 * @param key ciąg znaków zawierający klucz szyfrujący
 * @param results ciąg znaków do której ma zostać wpisany wynik szyfrowania
*/
void Encryption(string line, string key, string& results);

/** Funkcja tworząca ciąg wszystkich liter zaczynając od podanej litery i zwraca odległość między początkiem a drugą literą podaną w tym ciągu.
 * @param key numer litery w ASCII od ktorej zaczyna sie ciag wszystkich liter
 * @param let numer litery ktora szukamy w stworzonym ciagu liter
 * @return funkcja zwraca liczbę pozycji między początkiem a drugą podaną literę
*/
int itrCount(int key, int let);

/** Funkcja deszyfrująca podany tekst według określonego klucza.
 * @param text ciąg znaków zawierający tekst do deszyfracji
 * @param key ciąg znaków zawierający klucz szyfrujący
 * @param results zmienna do której ma zostać wpisany wynik deszyfracji
*/
void Decryption(string text, string key, string& results);

#endif
