/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */
#include <iostream>
#include "maxstack.h"
using namespace std;

maxstack::maxstack() = default;

maxstack::maxstack(const maxstack &ms): q(ms.q) {}

void maxstack::push(int i)
{
    queue<element> aux(this->q);
    while (!this->q.empty()) this->q.pop();

    element e;
    e.value = i;
    if (i > this->q.front().maximum) e.maximum = i;
    else e.maximum = q.front().maximum;

    this->q.push(e);

    while (!aux.empty()){
        this->q.push(aux.front());
        aux.pop();
    }
}

void maxstack::pop()
{
    this->q.pop();
}

bool maxstack::empty()
{
    return (this->q.empty());
}

size_t maxstack::size() {
    return (this->q.size());
}

element maxstack::top() {
    return (this->q.front());
}

