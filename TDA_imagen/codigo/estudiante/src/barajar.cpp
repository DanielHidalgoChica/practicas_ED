//
// Created by daniel on 10/10/23.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <image.h>

using namespace std;

int main (int argc, char* argv[]) {
    char *fich_orig, *fich_rdo; // Nombres de los ficheros

    Image image; // Imagen que barajamos

    // Comprobamos validez de la llamada

    if (argc !=3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: barajar <fich_orig> <fich_rdo>";
        exit (1);
    }

    // Recuperamos argumentos
    fich_orig = argv[1];
    fich_rdo = argv[2];

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << fich_orig << endl;
    cout << "Fichero resultado: " << fich_rdo << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(fich_orig)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
    cout << endl;
    cout << "Dimensiones de " << fich_orig << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

    // Barajamos las filas
    Image barajada(image); // Copia de image
    barajada.ShuffleRows_eff();

    if (barajada.MySave(fich_rdo))
        cout  << "La imagen se guardo en " << fich_rdo << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}