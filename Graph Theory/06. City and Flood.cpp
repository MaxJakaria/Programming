#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int _size[N];

void make(int v){
    parent[v] = v;
    _size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        // Union by _size
        if(_size[a] < _size[b])
            swap(a,b);
        parent[b] = a;
        _size[a] += _size[b];
    }
}

int main(){
    int n, k; cin >>n >>k;

    for(int i=1; i<=n; i++) make(i);

    while(k--){
        int u, v; cin >>u >>v;
        Union(u,v);
    }

    int Empiers_cnt = 0;
    for(int v=1; v<=n; v++)
        if(find(v) == v) Empiers_cnt++;

    cout <<Empiers_cnt <<'\n';
    return 0;
}
