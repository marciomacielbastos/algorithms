#include "depthfirstsearch.h"

unsigned long int DepthFirstSearch::Mask(unsigned int v){
    unsigned long int mask = (1 << v);
    return mask;
}

void DepthFirstSearch::Mark(unsigned int v){
    this->marked |= Mask(v);
}

bool DepthFirstSearch::IsMarked(unsigned int v){
    return (this->marked & Mask(v));
}

bool DepthFirstSearch::HasPathTo(unsigned int v){
    return this->IsMarked(v);
}

void DepthFirstSearch::Dfs(Graph g, unsigned int v){
    Mark(v);
    this->count++;
    std::vector<unsigned int> adjacent_vertices = g.AdjcentVerticesTo(v);
    for (std::vector<unsigned int>::iterator w = adjacent_vertices.begin() ; w != adjacent_vertices.end(); ++w)
        if(!IsMarked(*w)){
            this->upperVertice[*w] = v;
            Dfs(g, *w);
        }
}

DepthFirstSearch::DepthFirstSearch(Graph g, unsigned int r):marked(0),count(0),root(r){
    std::vector<unsigned int> temp(g.NumberOfVertices());
    this->upperVertice = temp;
    Dfs(g, r);
}

unsigned int DepthFirstSearch::Count(){
    return this->count;
}

std::vector<unsigned int> DepthFirstSearch::PathTo(unsigned int v){
    std::vector<unsigned int> path;
    if(!HasPathTo(v)){
        return path;
    }
    for (unsigned int x = v; x!=this->root; x = this->upperVertice[x]) {
        path.push_back(x);
    }
    return path;
}
