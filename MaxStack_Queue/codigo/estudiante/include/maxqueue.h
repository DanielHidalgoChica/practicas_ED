/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */

#ifndef MAX_QUEUE_H_
#define MAX_QUEUE_H_

#include <iostream>
#include <stack>
#include <element.h>

using namespace std;

class maxqueue {
private:
    stack<element> p;
    stack<int> maxs_stack;
public:
    maxqueue();
    maxqueue(const maxqueue& mq);

    element front();
    void pop();
    void push(int i);
    bool empty();
    size_t size();
};

#endif