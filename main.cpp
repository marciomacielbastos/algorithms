#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <graph.h>
#include <depthfirstsearch.h>
#include <breadthfirstsearch.h>
//#include <cstdlib>
//#include <heap.h>
//#include <ctime>

std::vector<long> tests(std::vector<long>& d){
    d[6] = 999;
    return d;
}

int main(){
    std::string file("/home/marcim/MEGA/Physics/tinyDG.txt");
    Graph g(file);
    std::cout<<g.ToString();
//    unsigned int a = 2;
//    unsigned long int mask= (1 << a);
    DepthFirstSearch d = DepthFirstSearch(g);
    BreadthFirstSearch b = BreadthFirstSearch(g, 6);
    std::cout<<"Is 0 and 6 connected?"<<d.IsConnected(7,6)<<std::endl;
    std::cout<<"Number of Components: "<<d.NumberOfComponents()<<std::endl;
    std::cout<<"Components of "<<0<<": "<<d.ComponentId(0)<<std::endl;
//    std::vector<unsigned int> path = d.PathTo(7);
//    std::reverse(path.begin(),path.end());
//    for(std::vector<unsigned int>::iterator it = path.begin(); it != path.end(); ++it) {
//        std::cout<<*it<<' ';
//    }
    std::cout<<std::endl;
    std::vector<unsigned int> path = b.PathTo(7);
    std::reverse(path.begin(),path.end());
    for(std::vector<unsigned int>::iterator it = path.begin(); it != path.end(); ++it) {
        std::cout<<*it<<' ';
    }
    std::cout<<std::endl;
//    std::cout<<g.DegreeOf(11)<<std::endl;

//    unsigned long int test = (~0) ^ (1<<30);
//    std::cout<<test;
    return 0;
}
