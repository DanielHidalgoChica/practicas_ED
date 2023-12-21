/**
 * @file almacenRutas.h
 * @brief Fichero cabecera del TDA almacenRutas
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#ifndef PRACTICAFINAL_ALMACENRUTAS_H
#define PRACTICAFINAL_ALMACENRUTAS_H

#include <map>
#include <string>
#include <iostream>
#include "ruta.h"

using namespace std;

class AlmacenRutas {
private:
	/**
	 * @brief Mapa que contiene las rutas
	 *
	 * El mapa contiene como clave el código de la ruta y como valor la ruta
	 */
	map<string, Ruta> rutas;

public:

	/**
	 * @brief Constructor por defecto de la clase
	 */
	AlmacenRutas(){}

	/**
	 * @brief Constructor de la clase
	 * @param rutas Mapa que contiene las rutas
	 */
	AlmacenRutas(const map<string, Ruta> &rutas);

	/**
	 * @brief Método que devuelve la ruta correspondiente a un código
	 * @param codigo Código de la ruta
	 * @return Ruta correspondiente al código
	 */
	const Ruta& getRuta(string codigo);

	/**
	 * @brief Método que añade una ruta al almacén
	 * @param ruta Ruta a añadir
	 */
	void insertarRuta(const Ruta &ruta);

	/**
	 * @brief Método que elimina una ruta del almacén
	 * @param codigo Código de la ruta a eliminar
	 */
	void eliminarRuta(string codigo);

	/**
	 * @brief Método que devuelve el número de rutas del almacén
	 * @return Número de rutas del almacén
	 */
	int getNumRutas() const;

	class const_iterator;

	/**
	 * @brief Clase iterador de la clase AlmacenRutas
	 */
	 class iterator {
	 private:
		 map<string, Ruta>::iterator it;
	 public:
		 /**
		  * @brief Constructor por defecto de la clase
		  */
		 iterator() {}

		 /**
		  * @brief Constructor de la clase
		  * @param it Iterador de la clase map
		  */
		 iterator(map<string, Ruta>::iterator it) : it(it) {}

		 /**
		  * @brief Sobrecarga del operador de incremento
		  * @return Iterador incrementado
		  */
		 iterator &operator++() {
			 ++it;
			 return *this;
		 }

		 /**
		  * @brief Sobrecarga del operador de decremento
		  * @return Iterador decrementado
		  */
		 iterator &operator--() {
			 --it;
			 return *this;
		 }

		 /**
		  * @brief Sobrecarga del operador de acceso
		  * @return Ruta apuntada por el iterador
		  */
		 Ruta &operator*() {
			 return it->second;
		 }

		 /**
		  * @brief Sobrecarga del operador de comparación
		  * @param i Iterador con el que se compara
		  * @return True si son iguales, false en caso contrario
		  */
		 bool operator==(const iterator &i) {
			 return it == i.it;
		 }

		 /**
		  * @brief Sobrecarga del operador de comparación
		  * @param i Iterador con el que se compara
		  * @return True si son distintos, false en caso contrario
		  */
		 bool operator!=(const iterator &i) {
			 return it != i.it;
		 }

		 friend class AlmacenRutas;
		 friend class const_iterator;
	 };

	 /**
	  * @brief Devuelve un iterador al principio del mapa
	  * @return Iterador al principio del mapa
	  */
	 iterator begin() {
		 iterator i;
		 i.it = rutas.begin();
		 return i;
	 }

	 /**
	  * @brief Devuelve un iterador al final del mapa
	  * @return Iterador al final del mapa
	  */
	 iterator end() {
		 iterator i;
		 i.it = rutas.end();
		 return i;
	 }

	 /**
	  * @brief Clase iterador constante de la clase AlmacenRutas
	  */
	 class const_iterator {
     private:
		 map<string, Ruta>::const_iterator it;
     public:

		 const_iterator() {}
		 const_iterator(const map<string, Ruta>::const_iterator &it) : it(it) {}
		 const_iterator &operator++() {
			 ++it;
			 return *this;
		 }
		 const_iterator &operator--() {
			 --it;
			 return *this;
		 }
		 bool operator==(const const_iterator &i) {
			 return it == i.it;
		 }
		 bool operator!=(const const_iterator &i) {
			 return it != i.it;
		 }
		 const Ruta &operator*() {
			 return it->second;
		 }
		 friend class AlmacenRutas;
     };

	friend ostream & operator<<(ostream & os, const AlmacenRutas & almacen);
	friend istream & operator>>(istream & is, AlmacenRutas & almacen);
};

/**
 * @brief Sobrecarga del operador de salida
 * @param os  Stream de salida
 * @param almacen  Almacén de rutas
 * @return  Stream de salida
 */
ostream & operator<<(ostream & os, const AlmacenRutas & almacen);

/**
 * @brief Sobrecarga del operador de entrada
 * @param is  Stream de entrada
 * @param almacen  Almacén de rutas
 * @return  Stream de entrada
 */
istream & operator>>(istream & is, AlmacenRutas & almacen);


#endif //PRACTICAFINAL_ALMACENRUTAS_H