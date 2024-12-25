#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const long long INF = 1e18+10;

vector<pair<int, long long>> graph[N];

void dijkstra(int &n) {
    vector<int> vis(N, 0);
    vector<long long> dist(N, INF);
    // To store the parent of each node in the path
    vector<int> parent(N, -1);

    set<pair<long long, int>> st;
    // Start from node 1
    st.insert({0, 1});
    dist[1] = 0;

    while (!st.empty()) {
        auto node = *st.begin();
        int v = node.second;
        int v_dis = node.first;
        st.erase(st.begin());

        if (vis[v]) continue;
        vis[v] = 1;

        for (auto &child : graph[v]) {
            int child_v = child.first;
            long long wt = child.second;

            if (dist[v] + wt < dist[child_v]) {
                // Remove old distance
                st.erase({dist[child_v], child_v}); 
                dist[child_v] = dist[v] + wt;
                // Update parent
                parent[child_v] = v;
                // Insert updated distance
                st.insert({dist[child_v], child_v});
            }
        }
    }

    // If destination is unreachable
    if (dist[n] == INF) {
        cout << -1;
        return;
    }

    // Reconstruct and print the path
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (int node : path){
        cout << node <<' ';
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    dijkstra(n);

    return 0;
}
