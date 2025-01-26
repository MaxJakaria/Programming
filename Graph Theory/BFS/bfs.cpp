//______________bfs(Level ordered traversal)..........

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

bool visited[N];
int level[N];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty()) {
        int cur_v = q.front();
        q.pop();

        cout << cur_v << "-> ";
        for (int &child : graph[cur_v]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}




int main() {
    int numberOfVertices, numberOfEdges;
    cin >> numberOfVertices >> numberOfEdges;

    for (int i = 0; i < numberOfEdges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bfs(1);
    cout << "complete traversal....\n\n";

    for (int i = 1; i <= numberOfVertices; i++) {
        cout << i << ": " << level[i] << '\n';
    }
    return 0;
}