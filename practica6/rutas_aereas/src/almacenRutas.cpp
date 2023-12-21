/**
 * @file almacenRutas.cpp
 * @brief Fichero de implementación del TDA almacenRutas
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "almacenRutas.h"
using namespace std;

AlmacenRutas::AlmacenRutas(const map<string, Ruta> &rutas) {
	this->rutas = rutas;
}

const Ruta& AlmacenRutas::getRuta(string codigo) {
	return rutas[codigo];
}

void AlmacenRutas::insertarRuta(const Ruta &ruta) {
	rutas.insert(pair<string, Ruta>(ruta.getCodigo(), ruta));
}

void AlmacenRutas::eliminarRuta(string codigo) {
	rutas.erase(codigo);
}

int AlmacenRutas::getNumRutas() const {
	return rutas.size();
}

ostream & operator<<(ostream & os, const AlmacenRutas & ar) {
	map<string, Ruta>::const_iterator it;
	for (it = ar.rutas.begin(); it != ar.rutas.end(); ++it) {
		os << it->second << endl;
	}
	return os;
}

istream & operator>>(istream & is, AlmacenRutas & ar) {
	map<string, Ruta> rutas;
	Ruta ruta;
	while (is >> ruta) {
		rutas.insert(pair<string, Ruta>(ruta.getCodigo(), ruta));
	}
	ar = AlmacenRutas(rutas);
	return is;
}