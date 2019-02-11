#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H
#include <vector>
#include <graph.h>


class DepthFirstSearch{
private:
    unsigned long int marked;
    unsigned int count;
    std::vector<unsigned int> upperVertice;
    const unsigned int root;

    unsigned long int Mask(unsigned int v);
    void Mark(unsigned int v);
    void Dfs(Graph g, unsigned int v);

public:
    bool IsMarked(unsigned int v);
    bool HasPathTo(unsigned int v);
    DepthFirstSearch(Graph g, unsigned int r);
    unsigned int Count();
    std::vector<unsigned int> PathTo(unsigned int v);
};

#endif // DEPTHFIRSTSEARCH_H
