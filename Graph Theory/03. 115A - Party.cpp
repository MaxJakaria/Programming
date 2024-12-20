#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];
vector<int> roots;
bool vis[N] = {false};
int depth[N];

void dfs(int vertex, int par = 0) {
    for (int child : graph[vertex]) {
        if (child == par) continue;
        if (!vis[child]) {
            vis[child] = true;
            depth[child] = depth[vertex] + 1;
            dfs(child, vertex);
        }
    }
}

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        if (x == -1) {
            roots.push_back(i);
        } else {
            graph[i].push_back(x);
            graph[x].push_back(i);
        }
    }

    int maxHeight = 0;

    for (int root : roots) {
        memset(vis, false, sizeof(vis));
        memset(depth, 0, sizeof(depth));
        vis[root] = true;
        dfs(root);
        maxHeight = max(maxHeight, *max_element(depth, depth + n + 1));
    }

    cout << maxHeight + 1 << endl;
    return 0;
}
