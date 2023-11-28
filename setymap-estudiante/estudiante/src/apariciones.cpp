//
// Created by daniel on 19/11/23.
//

#include "dictionary.h"
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
int main(int argc, char* argv[]) {
    // Check the arguments
    if (argc != 3 || strlen(argv[2]) != 1) {
        cerr << "Use: " << argv[0] << " <filename>" << " <char_to_find>";
        exit(1);
    }

    char* file_name(argv[1]);
    char char_to_find = *argv[2]; // Como es un puntero a char que guarda el caracter, deferenciamos

    // Open the file
    ifstream is;
    is.open(file_name);
    if (!is.is_open()) {
        cerr << "Error opening the file " << file_name;
        exit(1);
    }
    // Create and read the dic
    Dictionary dic;
    is >> dic;

    cout << "El carácter " << char_to_find << " aparece " << dic.getOcurrences(char_to_find) << " veces en el diccionario "
         << file_name;
    is.close();

    return 0;
}