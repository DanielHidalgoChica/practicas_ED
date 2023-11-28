/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#ifndef MAX_STACK_H_
#define MAX_STACK_H_
#include <iostream>
#include <queue>
#include <element.h>

using namespace std;

class maxstack {
private:
    queue<element> q;
public:
    maxstack();
    maxstack(const maxstack & ms);

    element top();
    void push(int i);
    void pop();
    bool empty();
    size_t size();
};

#endif
