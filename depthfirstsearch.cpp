#include "depthfirstsearch.h"

unsigned long int DepthFirstSearch::Mask(unsigned int v){
    unsigned long int mask = (1 << v);
    return mask;
}

void DepthFirstSearch::Mark(unsigned int v){
    this->marked |= Mask(v);
}

bool DepthFirstSearch::IsMarked(unsigned v){
    return (this->marked & Mask(v));
}

void DepthFirstSearch::Dfs(Graph g, unsigned int v){
    Mark(v);
    this->count++;
    std::vector<unsigned int> adjacent_vertices = g.AdjcentVerticesTo(v);
    for (std::vector<unsigned int>::iterator w = adjacent_vertices.begin() ; w != adjacent_vertices.end(); ++w)
        if(!IsMarked(*w)) Dfs(g, *w);
}

DepthFirstSearch::DepthFirstSearch(Graph g, unsigned int s):marked(0),count(0){
    Dfs(g, s);
}

unsigned int DepthFirstSearch::Count(){
    return this->count;
}
