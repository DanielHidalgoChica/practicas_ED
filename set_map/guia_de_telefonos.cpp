//
// Created by daniel on 18/11/23.
//

#include "guia_de_telefonos.h"

using namespace std;

unsigned int guia_de_telefonos::telefono(string nombre) {
    if (guia.count(nombre) > 0) return (guia[nombre]);
    else return 0;
}

void guia_de_telefonos::insertar_elemento(std::string nombre, unsigned int telefono) {
   guia.insert(pair<string, unsigned int>(nombre, telefono));
}

void guia_de_telefonos::eliminar_elemento(std::string nombre) {
    guia.erase(nombre);
}

void guia_de_telefonos::imprimir() {
    cout << "///////////////////////////////" << endl;
    map<string, unsigned int>::iterator it = guia.begin();
    while (it != guia.end()) {
        cout << "Nombre: " << it->first << " Tlf: " << it->second << endl;
    }
    cout << "///////////////////////////////" << endl;
}