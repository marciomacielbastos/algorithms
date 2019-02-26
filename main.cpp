#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <graph.h>
#include <depthfirstsearch.h>
#include <breadthfirstsearch.h>
#include <string>
#include <sstream>
//#include <cstdlib>
//#include <heap.h>
//#include <ctime>

std::vector<long> tests(std::vector<long>& d){
    d[6] = 999;
    return d;
}

using namespace std;

int main()
{
    ifstream in;
    string a, b;
    string c, d;
    stringstream ss;
    in.open("/home/marcim/MEGA/Physics/text.txt",ios::in);
    getline(in, a);
    getline(in, b);
    while (in.good())
    {
        getline(in, a);
        ss << a;
        getline(ss, b, ':');
        getline(ss, b, ':');
        cout << b << " ";
    }

    in.close();
}

//int main(){
//    std::string file("/home/marcim/MEGA/Physics/tinyDG.txt");
//    Graph g(file);
//    std::ifstream infile(file);
//    std::string a, b;
//    while(infile.good()){
//        getline(infile, a,":");

//    }
//    unsigned long int test = 1;
//    unsigned long int test2 = 1;
//    test <<= 33;
//    std::cout<<test<<std::endl;
//    std::cout<<g.ToString();
//    unsigned int a = 2;
//    unsigned long int mask= (1 << a);
//    DepthFirstSearch d = DepthFirstSearch(g);
//    BreadthFirstSearch b = BreadthFirstSearch(g, 0);
//    std::cout<<"Is 0 and 6 connected?"<<d.IsConnected(0,6)<<std::endl;
//    std::cout<<"Number of Components: "<<d.NumberOfComponents()<<std::endl;
//    std::cout<<"Components of "<<6<<": "<<d.ComponentId(6)<<std::endl;
//    std::cout<<"Is Bipartite? "<<d.IsBipartite()<<std::endl;
//    bool hasCycle = d.HasCycle();
//    std::string txt;
//    if(hasCycle) txt = "yes";
//    else txt = "no";
//    std::cout<<"Has cycle: "<<txt<<std::endl;
//    std::vector<unsigned int> path = d.PathTo(4);
//    std::reverse(path.begin(),path.end());
//    for(std::vector<unsigned int>::iterator it = path.begin(); it != path.end(); ++it) {
//        std::cout<<*it<<' ';
//    }
//    std::cout<<std::endl;
//    path = b.PathTo(4);
//    std::reverse(path.begin(),path.end());
//    for(std::vector<unsigned int>::iterator it = path.begin(); it != path.end(); ++it) {
//        std::cout<<*it<<' ';
//    }
//    std::cout<<std::endl;
//    std::cout<<g.DegreeOf(11)<<std::endl;

//    unsigned long int test = (~0) ^ (1<<30);
//    std::cout<<test;
//    return 0;
//}
