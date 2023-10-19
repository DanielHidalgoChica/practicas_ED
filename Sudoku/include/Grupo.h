/**
 * @file Tablero.h
 * @brief
 * @author Arturo
 */

#ifndef SUDOKU_GRUPO_H
#define SUDOKU_GRUPO_H

#include <vector>
#include "Casilla.h"
using namespace std;

class Grupo {
private:
    int suma;
    vector<Casilla> grupo;

    // Tenemos un vector de matrices, donde para una cierta entrada (combinación),
    // sus columnas representan cada una de las posibles posiciones de
    // los enteros asociados a esa entrada (combinación; sumandos)
    // (ej. combinación: {2,5,6}--> posición[i] = (5,2,6); posicion[j] = (2,5,6))
    vector<vector<vector<int>>> combinaciones;




};


#endif //SUDOKU_GRUPO_H
