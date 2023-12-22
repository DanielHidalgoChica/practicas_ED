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
#include <cmath>

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

Imagen Imagen::Rota(double angulo) const {
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=GetFilas()-1;
    rcorners[3]=GetFilas()-1;
    ccorners[1]=GetColumnas()-1;
    ccorners[3]=GetColumnas()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++){
        inter=rcorners[count]*coseno+ccorners[count]*seno;

        if(inter<new_row_min)
            new_row_min=inter;
        if(inter>new_row_max)
            new_row_max=inter;
        inter1=-rcorners[count]*seno+ccorners[count]*coseno;

        if(inter1<new_col_min)
            new_col_min=inter1;
        if(inter1>new_col_max)
            new_col_max=inter1;
    }

    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);

    Imagen Iout(newimgrows,newimgcols);
    for(int rows=0;rows<newimgrows;rows++){
        for(int cols=0;cols<newimgcols;cols++){
            float oldrowcos=((float)rows+new_row_min)*cos(-rads);
            float oldrowsin=((float)rows+new_row_min)*sin(-rads);
            float oldcolcos=((float)cols+new_col_min)*cos(-rads);
            float oldcolsin=((float)cols+new_col_min)*sin(-rads);
            float old_row=oldrowcos+oldcolsin;
            float old_col=-oldrowsin+oldcolcos;
            old_row=ceil((double)old_row);
            old_col=ceil((double)old_col);
            if ((old_row >= 0) && (old_row < GetFilas()) &&
                (old_col >= 0) && (old_col < GetColumnas())) {
                Iout(rows, cols) = (*this).operator()(old_row, old_col);
            } else
                Iout(rows, cols).r = Iout(rows, cols).g = Iout(rows, cols).b = 255;
        }
    }
    return Iout;
}

void EscribirImagen(const char nombre[], const Imagen & I){
	// TODO Método EscribirImagen
}

void LeerImagen(const char nombre[], Imagen & I){
	// TODO Método LeerImagen
}

void Imagen::PutImagen(int posi, int posj, const Imagen & I, Tipo_Pegado t){
	// TODO Método PutImagen
}

Imagen Imagen::ExtraerImagen(int posi, int posj, int dimi, int dimj) const{
	// TODO Método ExtraerImagen
}


// TODO Ambos Iteradores