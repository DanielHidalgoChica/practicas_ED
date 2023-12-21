/**
 * @file pais.cpp
 * @brief Fichero de implementación del TDA pais
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "pais.h"

Pais::Pais(string nombre, string bandera, const Punto &p) {
	this->nombre = nombre;
	this->bandera = bandera;
	this->p = p;
}

string Pais::getNombre() const {
	return nombre;
}

string Pais::getBandera() const {
	return bandera;
}

const Punto & Pais::getPunto() const {
	return p;
}

void Pais::setNombre(string nombre) {
	this->nombre = nombre;
}

void Pais::setBandera(string bandera) {
	this->bandera = bandera;
}

void Pais::setPunto(const Punto &p) {
	this->p = p;
}

bool Pais::operator<(const Pais &p) const {
	return nombre < p.getNombre();
}

ostream & operator<<(ostream & os, const Pais & p) {
	os << p.getPunto() << " " << p.getNombre() << " " << p.getBandera();
	return os;
}

istream & operator>>(istream & is, Pais & p) {
	string nombre, bandera;
	Punto punto;
	is >> punto >> nombre >> bandera;
	p.setNombre(nombre);
	p.setBandera(bandera);
	p.setPunto(punto);
	return is;
}