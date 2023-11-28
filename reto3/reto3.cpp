#include <iostream>
#include <list>
#include <utility>

using namespace std;

typedef pair<int, int> intervalo;
typedef list<intervalo>::iterator ilist;

/**
 * Integrantes del grupo:
 *
 * Daniel Hidalgo Chica
 * Irina Kuzyshyn Basarab
 * Jose Juan Urrutia Milan
 * -------------------------
 *
 * Decidimos realizar tres versiones de nuestro reto para facilitar
 * su correccion debido al codigo ilegible que esta presenta.
 * La version 3 es la version que contiene todo el codigo en una linea.
 *
*/

/**	----------------------------------------
*       Version 1 - Codigo legible y claro
*	----------------------------------------
*/

// Dado un intervalo de enteros x y una lista de intervalos L1, busca x en ella (el parametro it es fantasma, debe usarse
// pasandole siempre L1.begin() para la recursividad)
// El intervalo x se considerara "contenido" en la lista si aparece como elemento de esta
// o si para cierto elemento de la lista el intervalo queda contenido dentro en el sentido matematico
// (los extremos inferior y superior de x son, respectivamente, mayor que el extremo inferior del intervalo de L1 y menor que el extremo
// superior de el intervalo de L1)
// Devuelve un interador al intervalo e el que se encuentra contenido o un L1.end() si no se encuentra

ilist contenido(list<intervalo> &L1, const intervalo& x, ilist it){
	if(it == L1.end() || (it->first <= x.first && it->second >= x.second)){
		return it;
	}else{
		return contenido(L1, x, ++it);
	}
}

// Extrae del intervalo x de L1, que se asume contenido en *it
// Esto es, dado un intervalo x contenido en L1 en el sentido
// definido en la funcion anterior, se extrae de esta quitando de la lista
// los enteros que x contenga (respetando las propiedades de la lista de intervalos).

void borrar(list<intervalo> &L1, intervalo x, ilist it){
	if(*it == x){  // Si el intervalo esta en la lista, se elimina.
		L1.erase(it);
	}else{// Si el interavlo esta dentro de otro intervalo de la lista, se hara un corte del mismo, de forma
          // que de ese intervalo original queden tan solo los valores que no estan en en intervalo x, aunque esta
          // extraccion suponga crear un nuevo intervalo de la lista (caso que el intervalo x no abarque desde o hasta alguno
          // de los extremos del intervalo del que se extrae).
		if(it->first == x.first){
			it->first = x.second + 1;
		}else{
			if(it->second == x.second){
				it->second = x.first - 1;
			}else{
				L1.insert(it, intervalo(it->first, x.first - 1));
				it->first = x.second + 1;

				// Equivalente a (en version 2):
				// next(L1.insert(it, intervalo(it->first, x.first-1))).operator*().first=x.second+1;
			}
		}
	}
}

// Devuelve un iterador al siguiente al ultimo intervalo con second menor que x.first
// En caso de no existir, devuelve L1.begin()
// Usamos it para la recursividad, debe llamarse con it = L1.begin()

ilist anterior(list<intervalo> &L1, const intervalo &x, ilist it){
	if(it == L1.end()){
		return prev(L1.end());
	}else{
		if(it->second < x.first){
			return anterior(L1, x, ++it);
		}else{
			return it;
		}
	}
}

// Devuelve un iterador al anterior al primer intervalo con first mayor que x.second
// En caso de no exister, devuelve --L1.end()
// Usamos it para la recursividad, debe llamarse con it = L1.begin()

ilist posterior(list<intervalo> &L1, const intervalo &x, ilist it){
	if(it == L1.end() || it->first > x.second){
		return --it;
	}else{
		return posterior(L1, x, ++it);
	}
}

// Inserta el intervalo x en la lista de intervalos L2, solucionando los posibles
// solapamientos que puedan darse entre intervalos de la lista L2.

