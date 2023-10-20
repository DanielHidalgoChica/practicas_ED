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
 * dotado un conjunto de casillas contiguas; la suma de los valores de éstas, y el conjunto
 * de combinaciones posibles.
 * Representa los conjuntos contiguos de celdas marcados con línea
 * discontinua en un Sudoku Killer.
 *
 * Lo representamos como una estructura con un vector de casillas y un entero como suma,
 * aparte de un vector matrices, donde cada una de esas matrices está asociada a un conjunto de
 * enteros positivos que suma @a suma, y cada una de las columnas de esas matrices, que tendrán
 * tantas filas como elementos tenga el grupo, será una posible ordenación de los elementos del grupo
 * (fijada cada casilla para cada una de las filas)
 *
 */

class Grupo {
private:
/**
  * @page repConjunto Rep del TDA Racional
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante de representación es grupo[i] in {Casillas Válidas de Sudoku} ^ 0 < suma <= 81
  *
  */
    int suma;
    vector<Casilla> grupo;
    vector<vector<vector<int>>> combinaciones;
public:
    /**
     * @brief Recupera las casillas de grupo
     * @return vector con las casillas que pertenecen al grupo
     */
    const vector<Casilla> &getCasillas() const;

    /**
     * @brief Recupera la suma asociada al grupo
     * @return La suma del grupo
     */
     int getSuma() const;

    /**
     * @brief Recupera las combinaciones posibles del grupo (basadas en el instante del tablero)
     * @return Combinaciones posibles
     */
    const vector<vector<vector<int>>> &getCombinaciones() const;

    /**
     * @brief Fija las casillas de grupo
     * @param cas vector de casillas
     * @post Casillas cambiadas
     */
    void setCasillas(const vector<Casilla> & cas);

    /**
     * @brief Fija la suma asociada al grupo
     * @param sum suma que asigno al grupo
     * @post Suma cambiada (no debería tener sentido hacer esto)
     */
    void setSuma(int sum);

    /**
     * @brief Fija las combinaciones posibles del grupo (basadas en el instante del tablero)
     * @post Quedan alteradas las combinaciones posibles
     */
    void setCombinaciones(const vector<vector<vector<int>>> &comb);


    /**
     * @brief Informa sobre si el grupo está enteramente contenido en una fila
     * @return true si todas las casillas del grupo quedan dentro de cierta fila
     */
    bool InFila() const;

    /**
     * @brief Informa sobre si el grupo está enteramente contenido en un grupo
     * @return true si todas las casillas del grupo quedan dentro de cierto cubo
     */
    bool InCubo() const;

    /**
     * @brief Informa sobre si el grupo está enteramente contenido en un grupo
     * @return true si todas las casillas del grupo quedan dentro de cierta columna
     */
    bool InCol() const;

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
     * @pre La casilla solo se eliminará si está en alguno de los bordes del grupo (pues en caso
     * contrario se dividiría un grupo en dos o más sin saber cuál sería su suma).
     * @post La suma del grupo disminuye por la cantidad que guarde que la casilla eliminada y el vector
     * de combinaciones cambia correspondientemente
     */
    void quitar_casilla(const Casilla& cas);

    /**
     * @brief Rellena las todas las posibles sumas del grupo
     * con cada una de sus posiciones posibles
     * @post El grupo queda inicializado. Se usa solo su suma
     */
     void rellena_comb_y_pos();

    /**
    * @brief Limpia todas las combinaciones que contengan el dígito de la casilla @a cas
    * @pre InFila() == true
    * @param cas Última casilla escrita
    * @post El grupo elimina las combinaciones precisadas
    */
    void limp_comb_en_fila(const Casilla& cas);

    /**
    * @brief Limpia todas las posiciones que tengan al dígito
    * de @cas en una casilla en la fila en la que se encuentra @cas (reglas del Sudoku)
    * @pre InFila() == false
    * @param cas Última casilla escrita
    * @post El grupo elimina las posiciones precisadas
    */
    void limp_comb_no_en_fila(const Casilla& cas);

    /**
    * @brief Limpia todas las combinaciones que contengan el dígito de la casilla @a cas
    * @pre InCol() == true
    * @param cas Última casilla escrita
    * @post El grupo elimina las combinaciones precisadas
    */
    void limp_comb_en_col(const Casilla& cas);

    /**
    * @brief Limpia todas las posiciones que tengan al dígito
    * de @cas en una casilla en la col en la que se encuentra @cas (reglas del Sudoku)
    * @pre InCol() == false
    * @param cas Última casilla escrita
    * @post El grupo elimina las posiciones precisadas
    */
    void limp_comb_no_en_col(const Casilla& cas);

    /**
    * @brief Limpia todas las combinaciones que contengan el dígito de la casilla @a cas
    * @pre InCubo() == true
    * @param cas Última casilla escrita
    * @post El grupo elimina las combinaciones precisadas
    */
    void limp_comb_en_cubo(const Casilla& cas);

    /**
    * @brief Limpia todas las posiciones que tengan al dígito
    * de @cas en una casilla en el cubo en la que se encuentra @cas (reglas del Sudoku)
    * @pre InCubo() == false
    * @param cas Última casilla escrita
    * @post El grupo elimina las posiciones precisadas
    */
    void limp_comb_no_en_cubo(const Casilla& cas);

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
     *  @pos Quedan escritass las casillas totalmente determinadas del grupo (y se eliminan de éste)
    */
    void escribir_determinados();

private:
    /**
     * @brief Devuelve cuántas casillas se quedan fuera de "cubo"
     * @param cubo La esquina superior izquierda del cubo
     * @return Número de casillas que se quedan fuera
     */
    int CuantasFuera_cubo(const Casilla& cubo);

    /**
     * @brief Devuelve cuántas casillas se quedan fuera de "fila"
     * @param cubo La esquina superior izquierda de fila
     * @return Número de casillas que se quedan fuera
     */
    int CuantasFuera_fila(const Casilla& fila);

    /**
     * @brief Devuelve cuántas casillas se quedan fuera de "col"
     * @param cubo La esquina superior izquierda de col
     * @return Número de casillas que se quedan fuera
     */
    int CuantasFuera_col(const Casilla& col);

    /**
     * @brief Controla si cierta casilla del grupo está en el borde de éste (puede eliminarse sin desconectar el grupo)
     * Procederá simulando iterando sobre cada una de las otras casillas del grupo y comprobando si para cada una de éstas
     * existe al menos una de las otras casillas del grupo (no contando sobre la que nos estamos planteando) tal que
     * ésta esté en la misma fila y a una sola columna de distancia, o en la misma columna y a una sola fila de distancia
     * @param cas
     * @return true si la casilla está en el grupo y está en el borde
     */
    bool esta_en_el_borde(const Casilla &cas);

};


#endif //SUDOKU_GRUPO_H
