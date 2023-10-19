/**
 * @file Tablero.h
 * @brief
 * @author Arturo
 */

#ifndef SUDOKU_TABLERO_H
#define SUDOKU_TABLERO_H

#include <vector>
#include "Casilla.h"
#include "Grupo.h"

class Tablero {
private:
    vector<vector<Casilla>> sudoku;
public:
    // set-get
    // Modifica el grupo de la casilla que escribe eliminándola de este
    // Llama a limpiar
    void set_casilla(Casilla casilla_escrita);

    /**
     * @brief Escribe las casillas inmediatas obtenidas:
     * - Usando el método del 45 para el sudoku killer (y derivados con estructuras mayores)
     * - Rellenando grupos con una única casilla
     */
    void escribir_inmediatos();

    /**
     * @brief Rellena todas las combinaciones posibles (cada una con todas sus posiciones)
     * LLama a calcular combinaciones de cada grupo
     */
    void calcular_todas_combinaciones();

    /**
     * @brief Actualiza el tablero. LLama a:
     *  - Limpiar básico (cas)
     *  - Limpiar unic_comb (cas)
     * @param cas
     */
    void limpiar(Casilla cas);

    /**
     * @brief Itera sobre cada grupo llamando a escribe_determinados()
     */
    void escribir_determinados();
private:

    vector<Grupo>  getGrupos_fila(Casilla fila);
    vector<Grupo>  getGrupos_col(Casilla col);
    vector<Grupo>  getGrupos_cubo(Casilla cubo);
    void rellenar_unitarias();

    /**
    * MÉTODO DE LOS 45
    * Iterando sobre cada una de las estructuras del tablero (todas las filas, columnas y cubos de 3x3)
    * examinamos si todos los grupos con casillas en esa estructura están totalmente contenidos menos
    * uno de ellos. En ese caso, si el grupo no-enteramente-contenido tiene fuera de la estructura
    * 1 sola casilla, o size_grupo-1 casillas, podremos determinar de manera inmediata una casilla
            * del grupo.
    * En el caso de una sola casilla fuera:
            *      casilla = suma_todos_grupos_de_la_estructura - 45
                                                                  * En el caso de size-1 casillas fuera:
            *      casilla = 45 - suma_grupos_enteros_dentro
                                  *
                                  * Nótese que el método es fácilmente aplicable al caso en el que tengamos una estructura
    * compuesta de dos o más de las estructuras anteriormente consideradas (sea n) usando
    * 45*n en las fórmulas.
    */
    void método_45();

    // Para obtener inmediatas, devuelven casilla (identificando grurpo)
    // nula si no hay uno solo en la estructura
    // Devuelve precisamente la casilla que se puede calcular (única fuera o única dentro)
    Casilla unico_casillas_fuera_fil(Casilla fila, int desp=0);
    Casilla unico_casillas_fuera_col(Casilla col, int desp=0);
    Casilla unico_casillas_fuera_cubo(Casilla cubo, bool desp_dcha=false, bool desp_abj=false);


    // Para la limpieza

    /**
     * @brief Dada la última casilla escrita en el tablero, limpia todas las combinaciones y
     * posiciones de cada estructura que contenga a @cas
     * LLama a limp_estructura(Casilla cas)
     *
     * @param cas Última casilla escrita
     */
    void limpiar_básico(Casilla cas);


    /**
    * @brief Dada la última casilla escrita en el tablero (o simulada). Itera sobre todos los grupos
    * con casillas dentro de la fila a la que @a cas pertenece
    *
    * LLama a limp_comb_en_fila(Casilla cas)
    * LLama a limp_comb_no_en_fila(Casilla cas)
    *
    * Esto se da porque la manera de limpiar un grupo de imposibilidades es
    * notablemente distinta en los casos en los que los grupos afectados estén
    * o no enteramente contenidos dentro de la estructura afectada
    *
    * @param cas última casilla escrita (o simulada)
    */
    void limpiar_fila(Casilla cas);

    /**
    * @brief Dada la última casilla escrita (o simulada) en el tablero. Itera sobre todos los grupos
    * con casillas dentro de la col a la que @a cas pertenece
    *
    * LLama a limp_comb_en_col(Casilla cas)
    * LLama a limp_comb_no_en_col(Casilla cas)
    *
    * Esto se da porque la manera de limpiar un grupo de imposibilidades es
    * notablemente distinta en los casos en los que los grupos afectados estén
    * o no enteramente contenidos dentro de la estructura afectada
    *
    * @param cas última casilla escrita (o simulada)
    */
    void limpiar_col(Casilla cas);

    /**
    * @brief Dada la última casilla escrita (o simulada) en el tablero. Itera sobre todos los grupos
    * con casillas dentro de la cubo a la que @a cas pertenece
    *
    * LLama a limp_comb_en_cubo(Casilla cas)
    * LLama a limp_comb_no_en_cubo(Casilla cas)
    *
    * Esto se da porque la manera de limpiar un grupo de imposibilidades es
    * notablemente distinta en los casos en los que los grupos afectados estén
    * o no enteramente contenidos dentro de la estructura afectada
    *
    * @param cas última casilla escrita (o simulada)
    */
    void limpiar_cubo(Casilla cas);

    /**
    * @brief
    *  Sobre cada uno de los grupos de las estructuras a los que @a cas pertenece se comprobará:
    *      - Si ese grupo está contenido entero dentro de una estructura
    *      - Si ese grupo tan solo conserva una de sus combinaciones
    *  Si ambas condiciones se cumplen, ejecutará este método de la siguiente
    *  manera:
    *  for (int i = 0; i < tam_unica_comb; i++) {
    *      Casilla cas(grupo[0].getCoord(),grupo.getComb[0][i]); // Solo hay una comb. ([0]) (con i sumandos)
    *      limpiar_{esctructura}(cas); // Donde {estructura} será la fila, col. o cubo
     *                                 // en el que grupo esté enteramente contenido (guión 1)
    *  }
    *
    * La motivación de este uso del método reside en que si en cierta estructura encontramos
    * un grupo con una única combinación, aunque no sepamos el orden en el que esta
    * aparecerá (su posición) y por tanto no podamos escribirla, sabemos que todos
    * esos dígitos aparecerán en las casillas asociadas al grupo, y por tanto no aparecerán
    * en ninguna otra casilla de la estructura que lo contenga
     * Por tanto llamamos a limpiar_{estructura} con una casilla simulada
     * @param cas Úlima casilla escrita
     */

    void limpiar_unic_comb(Casilla cas);
};


#endif //SUDOKU_TABLERO_H
