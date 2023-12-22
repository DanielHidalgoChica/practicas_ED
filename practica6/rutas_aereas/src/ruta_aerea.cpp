/**
 * @file pruebapegado.cpp
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 *
 * @brief // TODO: TERMINAR brief
 *
 * @param fichero_paises Fichero con la informacion de los paises
 * @param mapa_mundo Nombre de la imagen con el mapa del mundo
 * @param dir_banderas Directorio con las banderas
 * @param almacen_rutas Fichero con el almacen de rutas
 * @param avion Nombre de la imagen con el avion. Tipo PPM
 * @param mascara_avion Nombre de la imagen de la mascara del avion. Tipo PGM
 *
 *
 * Un ejemplo de ejecución es:
 * Ejemplo de uso:
 * @code{.sh}
 * ruta_aerea fichero_paises.txt mapa_mundo.txt ./dir_banderas almacen_rutas.txt avion.ppm mascara_avion.pgm
 * // TODO: TERMINAR
 * @endcode
 *
 * Este ejemplo muestra cómo utilizar el ejecutable **ruta_aerea** para representar una rura.
 *
 * // TODO: Terminar imágenes
 * <div style="text-align: center;">
 *   <div style="display: inline-block; text-align: center; margin: 0 3em;">
 *     <img src="vacas.png" alt="Imagen Original" style="border: none;" />
 *     <br>
 *     <small>Imagen Original</small>
 *   </div>
 *   <div style="display: inline-block; text-align: center; margin: 0 3em;">
 *     <img src="Ex_Recortada.png" alt="Imagen Superpuesta Blending" style="border: none;" />
 *     <br>
 *     <small>Imagen Superpuesta usando el tipo de pegado Blending</small>
 *   </div>
 *   <div style="display: inline-block; text-align: center; margin: 0 3em;">
 *     <img src="Ex_Recortada.png" alt="Imagen Superpuesta Opaco" style="border: none;" />
 *     <br>
 *     <small>Imagen Superpuesta usando el tipo de pegado Opaco</small>
 *   </div>
 * </div>
 */

// TODO: revisar formatos E/S
#include "almacenRutas.h"
#include "paises.h"
#include "imagen.h"
#include <fstream>

#define RESULT_PATH "./output/"

int main (int argc, char* argv[]) {
    if (argc!=7){
        cout<<"Los parametros son:"<<endl;
        cout<<"1 - Fichero con la informacion de los paises"<<endl;
        cout<<"2 - Nombre de la imagen con el mapa del mundo"<<endl;
        cout<<"3 - Directorio con las banderas"<<endl;
        cout<<"4 - Fichero con el almacen de rutas"<<endl;
        cout<<"5 - Nombre de la imagen con el avion"<<endl;
        cout<<"6 - Nombre de la imagen de la mascara del avion"<<endl;

		cout << "Uso: " << argv[0] << " <fichero_paises> <mapa_mundo> <dir_banderas> <almacen_rutas> <avion> <mascara_avion>" << endl;

        return -1;
    }

	ifstream file;
	file.open(argv[1]);
	Paises paises; // Leemos los paises
	if (file)
		file >> paises;
	else {
		cout << "Error de apertura del fichero" << argv[1] << endl;
		return -1;
	}
	file.close();

	cout << "Hola" << endl;

	Imagen mapa;
	mapa.LeerImagen(argv[2]);

	Imagen avion;
	avion.LeerImagen(argv[5], argv[6]); // Leemos con la máscara

	cout << "Hola2" << endl;

    AlmacenRutas Ar; // Leemos el almacen de rutas
    file.open (argv[4]);
	cout << "Hola3" << endl;
	if (file){
		cout << "Hola4" << endl;
		file >> Ar;
		cout << "Hola5" << endl;
	}
	else {
		cout << "Error de apertura del fichero " << argv[4] << endl;
		return -1;
	}
	file.close();

	// Muestra todas las rutas disponibles
    cout<<"Las rutas: "<<endl;
	cout << Ar << endl;
    cout<<"Introduzca el codigo de una ruta"<<endl;
    string id_ruta; // Ruta
    cin>>id_ruta;
    // Comprobación de que "id_ruta" es una ruta valida
    if (!Ar.existeRuta(id_ruta)) {
        cout << "La ruta no existe" << endl;
        return 1;
    }
    Ruta route=Ar.getRuta(id_ruta);

    // Ya tenemos la ruta, ahora vamos a mostrarla
    string dir_banderas = argv[3];

    Ruta::iterator it_r=route.begin();
    Punto point1, point2;
    pair<int,int> coord_point1, coord_point2, coord_point_midpoint;
    double orientation_angle;
    Imagen avion_rotado;
    Pais pais;
    Imagen bandera;

    while (it_r != route.end()) {
        point1=*it_r;
        coord_point1 = point1.coordenadasMapa(mapa.getColumnas(), mapa.getFilas());

        // Extraigo país
        Paises::iterator pos_pais_point1 = paises.find(point1);
        if (pos_pais_point1 == paises.end()) {
            cout << "No pudo encontrarse el pais que tiene como punto " << point1 << endl;
            exit(-1);
        }
        pais = *(paises.find(point1));

        // Pongo bandera en el mapa
        string nombre_bandera = dir_banderas + "/" + pais.getBandera();
        bandera.LeerImagen(nombre_bandera.c_str());
        Tipo_Pegado tp_bl = BLENDING;
        mapa.PutImagen(coord_point1.first, coord_point1.second, bandera, tp_bl);
        // Imprimo por pantalla el nombre del país
        cout << pais.getNombre() << " ";

        // Leo siguiente punto
        ++it_r;
        if (it_r != route.end()) {
            point2=*it_r;
            coord_point2 = point2.coordenadasMapa(mapa.getColumnas(), mapa.getFilas());
            coord_point_midpoint = point1.punto_medio_en_mapa(point2, mapa.getColumnas(), mapa.getFilas());
            orientation_angle = point1.angulo_en_mapa(point2, mapa.getColumnas(), mapa.getFilas());

            // Pego los 3 aviones correspondientes
            Tipo_Pegado tp_op = OPACO;
            avion_rotado = avion.Rota(orientation_angle);
            mapa.PutImagen(coord_point_midpoint.first, coord_point_midpoint.second, avion_rotado, tp_op);
            mapa.PutImagen(coord_point1.first, coord_point1.second, avion_rotado, tp_op);
            mapa.PutImagen(coord_point2.first, coord_point2.second, avion_rotado, tp_op);
        } // if (it_r != route.end())
    } // while (it_r != route.end())

    string result_path = RESULT_PATH + route.getCodigo() + string("_Mapa.ppm");
    mapa.EscribirImagen(result_path.c_str());

    return 0;
}