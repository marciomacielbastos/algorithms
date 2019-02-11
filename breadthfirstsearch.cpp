#include "breadthfirstsearch.h"

BreadthFirstSearch::BreadthFirstSearch(Graph g, unsigned int r):marked(0), root(r){
    std::vector<unsigned int> temp(g.NumberOfVertices());
    this->upperVertice = temp;
    Bfs(g, r);
}

unsigned long int BreadthFirstSearch::Mask(unsigned int v){
    unsigned long int mask = (1 << v);
    return mask;
}

void BreadthFirstSearch::Mark(unsigned int v){
    this->marked |= Mask(v);
}

bool BreadthFirstSearch::IsMarked(unsigned int v){
    return (this->marked & Mask(v));
}

void BreadthFirstSearch::Bfs(Graph g, unsigned int r){
    std::queue<unsigned int> queue;
    Mark(r);
    queue.push(r);
    while(!queue.empty()){
        unsigned int v = queue.front();
        queue.pop();
        std::vector<unsigned int> adjacent_vertices = g.AdjcentVerticesTo(v);
        for (std::vector<unsigned int>::iterator w = adjacent_vertices.begin() ; w != adjacent_vertices.end(); ++w){
            if(!IsMarked(*w)){
                this->upperVertice[*w] = v;
                Mark(*w);
                queue.push(*w);
            }
        }
    }
}

bool BreadthFirstSearch::HasPathTo(unsigned int v){
    return this->IsMarked(v);
}

std::vector<unsigned int> BreadthFirstSearch::PathTo(unsigned int v){
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