void insertar(list<intervalo> &L2, intervalo &x) {
    ilist it = anterior(L2, x, L2.begin());	// Buscamos el iterador anterior al primero con first mayor que x.second
    ilist it2 = posterior(L2, x, L2.begin()); // Buscamos el iterador siguiente al ultimo con second menor que x.first

    if(it2->first < it->first){	// Si los iteradores se han cruzado es por que el x no toca ningun intervalo, por lo que se inserta entre los dos iteradores
    	L2.insert(it, x);
	}else{
		if(it2->first > it->first){	 // Si se topa con varios intervalos, se pone la union entre los intervalos y x.
			L2.insert(it, intervalo(min(x.first, it->first), max(x.second, it2->second)));
			L2.erase(it, ++it2);

			// Equivalente a (en version 2):
			// (it = L2.erase(it, it2)).operator*() = {min(x.first, it->first), max(x.second, it2->second)};
		}else{
			if(*it == *it2 && it->second < x.first){	// Caso de que haya que insertarlo al final
				L2.push_back(x);
			}else{
				if(*it == *it2 && it->first > x.second){	// Caso de que haya que insertarlo por completo al principio
					L2.push_front(x);
				}else{	// Caso de que solo se topa con un intervalo, se le asigna la union del intervalo y x.
					(*it) = {min(x.first, it->first), max(x.second, it->second)};
				}
			}
		}
	}
}

// Extraer combina las funcionalidades de las funciones borrar e insertar, pasando
// un intervalo x que, de estar contenido en la lista L1, se borrara e insertara en la lista L2
// La funcion devuelve si el intervalo pudo eliminarse (y por tanto insertarse), es decir,
// si estaba efectivamente contenido en la lista L1.

bool extraer1(list<intervalo> &L1, intervalo x, list<intervalo> &L2){
	ilist it = contenido(L1, x, L1.begin());

	if(it == L1.end()){		// Si x no estaba contenido en L1
		return false;
	}else{
		borrar(L1, x, it);
		insertar(L2, x);
	}

	return true;
}

/**	   --------------------------------------------------
 *      Version 2 - Version final sin operador ternario
 *     --------------------------------------------------
 */

// Para reducir todo el codigo anterior a una linea nos vasamos en el uso del operador ternario. Para
// aportar un paso intermedio entre la linea y lo visto anteriormente, usamos if/else para facilitar
// la lectura del codigo.

// La estrategia detras de la linea es una funcion recursiva que dispone de diversos parametros que
// usaremos como variables dentro de la funcion, ya que al declarar variables aumentamos el numero de
// lineas de codigo.
// La estrategia es ejecutar el codigo en la misma llamada a la funcion y controlaremos que linea ejecutamos
// en cada llamada gracias a los "codops", un entero que nos permite seleccionar la linea que queremos ejecutar.

// TABLA DE TRADUCCION DE CODOPS:
// -2 --> La funcion se ejecuta por primera vez
// 0  --> Trata de localizar el intervalo de L1 en el que esta x (lo almacena en it). Analogo a contenido()
// 1  --> Extrae del intervalo *it de L1 el intervalo x. Analogo a borrar()
// 2  --> Inicializa it = L2.begin(), it2 = L2.begin().
// 3  --> Ejecuta anterior de forma recursiva, almacena el iterador en it.
// 4  --> Ejecuta posterior de forma recursiva, almacena el iterador en it2.
// 5  --> Ejecuta insertar el analogo a insertar().
// -1 --> La ejecucion de la funcion ha terminado y ha tenido exito, se devuelve true.

// Extraer2 es analogo a extraer1() pero con disponibiilidad a escribirse en una linea:
// Pasado un intervalo x que, de estar contenido en la lista L1, se borrara e insertara en la lista L2
// La funcion devuelve si el intervalo pudo eliminarse (y por tanto insertarse), es decir,
// si estaba efectivamente contenido en la lista L1.

// L1 : Lista de intervalos de los que extraer x
// x : Intervalo a extraer
// L2 : Lista de intervalos en el que insertar x si estaba contenido en L1
// it : Iterador que nos sirve como variable dentro de la funcion
// it2 : Otro iterador que nos sirve como variable
// codop : Indica la linea que se debe ejecutar en cada llamada a la funcion
// codigo : Campo en el que podemos ejecutar codigo, siempre y cuando realicemos casting a void* del mismo

// Recomendamos la lectura de la tabla de codops mientras se lee la implementacion.

