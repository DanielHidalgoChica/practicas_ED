//
// Created by daniel on 18/11/23.
//
#include <map>
#include <iostream>
#include <utility>
using namespace std;

#ifndef SET_MAP_GUIA_DE_TELEFONOS_H
#define SET_MAP_GUIA_DE_TELEFONOS_H


class guia_de_telefonos {
private:
   map<string, unsigned int>guia;
public:
   guia_de_telefonos() {}
    // Recuperar el teléfono asociado a un nombre
    unsigned int telefono(string nombre);
    void insertar_elemento(string nombre, unsigned int telefono);
    void eliminar_elemento(string nombre);
    void imprimir();
};


#endif //SET_MAP_GUIA_DE_TELEFONOS_H
