#include "symbolgraph.h"

SymbolGraph::SymbolGraph(const std::string& file, char delim):g(Graph()){
    std::ifstream in;
    std::string a, b;
    std::stringstream ss;
    std::pair<std::map<std::string, unsigned int>::iterator,bool> ret;
    in.open(file,std::ios::in);
    unsigned int key = 0;
    while (in.good()) {
        getline(in, a);
        ss << a;
        if(a.size() > 0) StringStreamToMap(ss, &key, delim, &ret);
        ss.clear();
    }
    in.close();
}

void SymbolGraph::StringStreamToMap(std::stringstream& ss, unsigned int *key, char delim,
                                    std::pair<std::map<std::string, unsigned int>::iterator,bool> *ret){

    std::string value;
    getline(ss, value, delim);
    InsertStringMap(ret, value, key);
    getline(ss, value);
    InsertStringMap(ret, value, key);
}

void SymbolGraph::InsertStringMap(std::pair<std::map<std::string, unsigned int>::iterator,bool> *ret,
                                          std::string value, unsigned int * key){
    *ret = this->stringMap.insert (std::pair<std::string, unsigned int>(value, *key));
    if (ret->second == true) {
        this->keys.push_back(value);
        (*key)++;
    }
}
