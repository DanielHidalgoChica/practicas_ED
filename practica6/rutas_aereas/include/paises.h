/**
 * @file paises.h
 * @brief Fichero cabecera del TDA paises
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include <set>
#include "pais.h"
using namespace std;

/**
 * @brief TDA Paises
 *
 * Una instancia @e p del tipo de datos abstracto @c Paises es un objeto
 * que representa un conjunto de paises.
 */
class Paises {
private:
	/**
	 * @brief Conjunto de paises
	 */
	set<Pais> datos;

public:
	/**
	 * @brief Constructor por defecto de la clase
	 */
	Paises(){}

	/**
	 * @brief Constructor de la clase
	 * @param paises Conjunto de paises
	 */
	Paises(const set<Pais> &paises);

	/**
	 * @brief Devuelve el numero de paises
	 * @return Numero de paises
	 */
	int size() const;

	/**
	 * @brief Devuelve el conjunto de paises
	 * @return Conjunto de paises
	 */
	const set<Pais>& getDatos() const;

	/**
	 * @brief Inserta un nuevo pais en el conjunto
	 * @param pais Pais a insertar
	 */
	void insertar(const Pais &pais);

	/**
	 * @brief Elimina un pais del conjunto
	 * @param pais Pais a eliminar
	 */
	void eliminar(const Pais &pais);

	// Iteradores
	class const_iterator;

	/**
	 * @brief Clase iterator
	 *
	 * Clase que permite iterar sobre los paises
	 */
	class iterator{
	private:
		/**
		 * @brief Iterador sobre el conjunto de paises
		 */
		set<Pais>::iterator it;
	public:
		/**
		 * @brief Constructor por defecto de la clase
		 */
		iterator(){}

		/**
		 * @brief Constructor de la clase
		 * @param i Iterador sobre el conjunto de paises
		 */
		iterator(set<Pais>::iterator i){it = i;}

		/**
		 * @brief Sobrecarga del operador *
		 * @return Pais apuntado por el iterador
		 */
		Pais operator*() {return *it;}

		/**
		 * @brief Sobrecarga del operador ++
		 * @return Iterador apuntando al siguiente pais
		 */
		iterator operator++(){return ++it;}

		/**
		 * @brief Sobrecarga del operador --
		 * @return Iterador apuntando al pais anterior
		 */
		iterator operator--(){return --it;}

		/**
		 * @brief Sobrecarga del operador ==
		 * @param i Iterador con el que comparar
		 * @return True si son iguales, false en caso contrario
		 */
		bool operator==(const iterator &i) const {return it == i.it;}

		/**
		 * @brief Sobrecarga del operador !=
		 * @param i Iterador con el que comparar
		 * @return True si son distintos, false en caso contrario
		 */
		bool operator!=(const iterator &i) const {return it != i.it;}

		friend class Paises;
		friend class const_iterator;
	};

	/**
	 * @brief Clase const_iterator
	 *
	 * Clase que permite iterar sobre los paises sin modificarlos
	 */
	class const_iterator{
	private:
		/**
		 * @brief Iterador sobre el conjunto de paises
		 */
		set<Pais>::const_iterator it;
	public:
/**
		 * @brief Constructor por defecto de la clase
		 */
		const_iterator(){}

		/**
		 * @brief Constructor de la clase
		 * @param i Iterador sobre el conjunto de paises
		 */
		const_iterator(set<Pais>::const_iterator i){it = i;}

		/**
		 * @brief Sobrecarga del operador *
		 * @return Pais apuntado por el iterador
		 */
		const Pais operator*() const {return *it;}

		/**
		 * @brief Sobrecarga del operador ++
		 * @return Iterador apuntando al siguiente pais
		 */
		const_iterator operator++(){return ++it;}

		/**
		 * @brief Sobrecarga del operador --
		 * @return Iterador apuntando al pais anterior
		 */
		const_iterator operator--(){return --it;}

		/**
		 * @brief Sobrecarga del operador ==
		 * @param i Iterador con el que comparar
		 * @return True si son iguales, false en caso contrario
		 */
		bool operator==(const const_iterator &i) const {return it == i.it;}

		/**
		 * @brief Sobrecarga del operador !=
		 * @param i Iterador con el que comparar
		 * @return True si son distintos, false en caso contrario
		 */
		bool operator!=(const const_iterator &i) const {return it != i.it;}

		friend class Paises;
	};

	/**
	 * @brief Devuelve un iterador al principio del conjunto
	 * @return Iterador al principio del conjunto
	 */
	iterator begin(){return iterator(datos.begin());}

	/**
	 * @brief Devuelve un iterador al final del conjunto
	 * @return Iterador al final del conjunto
	 */
	iterator end(){return iterator(datos.end());}

	/**
	 * @brief Devuelve un iterador constante al principio del conjunto
	 * @return Iterador constante al principio del conjunto
	 */
	const_iterator begin() const {return const_iterator(datos.begin());}

	/**
	 * @brief Devuelve un iterador constante al final del conjunto
	 * @return Iterador constante al final del conjunto
	 */
	const_iterator end() const {return const_iterator(datos.end());}

	// TODO: Revisar Iteradores

	/**
	 * @brief Busca un pais en el conjunto
	 * @param pais Pais a buscar
	 * @return Iterador apuntando al pais buscado, o end() si no se encuentra.
	 */
	iterator find(const Pais &pais);

	friend ostream& operator<<(ostream &os, const Paises &paises);
	friend istream& operator>>(istream &is, Paises &paises);
};

/**
 * @brief Sobrecarga del operador >> para la clase Paises
 * @param os  Flujo de salida
 * @param paises Paises a escribir
 * @return  Flujo de salida
 */
ostream& operator<<(ostream &os, const Paises &paises);

/**
 * @brief Sobrecarga del operador << para la clase Paises
 * @param is  Flujo de entrada
 * @param paises Paises a leer
 * @return  Flujo de entrada
 */
istream& operator>>(istream &is, Paises &paises);

#endif //PRACTICAFINAL_PAISES_H
