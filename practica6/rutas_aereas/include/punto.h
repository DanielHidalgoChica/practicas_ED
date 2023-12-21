/**
 * @file punto.h
 * @brief Fichero cabecera del TDA Punto
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H

#include <iostream>
using namespace std;

/**
 * @brief TDA Punto
 *
 * Una instancia @e p del tipo de datos abstracto @c Punto es un objeto
 * con dos campos, latitud y longitud, que representan las coordenadas
 * de un punto en el mapa.
 */
class Punto {

private:
	/**
	 * @brief Latitud del punto
	 */
	int latitud;
	// TODO:Cambiar a double

	/**
	 * @brief Longitud del punto
	 */
	int longitud;



public:

	/**
	 * @brief Constructor por defecto
	 */
	Punto();

	/**
	 * @brief Constructor con parámetros
	 * @param lat Latitud del punto
	 * @param lon Longitud del punto
	 */
	Punto(int lat, int lon);

	/**
	 * @brief Devuelve la latitud del punto
	 * @return Latitud del punto
	 */
	int getLatitud() const;

	/**
	 * @brief Devuelve la longitud del punto
	 * @return Longitud del punto
	 */
	int getLongitud() const;

	/**
	 * @brief Asigna una latitud al punto
	 * @param lat Latitud a asignar
	 */
	void setLatitud(int lat);

	/**
	 * @brief Asigna una longitud al punto
	 * @param lon Longitud a asignar
	 */
	void setLongitud(int lon);

	/**
	 * @brief Sobrecarga del operador ==
	 * @param p Punto a comparar
	 * @retval True si son iguales
	 * @retval False en caso contrario
	 */
	bool operator==(const Punto & p) const;

	// TODO: Pasar a coordenadas en mapa
	// TODO: Punto medio usando coordenadas
	// TODO: Ángulo de la recta que los une en coordenadas

	friend ostream & operator<<(ostream & os, const Punto & p);
	friend istream & operator>>(istream & is, Punto & p);
};

/**
 * @brief Sobrecarga del operador >>
 * @param is Flujo de entrada
 * @param p Punto a leer
 * @return Flujo de entrada
 */
istream & operator>>(istream & is, Punto & p);

/**
 * @brief Sobrecarga del operador <<
 * @param os Flujo de salida
 * @param p Punto a escribir
 * @return Flujo de salida
 */
ostream & operator<<(ostream & os, const Punto & p);


#endif //PRACTICAFINAL_PUNTO_H
