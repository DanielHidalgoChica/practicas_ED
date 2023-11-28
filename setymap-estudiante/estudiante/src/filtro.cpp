//
// Created by daniel on 19/11/23.
//
#include "guiatlf.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <filename_guia1>" << " <beg_of_name>";
        exit(1);
    }

    ifstream is1;
    is1.open(argv[1]);

    string beg = argv[2];

    if (!is1.is_open()) {
        cerr << "Error al abrir el fichero" << argv[1];
        exit(1);
    }

    Guia_Tlf guia1, guia_ret;
    is1 >> guia1;
    guia_ret = guia1.guia_con_nombres_comenzando(beg);

    cout << guia_ret;

    return 0;
}
