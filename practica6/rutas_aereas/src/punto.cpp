/**
 * @file punto.cpp
 * @brief Fichero de implementacion del TDA Punto
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "punto.h"

Punto::Punto(): latitud(0), longitud(0){}

Punto::Punto(int lat, int lon): latitud(lat), longitud(lon){}

int Punto::getLatitud() const{
	return latitud;
}

int Punto::getLongitud() const{
	return longitud;
}

void Punto::setLatitud(int lat){
	latitud = lat;
}

void Punto::setLongitud(int lon){
	longitud = lon;
}

bool Punto::operator==(const Punto &p) const{
	return (latitud == p.latitud && longitud == p.longitud);
}

ostream & operator<<(ostream & os, const Punto &p){
	os << "(" << p.getLatitud() << "," << p.getLongitud() << ")";
	return os;
}

istream & operator>>(istream & is, Punto &p){
	int lat, lon;
	char c;
	is >> c >> lat >> c >> lon >> c;
	p.setLatitud(lat);
	p.setLongitud(lon);
	return is;
}