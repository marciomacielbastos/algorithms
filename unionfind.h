#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <vector>

class UnionFind
{
private:
    std::vector<unsigned int> id;
    std::vector<unsigned int> sizes;
    int count;
public:
    UnionFind(unsigned int N);
    void Union(unsigned int v, unsigned int w);
    unsigned int Find(unsigned int v);
    unsigned int GetCount();
    bool Connected(unsigned int v, unsigned int w);
};

#endif // UNIONFIND_H
