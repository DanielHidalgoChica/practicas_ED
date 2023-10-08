/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

bool Image::operator==(const Image & other){

    bool iguales = true;

    // Han de tener las mismas filas y columnas.
    iguales &= this->get_rows() == other.get_rows();
    iguales &= this->get_cols() == other.get_cols();

    int i=0;
    while (iguales && i<this->size()){

        // Compara cada píxel
        iguales = this->get_pixel(i) == other.get_pixel(i);
        i++;
    }

    return iguales;
}


double Image::Mean(int i, int j, int height, int width) const {

    double mean = 0;

    if (height * width!= 0) { // Si hay puntos
        // Se acumulan las sumas de los píxeles en cuestión.
        for (int fil = i; fil < i + width; fil++)
            for (int col = j; col < j + height; col++)
                mean += get_pixel(fil, col);

        // Se divide entre el número de puntos.
        mean /= height * width;
    }

    return mean;
}


// Genera una imagen aumentada 2x.
Image Image::Zoom2X() const{

    const int NFILS = 2*get_rows()-1;
    const int NCOLS = 2*get_cols()-1;

    // Genero mi imagen aumentada con todos los píxeles a 0.
    Image zoomed(NFILS, NCOLS);

    // Itero sobre cada pixel para cambiarlo
    for(int fil=0; fil<NFILS; ++fil)
        for(int col=0; col<NCOLS; col++){

            // Píxel original
            if (fil%2==0 && col%2==0) {
                byte original_pixel = get_pixel(fil/2, col/2);
                zoomed.set_pixel(fil, col, original_pixel);
            }

                // Pixel insertado. Hay que calcular la media.
            else {

                byte average_pixel;

                // Como (int) trunca, tenemos que al dividir entre dos nos quedamos con la fila o columna deseada
                // El operador % nos permite diferenciar si la columna, fila, o ambas son insertadas.
                average_pixel = round(Mean((int)(fil/2), (int)(col/2), 1+fil%2, 1+col%2));

                zoomed.set_pixel(fil, col, average_pixel);
            }
        }

    return zoomed;
}

// Genera un icono como reducción de una imagen.
Image Image::Subsample(int factor) const{

    Image icono = Image((int)(get_rows()/factor), (int)(get_cols()/factor));

    for(int fil=0; fil<icono.get_rows(); fil++)
        for(int col=0; col<icono.get_cols(); col++){

            // Cada pixel resultante es la media de un cuadrado de lado factor
            byte average = round(Mean(factor*fil, factor*col, factor, factor));
            icono.set_pixel(fil, col, average);
        }

    return icono;
}

void Image::Invert() {
    for (int i = 0; i < this->size(); ++i)
        this->set_pixel(i,255-(this->get_pixel(i)));
}














