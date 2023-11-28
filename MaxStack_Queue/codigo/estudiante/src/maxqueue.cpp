/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */
#include <iostream>
#include "maxqueue.h"

using namespace std;


element maxqueue::front() {
    return this->p.top();
}

void maxqueue::pop() {
    this->p.pop();

    // Controlo la pila de máximos:
    // si el valor que he quitado era
    // el más alto que encontramos
    // en la pila entonces hago un
    // pop en la pila de máximos porque ha desaparecido una de las ocurrencias
    // de este valor en la cola. Así, en cuanto desaparezcan todas, el valor del máximo
    // en cola se actualizará al del siguiente valor en la pila de máximos
    // Solo falla una cosa, si tengo que el máximo después después de popear
    // el último máximo ya no está en la cola, tengo que quitármelo de la cola de máximos
}

void maxqueue::push(int i) {
    // hago un push normal con pilas auxiliares
    stack<element> aux_s;
    while (!this->p.empty())
    {
        aux_s.push(this->p.top());
        this->p.pop();
    }
    element e;
    e.value = i;
    e.maximum = i; // NO RELLENO ESTO POR AHORA PORQUE NO SÉ QUÉ ESTOY HACIENDO (meto i provisionalmente
                   // porque creo que me vale cualquier valor)
    aux_s.push(e);

    while (!aux_s.empty())
    {
        this->p.push(aux_s.top());
        aux_s.pop();
    }

    // ¿Cómo actualizo el máximo de front? Meto en la pila de máximos
    // cuyo tope va a ser el máximo de front el valor que he metido si
    // esque cumple que la pila de máximos está vacía o su tope es mayor
    // o igual al valor

    if (maxs_stack.empty() || maxs_stack.top() <= i) maxs_stack.push(i);
}

bool maxqueue::empty() {
    return this->p.empty();
}

size_t maxqueue::size() {
    return this->p.size();
}
