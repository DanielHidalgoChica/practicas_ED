#include "dictionary.h"
#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const Dictionary& dic){
    set<string>::iterator it = dic.words.begin();
    while (it != dic.words.end()){
        os << *it << endl;
        it++;
    }
    return os;
}

istream& operator>>(istream& is, Dictionary& dic) {
    dic.clear();
    string wrd;
    while (is >> wrd){
        dic.words.insert(wrd);
    }
    return is;
}

Dictionary::Dictionary() {}

Dictionary::Dictionary(const Dictionary &othr) {
    this->words = othr.words;
}

bool Dictionary::exists(const string &s) const {return (bool)words.count(s);}

bool Dictionary::insert(const string &s) {
    pair<set<string>::iterator, bool> ret = words.insert(s);
    return ret.second;
}

bool Dictionary::erase(const std::string &s) {
    return (bool) this->words.erase(s);
}

void Dictionary::clear() {this->words.clear();}

bool Dictionary::empty() const {return this->words.empty();}

unsigned int Dictionary::size() const {return this->words.size();}

vector<string> Dictionary::wordsOfLength(int length) const {
    vector<string> v_ret;
    set<string>::iterator it = this->words.begin();
    while (it != this->words.end()) {
        if ((*it).length() == length) v_ret.push_back(*it);
        it++;
    }
    return v_ret;
}

int count_ocurrences(char c, string word, size_t pos) {
    int cont = 0;
    size_t s = word.find(c,pos);
    if (s != string::npos) {
        cont++;
        cont += count_ocurrences(c,word,s+1);
    }
    return cont;
}

int Dictionary::getOcurrences(char c) const {
    int cont = 0;
    set<string>::iterator it = this->words.begin();
    while (it != this->words.end()) {
        cont += count_ocurrences(c,*it);
        it++;
    }
    return cont;
}

void Dictionary::anade(const Dictionary &dic) {
    set<string>::iterator it = dic.words.begin();
    while (it != dic.words.end()) {
        this->words.insert(*it);
        it++;
    }
}

