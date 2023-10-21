/**
 * @file barajar_medida_filcols.cpp
 * @brief Fichero usado para medir la eficiencia empírica al llamar
 * 			a Image::ShuffleRows() con una imagen de distinto número de filas y columnas
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <image.h>

using namespace std;

int main (int argc, char* argv[]) {
    int nfils, ncols;

	// Comprobamos validez de la llamada
	if (argc !=3){
		cerr << "Error: Numero incorrecto de parametros.\n";
		cerr << "Uso: barajar_medida_filcols <nfils> <ncols>";
		exit (1);
	}

	// Recuperamos argumentos
	nfils = stoi(argv[1]);
	ncols = stoi(argv[2]);

    Image image(nfils, ncols, 0); // Imagen vamos a barajar

	const int NUM_VECES = 1e3; // Media eficiencia

	clock_t tini = clock();    // Anotamos el tiempo de inicio

	for (int n=0; n<NUM_VECES; n++)
		image.ShuffleRows_eff();

	clock_t tfin = clock();   // Anotamos el tiempo de finalización

	// Mostramos resultados
	cout << (tfin - tini) / (double)CLOCKS_PER_SEC / NUM_VECES << endl;
}