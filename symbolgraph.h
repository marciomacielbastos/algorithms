#ifndef SYMBOLGRAPH_H
#define SYMBOLGRAPH_H
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <graph.h>

class SymbolGraph{
private:
    std::map<std::string, unsigned int> stringMap;
    std::vector<std::string> keys;
    Graph g;
    void StringStreamToMap(std::stringstream& ss, unsigned int *key, char delim,
                           std::pair<std::map<std::string, unsigned int>::iterator,bool> *ret);
    void InsertStringMap(std::pair<std::map<std::string, unsigned int>::iterator,bool> *ret,
                                 std::string value, unsigned int * key);
public:
    SymbolGraph(const std::string& file, char delim);
};

#endif // SYMBOLGRAPH_H
