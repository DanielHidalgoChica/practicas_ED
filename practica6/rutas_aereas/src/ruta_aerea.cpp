/**
 * @file ruta_aerea.cpp
 * @brief
 *
 * @author Arturo Olivares Martos
 * @author Daniel Hidalgo Chica
 */

#include "almacenRutas.h"
#include "paises.h"
#include "imagen.h"
#include <fstream>

int main (int argc, char* argv[]) {
    if (argc!=7){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.-Fichero con la informacion de los paises"<<endl;
        cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
        cout<<"3.-Directorio con las banderas"<<endl;
        cout<<"4.-Fichero con el almacen de rutas"<<endl;
        cout<<"5.- Nombre de la imagen con el avion"<<endl;
        cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;

        return -1;
    }

   ifstream file(argv[1]);
   Paises paises;
   if (file)
    file >> paises;
   else {
       cout << "Error de apertura del fichero" << endl;
       return -1;
   }

   Imagen mapa;
   mapa.LeerImagen(argv[2]);

   Imagen avion;
   avion.LeerImagen(argv[5], argv[6]); // Leemos con la máscara

    AlmacenRutas Ar;
    file.close();
    file.open (argv[4]);
    file>>Ar;
    cout<<"Las rutas: "<<endl<<Ar; // Muestra todas las rutas disponibles
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
        coord_point1 = point1.coordenadasMapa(mapa.GetColumnas(), mapa.GetFilas());

        // Extraigo país
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
            coord_point2 = point2.coordenadasMapa(mapa.GetColumnas(), mapa.GetFilas());
            coord_point_midpoint = point1.punto_medio_en_mapa(point2, mapa.GetColumnas(), mapa.GetFilas());
            orientation_angle = point1.angulo_en_mapa(point2, mapa.GetColumnas(), mapa.GetFilas());

            // Pego los 3 aviones correspondientes
            Tipo_Pegado tp_op = OPACO;
            avion_rotado = avion.Rota(orientation_angle);
            mapa.PutImagen(coord_point_midpoint.first, coord_point_midpoint.second, avion_rotado, tp_op);
            mapa.PutImagen(coord_point1.first, coord_point1.second, avion_rotado, tp_op);
            mapa.PutImagen(coord_point2.first, coord_point2.second, avion_rotado, tp_op);
        } // if (it_r != route.end())
    } // while (it_r != route.end())

    return 0;
}