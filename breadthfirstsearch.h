#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H
#include <vector>
#include <graph.h>
#include <queue>

class BreadthFirstSearch{
private:
    unsigned long int marked;
    std::vector<unsigned int> upperVertice;
    const unsigned int root;

    unsigned long int Mask(unsigned int v);
    void Mark(unsigned int v);
    void Bfs(Graph g, unsigned r);
public:
    BreadthFirstSearch(Graph g, unsigned int r);
    bool IsMarked(unsigned int v);
    bool HasPathTo(unsigned int v);
    std::vector<unsigned int> PathTo(unsigned int v);
};

#endif // BREADTHFIRSTSEARCH_H
