// Fichero: zoom.cpp
// Aplica un zoom 2x de una imagen PGM
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
  if (argc != 6){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: zoom <FichImagenOriginal> <FichImagenDestino> <fila> <columna> <lado>\n";
    exit (1);
  }

  // Obtener argumentos
  origen   = argv[1];
  destino  = argv[2];
  int fil  = stoi(argv[3]);
  int col  = stoi(argv[4]);
  int lado = stoi(argv[5]);

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



  // Comprobar los parámetros

  // Coordenada de inicio
  bool fil_ok = 0<= fil && fil < image.get_rows();
  bool col_ok = 0<= col && col < image.get_cols();
  if (!(fil_ok && col_ok)){
    cerr << "Error: Coordenada de inicio no valida." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Coordenada final
  fil_ok = 0<= fil+lado && fil+lado <= image.get_rows();
  col_ok = 0<= col+lado && col+lado <= image.get_cols();
  if (!(fil_ok && col_ok)){
      cerr << "Error: Zona descrita no está totalmente incluida." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      return 1;
  }

  // Aplicar el crop
  Image recortada = image.Crop(fil, col, lado, lado);

  // Aplicar el zoom
  Image ampliada = recortada.Zoom2X();

  // Guardar la imagen resultado en el fichero
  if (ampliada.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  return 0;
}