bool extraer2(list<intervalo> &L1, intervalo x, list<intervalo> &L2, ilist it=list<intervalo>().begin(), ilist it2=list<intervalo>().begin(), int codop=-2, void* codigo = nullptr){

	if(codop == -2){	// Inicializamos it = L1.begin() y buscamos el intervalo de L1 en el que esta x (pasa a codop 0)
		return extraer2(L1, x, L2, L1.begin(), it2, 0);
	}else{
		if(codop == 0){
			if(it == L1.end()){     // Si x no esta contenido en ningun intervalo de L1
				return false;
			}else{
				if(it->first <= x.first && it->second >= x.second){     // Si x esta contenido en *it, finaliza codop 0, se pasa al 1
					return extraer2(L1, x, L2, it, it2, 1);
				}else{                                                  // Sigue buscando, en codop 0, con el siguiente valor de it
					return extraer2(L1, x, L2, ++it, it2, 0);
				}
			}
		}else{  // else de codop 0
			if(codop == 1){        // Elimina el intervalo de L1 en el que esta x en una instruccian (en cada caso), finaliza codop 1, se pasa al 2
				if(*it == x){
					return extraer2(L1, x, L2, it, it2, 2, static_cast<void*>(&(*(L1.erase(it)))));
				}else{
					if(it->first == x.first){
						return extraer2(L1, x, L2, it, it2, 2, reinterpret_cast<void*>(&(it->first = x.second + 1)));
					}else{
						if(it->second == x.second){
							return extraer2(L1, x, L2, it, it2, 2, reinterpret_cast<void*>(&(it->second = x.first - 1)));
						}else{
							return extraer2(L1, x, L2, it, it2, 2, reinterpret_cast<void*>(&(next(L1.insert(it, intervalo(it->first, x.first-1))).operator*().first = x.second+1)));    //
						}
					}
				}
			}else{  // else de codop 1

				if(codop == 2){     // Inicializa it = L2.begin(), it2 = L2.begin(), pasa a codop 3

					return extraer2(L1, x, L2, L2.begin(), L2.begin(), 3);

				}else{  // else de codop 2

					if(codop == 3){

						if(it == L2.end()){         							// Pasa a codop 4 con it apuntando al ultimo elemento de L2
							return extraer2(L1, x, L2, prev(L2.end()), it2, 4);
						}else{
							if(it->second < x.first){         					// Sigue buscando en codop 3 con el siguiente valor de it
								return extraer2(L1, x, L2, ++it, it2, 3);
							}else{         										// Pasa a codop 4 con el valor de it
								return extraer2(L1, x, L2, it, it2, 4);
							}
						}

					}else{  // else de codop 3
						if(codop == 4){

							if(it2 == L2.end() || it2->first > x.second){   // Se ha encontrado, es --it2, pasa a codop 5
								return extraer2(L1, x, L2, it, --it2, 5);
							}else{                                          // Sigue buscando, en codop 4, con el siguiente valor de it2
								return extraer2(L1, x, L2, it, ++it2, 4);
							}

						}else{  // else de codop 4
							if(codop == 5){ // Inserta el intervalo en una instruccion (en cada caso), finaliza codop 5, se pasa al -1

								if(it2->first < it->first){

									return extraer2(L1, x, L2, it, it2, -1, static_cast<void*>(&(*(L2.insert(it, x)))));

								}else{
									if(it2->first > it->first){

										return extraer2(L1, x, L2, it, it2, -1, static_cast<void*>(&((it = L2.erase(it, it2)).operator*() = {min(x.first, it->first), max(x.second, it2->second)})));

									}else{

										if(*it == *it2 && it->second < x.first){
											return extraer2(L1, x, L2, it, it2, -1, static_cast<void*>(&(*(L2.insert(L2.end(), x)))));
										}else{
											if(*it == *it2 && it->first > x.second){
												return extraer2(L1, x, L2, it, it2, -1, static_cast<void*>(&(*(L2.insert(L2.begin(), x)))));
											}else{
												return extraer2(L1, x, L2, it, it2, -1, static_cast<void*>(&((*it) = {min(x.first, it->first), max(x.second, it->second)})));
											}
										}

									}
								}

							}else{  // else de codop 5
								// En este punto, el unico codop posible es -1. Se termina la ejecucion de la funcion de forma correcta.
								return true;
							}
						}
					}
				}
			}
		}
	}
}

/** -------------------------------------
 *          Version 3 - Una linea
 *  -------------------------------------
*/

// La funcionalidad de esta version es identica (salvo if/else en lugar de operador ternario) a la de extrar2() (consultese antes
// de ver esta implementacion)

