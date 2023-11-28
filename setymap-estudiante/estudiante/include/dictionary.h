#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Dictionary {
private:
    set <string> words;
public:
    Dictionary();

    Dictionary(const Dictionary& othr);

    bool exists(const string &s) const;
    bool insert(const string &s);
    bool erase(const string &s);
    void clear();
    bool empty() const;
    unsigned int size() const;
    vector<string> wordsOfLength(int length) const;
    int getOcurrences(char c) const;

    void anade(const Dictionary &dic);

    friend istream& operator>>(istream &is, Dictionary &dic);
    friend ostream& operator<<(ostream &os, const Dictionary& dic);

};


// Funtion to count the number of occurences of a character in a word
int count_ocurrences(char c, string word, size_t pos = 0);

#endif
