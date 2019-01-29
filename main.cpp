#include <iostream>
#include <fstream>
#include <vector>
#include <graph.h>
#include <depthfirstsearch.h>
//#include <cstdlib>
//#include <heap.h>
//#include <ctime>

std::vector<long> tests(std::vector<long>& d){
    d[6] = 999;
    return d;
}

int main(){
    std::string file("/home/marcio/MEGA/Physics/tinyCG.txt");
    Graph g(file);
    std::cout<<g.ToString();
    unsigned int a = 2;
    unsigned long int mask= (1 << a);
    DepthFirstSearch h = DepthFirstSearch(g,0);
    std::cout<< mask;
//    std::cout<<g.DegreeOf(11)<<std::endl;

//    unsigned long int test = (~0) ^ (1<<30);
//    std::cout<<test;
    return 0;
}
