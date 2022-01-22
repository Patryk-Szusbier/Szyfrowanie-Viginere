#include <iostream>
#include <string.h>
#include <fstream>
#include "function.h"

using namespace std;

int main(int argc, char **argv)

{
    /*Inicjalizacja zmiennych*/
    string line, basic_key, code, result;
    string file_public, key_file, target, mode, temp;
    
    //Rozdzielenie argumentow startowych
    Arguments(mode, file_public, key_file,target, argc, argv);

    //Pobranie z pliku klucza szyfrującego
    ifstream key(key_file);
    if (key.peek() != EOF)
        getline(key, basic_key);
    key.close();

    //Zamiana klucza na duze litery
    Upperletter(basic_key);

    ifstream file(file_public);
    if (mode =="en")
    {
        while (file.peek() != EOF)
        {
            getline(file, temp);
            for(int i = 0; temp[i] != '\0';i++)
            {
                line.push_back(temp[i]);
            }
            line.push_back(' ');
        }//end of while

        //Zamiana tekstu na duze litery
        Upperletter(line);

        //Dopasowanie dlugosci klucza do tekstu
        Mapping_Key(line, basic_key, code);

        //Szyfrowanie
        Encryption(line, code, result);

    }//end of if
    else if (mode == "de")
    {
        while (file.peek() != EOF)
        {
            getline(file, temp);
            for(int i = 0; temp[i] != '\0';i++)
            {
                line.push_back(temp[i]);
            }
            line.push_back(' ');
        }//end of while

        //Zamiana tekstu na duze litery
        Upperletter(line);

        //Dopasowanie dlugosci klucza do tekstu
        Mapping_Key(line, basic_key, code);

        //Deszyfrowanie
        Decryption(line, code, result);
    }
    file.close();

    //Zapis wyniku do pliku
    ofstream wynik(target);

    wynik<<result;

    wynik.close();

    cout << endl;
}


