/**
 * @file paises.cpp
 * @brief Fichero de implementación del TDA Paises
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "paises.h"

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

Paises::iterator Paises::find(const Pais &pais) {
	return datos.find(pais);
}

ostream &operator<<(ostream &os, const Paises &paises) {
	Paises::iterator it;
	for (it = paises.begin(); it != paises.end(); ++it) {
		os << *it << "\t";
	}
	return os;
}


