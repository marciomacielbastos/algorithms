#include "depthfirstsearch.h"

//DepthFirstSearch::DepthFirstSearch(Graph g, unsigned int r):marked(0),color(0),count(0),hasCycle(false),isBipartite(true),root(r) {
//    std::vector<unsigned int> temp(g.NumberOfVertices());
//    this->upperVertice = temp;
//    Dfs(g, r, r);
//}

//DepthFirstSearch::DepthFirstSearch(Graph g):marked(0),color(0),count(0),id(0),hasCycle(false),isBipartite(true),root(0) {
//    std::vector<unsigned int> temp(g.NumberOfVertices());
//    this->upperVertice = temp;
//    std::vector<unsigned int> temp1(g.NumberOfVertices());
//    this->componentId = temp1;
//    for (unsigned int v=0; v < g.NumberOfVertices(); v++) {
//        if(!IsMarked(v)){
//            Dfs(g, v, v);
//            this->id++;
//        }
//    }
//}

void DepthFirstSearch::StartVectors(Graph g){
    std::vector<bool> marked(g.NumberOfVertices());
    this->marked = marked;
    std::vector<unsigned int> componentId(g.NumberOfVertices());
    this->componentId = componentId;
    for(unsigned int i = 0; i < g.NumberOfVertices(); i++){
        this->upperVertice.push_back(i);
    }
    std::vector<bool> colors(g.NumberOfVertices());
    this->colors = colors;
}

DepthFirstSearch::DepthFirstSearch(Graph g):count(0),id(0),hasCycle(false),isBipartite(true),root(0) {
    StartVectors(g);
    for (unsigned int v=0; v < g.NumberOfVertices(); v++) {
        if(!IsMarked(v)){
            Dfs(g, v, v);
            this->id++;
        }
    }
}

DepthFirstSearch::DepthFirstSearch(Graph g, unsigned int r):count(0),root(r) {
    StartVectors(g);
    Dfs(g, r);
}

//unsigned long int DepthFirstSearch::Mask(unsigned int v) {
//    unsigned long int mask = (1 << v);
//    return mask;
//}

//void DepthFirstSearch::Mark(unsigned int v) {
//    this->marked |= Mask(v);
//}

//bool DepthFirstSearch::IsMarked(unsigned int v) {
//    return (this->marked & Mask(v));
//}

void DepthFirstSearch::Mark(unsigned int v) {
    this->marked[v] = true;
}

bool DepthFirstSearch::IsMarked(unsigned int v) {
    return this->marked[v];
}

bool DepthFirstSearch::HasPathTo(unsigned int v) {
    return this->IsMarked(v);
}

void DepthFirstSearch::Dfs(Graph g, unsigned int v) {
    Mark(v);
    this->count++;
    std::vector<unsigned int> adjacent_vertices = g.AdjcentVerticesTo(v);
    for (std::vector<unsigned int>::iterator u = adjacent_vertices.begin() ; u != adjacent_vertices.end(); ++u){
        if(!IsMarked(*u)){
            this->upperVertice[*u] = v;
            Dfs(g, *u);
        }
    }
}

void DepthFirstSearch::Dfs(Graph g, unsigned int v, unsigned int w) {
    Mark(v);
    this->componentId[v] = id;
    this->count++;
    std::vector<unsigned int> adjacent_vertices = g.AdjcentVerticesTo(v);
    for (std::vector<unsigned int>::iterator u = adjacent_vertices.begin() ; u != adjacent_vertices.end(); ++u){
        if(!IsMarked(*u)){
            this->upperVertice[*u] = v;
            this->colors[*u] = !this->colors[v];
            Dfs(g, *u, v);
        }
        else if (w != *u){
            this->hasCycle=true;
        }
        else if ((this->colors[w] == this->colors[v]) & this->isBipartite ) this->isBipartite = false;
    }
}

unsigned int DepthFirstSearch::Count() {
    return this->count;
}

std::vector<unsigned int> DepthFirstSearch::PathTo(unsigned int v) {
    std::vector<unsigned int> path;
    unsigned int upperVertice = this->upperVertice[v];
    if(!HasPathTo(v)){
        return path;
    }
    unsigned int currentVertice = v;
    while(currentVertice != this->upperVertice[currentVertice]){
        path.push_back(currentVertice);
        currentVertice = this->upperVertice[currentVertice];
    } path.push_back(currentVertice);
    
//    for (unsigned int x = v; x!=this->root; x = this->upperVertice[x]) {
//        path.push_back(x);
//    }
//    path.push_back(this->root);
    
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

bool DepthFirstSearch::HasCycle(){
    return this->hasCycle;
}

bool DepthFirstSearch::IsBipartite(){
    return this->isBipartite;
}
