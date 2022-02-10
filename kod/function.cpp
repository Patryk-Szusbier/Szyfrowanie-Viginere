#include "function.h"
#include <iostream>
#include <string>

using namespace std;

const int spacebar = 32;
const int number_A = 65;
const int number_Z = 90;
int number_of_letter = 26;


void Arguments(string& mode, string& file, string& key_file, string& file_target, int number, char **argv)
{
	if (number <= 2)
	{
		cout << endl;
		cout << "Podaj wszystkie wymagane parametry aby uzyc progamu.";
		cout << endl<<endl;
		cout << "Dla Szyfrowania musisz podac: \nflage --en \n-i plik wejsciowy jawny \n-o plik wyjsciowy zaszyfrowany \n-k plik tekstowy z kluczem";
		cout << endl<<endl;
		cout << "Dla Deszyfrowania musisz podac: \nflage --de \n-i plik tekstowy wejsciowy zaszyfrowany \n-o plik tekstowy wyjsciowy jawny \n-k plik tekstowy z kluczem";
		cout<<endl;
	}
	else
	{
		for (int i = 0; i < number; i++)
		{
			if (strcmp(argv[i], "--en") == 0)
				mode = "en";
			else if (strcmp(argv[i], "--de") == 0)
				mode = "de";
			else if (strcmp(argv[i],"-i") == 0)
				file = argv[i + 1];
			else if (strcmp(argv[i], "-o") == 0)
				file_target = argv[i + 1];
			else if (strcmp(argv[i], "-k") == 0)
				key_file = argv[i + 1];

		}
	}
}
void Upperletter(string&key)
{
	for (int i = 0; i < key.length(); i++)
	{
		key[i] = toupper(key[i]);
	}
}

void Mapping_Key(string line, string key, string&keyMap)
{
	string x = " ";
		for (int i = 0, j = 0; i < line.length(); i++)
		{
			if (line[i] == spacebar)
			{
				keyMap += " ";
			}
			else
			{
				if (j < key.length())
				{
					keyMap.push_back(key[j]);
					j++;
				}
				else
				{
					j = 0;
					keyMap.push_back(key[j]);
					j++;
				}//else
			}//else
		}//for
}


char** Create_Table()
{
	char** table = new char* [26];
	int z = 65;
	char temp_storage;
	for (int i = 0; i < number_of_letter; i++)
	{
		table[i] = new char[26];
		for (int j = 0; j < number_of_letter; j++)
		{
			if (i == 0) {
				table[i][j] = static_cast<char>(z);
				z++;
			}
			else
			{
				temp_storage = table[i - 1][0];
				if (j + 1 < number_of_letter)
					table[i][j] = table[i - 1][j + 1];
				if (j + 1 == number_of_letter)
					table[i][j] = temp_storage;
			}

		}
	}
	return table;
}

void Encryption(string text, string key, string&results)
{
	char** table = Create_Table();

	for (int i = 0; i < text.length(); i++)
	{
		if ((int)text[i] < number_A || (int)text[i]>number_Z)
		{
			results += text[i];
		} 
		else
		{
			int x = (int)text[i] - number_A;
			int y = (int)key[i] - number_A;
			results += (char)table[x][y];
		}
	}
}
int itrCount(int key, int let)
{
	int counter = 0;
	string ans = "";

	for (int i = 0; i < number_of_letter; i++)
	{
		if (key + i > number_Z)
		{
			ans += (char)(key + (i - number_of_letter));
		}
		else
		{
			ans += (char)(key + i);
		}
	}

	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] == let)
		{
			break;
		}
		else
			counter++;
	}
	return counter;

}
void Decryption(string text, string key, string&results)
{
	for (int i = 0; i < text.length(); i++)
	{
		if ((int)text[i] < number_A || (int)text[i]>number_Z)
		{
			results += text[i];
		}
		else
		{
			int temp = itrCount((int)key[i], (int)text[i]);
			results += (char)(number_A + temp);
		}
	}
}

