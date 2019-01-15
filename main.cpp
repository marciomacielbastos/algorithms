#include <iostream>
#include <fstream>
#include <vector>
#include <graph.h>
//#include <cstdlib>
//#include <heap.h>
//#include <ctime>

std::vector<long> tests(std::vector<long>& d){
    d[6] = 999;
    return d;
}

int main(){
    std::string file("/home/marcio/MEGA/Physics/thefile.txt");
    Graph g(file);
    std::cout<<g.ToString();
    long int a=1;
    a<<=3;
    std::cout<<g.DegreeOf(11)<<std::endl;

    return 0;
}
