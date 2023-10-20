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
/**
 * @brief T.D.A Grupo
 * Una instancia @e grupo del tipo de dato abstracto @c Grupo es un objeto
 * dotado un conjunto de casillas contiguas y la suma de los valores de éstas.
 * Representa los conjuntos contiguos de celdas marcados con línea
 * discontinua en un Sudoku Killer.
 *
 * Lo representamos como una estructura con un vector de casillas y un entero como suma
 */

class Grupo {
private:
    int suma;
    vector<Casilla> grupo;

    // Tenemos un vector de matrices, donde para una cierta entrada (combinación),
    // sus columnas representan cada una de las posibles posiciones de
    // los enteros asociados a esa entrada (combinación; sumandos)
    // (ej. combinación: {2,5,6}--> posición[i] = (5,2,6); posicion[j] = (2,5,6))
    vector<vector<vector<int>>> combinaciones;

public:
    // get-set
    vector<Casilla> getCasillas();
    // Para los primeros
    int InFila();
    int InCol();
    int InCubo();

    /**
     * @brief Se ejecutará al escribir una casilla para quitarla del grupo
     * Esto tiene como propósito ir simplificando los grupos lo máximo posible
     * para aumentar la posibilidad de que el grupo entero caiga dentro
     * de cierta estructura (este caso nos da mucha información sobre los
     * dígitos posibles en la estructura)
     *
     * Se elimnará la casilla del vector grupo, y se ajustarán los sumandos y posiciones
     * adecuadamente
     * @param cas la casilla que se borra del grupo
     */
    void quitar_casilla(Casilla cas);

    /**
     * @brief Rellena las todas las posibles sumas del grupo
     * con cada una de sus posiciones posibles
     */
     void rellena_comb_y_pos();


    /**
    * @brief Limpia todas las combinaciones que contengan el dígito de la casilla @a cas
    * @pre InFila() == true
    * @param cas Última casilla escrita
    */
    void limp_comb_en_fila(Casilla cas);

    /**
    * @brief Limpia todas las posiciones que tengan al dígito
    * de @cas en una casilla en la fila en la que se encuentra @cas (reglas del Sudoku)
    * @pre InFila() == false
    * @param cas Última casilla escrita
    */
    void limp_comb_no_en_fila(Casilla cas);

    /**
    * @brief Limpia todas las combinaciones que contengan el dígito de la casilla @a cas
    * @pre InCol() == true
    * @param cas Última casilla escrita
    */
    void limp_comb_en_col(Casilla cas);

    /**
    * @brief Limpia todas las posiciones que tengan al dígito
    * de @cas en una casilla en la col en la que se encuentra @cas (reglas del Sudoku)
    * @pre InCol() == false
    * @param cas Última casilla escrita
    */
    void limp_comb_no_en_col(Casilla cas);

    /**
    * @brief Limpia todas las combinaciones que contengan el dígito de la casilla @a cas
    * @pre InCubo() == true
    * @param cas Última casilla escrita
    */
    void limp_comb_en_cubo(Casilla cas);

    /**
    * @brief Limpia todas las posiciones que tengan al dígito
    * de @cas en una casilla en el cubo en la que se encuentra @cas (reglas del Sudoku)
    * @pre InCubo() == false
    * @param cas Última casilla escrita
    */
    void limp_comb_no_en_cubo(Casilla cas);

    /**
     * @brief Escribe las casillas totalmente determinadas por un proceso
     * de eliminación de posiciones. Los casos de determinación son los siguientes:
     * - El grupo tiene una única combinación posible (sumandos) y en todas las posiciones
     *   posibles el dígito de cierta casilla (cierta posición del vector) coincide
     * - El grupo tiene más de unica combinación posible, pero todas comparten un dígito
     *   y ese dígito siempre se encuentra en la misma casilla (posición del vector) en todas las posiciones
     *   posibles
     *
     *  Notemos que el caso de la obtención de un grupo unitario por la reducción de los grupos
     *  tras escritura queda considerado en el primer guión
    */
    void escribir_determinados();

private:
    int CuantasFuera_cubo(Casilla cubo); // casilla subo esquina superior izquierdaci
    int CuantasFuera_fila(Casilla fila);
    int CuantasFuera_col(Casilla col);
   /**
    * @brief Dada la suma, calcula las posibles combinaciones (conjuntos de enteros
    * positivos que suman la cantidad precisada)
    * @return vector con las distintas combinaciones en forma de vectores de enteros de tamaño
    * grupo.size() que suman @a suma
    */
    vector<vector<int>> get_combinacion();


};


#endif //SUDOKU_GRUPO_H
