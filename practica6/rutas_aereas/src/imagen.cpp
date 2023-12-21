/**
 * @file imagen.cpp
 * @brief Fichero de implementación del TDA Imagen
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "imagen.h"
#include <iostream>
using namespace std;

Imagen::Imagen(){
	datos.resize(0);
}

Imagen::Imagen(int filas, int columnas){
	datos.resize(filas);
	for(int i=0;i<filas;i++)
		datos[i].resize(columnas);
}

const Pixel &Imagen::operator()(int i, int j) const {
	return datos[i][j];
}

Pixel &Imagen::operator()(int i, int j) {
	return datos[i][j];
}

int Imagen::GetFilas() const {
	return datos.size();
}

int Imagen::GetColumnas() const {
	return datos[0].size();
}

void EscribirImagen(const char * nombre, const Imagen & I){
	// TODO Método EscribirImagen
}

void LeerImagen(const char * nombre, Imagen & I){
	// TODO Método LeerImagen
}

void Imagen::PutImagen(int posi, int posj, const Imagen & I, Tipo_Pegado t){
	// TODO Método PutImagen
}

Imagen Imagen::ExtraerImagen(int posi, int posj, int dimi, int dimj) const{
	// TODO Método ExtraerImagen
}


// TODO Ambos Iteradores