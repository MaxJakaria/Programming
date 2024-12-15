#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];
int cats[N], ans = 0, m;
bool vis[N];

void dfs(int node, int con_cats){
    vis[node] = true;

    if (con_cats > m) return;

    bool is_leaf = true;
    for (auto child : graph[node]){
        if (!vis[child]) {
            is_leaf = false;
            
            dfs(child, (cats[child] ? con_cats + 1 : 0));
        }
    }

    if (is_leaf) ans++;
}

int main(){
    int n, x, y;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> cats[i];

    for (int i = 0; i < n - 1; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, cats[1]);

    cout << ans << '\n';
    return 0;
}
