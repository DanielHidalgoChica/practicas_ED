/**
 * @file barajar_medida_nreps.cpp
 * @brief Fichero usado para medir la eficiencia empírica al llamar
 * 			$n$ veces a Image::ShuffleRows() entre Image::Load() y Image::Save()
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <image.h>

using namespace std;

int main (int argc, char* argv[]) {
	char *fich_orig, *fich_rdo; // Nombres de los ficheros
	int nreps;

	Image image; // Imagen que barajamos

	// Comprobamos validez de la llamada
	if (argc !=4){
		cerr << "Error: Numero incorrecto de parametros.\n";
		cerr << "Uso: barajar_medida_nreps <fich_orig> <fich_rdo> <nreps>";
		exit (1);
	}

	// Recuperamos argumentos
	fich_orig = argv[1];
	fich_rdo = argv[2];
	nreps = stoi(argv[3]);


	// Leer la imagen del fichero de entrada
	if (!image.Load(fich_orig)){
		cerr << "Error: No pudo leerse la imagen." << endl;
		cerr << "Terminando la ejecucion del programa." << endl;
		return 1;
	}

	clock_t tini = clock();    // Anotamos el tiempo de inicio

	for (int n=0; n<nreps; n++)
		image.ShuffleRows_eff();

	clock_t tfin = clock();   // Anotamos el tiempo de finalización

	// Mostramos resultados
	cout << (tfin - tini) / (double)CLOCKS_PER_SEC << endl;

	if (!image.MySave(fich_rdo)){
		cerr << "Error: No pudo guardarse la imagen." << endl;
		cerr << "Terminando la ejecucion del programa." << endl;
		return 1;
	}
}