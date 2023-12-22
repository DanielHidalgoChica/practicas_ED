/**
 * @file paises.cpp
 * @brief Fichero de implementación del TDA Paises
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "paises.h"

const string CAD_MAGS[4] = {"# Latitud", "Longitud", "Pais", "Bandera"};

Paises::Paises(const set<Pais> &paises) {
	datos = paises;
}

int Paises::size() const {
	return datos.size();
}

const set<Pais>& Paises::getDatos() const {
	return datos;
}

void Paises::insertar(const Pais &pais) {
	datos.insert(pais);
}

void Paises::eliminar(const Pais &pais) {
	datos.erase(pais);
}

Paises::iterator Paises::find(const Pais &pais) const {
	return datos.find(pais);
}

Paises::iterator Paises::find(const Punto &punto) const {
	Paises::iterator it;
	for (it = this->begin(); it != this->end(); ++it) {
		if ((*it).getPunto() == punto) {
			return it;
		}
	}
	return this->end();
}


ostream &operator<<(ostream &os, const Paises &paises) {

	for (int i = 0; i < 4; i++) {
		os << CAD_MAGS[i] << "\t";
	}
	os << endl;

	Paises::iterator it;
	for (it = paises.begin(); it != paises.end(); ++it) {
		os << *it << endl;
	}
	return os;
}


