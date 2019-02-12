#include "depthfirstsearch.h"

DepthFirstSearch::DepthFirstSearch(Graph g, unsigned int r):marked(0),count(0),root(r) {
    std::vector<unsigned int> temp(g.NumberOfVertices());
    this->upperVertice = temp;
    Dfs(g, r);
}

DepthFirstSearch::DepthFirstSearch(Graph g):marked(0),count(0),id(0),root(0) {
    std::vector<unsigned int> temp(g.NumberOfVertices());
    this->upperVertice = temp;
    std::vector<unsigned int> temp1(g.NumberOfVertices());
    this->componentId = temp1;
    for (unsigned int v=0; v < g.NumberOfVertices(); v++) {
        if(!IsMarked(v)){
            Dfs(g, v);
            this->id++;
        }
    }
}

unsigned long int DepthFirstSearch::Mask(unsigned int v) {
    unsigned long int mask = (1 << v);
    return mask;
}

void DepthFirstSearch::Mark(unsigned int v) {
    this->marked |= Mask(v);
}

bool DepthFirstSearch::IsMarked(unsigned int v) {
    return (this->marked & Mask(v));
}

bool DepthFirstSearch::HasPathTo(unsigned int v) {
    return this->IsMarked(v);
}

void DepthFirstSearch::Dfs(Graph g, unsigned int v) {
    Mark(v);
    this->componentId[v] = id;
    this->count++;
    std::vector<unsigned int> adjacent_vertices = g.AdjcentVerticesTo(v);
    for (std::vector<unsigned int>::iterator w = adjacent_vertices.begin() ; w != adjacent_vertices.end(); ++w){
        if(!IsMarked(*w)){
            this->upperVertice[*w] = v;
            Dfs(g, *w);
        }
    }
}

unsigned int DepthFirstSearch::Count() {
    return this->count;
}

std::vector<unsigned int> DepthFirstSearch::PathTo(unsigned int v) {
    std::vector<unsigned int> path;
    if(!HasPathTo(v)){
        return path;
    }
    for (unsigned int x = v; x!=this->root; x = this->upperVertice[x]) {
        path.push_back(x);
    }
    path.push_back(this->root);
    return path;
}

bool DepthFirstSearch::IsConnected(unsigned int v, unsigned int w) {
    return (this->componentId[v] ==   this->componentId[w]);
}

unsigned int DepthFirstSearch::ComponentId(unsigned int v){
    return this->componentId[v];
}

unsigned int DepthFirstSearch::NumberOfComponents(){
    return this->id;
}
