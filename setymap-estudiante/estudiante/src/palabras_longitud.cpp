//
// Created by daniel on 19/11/23.
//

#include "dictionary.h"
#include <fstream>

using namespace std;
int main(int argc, char* argv[]) {
    // Check the arguments
    if (argc != 3) {
        cerr << "Use: " << argv[0] << " <filename>" << " <word_length>";
        exit(1);
    }

    char* file_name(argv[1]);
    int word_length = stoi(argv[2]);

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

    vector<string> wol = dic.wordsOfLength(word_length);

    // Print words
    for (int i = 0; i != wol.size(); i++)
        cout << wol[i] << endl;

    is.close();

    return 0;
}