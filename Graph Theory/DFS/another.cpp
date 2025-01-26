//________________dfs................

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> graph[N];
bool visited[N];

void dfs(int vertex) {
    if (visited[vertex]) return;

    visited[vertex] = true;
    cout<< vertex<< '\n';

    for (int &child : graph[vertex]) {
        printf("par = %d, child = %d\n", vertex, child);
        dfs(child);
    }

}

int main() {
    int numberOfVertices, numberOfEdges;
    cin >>numberOfVertices >>numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);
}