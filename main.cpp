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
    std::string file("/home/marcim/MEGA/Physics/tinyCG.txt");
    Graph g(file);
    std::cout<<g.ToString();
//    unsigned int a = 2;
//    unsigned long int mask= (1 << a);
    DepthFirstSearch d = DepthFirstSearch(g,0);
    BreadthFirstSearch b = BreadthFirstSearch(g, 0);
    std::vector<unsigned int> path = d.PathTo(5);
    std::reverse(path.begin(),path.end());
    for(std::vector<unsigned int>::iterator it = path.begin(); it != path.end(); ++it) {
        std::cout<<*it<<' ';
    }
    std::cout<<std::endl;
    path = b.PathTo(5);
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