bool extraer(list<intervalo> &L1, intervalo x, list<intervalo> &L2, ilist it=list<intervalo>().begin(), ilist it2=list<intervalo>().begin(), int codop=-2, void* codigo = nullptr){
	return (codop == -2)? extraer(L1, x, L2, L1.begin(), it2, 0) : ((codop == 0)? ((it == L1.end())? (false) : ((it->first <= x.first && it->second >= x.second)?
	(extraer(L1, x, L2, it, it2, 1)) : (extraer(L1, x, L2, ++it, it2, 0)) ) ) : ( (codop == 1)? ((*it == x)? (extraer(L1, x, L2, it, it2, 2, static_cast<void*>(&(*(L1.erase(it)))))) :
	((it->first == x.first)? (extraer(L1, x, L2, it, it2, 2, reinterpret_cast<void*>(&(it->first = x.second + 1)))) : ((it->second == x.second)?
	(extraer(L1, x, L2, it, it2, 2, reinterpret_cast<void*>(&(it->second = x.first - 1)))) :
	(extraer(L1, x, L2, it, it2, 2, reinterpret_cast<void*>(&(next(L1.insert(it, intervalo(it->first, x.first-1))).operator*().first = x.second+1)))) ) ) ) :
	((codop == 2)? (extraer(L1, x, L2, L2.begin(), L2.begin(), 3)) : ((codop == 3)? ((it == L2.end())? (extraer(L1, x, L2, prev(L2.end()), it2, 4)) :
	((it->second < x.first)? (extraer(L1, x, L2, ++it, it2, 3)) : (extraer(L1, x, L2, it, it2, 4)) ) ) : ((codop == 4)? ((it2 == L2.end() || it2->first > x.second)?
	(extraer(L1, x, L2, it, --it2, 5)) : (extraer(L1, x, L2, it, ++it2, 4)) ) : ((codop == 5)? ((it2->first < it->first)?
	(extraer(L1, x, L2, it, it2, -1, static_cast<void*>(&(*(L2.insert(it, x)))))) : ((it2->first > it->first)?
	(extraer(L1, x, L2, it, it2, -1, static_cast<void*>(&((it = L2.erase(it, it2)).operator*() = {min(x.first, it->first), max(x.second, it2->second)})))) :
	((*it == *it2 && it->second < x.first)? (extraer(L1, x, L2, it, it2, -1, static_cast<void*>(&(*(L2.insert(L2.end(), x)))))) :
	((*it == *it2 && it->first > x.second)? (extraer(L1, x, L2, it, it2, -1, static_cast<void*>(&(*(L2.insert(L2.begin(), x)))))) :
	(extraer(L1, x, L2, it, it2, -1, static_cast<void*>(&((*it) = {min(x.first, it->first), max(x.second, it->second)})))) ) ) ) ) : (true) ) ) ) ) ) ) ;
}

// ------------------------------------------------------------
// Funcion main y funcionalidades para comprobar la ejecucion

// Funcion para imprimir una lista.

void print(const list<intervalo> &L1){
	cout << "<";
	for(list<intervalo>::const_iterator it = L1.begin(); it != L1.end(); ++it){
		cout << "[" << it->first << ", " << it->second << "]";
		if (it != --L1.end()) cout <<  ", ";
	}

	cout << ">" << endl;
}

int main(){

	// Ejemplo 1
	intervalo array1[] = {intervalo(1,7), intervalo(10,14), intervalo(18,20), intervalo(25,26)};
	intervalo array2[] = {intervalo(0,1), intervalo(14,16), intervalo(20,23)};
	intervalo x(12,14);

	list<intervalo> L1(array1, array1+4);
	list<intervalo> L2(array2, array2+3);

	// Ejemplo 2
	intervalo array3[] = {intervalo(1,7), intervalo(10,22), intervalo(25,26)};
	intervalo array4[] = {intervalo(0,1), intervalo(14,16), intervalo(20,23)};
	intervalo y(12,20);

	list<intervalo> L3(array3, array3+3);
	list<intervalo> L4(array4, array4+3);

	// Llamamos a la funcion e imprimimos los resultados
	cout << "Ejemplo 1:" << endl;

	cout << "L1: ";
	print(L1);
	cout << "L2: ";
	print(L2);

	cout << boolalpha << extraer(L1, x, L2) << endl << endl;

	// Ejemplo 2

	cout << endl << "Ejemplo 2:" << endl;

	cout << "L1: ";
	print(L3);
	cout << "L2: ";
	print(L4);

	cout << boolalpha << extraer(L3, y, L4) << endl;

	return 0;
}

