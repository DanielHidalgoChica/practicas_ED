/**
 * @file pruebapegado.cpp
 *
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;



int main(int argc, char * argv[]){
	if (argc!=8){
		cout<<"Los parametros son :"<<endl;
		cout<<"1 - La imagen de fondo"<<endl;
		cout<<"2 - La imagen a pegar"<<endl;
		cout<<"3 - La máscara de la imagen a pegar"<<endl;
		cout<<"4 - El nombre de la imagen de salida"<<endl;
		cout<<"5 - La fila donde pegar"<<endl;
		cout<<"6 - La columna donde pegar"<<endl;
		cout<<"7 - 0: Pegado Opaco 1: Pegado Blending"<<endl;
		return -1;
	}
	Imagen I,Ip;
	I.LeerImagen(argv[1]);  // Imagen donde voy a pegar
	Ip.LeerImagen(argv[2],argv[3]);     // Imagen que voy a pegar

	int i,j;    // Pasamos fila y columnas a enteros
	i=atoi(argv[5]); j=atoi(argv[6]);

	Tipo_Pegado tp; //variable de tipo Tipo_Pegado que es un enumerado con los valores OPACO y BLENDING
	int au= atoi(argv[7]);
	if (au==0) tp=OPACO;
	else if (au==1) tp=BLENDING;
	else {
		cout<<"El valor de pegado debe ser 0 o 1"<<endl;
		return -1;
	}

	// Pegamos la imagen
	I.PutImagen(i,j,Ip,tp);

	// Guardamos la imagen
	I.EscribirImagen(argv[4]);

	return 0;
}  