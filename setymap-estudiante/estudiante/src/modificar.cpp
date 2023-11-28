//
// Created by daniel on 19/11/23.
//

#include "guiatlf.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <filename_guia1>" << " <name> " << " <tlf> " <<  endl;
        exit(1);
    }

    ifstream is1;
    is1.open(argv[1]);

    string nombre = argv[2];
    string tlf = argv[3];

    if (!is1.is_open()) {
        cerr << "Error al abrir el fichero" << argv[1];
        exit(1);
    }

    Guia_Tlf guia1;
    is1 >> guia1;
    guia1.cambiar_tlf(nombre,tlf);

    cout << guia1;

    return 0;
}
