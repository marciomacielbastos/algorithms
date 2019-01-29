#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <fstream>

class Graph
{
private:
    unsigned int numberOfVertices;
    unsigned int numberOfEdges;
    bool directed;
    std::vector<std::vector<unsigned long int> > adjacencyList;

public:
    Graph(unsigned int numberOfVertices);
    Graph(unsigned int numberOfVertices, bool directed);
    Graph(const std::string& file);
    Graph(const std::string& file, bool directed);
    bool IsDirected();
    unsigned int NumberOfVertices();
    unsigned int NumberOfEdges();
    void AddEdge(unsigned int v, unsigned int w);
    void AddUndirectedEdge(unsigned int v, unsigned int w);
    void AddDirectedEdge(unsigned int v, unsigned int w);
    bool IsConnected(unsigned int v, unsigned int w);
    std::vector<unsigned int> AdjcentVerticesTo(unsigned int v);
    std::string ToString();
    unsigned long DegreeOf(unsigned int v);
    unsigned long MaximumDegree();
    float AverageDegree();
    unsigned int NumberOfSelfLoops();
};

#endif // GRAPH_H
