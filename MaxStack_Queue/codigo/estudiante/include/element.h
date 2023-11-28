//
// Created by daniel on 30/10/23.
//

#ifndef P03_PILAS_COLAS_ELEMENT_H
#define P03_PILAS_COLAS_ELEMENT_H

#include <iostream>
using namespace std;

struct element {
    int value; // Current value to store
    int maximum; // Current max value in the structure

    friend ostream& operator<<(ostream& os,const element& e) {
        cout << "(" << e.value << ", " << e.maximum << ")";
        return os;
    }
};

#endif //P03_PILAS_COLAS_ELEMENT_H
