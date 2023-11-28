#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

template <class T>
void printStack(const stack<T> &p) {
   stack<T> aux(p);
   while (!aux.empty()) {
       cout << aux.top() << " ";
       aux.pop();
   }
}

template <class T>
void reverse_stack(stack<T>& p) {
    stack<T> aux_p1;

    while (!p.empty()) {
        aux_p1.push(p.top());
        p.pop();
    }
    swap(p,aux_p1);
}
/*
 * @brief Me rayo del to y hago una cola con una pila
 */
template <class T>
class cola_con_pila {
private:
    stack<T> p;
public:
    // Constructor sin argumentos
    cola_con_pila(){}

    // Constructor de copia
    cola_con_pila(const cola_con_pila& c)
    {
        this->p = c.p;
    }

    bool empty() { return p.empty();}
    T front () { return p.top();}
    void push (T t) {
        // Vuelvo la pila en una auxiliar
        stack<T> aux_p;
        while (!p.empty()) {
            aux_p.push(p.top());
            p.pop();
        }
        // Metemos el nuevo en la auxiliar (parte de atrás de la original)
        p.push(t);
        // Volvemos a volcar (dando la vuelta)
        while (!aux_p.empty()) {
            p.push(aux_p.top());
            aux_p.pop();
        }
    }

    void pop() {p.pop();}
    size_t size() {return p.size();}
    void swap (cola_con_pila<T>& c) {swap(this->p, c.p);}

};

template <class T>
class pila_con_cola {
private:
   queue<T> q;
public:
    pila_con_cola() = default;
    pila_con_cola(const pila_con_cola<T>& p) { this->q=p.q;}

    bool empty() {return this->q.empty();}
    void swap(const pila_con_cola<T> &p) { swap(this->q, p.q);}
    T top() {return this->q.front();}
    void push(const T t)
    {
        queue<T> aux_q(this->q);
        while (!q.empty()){
            q.pop();
        }
        // Lo metemos al principio
        q.push(t);

        while (!aux_q.empty()){
            q.push(aux_q.front());
            aux_q.pop();
        }
    }

    void pop() {this->q.pop();}
    size_t size() {return this->q.size();}

};


int main() {
    string pos_pal = "n";

    // Usando pilas
    stack<char> p1, p2, aux_s;

    for (char c : pos_pal)
        p1.push(c);

    aux_s = p1;

    while (!aux_s.empty())
    {
        p2.push(aux_s.top());
        aux_s.pop();
    }

    assert(p2.size() == p1.size());
    bool pal = true;
    while (!p2.empty() && pal)
    {
       pal = p2.top() == p1.top();
       p1.pop(); p2.pop();
    }

    cout << "La palabra " << pos_pal << " "; !pal ? cout << "no " : cout << "sí "; cout << "es un palíndromo.";
}


