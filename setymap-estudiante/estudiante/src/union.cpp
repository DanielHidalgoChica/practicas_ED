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
    if (argc != 3) {
        cerr << "Use: " << argv[0] << " <dic_1_file_name>" << " <dic_2_file_name>";
        exit(1);
    }

    char* file_name_1(argv[1]);
    char* file_name_2(argv[2]);

    // Open the file
    ifstream is1, is2;
    is1.open(file_name_1);
    is2.open(file_name_2);

    if (!(is1.is_open() || is2.is_open())) {
        cerr << "Error opening the files " << file_name_1 << " " << file_name_2;
        exit(1);
    }

    // Create and read the dic
    Dictionary dic1, dic2;
    is1 >> dic1;
    is2 >> dic2;

    dic1.anade(dic2); // Unimos sobre dic1

    cout << "La unión de los diccionarios es: " << endl << dic1;

    is1.close();
    is2.close();

    return 0;
}
