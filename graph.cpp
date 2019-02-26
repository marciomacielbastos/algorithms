#include "graph.h"

Graph::Graph(unsigned int numberOfVertices):directed(false){
    this->numberOfVertices = numberOfVertices;
    this->numberOfEdges = 0;
    for(unsigned int i=0; i<numberOfVertices; i++){
        std::vector<unsigned long int> newAdjacencies;
        newAdjacencies.push_back(0);
        this->adjacencyList.push_back(newAdjacencies);
    }
}

Graph::Graph(unsigned int numberOfVertices, bool directed){
    this->numberOfVertices = numberOfVertices;
    this->numberOfEdges = 0;
    this->directed = directed;
    for(unsigned int i=0; i<numberOfVertices; i++){
        std::vector<unsigned long int> newAdjacencies;
        newAdjacencies.push_back(0);
        this->adjacencyList.push_back(newAdjacencies);
    }
}

Graph::Graph(const std::string& file):directed(false){
    unsigned int a, b;
    std::ifstream infile(file);
    infile >> this->numberOfVertices;
    infile >> this->numberOfEdges;
    this->numberOfEdges = 0;
    for(unsigned int i=0; i<numberOfVertices; i++){
        std::vector<unsigned long int> newAdjacencies;
        newAdjacencies.push_back(0);
        this->adjacencyList.push_back(newAdjacencies);
    }
    while (infile >> a >> b)
    {
        this->AddEdge(a,b);
    }
    infile.close();
}

Graph::Graph(const std::string& file, bool directed){
    unsigned int a, b;
    this->directed = directed;
    std::ifstream infile(file);
    infile >> this->numberOfVertices;
    infile >> this->numberOfEdges;
    this->numberOfEdges = 0;
    for(unsigned int i=0; i<numberOfVertices; i++){
        std::vector<unsigned long int> newAdjacencies;
        newAdjacencies.push_back(0);
        this->adjacencyList.push_back(newAdjacencies);
    }
    while (infile >> a >> b){
        this->AddEdge(a,b);
    }
    infile.close();
}

bool Graph::IsDirected(){
    bool isdirected = this->directed;
    return isdirected;
}

unsigned int Graph::NumberOfVertices(){
    unsigned int numberOfVertices = this->numberOfVertices;
    return  numberOfVertices;
}

unsigned int Graph::NumberOfEdges(){
    unsigned int numberOfEdges = this->numberOfEdges;
    return numberOfEdges;
}

void Graph::AddDirectedEdge(unsigned int v, unsigned int w){
    if(this->IsConnected(v, w)) return;
    unsigned int box, slot;
    unsigned int key = 1;
    box = w/32;
    slot = w%32;
    if(adjacencyList[v].size() < box){
        for(unsigned int i=0; i < (box - adjacencyList[v].size()); i++){
            adjacencyList[v].push_back(0);
        }
    }
    key<<=slot;
    this->adjacencyList[v][box] |= key;
    this->numberOfEdges++;
}

void Graph::AddUndirectedEdge(unsigned int v, unsigned int w){
    this->AddDirectedEdge(v, w);
    this->AddDirectedEdge(w, v);
    this->numberOfEdges--;
}

void Graph::AddEdge(unsigned int v, unsigned int w){
    if(this->directed){
        this->AddDirectedEdge(v, w);
    } else {
        this->AddUndirectedEdge(v, w);
    }
}

bool Graph::IsConnected(unsigned v, unsigned w){
    unsigned int box, slot;
    unsigned int key = 1;
    box = w/32;
    slot = w%32;
    key<<=slot;
    bool isConnected = (this->adjacencyList[v][box] & key);
    return isConnected;
}

std::vector<unsigned int> Graph::AdjcentVerticesTo(unsigned int v){
    std::vector<unsigned int> adjacentVertices;
    for(unsigned int i=0; i < this->NumberOfVertices(); i++){
        if(this->IsConnected(v, i)){
            adjacentVertices.push_back(i);
        }
    }
    return adjacentVertices;
}

unsigned long Graph::DegreeOf(unsigned int v){
    std::vector<unsigned int> adjV = this->AdjcentVerticesTo(v);
    unsigned long degree = adjV.size();
    return degree;
}

unsigned long Graph::MaximumDegree(){
    unsigned long max = 0;
    unsigned long degree;
    for(unsigned int v=0; v < this->NumberOfVertices(); v++){
        degree = this->DegreeOf(v);
        if(degree > max){
            max = degree;
        }
    }
    return max;
}

std::string Graph::ToString(){
    std::string s = std::to_string(this->NumberOfVertices()) + " vertices, ";
    s += std::to_string(this->NumberOfEdges()) + " edges\n" ;
    s += "directed: " + std::to_string(this->directed) + "\n";
    for(unsigned int v=0; v<this->NumberOfVertices(); v++){
        s += std::to_string(v) + ": ";
        std::vector<unsigned int> adjV = this->AdjcentVerticesTo(v);
        for(unsigned int i=0; i<adjV.size(); i++){
            s += std::to_string(adjV[i]) + " ";
        }
        s += " \n";
    }
    return s;
}
