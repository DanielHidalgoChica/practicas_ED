/**
 * @file ruta.cpp
 * @brief Fichero de implementación del TDA ruta
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "ruta.h"

Ruta::Ruta(string codigo, const list<Punto> &puntos) {
	this->codigo = codigo;
	this->puntos = puntos;
}

void Ruta::setCodigo(string codigo) {
	this->codigo = codigo;
}


void Ruta::setPuntos(const list<Punto> &puntos) {
	this->puntos = puntos;
}

string Ruta::getCodigo() const {
	return codigo;
}

const list<Punto>& Ruta::getPuntos() const {
	return puntos;
}

int Ruta::getNumPuntos() const {
	return puntos.size();
}

void Ruta::insertarPunto(const Punto &p) {
	puntos.push_back(p);
}

void Ruta::eliminarPunto(const Punto &p) {
	puntos.remove(p);
}

ostream & operator<<(ostream & os, const Ruta & r) {
	os << r.codigo << " ";
	list<Punto>::const_iterator it;
	for (it = r.puntos.begin(); it != r.puntos.end(); ++it) {
		os << *it << " ";
	}
	return os;
}

istream & operator>>(istream & is, Ruta & r) {
	string codigo;
	list<Punto> puntos;
	is >> codigo;
	r.setCodigo(codigo);
	Punto p;
	while (is >> p) {
		puntos.push_back(p);
	}
	r.setPuntos(puntos);
	return is;
}