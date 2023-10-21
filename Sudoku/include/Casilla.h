/**
 * @file Casilla.h
 * @brief fichero cabecera del TDA Casilla
 */

#ifndef SUDOKU_CASILLA_H
#define SUDOKU_CASILLA_H

#include <utility>
#include <vector>
using namespace std;
/**
 * @brief T.D.A Casilla
 * Una instancia @e cas del tipo de dato abstracto @c Casilla es un objeto
 * dotado de un par de enteros positivos que representan sus coordenadas
 * en un tablero 9x9 de Sudoku, y el valor que identifica al numero que guarda
 * esa casilla
 * Lo representaremos como una estructura de un objeto de tipo pair<int> y un entero
 */
class Casilla {
private:
/**
  * @page repCasilla Rep del TDA Casilla
  *
  * @section invConjunto Invariante de la representación
  *
  * 0 < casilla.coord.first(), casilla.coord.second() <= 9 ||
  * 0 <= valor <= 9 (Solo valdrá 0 si la casilla no está escrita aún)
  */
    pair<int, int> coord;
    int valor;
public:
    /**
     * @brief Constructor de la clase con unas coordenadas y con un valor preciso
     * @param coord Coordenadas de la casilla en el tabero
     * @param valor Valor que guarda la casilla
     * @return Crea la casilla precisada
     * @pre @a 0 <= coord.first(), coord.second() < 9
     * @pre @a valor 1 <= valor <= 9
     */
    Casilla(pair<int,int> coord, int valor=0);

    /**
     * @brief Constructor sin argumentos
     * @return Objeto por defecto de la clase Casilla
     */
    Casilla();

    /**
     * @brief Recupera coordenadas de la casilla
     * @return Par de enteros con las coordenadas
     */
    pair<int,int> getCoord() const;
    /**
     * @brief Recupera valor de la casilla
     * @return Valor que guarda la casilla
     */
    int getValor() const;
    /**
     * @brief Fija coordenadas de la casilla
     * @param coord Coordenadas que se pasan
     * @pre Las coordenadas son válidas en un Sudoku
     */
     void setCoord(pair<int,int> coord);

    /**
     * @brief Fija valor de la casilla
     * @param valor Valor que se escribirá en la casilla
     * @pre 1<=valor<=9
     */
    void setValor(int valor);

};


#endif //SUDOKU_CASILLA_H
