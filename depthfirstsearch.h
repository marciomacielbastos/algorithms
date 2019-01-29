#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H
#include <vector>
#include <graph.h>


class DepthFirstSearch{
private:
    unsigned long int marked;
    unsigned int count;
    unsigned long int Mask(unsigned int v);
    void Mark(unsigned int v);
    void Dfs(Graph g, unsigned int v);

public:
    bool IsMarked(unsigned v);
    DepthFirstSearch(Graph g, unsigned int s);
    unsigned int Count();
};

#endif // DEPTHFIRSTSEARCH_H
