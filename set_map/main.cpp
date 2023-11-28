#include <iostream>
#include <set>
#include <map>

using namespace std;

bool cut_odd_even (const set<int> & s_orig, set<int> &s_even,set<int> &s_odd) {
    set<int>::iterator it = s_orig.begin();
    while (it != s_orig.end()) {
        if (*it % 2 == 0) s_even.insert(*it);
        else s_odd.insert(*it);
        it++;
    }
    return (s_even.size() >= s_odd.size());
}

// Determine if a set has more than half of its elemenets contained in some other
template <typename T>
bool half_contained(const set<T> s_orig, const set<T> s_other) {
    set<int>::iterator it = s_orig.begin();
    int cont = 0;
    while (it != s_orig.end())
    {
       if (s_other.count(*it)) cont++;
       it++;
    }
    return ((double)cont >= (double)s_orig.size()/2);
}

template <typename T>
void print_set(const multiset<T> s1) {
    auto it = s1.begin();
    while (it != s1.end()) {cout << *it << " "; it++;}
}


void imprimir(map<string,int> guia) {
    cout << "///////////////////////////////" << endl;
    map<string, int>::iterator it = guia.begin();
    while (it != guia.end()) {
        cout << "Nombre: " << it->first << " Num: " << it->second << endl;
        it++;
    }
    cout << "///////////////////////////////" << endl;
}

int main() {
    map<string, int>datos; // Número de libros leidos
    datos.insert(pair<string, int>("Daniel", 8));
    datos.insert(pair<string, int>("Daniel", 9));
    datos.insert(pair<string, int>("Daniel", 3));
    datos.insert(std::make_pair("Ana", 12));
    datos.insert(std::make_pair("Carlos", 5));
    datos.insert(std::make_pair("Elena", 15));
    datos.insert(std::make_pair("Beto", 3));
    imprimir(datos);
    auto ub = datos.upper_bound("Daniel");
    auto lb = datos.lower_bound("Daniel");
    datos.erase(lb,ub);
    datos["Javier"];
    imprimir(datos);
}

