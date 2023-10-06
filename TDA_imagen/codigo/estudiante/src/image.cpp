/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <cmath>

#include <image.h>
#include <imageIO.h>

using namespace std;

/********************************
      FUNCIONES PRIVADAS
********************************/
void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}

LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor

Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    img[0][k] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?
    return img[0][k];
}

// Métodos para almacenar y cargar imagenes en disco
bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    byte * p = img[0];
    return WritePGMImage(file_path, p, rows, cols);
}

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
