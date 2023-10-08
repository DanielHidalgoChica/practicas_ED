//
// Created by Daniel Hidalgo Chica on 8/10/23.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <image.h>

using namespace std;

int main (int argc, char* argv[]) {
    char *fich_orig, *fich_rdo; // Nombres de los ficheros
    int fila,col; // Fila y columna donde empezar el recorte
    int filas_sub, cols_sub;

    Image image; // Imagen que recortamos
    Image recorte; // Recorte que devuelve el programa

    // Comprobamos validez de la llamada

    cout << "NUMPAR: " << argc << endl;
    if (argc !=7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: crop <fich_orig> <fich_rdo> <fila> <col> <filas_sub> <cols_sub>";
        exit (1);
    }

    // Recuperamos argumentos
    fich_orig = argv[1];
    fich_rdo = argv[2];
    fila = atoi(argv[3]);
    col = atoi(argv[4]);
    filas_sub = atoi(argv[5]);
    cols_sub = atoi(argv[6]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << fich_orig << endl;
    cout << "Fichero resultado: " << fich_rdo << endl;
    cout << "Fila donde comienza el recorte:" << fila << endl;
    cout << "Columna donde comienza el recorte:" << col << endl;
    cout << "Altura en filas del recorte:" << filas_sub << endl;
    cout << "Anchura en columnas del recorte:" << cols_sub << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(fich_orig)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << fich_orig << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    // Calculamos el recorte
    recorte = image.Crop(fila, col, filas_sub, cols_sub);

    if (recorte.Save(fich_rdo))
        cout  << "La imagen se guardo en " << fich_rdo << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}