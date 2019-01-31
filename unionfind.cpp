#include "unionfind.h"

UnionFind::UnionFind(unsigned int N){
    this->count = N;
    for(unsigned int i=0; i < N;i++){
        this->id.push_back(i);
    }
    for(unsigned int i=0; i < N;i++){
        this->sizes.push_back(1);
    }
}

unsigned int UnionFind::GetCount(){
    return count;
}

unsigned int UnionFind::Find(unsigned int v){
    while (v != this->id[v]) {
       v = this->id[v];
    }
    return v;
}

void UnionFind::Union(unsigned int v, unsigned int w){
    unsigned int vRoot = this->Find(v);
    unsigned int wRoot = this->Find(w);
    if(vRoot == wRoot) return;
    else if (this->sizes[vRoot] < this->sizes[wRoot]) {
        this->id[vRoot] = wRoot;
        this->sizes[wRoot] += this->sizes[vRoot];
    } else {
        this->id[wRoot] = vRoot;
        this->sizes[vRoot] += this->sizes[wRoot];
    }
    this->count--;
}

bool UnionFind::Connected(unsigned int v, unsigned int w){
    return (this->Find(v) == this->Find(w));
}
