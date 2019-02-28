#include "symbolgraph.h"

SymbolGraph::SymbolGraph(const std::string& file, char delim):g(Graph()){
    std::ifstream in;
    std::string line, value;
    std::stringstream ss;
    unsigned int v, w;
    std::pair<std::map<std::string, unsigned int>::iterator,bool> ret;
    in.open(file,std::ios::in);
    unsigned int key = 0;
    while (in.good()) {
        getline(in, line);
        ss << line;
        if (line.size() > 0) StringStreamToMap(ss, &key, delim, &ret);
        ss.clear();
    }
    in.clear();
    in.seekg(0);
    Graph g(key);
    while (in.good()){
        getline(in, line);
        if (line.size() > 0){
            ss << line;
            getline(ss, value, delim);
            v = this->stringMap.find(value)->second;
            getline(ss, value);
            w = this->stringMap.find(value)->second;
            g.AddEdge(v, w);
            ss.clear();
        }
    }
    this->g = g;
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
