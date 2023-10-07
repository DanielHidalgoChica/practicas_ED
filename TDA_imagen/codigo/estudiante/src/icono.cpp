// Fichero: icono.cpp
// Obtiene un icono a partir de una imagen.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  Image image;

  // Comprobar validez de la llamada
  if (argc != 4){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: zoom <FichImagenOriginal> <FichImagenDestino> <factor>\n";
    exit (1);
  }

  // Obtener argumentos
  origen   = argv[1];
  destino  = argv[2];
  int factor  = stoi(argv[3]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  if (!image.Load(origen)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parámetros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;



  // Comprobar el parámetro factor
  if (factor <= 0){
    cerr << "Error: Factor no válido." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Aplicar el icono
  Image icono = image.Subsample(factor);

  // Guardar la imagen resultado en el fichero
  if (icono.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  return 0;
}
