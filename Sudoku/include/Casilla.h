/**
 * @file Tablero.h
 * @brief
 * @author Arturo
 */

#ifndef SUuOKU_CASILLA_H
#define SUDOKU_CASILLA_H

#include <utility>
#include "Grupo.h"
using namespace std;


class Casilla {
private:
    pair<int, int> coord;
    int valor;
public:
    // set-get
    void setValor();
    Grupo &getGrupo();
};


#endif //SUDOKU_CASILLA_H
