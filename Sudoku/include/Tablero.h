/**
 * @file Tablero.h
 * @brief fichero cabecera del TDA Tablero
 */

#ifndef SUDOKU_TABLERO_H
#define SUDOKU_TABLERO_H

#include <vector>
#include "Grupo.h"

/**
 * @brief T.D.A Tablero
 * Una instancia @e tab del tipo de dato abstracto @c Tablero es una matriz
 * 9x9 con casillas que identifican las distintas estructuras, es decir, a las filas, columnas
 * y cubo. Esto es de vital importancia, pues tomaremos en muchas ocasiones
 * el nombre estructura para identificar estos tres terminos, ya que en ninguno de ellos
 * se podran repetir casillas con mismo @c valor.
 *
 * Lo representaremos como un vector de grupos, que a su vez identifica todas las
 * casillas que tiene el Tablero del Sudoku Killer
 */

class Tablero {
private:
  /**
  * @page repTablero Rep del TDA Tablero
  *
  * @section invConjunto Invariante de la representación
  *
  * Todas las casillas deben ser válidas && Num_Casillas = 81
   * && todos los grupos del vector deben cumplir con su
   * respectivo invariante de representación
  */
    vector<Grupo> grupos;
    vector<vector<Casilla>> sudoku;
public:
    /**
     * @brief Devolvera el grupo correspondiente a la posicion
     * de este en el vector @c sudoku
     * @param pos Posición del grupo que se quiere tener
     * @return Objeto de la clase Grupo, que ocupa dicha @c pos
     */
    const Grupo &get_grupo (int pos) const;

    /**
     * @brief Modifica el grupo de la casilla que escribe eliminandola de este,
     * con el metodo quitar_casilla (Casilla cas) de la clase Grupo y modifica el sudoku
     * colocando el valor a la casilla correspondiente. Ademas llamara
     * a limpiar (por defecto) para quitar las combinaciones posibles de otros grupos.
     * @param casilla_escrita Casilla cuyo valor se escribe
     * @param limpiar Por defecto limpia, en el caso que no queramos pasar un booleano igual a false
     */
    void set_casilla(const Casilla &casilla_escrita, bool limpiar = true);

    /**
     * @brief Escribe las casillas inmediatas obtenidas:
     * - Usando el método del 45 para el sudoku killer (y derivados con estructuras mayores)
     * - Rellenando grupos con una única casilla
     */
    void escribir_inmediatos();

    /**
     * @brief Rellena todas las combinaciones posibles (cada una con todas sus posiciones).
     * LLama a calcular combinaciones de cada grupo de la clase Grupo
     */
    void calcular_todas_combinaciones();

    /**
     * @brief Actualiza el tablero. LLama a:
     *  - Limpiar básico (cas)
     *  - Limpiar unic_comb (cas)
     *
     * @param cas Casilla cuyo valor se limpiará
     */
    void limpiar(const Casilla &cas);

    /**
     * @brief Itera sobre cada grupo llamando a escribe_determinados()
     */
    void escribir_determinados();
private:
    /**
     * @brief Devuelve el grupo al que esta casilla pertenece
     * @param cas Casilla cuyo grupo se devuelve
     * @return referencia al grupo al que @a @cas pertenece
     */
    Grupo &getGrupo(const Casilla &cas) const;
    /**
     * @brief Devuelve un vector de los grupos que tienen al menos una casilla
     * en esa fila
     * @param fila Fila del sudoku en la que buscar grupos
     * @return vector de Grupos
     */
    vector<Grupo>  getGrupos_fila(const Casilla &fila) const;

    /**
     * @brief Devuelve un vector de los grupos que tienen al menos una casilla
     * en esa columna
     * @param col Columna del sudoku en la que buscar grupos
     * @return vector de Grupos
     */
    vector<Grupo>  getGrupos_col(const Casilla &col) const;

    /**
     * @brief Devuelve un vector de los grupos que tienen al menos una casilla
     * en ese cubo
     * @param cubo Cubo del sudoku en el que buscar grupos
     * @return vector de Grupos
     */
    vector<Grupo>  getGrupos_cubo(const Casilla &cubo) const;

    /**
     * @brief Rellena los grupos que tienen una sola casilla, por lo que llama al método set_casilla
     */
    void rellenar_unitarias();

    /**
    * @brief Escribe las casillas determinadas por el método del 45 (o derivados inmediatos). Recalcar que para
    * escribir dichos valores llamamos al método set_casilla con un booleanoa a false, ya que al inicio no tendremos
    * combinaciones que limpiar.
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

    // Para obtener inmediatas, devuelven casilla (identificando grupo)
    // nula si no hay uno solo en la estructura
    // Devuelve precisamente la casilla que se puede calcular (única fuera o única dentro)
    /**
     * @brief Devuelve la casilla que se puede calcular (única fuera o única dentro). Devuelve casilla
     * nula si no existe una única fuera o dentro de la estructura
     * @param fila Casilla de la cual solo tomaremos la primera coordenada
     * @param desp Numero de filas que hemos utilizado en el método 45
     * @return casilla que se puede calcular
     */
    Casilla& unico_casillas_fuera_fil(const Casilla &fila, int desp=0) const;

    /**
     * @brief Devuelve la casilla que se puede calcular (única fuera o única dentro). Devuelve casilla
     * nula si no existe una única fuera o dentro de la estructura
     * @param col Casilla de la cual solo tomaremos la segunda coordenada
     * @param desp Numero de columnas que hemos utilizado en el método 45
     * @return casilla que se puede calcular
     */
    Casilla& unico_casillas_fuera_col(const Casilla &col, int desp=0) const;

    /**
     * @brief Devuelve la casilla que se puede calcular (única fuera o única dentro). Devuelve casilla
     * nula si no existe una única fuera o dentro de la estructura
     * @param cubo Casilla que utilizaremos para identificar el cubo
     * @param desp_dcha Predeterminado false, ya que solo en el caso de quere tomar dos grupos hacia la derecha la
     * llamaremos con booleano igual a true
     * @param desp_abj Predeterminado false, ya que solo en el caso de quere tomar dos grupos hacia abajo la
     * llamaremos con booleano igual a true
     * @return casilla que se puede calcular
     */
    Casilla& unico_casillas_fuera_cubo(Casilla cubo, bool desp_dcha=false, bool desp_abj=false) const;


    // Para la limpieza

    /**
     * @brief Dada la última casilla escrita en el tablero, limpia todas las combinaciones y
     * posiciones de cada estructura que contenga a @cas
     * LLama a limp_estructura(Casilla cas)
     *
     * @param cas Última casilla escrita
     */
    void limpiar_básico(const Casilla &cas);


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
    void limpiar_fila(const Casilla &cas);

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
    void limpiar_col(const Casilla &cas);

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
    void limpiar_cubo(const Casilla &cas);

    /**
    * @brief
    *  Sobre cada uno de los grupos tocados por las estructuras a las que @a cas pertenece se comprobará:
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

    void limpiar_unic_comb(const Casilla &cas);
};


#endif //SUDOKU_TABLERO_H
